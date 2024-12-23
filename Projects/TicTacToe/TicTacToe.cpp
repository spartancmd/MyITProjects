#include "TicTacToe.hpp"
#include <iostream>
#include "Position.hpp"
#include <conio.h>

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

void TicTacToe::limitPosition() {
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

    TicTacToe::limitPosition();
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
    unsigned cnt2 = 0;

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

    // check diagonal rows
    // assume that MAX_ROW == MAX_LINE
    cnt = 0;
    cnt2 = 0;
    
    for (unsigned i = 0; i < MAX_ROW; i++) { 
        if (field_[i][i] == curSym)
            cnt++;
        if (field_[i][MAX_ROW - 1 - i] == curSym)
            cnt2++;
    }
    if ((cnt == MAX_ROW) || (cnt2 == MAX_ROW))
        return true;
    
    return false;
}
// Def. end