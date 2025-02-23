#include "Bank.hpp"

Bank::Bank()
: account{{2500},{1000},{200}}
{}

// = количество денег на счету с индексом index
int Bank::getAmount(int index) {
    std::unique_lock lock{account[index].locker};

    return account[index].balance;
}

// = общее количество денег в банке
int Bank::totalAmount() {
    int sum = 0;
    
    for (int i = 0; i < accountCnt; i++) {
        account[i].locker.lock();
    }

    for (unsigned i = 0; i < accountCnt; i++) {
        sum += account[i].balance;
    }

    for (int i = 0; i < accountCnt; i++) {
        account[i].locker.unlock();
    }

    return sum;
}

// = положить на счёт деньги
// returns how much money was added
int Bank::deposit(int index, int amount) {
    std::unique_lock lock{account[index].locker};

    account[index].balance += amount;
    return amount;
}

// - снять со счёта деньги
// return how much money was taken
int Bank::withdraw(int index, int amount) {
    std::unique_lock lock{account[index].locker};

    account[index].balance -= amount;
    return amount;
}

// - перевести деньги со счёта на счёт
// return how much money transfered
int Bank::transfer(int toIndex, int fromIndex, int amount) {
    // to avoid dead lock, organizing a hyrarchie by going from smallest to greatest index
    if (fromIndex < toIndex) {
        std::unique_lock lock1{account[fromIndex].locker};
        std::unique_lock lock2{account[toIndex].locker};
    }
    else {
        std::unique_lock lock1{account[toIndex].locker};
        std::unique_lock lock2{account[fromIndex].locker};
    }

    account[fromIndex].balance -= amount;
    account[toIndex].balance += amount;

    return amount;
}
