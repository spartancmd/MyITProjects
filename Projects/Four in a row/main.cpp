#include <iostream>
#include "FourInARow.hpp"
#include "ConsoleDecorations.hpp"


int main() {
    FourInARow game{'y'};

    // where the game runs
    while (true) {  
        game.choosePosition();
        if (game.operateOnField()) {
            continue; // give another try
        }
        if (game.isVictory()) {
            char input = 0;
            std::cout << ConsoleDecorations::clearConsole();
            game.outputField(); // output the updated field
            std::cout << ConsoleDecorations::setFontColor(game.playerColor) << "Player won!" << ConsoleDecorations::setFontColor(0) << std::endl;
            std::cout << "Do you want to play again? [y/n]" << std::endl;
            std::cin >> input;

            if (input == 'y')  {
                game.fillField(' ');
                game.changePlayer();
                continue;
            }

            // else leave 
            return 0;    
        }
        game.changePlayer();
    }

    return 0;
}