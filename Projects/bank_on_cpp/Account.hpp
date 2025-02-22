#pragma once 

#include <mutex>

struct Account {
    int balance = 0;
    std::mutex locker;
};