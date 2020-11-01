//
// Created by sergey on 31.10.2020.
//
#include <iostream>
#include <cstddef>
#include <vector>
#include "main.h"

void Map::set_dimensions(std::istream& is) {
    ptrdiff_t rows = 0;
    ptrdiff_t cols = 0;
    is >> rows >> cols;
    std::vector<ptrdiff_t> coordinate;
    coordinate.push_back(rows);
    coordinate.push_back(cols);
    this->coordinates = coordinate;
}

std::vector<ptrdiff_t> Map::get_dimensions() {
    return this->coordinates;
}

