#pragma once

struct Position {
    short line_;
    short row_;

    Position(short line, short row)
    : line_{line}, row_{row}
    {}

    Position()
    : line_{0}, row_{0}
    {}
};