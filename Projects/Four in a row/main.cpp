#include <iostream>
#include <windows.h>
#include "FourInARow.hpp"
#include "ConsoleDecorations.hpp"

void greeting(const unsigned durationMs) {
    std::cout << ConsoleDecorations::setFontColor('y') << "\t\tGame: Four In A Row " << std::endl;
    std::cout << ConsoleDecorations::setFontColor('g') << "\t\tProgrammed by Deniel on C++" << ConsoleDecorations::resetColor() << std::endl;
    std::cout << "\t\tPlease wait..." << std::endl;
    Sleep(durationMs);
}

int main() {
    FourInARow game{'y'}; // initializing the game with the yellow player

    greeting(5000);

    // where the game runs
    while (true) {  
        game.choosePosition();
        if (game.operateOnField()) { // if something goes wrong
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

        if (game.isFilled()) {
            char input = 0;

            std::cout << ConsoleDecorations::clearConsole();
            game.outputField();
            std::cout << ConsoleDecorations::setFontColor('r');
            std::cout << "\t\tGame over" << std::endl;
            std::cout << "The field is filled. Nobody won."  << std::endl;
            std::cout << ConsoleDecorations::setFontColor(0) << std::endl;
            

            std::cout << "Do you want to play again? [y/n]" << std::endl;
            std::cin >> input;

            if (input == 'y')  {
                game.fillField(' ');
                game.setCntFilledSlots(0);
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