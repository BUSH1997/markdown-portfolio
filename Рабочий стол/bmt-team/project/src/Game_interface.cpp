//
// Created by sergey on 31.10.2020.
//
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>
#include "main.h"
void Game_interface::change_main_hero_position(Main_hero& main_hero, Map& map) {
    std::vector<std::string> proper_actions;
    std::cout << "Supported actions:" << std::endl;
    if (main_hero.get_coordinates()[0] > 0) {
        std::cout << " * move left" << std::endl;
        proper_actions.push_back("move left");
    }
    if (main_hero.get_coordinates()[0] < map.get_dimensions()[0] - 1) {
        std::cout << " * move right" << std::endl;
        proper_actions.push_back("move right");
    }
    if (main_hero.get_coordinates()[1] > 0) {
        std::cout << " * move down" << std::endl;
        proper_actions.push_back("move down");
    }
    if (main_hero.get_coordinates()[1] < map.get_dimensions()[1] - 1) {
        std::cout << " * move up" << std::endl;
        proper_actions.push_back("move up");
    }
    proper_actions.push_back("improper action");
    std::string action;
    std::getline(std::cin, action);
    if (action == "") {
        throw -1;
    }
    while (std::find(proper_actions.begin(), proper_actions.end(), action) == proper_actions.end()) {
        std::getline(std::cin, action);
    }
    if (action == "move left") {
        main_hero.set_coordinates({main_hero.get_coordinates()[0] - 1, main_hero.get_coordinates()[1]});
    }
    if (action == "move right") {
        main_hero.set_coordinates({main_hero.get_coordinates()[0] + 1, main_hero.get_coordinates()[1]});
    }
    if (action == "move down") {
        main_hero.set_coordinates({main_hero.get_coordinates()[0], main_hero.get_coordinates()[1] - 1});
    }
    if (action == "move up") {
        main_hero.set_coordinates({main_hero.get_coordinates()[0], main_hero.get_coordinates()[1] + 1});
    }
    std::cout << main_hero.get_coordinates()[0] << " x " << main_hero.get_coordinates()[1];
    std::cout << ", hp: " << main_hero.get_health_points() << " > " << std::endl;
    std::cout << "moved" << std::endl;
}

void Game_interface::fight(Main_hero& main_hero, Enemy& enemy) {
    if (enemy.get_health_points() > 0) {
        std::cout << enemy.get_name() << " found, " << enemy.get_health_points() << " hp" << std::endl;
    }
    while (main_hero.get_health_points() > 0 && enemy.get_health_points() > 0) {
        std::cout << "Supported actions:" << std::endl;
        std::cout << " * kick enemy" << std::endl;
        std::string action;
        std::getline(std::cin, action);
        while (action != "kick enemy") {
            std::getline(std::cin, action);
        }
        std::cout << main_hero.get_coordinates()[0] << " x " << main_hero.get_coordinates()[1];
        std::cout << ", hp: " << main_hero.get_health_points() << " > " << std::endl;
        enemy.set_health_points(enemy.get_health_points() - main_hero.get_damage());
        if (enemy.get_health_points() > 0) {
            main_hero.set_health_points(main_hero.get_health_points() - enemy.get_damage());
            if (main_hero.get_health_points() <= 0) {
                std::cout << "player died" << std::endl;
                break;
            } else {
                std::cout << "enemy kicked. Enemy hp: " << enemy.get_health_points() << std::endl;
            }
        } else {
            std::cout << "enemy killed" << std::endl;
            break;
        }
    }
}

std::vector<Enemy> Game_interface::set_enemy_data(std::istream& is) {
    std::vector < std::vector <ptrdiff_t> > map_data;
    std::vector <std::string> enemy_name;
    ptrdiff_t x;
    ptrdiff_t y;
    std::string name;
    while (is >> x >> y >> name) {
        std::vector<ptrdiff_t> data;
        data.push_back(x);
        data.push_back(y);
        map_data.push_back(data);
        enemy_name.push_back(name);
    }
    std::vector<Enemy> enemy(map_data.size());
    for (size_t i = 0; i < map_data.size(); ++i) {
        enemy[i].set_coordinates(map_data[i]);
        enemy[i].set_name(enemy_name[i]);
    }
    return enemy;
}
void Game_interface::set_enemy_health_points(Enemy& enemy) {
    if (enemy.get_name() == "dog") {
        enemy.set_health_points(3);
    } else if (enemy.get_name() == "wolf") {
        enemy.set_health_points(6);
    } else if (enemy.get_name() == "rat") {
        enemy.set_health_points(2);
    }
}

void Game_interface::set_enemy_damage_points(Enemy& enemy) {
    if (enemy.get_name() == "dog") {
        enemy.set_damage(5 + 1);
    } else if (enemy.get_name() == "wolf") {
        enemy.set_damage(10 + 1);
    } else if (enemy.get_name() == "rat") {
        enemy.set_damage(3 + 1);
    }
}
