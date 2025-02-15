#pragma once

#include "Account.hpp"

const int accountCnt = 3;

class Bank {
    
    Account account[accountCnt];    
public:

    Bank();

    int getAmount(int index); // = количество денег на счету с индексом index

    int totalAmount(); // = общее количество денег в банке

    int deposit(int index, int amount); // = положить на счёт деньги

    int withdraw(int index, int amount); // - снять со счёта деньги

    int transfer(int toIndex, int fromIndex, int amount); // - перевести деньги со счёта на счёт

};