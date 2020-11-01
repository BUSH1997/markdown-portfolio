//
// Created by sergey on 31.10.2020.
//

#ifndef PROJECT_INCLUDE_GAME_INTERFACE_H_
#define PROJECT_INCLUDE_GAME_INTERFACE_H_

#include <vector>

class Game_interface {
 private:
 public:
    void change_main_hero_position(Main_hero& main_hero, Map& map);
    void fight(Main_hero& main_hero, Enemy& enemy);
    std::vector<Enemy> set_enemy_data(std::istream& is);
    void set_enemy_health_points(Enemy& enemy);
    void set_enemy_damage_points(Enemy& enemy);
};

#endif  // PROJECT_INCLUDE_GAME_INTERFACE_H_
