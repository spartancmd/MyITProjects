#include <iostream>
#include <vector>
#include <conio.h>

#include "Ship.hpp"
#include "Battleships.hpp"
#include "ConsoleOp.hpp"
#include "Position.hpp"



// ***** def. private Methods ***** //

void Battleships::fillField(char field[MAXLINES][MAXROWS], char sym) {
    for (size_t line = 0; line < MAXLINES; line++)
        for (size_t row = 0; row < MAXROWS; row++) 
            field[line][row] = sym;
}

void Battleships::outputColumn(size_t lenght, bool withLetters=true) {
    char color = 'b';

    std::cout << ConsoleOp::setBackgroundColor(color);
    
    std::cout << "  ";

    for (char letter = 'A'; letter < ('A' + lenght); letter++) {
        if (withLetters)
            std::cout << ' ' << letter << ' ';
        else 
            std::cout << "  ";
    }

    std::cout << ConsoleOp::setBackgroundColor(0) << std::endl;
}

void Battleships::outputFieldHiddenShips(char field[MAXLINES][MAXROWS]) {
    char columnColor = 'b'; // blue
    char standartColor = 'w';
    char hitColor = 'r'; // red
    char missedColor = 'y'; // yellow
    
    Battleships::outputColumn(MAXLINES);
    for (size_t line = 0; line < MAXLINES; line++)
    {
        std::cout << ConsoleOp::setBackgroundColor(columnColor) << line + 1 << ConsoleOp::setBackgroundColor(0);
        for (size_t row = 0; row < MAXROWS; row++) 
        {
            // decide which color should the section here have
            switch (field[line][row]) { 
                case 'h': // if hit
                    std::cout << ConsoleOp::setBackgroundColor(hitColor);
                    break;
                case 'm': // if missed
                    std::cout << ConsoleOp::setBackgroundColor(missedColor);
                    break;
                default: // else
                    std::cout << ConsoleOp::setBackgroundColor(standartColor);
            }   

            std::cout << "   ";
        }
        std::cout << ConsoleOp::resetColor() << std::endl;
    }
}

void Battleships::outputField(char field[MAXLINES][MAXROWS]) {
    char columnColor = 'b'; // blue
    char shipColor = 'B'; // black
    char standardColor = 'w';   // white

    Battleships::outputColumn(MAXLINES);
    for (size_t line = 0; line < MAXLINES; line++)
    {
        std::cout << ConsoleOp::setBackgroundColor(columnColor) << line + 1 << '\t' << ConsoleOp::setBackgroundColor(0);
        for (size_t row = 0; row < MAXROWS; row++) 
        {
            // decide which color should the section here have
            switch (field[line][row]) { 
                case 's': // if there's a ship
                    std::cout << ConsoleOp::setBackgroundColor(shipColor);
                    break;
                case ' ':   // if it's empty
                    std::cout << ConsoleOp::setBackgroundColor(standardColor);
                    break;
            }   

            std::cout << "   ";
        }
        std::cout << ConsoleOp::resetColor() << std::endl;
    }
}

int Battleships::putShipByPosForOutput(char field[MAXLINES][MAXROWS], Position pos, size_t shipIdx, const char shipDirection) {
    const size_t shipLength = ships[shipIdx].size;

    if (shipDirection == 'h' && (pos.row + shipLength > MAXROWS)) return -1; // Out of bounds
    if (shipDirection == 'v' && (pos.line + shipLength > MAXLINES)) return -1; // Out of bounds

    for (size_t i = 0; i < shipLength; i++) {
        if (shipDirection == 'h') field[pos.line][pos.row + i] = 's';
        if (shipDirection == 'v') field[pos.line + i][pos.row] = 's';
    }

    return 0;
}

bool Battleships::changePosAllowed(const char field[MAXLINES][MAXROWS], Position pos, size_t shipIdx, const char shipDirection) {
    const size_t shipLenght = ships[shipIdx].size;

    // we look at the case where the cursor gets moved down or right to decide if allowed. So we increase the variable of position
    if (shipDirection == 'v')
        pos.line++;
    if (shipDirection == 'h')
        pos.row++;

    // check if the position with the ship is out of field
    if (shipDirection == 'v' && pos.line > (MAXLINES - 1 - shipLenght))
        return false;
    if (shipDirection == 'h' && pos.row > (MAXROWS - 1 - shipLenght))
        return false;

    return true;
}

void Battleships::changePos(char field[MAXLINES][MAXROWS], Position& pos, const char arrow, const char shipDirection, const size_t curShipIdx) {
        switch(arrow) {
            case 72: // arrow - up
                pos.line--;
                break;
            case 77: // arrow - right
                if (changePosAllowed(field, pos, curShipIdx, shipDirection))
                    pos.row++;
                break;
            case 80: // arrow - down
                if (changePosAllowed(field, pos, curShipIdx, shipDirection))
                    pos.line++;
                break;
            case 75: // arrow - left
                pos.row--;
                break;
        }
}


bool Battleships::changeShipsDirectionAllowed(const char field[MAXLINES][MAXROWS], Position pos, char shipDirection, const size_t curShipIdx) {
    const size_t shipLenght = ships[curShipIdx].size;
    
    // check if the new direction of the ship is out of field
    if (shipDirection == 'h' && (pos.line + shipLenght - 1) > MAXLINES - 1) // shipLenght - 1 because current position includes one part of the ship
        return false;
    if (shipDirection == 'v' && (pos.row + shipLenght - 1) > MAXROWS - 1)
        return false;

    return true;
}

void Battleships::changeShipsDirection(const char field[MAXLINES][MAXROWS], const Position& pos, char& shipDirection, const size_t curShipIdx) {
    switch (shipDirection) {
        case 'v':
            if (changeShipsDirectionAllowed(field, pos, shipDirection, curShipIdx))
                shipDirection = 'h';
            break;
        case 'h':
            if (changeShipsDirectionAllowed(field, pos, shipDirection, curShipIdx))
                shipDirection = 'v';
            break;
    }
}

bool Battleships::shipInTheWay(const char field[MAXLINES][MAXROWS], Position pos, const char shipDirection, const size_t curShipIdx) {
    size_t shipLenght = ships[curShipIdx].size;

    if (shipDirection == 'v') {
        size_t n = pos.line + shipLenght - 1; // shipLenght - 1 because position already takes one part of ship

        for (; pos.line < n; pos.line++) {
            if (field[pos.line][pos.row] != ' ')
                return true;
        }
    }

    if (shipDirection == 'h') {
        size_t n = pos.row + shipLenght - 1;

        for (; pos.row < n; pos.row++) {
            if (field[pos.line][pos.row] != ' ')
                return true;
        }
    }

    return false;
}

int Battleships::placeShipsOnField(char field[MAXLINES][MAXROWS], const std::vector<Ship>& ships) {
    char key1 = 0;
    char shipDirection = 'h'; // h - horizontal; v - vertical
    Position pos{MAXLINES, MAXROWS, {5, 5}};
    size_t curShipIdx = 0;
    
    char fieldBfr[MAXLINES][MAXROWS];
    memcpy(fieldBfr, field, sizeof(field));

    size_t n = ships.size();
    while (curShipIdx < n) {
        memcpy(fieldBfr, field, sizeof(field)); // reseting the fieldBuffer to actuall field everytime
        putShipByPosForOutput(fieldBfr, pos, curShipIdx, shipDirection); // colors the field to see where our current ship is for output 

        std::cout << ConsoleOp::clearConsole() << ConsoleOp::setFontColor(curPlayer) << "Place your " << ships[curShipIdx].name << " by pressing SPACE\nTAB to change shipsDirection\tq - to leave" << ConsoleOp::setFontColor(0) << std::endl;
        outputField(fieldBfr); // outputs the field 

        key1 = _getch(); 

        switch (key1) {
            case -32: // if an arrow has been pressed
                changePos(fieldBfr, pos, _getch(), shipDirection, curShipIdx); // changes the position if possible, and by that ensures that the ship is at an allowed place
                break;
            case ' ': // SPACE to put the ship
                if (!shipInTheWay(field, pos, shipDirection, curShipIdx)) { // this time using field instead of fieldBfr
                    memcpy(field, fieldBfr, sizeof(fieldBfr)); // copy the current buffer to the actuall field
                    curShipIdx++;
                }
                break;
            case '\t': // TAB to change ships direction
                changeShipsDirection(fieldBfr, pos, shipDirection, curShipIdx);
                break;
            case 'q':
                exit(0);
        }
    }

    return 0;
}



// ***** def. public Methods ***** //

    Battleships::Battleships(bool botActive_)
    : botActive{botActive_}, curPlayer{'b'}
    {
        fillField(field1, ' ');
        fillField(field2, ' ');
    }

    void Battleships::restart() {
        curPlayer = 'b';
        fillField(field1, ' ');
        fillField(field2, ' ');
    }

    int Battleships::switchPlayer() {
        if (botActive)
            return 1;

        switch(curPlayer) {
            case 'b':
                curPlayer = 'r';
                break;
            case 'r':
                curPlayer = 'b';
                break;
            default:
                return 2;   // smth went wrong -> nothing was changed
        }

        return 0;
    }

    int Battleships::placeShips() {
        // first player puts the ships on his field
        placeShipsOnField(field1, ships);

        // if bot is activated, it fills his field
        if (botActive) {

            return 0;
        }
                
        // else second player puts the ships on his field
        switchPlayer();
        placeShipsOnField(field2, ships);

        return 0;
    }

    int Battleships::battle() {

    }

    int Battleships::isVictory() const {

    }




