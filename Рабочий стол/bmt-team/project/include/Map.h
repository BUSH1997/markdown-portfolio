//
// Created by sergey on 31.10.2020.
//

#ifndef PROJECT_INCLUDE_MAP_H_
#define PROJECT_INCLUDE_MAP_H_

#include <vector>

class Map {
 private:
    std::vector<ptrdiff_t> coordinates;
 public:
    std::vector<ptrdiff_t> get_dimensions();
    void set_dimensions(std::istream& is);
};

#endif  // PROJECT_INCLUDE_MAP_H_
