#include <iostream>
#include <cassert>
#include "Bank.hpp"

void testBank() {
    std::cout << "# *** Start testCases *** #" << std::endl;
    Bank bank;

    assert(bank.getAmount(0) == 2500);
    assert(bank.getAmount(1) == 1000);
    assert(bank.getAmount(2) == 200);
    assert(bank.totalAmount() == (2500 + 1000 + 200));
    
    std::cout << "# *** End testCases *** #" << std::endl;
}

int main() {
    testBank();

    

    return 0;
}