#pragma once

struct Row {
    unsigned row = 0;
    unsigned maxIdx = 0;

    Row(unsigned maxIdx_) 
    : maxIdx{maxIdx_}
    {}

    Row(unsigned row_, unsigned maxIdx_) 
    : row{row_}, maxIdx{maxIdx_}
    {}

    Row operator++(int) { // i++
        if ((row + 1) > maxIdx) {
            row = 0;
            return *this;
        }

        Row copy = *this;
        row += 1;

        return copy;
    }

    Row& operator++() {    // ++i
        if ((row + 1) > maxIdx) {
            row = 0;
            return *this;
        }

        row += 1;

        return *this;
    }

    Row operator--(int) { // i--
        if (row == 0) {
            row = maxIdx;
            return *this;
        }

        Row copy = *this;
        row -= 1;

        return copy;
    }

    Row& operator--() {    // --i
        if (row == 0) {
            row = maxIdx;
            return *this;
        }

        row -= 1;

        return *this;
    }

    operator int() {
        return row;
    }

    // operator unsigned int() {
    //     return row;
    // }
};
