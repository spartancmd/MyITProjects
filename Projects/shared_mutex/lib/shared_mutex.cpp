#include "shared_mutex.hpp"

Shared_mutex::Shared_mutex() 
{}

Shared_mutex::~Shared_mutex() 
{}

void Shared_mutex::lock() {
    // wait untill there're no readers and writer (with CAS)
    uint64_t target = 0;
    uint64_t desired = 1ull << 63;

    do {
        target = 0;
    } while (!status.compare_exchange_strong(target, desired));
}

void Shared_mutex::unlock() {
    status -= 1ull << 63;
}

void Shared_mutex::lock_shared() {
    // wait until there's no writer
    uint64_t target = 0;

    do {
        // getting readers
        target = ~(1 << 63) & status;
    } while (!status.compare_exchange_strong(target, target + 1));
}

void Shared_mutex::unlock_shared() {
    status--;
}