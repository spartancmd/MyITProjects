#pragma once

#include "Position.hpp"

const int MAX_ROW = 3;
const int MAX_LINE = MAX_ROW;

class TicTacToe {
    char field_[MAX_LINE][MAX_ROW];
    Position pos;

    void limitPosition(); // for the case if the choosen field is out of the actual field
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

