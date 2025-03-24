#pragma once

#include <atomic>

class Shared_mutex {
private:
    std::atomic<uint64_t> status = 0; // 64 bits. Left bit means if there is a writer. Other right bits the count of readers

public:
    Shared_mutex();
    ~Shared_mutex();

    void lock(); // for writer
    void unlock();
    void lock_shared(); // for readers
    void unlock_shared();

};