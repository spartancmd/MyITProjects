#include "shared_mutex.hpp"

inline long Shared_mutex::get_readers() {
    // if left bit is 1
    if (status >= (1 << 64)) 
        return status - (1 << 64);
    return status;
}

Shared_mutex::Shared_mutex() 
{}

Shared_mutex::~Shared_mutex() 
{}

void Shared_mutex::lock() {
    // wait untill there're no readers and writer (with CAS)
    long target = 0;
    long desired = 1 << 64;

    do {
        target = 0;
    } while (!status.compare_exchange_strong(target, desired));
}

void Shared_mutex::unlock() {
    // if there's a writer
    if (status >= (1 << 64)){
        status -= 1 << 64;
    }
}

void Shared_mutex::lock_shared() {
    // wait until there's no writer
    long target = 0;

    do {
        target = get_readers();
    } while (!status.compare_exchange_strong(target, target + 1));
}

void Shared_mutex::unlock_shared() {
    // if there's at least one reader
    if (status > 0) {
        status--;
    }
}