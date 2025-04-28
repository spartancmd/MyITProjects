#pragma once

#include "Row.hpp"

struct Position {
    Row row;

    Position(const unsigned maxRow) 
    : row{maxRow - 1}    // giving them the max possible idx
    {}
};