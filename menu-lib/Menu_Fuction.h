//
// Created by guilherme on 15-04-2018.
//

#ifndef MENU_LIB_MENU_FUCTION_H
#define MENU_LIB_MENU_FUCTION_H


#include <functional>
#include "Menu_Option.h"

class Menu_Fuction: public Menu_Option {
private:
    /**
     * Stores the lambda expression.
     */
    std::function<int()> func;
public:

    /**
     * Builds a new menu function.
     * @param name Name of the option.
     * @param func
     */
    Menu_Fuction(const std::string &name, const std::function<int()> &func);

};


#endif //MENU_LIB_MENU_FUCTION_H
