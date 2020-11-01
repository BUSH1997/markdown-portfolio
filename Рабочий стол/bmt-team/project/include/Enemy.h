//
// Created by sergey on 31.10.2020.
//

#ifndef PROJECT_INCLUDE_ENEMY_H_
#define PROJECT_INCLUDE_ENEMY_H_

#include <vector>
#include <string>

class Enemy {
 private:
    std::string name;
    ptrdiff_t health_points;
    ptrdiff_t damage;
    std::vector<ptrdiff_t> coordinates;

 public:
    Enemy();
    Enemy(ptrdiff_t health_points, ptrdiff_t damage);
    std::string get_name();
    void set_name(std::string name);
    ptrdiff_t get_damage();
    void set_damage(ptrdiff_t damage);
    ptrdiff_t get_health_points();
    void set_health_points(ptrdiff_t health_points);
    std::vector<ptrdiff_t> get_coordinates();
    void set_coordinates(std::vector<ptrdiff_t> coordinates);
};



#endif  // PROJECT_INCLUDE_ENEMY_H_
