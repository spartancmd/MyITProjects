#pragma once
#include "Row.hpp"
#include <array>

struct Position {
    Row line;
    Row row;

    Position(const size_t maxLines, const size_t maxRows) 
    : line{0, maxLines - 1}, row{0, maxRows - 1}
    {}

    Position(const size_t maxLines, const size_t maxRows, std::array<size_t, 2> initCords) // inizialization for pos with defined coordinates
    : line{initCords[0], maxLines - 1}, row{initCords[1], maxRows - 1}
    {}

};