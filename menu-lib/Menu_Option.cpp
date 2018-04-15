//
// Created by guilherme on 15-04-2018.
//

#include "Menu_Option.h"

Menu_Option::Menu_Option(const std::string &name) : name(name) {}

const std::string &Menu_Option::getName() const {
    return name;
}

void Menu_Option::setName(const std::string &name) {
    Menu_Option::name = name;
}
