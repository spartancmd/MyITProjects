#pragma once

#include <iostream>
#include "Position.hpp"
#include "Ship.hpp"
#include <vector>
#include <array>

const size_t MAXLINES = 10;
const size_t MAXROWS = MAXLINES;

class Battleships {
private: // *** private variables *** //
    // creating fields for players
    std::array<std::array<char, MAXROWS>, MAXLINES> field1 = {};
    Position posF1{MAXLINES, MAXROWS, {5, 5}};
    std::array<std::array<char, MAXROWS>, MAXLINES> field2 = {};
    Position posF2{MAXLINES, MAXROWS, {5, 5}};

    const bool botActive = false;
    const std::vector<Ship> ships = {Ship{5, "Carrier"}, Ship{4, "Battleship"}, Ship{3, "Cruiser"}, Ship{3, "Submarine"}, Ship{2, "Destroyer"}};
    char curPlayer; // possible players: blue, (red if no AI)

public: // *** public variables *** //

private: // *** private Methods def. *** //

    void fillField(std::array<std::array<char, MAXROWS>, MAXLINES>& field, char sym);
    
    // * output part * // 
    void outputColumn(size_t lenght, bool withLetters);

    void outputFieldHiddenShips(std::array<std::array<char, MAXROWS>, MAXLINES>& field);  // needed at stage: battle

    void outputField(std::array<std::array<char, MAXROWS>, MAXLINES>& field); // needed at stage: placeShips

    // * field editing * //
    int putShipByPosForOutput(std::array<std::array<char, MAXROWS>, MAXLINES>& field, Position pos, size_t shipIdx, const char shipDirection); // colors the field to see where our current ship is for output 
    
    // * moving cursor * //
    bool changePosAllowed(const std::array<std::array<char, MAXROWS>, MAXLINES>& field, Position pos, size_t shipIdx, const char shipDirection);

    void changePos(std::array<std::array<char, MAXROWS>, MAXLINES>& field, Position& pos, const char arrow, const char shipDirection, const size_t curShipIdx); // moves the cursor if allowed

    // * changing ships position * //
    bool changeShipsDirectionAllowed(const std::array<std::array<char, MAXROWS>, MAXLINES>& field, Position pos, char shipDirection, const size_t curShipIdx);
    
    void changeShipsDirection(const std::array<std::array<char, MAXROWS>, MAXLINES>& field, const Position& pos, char& shipDirection, const size_t curShipIdx);
    
    bool shipInTheWay(const std::array<std::array<char, MAXROWS>, MAXLINES>& field, Position pos, const char shipDirection, const size_t curShipIdx);

    int placeShipsOnField(std::array<std::array<char, MAXROWS>, MAXLINES>& field, const std::vector<Ship>& ships);

    

    

public: // *** public Methods def. *** ///

    explicit Battleships(bool aiActive_);

    void restart(); // fills the fields and the current player as in the begining 

    int switchPlayer(); // return 0 if success, 1 if bot activated. If differenent number then smth went wrong

    int placeShips();

    int battle();

    bool isVictory() const;


// * get Methods  * //

    inline bool getBotActive() const { return botActive; }

    inline auto getFields() const { return std::vector{field1, field2}; }

    inline const std::vector<Ship>& getShips() const { return ships; }

    inline char getCurPlayer() const { return curPlayer; }
};