#pragma once 

#include <mutex>

class Account {
    int balance = 0;
    std::mutex locker;

public:
    Account() 
    {}

    Account(int balance_)
    : balance{balance_}
    {}

    int showBalance() const {
        return balance;
    }

    // return the added balance
    int addToBalance(int amountOfMoney) {
        std::lock_guard<std::mutex> lg(locker);
        balance += amountOfMoney;

        return amountOfMoney;
    }

    // returns the taken balance
    int takeMoney(int amountOfMoney) {
        std::lock_guard<std::mutex> lg(locker);
        int moneyToTake = amountOfMoney;

        // if amount of taken money is greater than the balance, take as much as possible
        if (amountOfMoney > balance) {
            moneyToTake = amountOfMoney - (amountOfMoney - balance);
        }

        balance -= moneyToTake;

        return moneyToTake;
    }
};