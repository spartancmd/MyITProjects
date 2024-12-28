// TicTacToe

// Programmed by Deniel.

#include <iostream>
#include <conio.h>
#include "TicTacToe.hpp"

int main()
{
    TicTacToe game;
    char curSym = 'X';

    while (true) {
        game.chooseField(curSym);

        if (game.operateOnField(curSym)) {
            char choice = 0;
            std::cout << curSym << ". player has won!" << std::endl << std::endl;
            std::cout << "Do you want to start a new game? [y/n]... ";
            choice = _getch();

            if (choice != 'y') {
                break;
            }
            
            game.emptyField();
        }
    }
    
    return 0; 
}