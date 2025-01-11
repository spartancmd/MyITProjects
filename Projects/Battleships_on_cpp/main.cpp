#include <iostream>
#include <cstdlib>
#include "Battleships.hpp"
#include "ConsoleOp.hpp"

int main() {
    Battleships game(false); // if true then the second player is a bot



    // the main part
    while (true) {
        game.placeShips(); // the stage where the ships get placed
        game.battle();  // the stage where the players fight agains each other
    }

    return 0;
}