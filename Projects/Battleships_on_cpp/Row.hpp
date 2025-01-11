#pragma once

struct Row {
    size_t row = 0;
    size_t maxIdx = 0;

    Row(size_t maxIdx_) 
    : maxIdx{maxIdx_}
    {}

    Row(size_t row_, size_t maxIdx_) 
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
        return static_cast<int>(row);
    }

    // operator size_t() {
    //     return static_cast<size_t>(row);
    // }

    // bool operator>(const int b) {
    //     return row > b;
    // }

    // bool operator<(const int b) {
    //     return row < b;
    // }
};



// int&& operator+(const Row& a, const int b) {
//     return a.row + b;
// }

// int&& operator+(const int a, const Row& b) {
//     return a + b.row;
// }