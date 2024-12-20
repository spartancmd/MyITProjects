#pragma once

#include <iostream>
#include "Position.hpp"
#include <conio.h>

#define MAX_ROW 3
#define MAX_LINE 3

class TicTacToe {
    char field_[MAX_LINE][MAX_ROW];
    Position pos;

    void rangePos(); // for the case if the choosen field is out of the actual field
    void processArrow(char); // decides how to change current position depending on the pressed arrow
public:
    // ****** DECLARATIONS OF METHODS ******

    TicTacToe(); // contructor

    void emptyField();   // fills each section of the field with a space
    void outputField(); // outputs the field as a table on the console (with coordinates)
    void chooseField(const char); // gives the user ability to choose the field by arrows and after pressing ENTER -> return the coordination
    bool operateOnField(char&); // exchanges the elm on current coordination, automaticly changes the symbol of the player (to set only if the current section was empty) 
                                // & checks if the current player won
    bool checkVictory(const char); // Checks if there is a row or a diagonal and return a bool
    
    // *** Decl. end
};

// ****** DEFINITIONS OF METHODS ****** //

TicTacToe::TicTacToe() {
    emptyField();
}

void TicTacToe::emptyField() {
    for (unsigned line = 0; line < MAX_LINE; line++) {
        for (unsigned row = 0; row < MAX_ROW; row++) {
            field_[line][row] = ' ';   
        }
    }
}

void TicTacToe::outputField() {
    std::cout << "-------" << std::endl;
    for (unsigned line = 0; line < MAX_LINE; line++) {
        std::cout << '|';
        for (unsigned row = 0; row < MAX_ROW; row++) {
            if (row == pos.row_ && line == pos.line_)
                std::cout << "\e[30;47m";
            std::cout << field_[line][row];
            std::cout << "\e[0m";
            std::cout << '|';
        }
        std::cout << std::endl;
    }    
    std::cout << "-------" << std::endl;    
}

void TicTacToe::rangePos() {
    if (pos.line_ >= MAX_LINE)
        pos.line_ = 0;
    else if (pos.line_ < 0)
        pos.line_ = MAX_LINE - 1;

    if (pos.row_ >= MAX_ROW)
        pos.row_ = 0;
    else if (pos.row_ < 0)
        pos.row_ = MAX_ROW - 1;
}

void TicTacToe::processArrow(char arrow) {
    switch(arrow) {
        case 72: // arrow - up
            pos.line_--;
            break;
        case 77: // arrow - right
            pos.row_++;
            break;
        case 80: // arrow - down
            pos.line_++;
            break;
        case 75: // arrow - left
            pos.row_--;
            break;
    }

    TicTacToe::rangePos();
}

void TicTacToe::chooseField(const char sym) {
    Position pos;
    char opt1 = 0;
    char opt2 = 0;

    do {
        std::cout << "\033[2J\033[1;1H"; // clear the console
        std::cout << "Use arrows to switch the field;\tTo continue press SPACE;\tTo leave press \"q\"" << std::endl;
        std::cout << "For the " << sym << ". player" << std::endl;
        TicTacToe::outputField();
        opt1 = _getch();
        
        // if wants to leave
        if (opt1 == 'q') { 
            exit(0);
        }
        // if the pressed key is an arrow
        if (opt1 == -32) {
            opt2 = _getch(); 
            TicTacToe::processArrow(opt2);
        }
    } while (opt1 != 32); // while opt1 is not SPACE
}

bool TicTacToe::operateOnField(char& sym) {
    if (field_[pos.line_][pos.row_] != ' ') // If the section isn't empty (so it repeats the choosing process)
        return false;
    
    field_[pos.line_][pos.row_] = sym;
    
    if (TicTacToe::checkVictory(sym)) {
        std::cout << "\033[2J\033[1;1H"; // clear the console
        TicTacToe::outputField();

        return true;
    }

    if (sym == 'X')
        sym = 'O';
    else 
        sym = 'X';

    return false;
}

bool TicTacToe::checkVictory(const char curSym) {
    unsigned cnt = 0;

    // check horizontal rows
    for (unsigned line = 0; line < MAX_LINE; line++) {
        cnt = 0;

        for (unsigned row = 0; row < MAX_ROW; row++) {
            if (field_[line][row] == curSym)
                cnt++;
        }
        if (cnt == MAX_ROW)
            return true;
    }    

    // check vertical rows
    for (unsigned row = 0; row < MAX_ROW; row++) {
        cnt = 0;

        for (unsigned line = 0; line < MAX_LINE; line++) {
            if (field_[line][row] == curSym)
                cnt++;
        }
        if (cnt == MAX_LINE)
            return true;
    }

    // manually checking diagonal rows ¯\_(ツ)_/¯

    if (field_[0][0] == curSym && field_[1][1] == curSym && field_[2][2] == curSym)
        return true;
    if (field_[0][2] == curSym && field_[1][1] == curSym && field_[2][0] == curSym)
        return true;

    return false;
}
// Def. end