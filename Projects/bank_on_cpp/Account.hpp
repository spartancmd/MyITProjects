#pragma once 

#include <shared_mutex>

struct Account {
    int balance = 0;
    std::shared_mutex locker;
};