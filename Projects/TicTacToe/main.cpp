// TicTacToe
//

#include <iostream>
#include "TicTacToe.hpp"


int main()
{
    TicTacToe game;
    char curSym = 'X';

    while (true) {
        std::cout << "Use arrows to switch the field;\tTo continue press SPACE;\tTo leave press \"q\"" << std::endl;
        game.chooseField(curSym);

        if (game.operateOnField(curSym)) {
            char choice = 0;
            std::cout << curSym << ". player has won!" << std::endl << std::endl;
            std::cout << "Do you want to start a new game? [y/n]... ";
            std::cin >> choice;

            if (choice != 'y') {
                return 0;
            }
            
            game.emptyField();
        }
    }
    
    return 0; 
}