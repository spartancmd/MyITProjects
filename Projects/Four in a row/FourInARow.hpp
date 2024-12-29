#pragma once

#include "Position.hpp"
#include <windows.h>


const unsigned maxLines = 6;
const unsigned maxRows = 7;

class FourInARow {
private: // ********* variables ********* //
    
    char field[maxLines][maxRows];
    Position pos{maxRows};

public:
    
    char playerColor = 'y';    // y - yellow; r - red 

private: // ********* METHODS decl. ********* //
    
    void switchPos(const char arrow);

    void outputColumn(const char color) const; // horizontal column

    void outputCursor(); 

    bool spaceBelowFilled(unsigned line, unsigned row);

    void outputLine(bool& fieldMarked, const unsigned line);

public:
    
    explicit FourInARow();

    explicit FourInARow(const char initPlayerColour);

    void fillField(const char sym);

    void outputField();
    
    void choosePosition(); // start of the game // allows the player to choose the field

    int operateOnField(); // operates on the field depending on the position // returns 0 if successful, else 1

    bool isVictory() const; // check if the current player won

    void changePlayer();
};