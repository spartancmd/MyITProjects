#include "Bank.hpp"

Bank::Bank()
: account{{2500},{1000},{200}}
{}

// = количество денег на счету с индексом index
int Bank::getAmount(int index) {
    return account[index].showBalance();
}

// = общее количество денег в банке
int Bank::totalAmount() {
    int sum = 0;

    for (unsigned i = 0; i < accountCnt; i++) {
        sum += account[i].showBalance();
    }

    return sum;
}

// = положить на счёт деньги
// returns how much money was added
int Bank::deposit(int index, int amount) {
    int addedMoney = account[index].addToBalance(amount);
    return addedMoney;
}

// - снять со счёта деньги
// return how much money was taken
int Bank::withdraw(int index, int amount) {
    int takenMoney = account[index].takeMoney(amount);
    return takenMoney;
}

// - перевести деньги со счёта на счёт
// return how much money transfered
int Bank::transfer(int toIndex, int fromIndex, int amount) {
    int takenMoney = account[fromIndex].takeMoney(amount);
    account[toIndex].addToBalance(takenMoney);

    return takenMoney;
}
