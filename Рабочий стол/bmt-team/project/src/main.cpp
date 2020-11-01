#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "main.h"

int main(int argc, const char** argv) {
    if (argc == 0) {
        return -1;
    }
    const char *mapa = argv[2]

    Game_interface game;
    Map map;
    Main_hero main_hero(100, 1);
    std::ifstream fin(mapa);
    map.set_dimensions(fin);
    // std::cout << map.get_dimensions()[0] << ' ' << map.get_dimensions()[1] << std::endl;
    std::vector<Enemy> enemy = game.set_enemy_data(fin);
    // main_hero.set_coordinates({4, 2});
    for (size_t i = 0; i < enemy.size(); ++i) {
        game.set_enemy_health_points(enemy[i]);
        game.set_enemy_damage_points(enemy[i]);
    }
    while (true) {
        try {
            game.change_main_hero_position(main_hero, map);
        }
        catch (int n) {
            if (n == -1) {
                std::cout << main_hero.get_coordinates()[0] << " x " << main_hero.get_coordinates()[1];
                std::cout << ", hp: " << main_hero.get_health_points() << " > " << std::endl;
            }
            return 0;
        }
        for (size_t i = 0; i < enemy.size(); ++i) {
            if (main_hero.get_coordinates() == enemy[i].get_coordinates()) {
                game.fight(main_hero, enemy[i]);
            }
        }
        if (main_hero.get_health_points() <= 0) {
            break;
        }
    }
    return 0;
}
