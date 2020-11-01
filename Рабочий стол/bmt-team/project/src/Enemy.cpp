//
// Created by sergey on 31.10.2020.
//
#include <string>
#include <vector>
#include <cstddef>
#include "main.h"

Enemy::Enemy():
        health_points(0),
        damage(0) {}

Enemy::Enemy(ptrdiff_t health_points, ptrdiff_t damage):
        health_points(health_points),
        damage(damage) {}
std::string Enemy::get_name() {
    return name;
}
void Enemy::set_name(std::string name) {
    this->name = name;
}
ptrdiff_t Enemy::get_damage() {
    return damage;
}
void Enemy::set_damage(ptrdiff_t damage) {
    this->damage = damage;
}
ptrdiff_t Enemy::get_health_points() {
    return health_points;
}
void Enemy::set_health_points(ptrdiff_t health_points) {
    this->health_points = health_points;
}
std::vector<ptrdiff_t> Enemy::get_coordinates() {
    return coordinates;
}
void Enemy::set_coordinates(std::vector<ptrdiff_t> coordinates) {
    this->coordinates = coordinates;
}
