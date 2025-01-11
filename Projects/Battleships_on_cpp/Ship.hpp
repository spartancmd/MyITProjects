#pragma once

struct Ship {
    size_t size;
    std::string name;

    Ship(const size_t size_, const char* name_)
    : size{size_}, name{name_}
    {}
};