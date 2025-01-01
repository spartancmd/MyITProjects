#include <iostream>
#include <conio.h>
#include "FourInARow.hpp"
#include "ConsoleDecorations.hpp"



// ********* METHODS def. ********* //

// ********* private ********* //
void FourInARow::switchPos(const char arrow) {
    switch (arrow) {
        case 77: // arrow - right
            pos.row++;
            break;
        case 75: // arrow - left
            pos.row--;
            break;
    }
}

void FourInARow::outputColumn(const char color) const {
    std::cout << ConsoleDecorations::setBackgroundColor('b');
    std::cout << ' ';
    for (unsigned row = 0; row < maxRows; row++) {
        std::cout << "   ";
    }
    std::cout << ' ';
    std::cout << ConsoleDecorations::setBackgroundColor(0) << std::endl;
}

void FourInARow::outputCursor() {
    std::cout << ' ';
    for (unsigned row = 0; row < maxRows; row++) {
        if (pos.row == row) {
            std::cout << ConsoleDecorations::setFontColor(playerColor) << "<#>" << ConsoleDecorations::setFontColor(0);
        }
        else 
            std::cout << "   ";
    }    
    std::cout << std::endl;
}

bool FourInARow::spaceBelowFilled(unsigned line, unsigned row) {
    if (line == (maxLines - 1)) { // to avoid going out of the array // if the current line is the bottom - we can use this space
        return true;
    }

    if (field[line + 1][pos.row] != ' ') { // the space below the current line is filled    
        return true;
    }

    return false;
}

void FourInARow::outputLine(bool& fieldMarked, const unsigned line) {
    for (unsigned row = 0; row < maxRows; row++) {  
        if (!fieldMarked && row == pos.row && spaceBelowFilled(line, row)) {
                std::cout << ConsoleDecorations::setBackgroundColor(playerColor);
                fieldMarked = true;
            }
        if (field[line][row] == ' ') { // if the current space is empty 
            std::cout << "   ";
        }
        else { 
            std::cout << ConsoleDecorations::setFontColor(field[line][row]) << " O ";
        }
        std::cout << ConsoleDecorations::resetColor();
    }   
}

// ********* public ********* //
FourInARow::FourInARow() {
    fillField(' ');
}

FourInARow::FourInARow(const char initPlayerColour) {
    fillField(' ');

    if (initPlayerColour == 'y' || initPlayerColour == 'r') {
        playerColor = initPlayerColour;
    } 
}

void FourInARow::fillField(const char sym) {
    for (unsigned line = 0; line < maxLines; line++) {
        for (unsigned row = 0; row < maxRows; row++) {
            field[line][row] = sym;
        }
    }
}

void FourInARow::outputField() {
    bool fieldMarked = false;
    
    outputColumn('b');
    for (unsigned line = 0; line < maxLines; line++) 
    {
        std::cout << ConsoleDecorations::setBackgroundColor('b') << ' ' << ConsoleDecorations::setBackgroundColor(0);
        outputLine(fieldMarked, line);
        std::cout << ConsoleDecorations::setBackgroundColor('b') << ' ' << ConsoleDecorations::setBackgroundColor(0) << std::endl;
    }
    outputColumn('b');
}

void FourInARow::choosePosition() {
    char input1 = 0;
    char input2 = 0;

    do {
        std::cout << ConsoleDecorations::clearConsole();
        std::cout << ConsoleDecorations::setFontColor(playerColor) << "Current player" << ConsoleDecorations::setFontColor(0) << std::endl;
        std::cout << "Press q to leave. Move the cursor by arrows. Choose the drop point by SPACE" << std::endl;
        outputCursor();
        outputField();
        
        input1 = _getch();

        switch (input1) {
            case 'q':
                exit(0);
            case 'Q':
                exit(0);
            case 32:
                return;
            case -32: // if an arrow
                input2 = _getch(); // reading second character of the buffer
                switchPos(input2);
                break;
        }  
    } while (true);
}

int FourInARow::operateOnField() {
    if (field[0][pos.row] != ' ')
        return 1; // can't change the highest element
    
    for (unsigned line = 0; line < maxLines; line++) {
        if (spaceBelowFilled(line, pos.row)) {
            field[line][pos.row] = playerColor;
            cntFilledSlots++;   

            return 0;
        }
    }

    return 1; // Something went wrong
}

bool FourInARow::isVictory() const {
    unsigned cnt = 0;
    unsigned cnt2 = 0;
    
    // check diagonal rows
    cnt = 0;
    for (unsigned initRow = 0; initRow < (maxLines - 3); initRow++)  // initRow is the row at which we start comparing
    {
        cnt = 0;
        cnt2 = 0;
        for (unsigned line = 0, row = initRow; line < maxLines && row < maxRows; line++, row++)
        {
            // checking the diagonal from upper left to bottom right
            if (field[line][row] != playerColor) { // if the streak gets interrupted by a different color or emptyness
                cnt = 0;
            }
            else { // else if current sector is the players color 
                cnt++;
            }

            // checking the diagonal from upper right to bottom left
            if (field[line][maxRows - 1 - row] != playerColor) {    
                cnt2 = 0; 
            } 
            else {
                cnt2++;
            }

            if (cnt >= 4 || cnt2 >= 4) {
                return true;
            } 
        }
    }

    // check vertical rows
    cnt = 0;
    for (unsigned row = 0; row < maxRows; row++)
    {   
        cnt = 0;
        for (unsigned line = 0; line < maxLines; line++)
        {
            if (field[line][row] != playerColor) { // if the streak gets interrupted by a different color or emptyness
                cnt = 0;
                continue;
            }
            // else if current sector is the players color 
            cnt++;
            if (cnt >= 4)
                return true;
        }
    }

    // check horizontal rows
    cnt = 0;
    for (unsigned line = 0; line < maxLines; line++)
    {
        cnt = 0;
        for (unsigned row = 0; row < maxRows; row++)
        {
            if (field[line][row] != playerColor) { // if the streak gets interrupted by a different color or emptyness
                cnt = 0;
                continue;
            }
            // else if current sector is the players color 
            cnt++;
            if (cnt >= 4)
                return true;
        }
    }
    
    return false;
}

void FourInARow::changePlayer() {
    if (playerColor == 'y')
        playerColor = 'r';
    else 
        playerColor = 'y';
}

bool FourInARow::isFilled() const {
    if (cntFilledSlots >= (maxLines * maxRows))
        return true;

    return false;
}

int FourInARow::setCntFilledSlots(const unsigned newCnt) {
    cntFilledSlots = newCnt;

    return 0;
}

unsigned FourInARow::getCntFilledSlots() const {
    return cntFilledSlots;
}

