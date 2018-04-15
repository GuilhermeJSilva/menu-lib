//
// Created by guilherme on 15-04-2018.
//

#include "Menu_Fuction.h"


Menu_Fuction::Menu_Fuction(const std::string &name, const std::function<int()> &func) : Menu_Option(name), func(func) {}
