//
// Created by sergey on 31.10.2020.
//
#include <vector>
#include <cstddef>
#include "Main_hero.h"

Main_hero::Main_hero(ptrdiff_t health_points, ptrdiff_t damage):
        health_points(health_points),
        damage(damage),
        coordinates({0, 0}) {}

ptrdiff_t Main_hero::get_damage() {
    return damage;
}
void Main_hero::set_damage(ptrdiff_t damage) {
    this->damage = damage;
}
ptrdiff_t Main_hero::get_health_points() {
    return health_points;
}
void Main_hero::set_health_points(ptrdiff_t health_points) {
    this->health_points = health_points;
}
std::vector<ptrdiff_t> Main_hero::get_coordinates() {
    return coordinates;
}
void Main_hero::set_coordinates(std::vector<ptrdiff_t> coordinates) {
    this->coordinates = coordinates;
}
