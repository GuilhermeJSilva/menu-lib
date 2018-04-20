//
// Created by guilherme on 15-04-2018.
//

#ifndef MENU_LIB_MENU_FUCTION_H
#define MENU_LIB_MENU_FUCTION_H


#include <functional>
#include "Menu_Option.h"

template<class T>
class Menu_Function : public Menu_Option<T> {
private:
    /**
     * Stores a function that receives a pointer with the menu's main class
     * and returns an int that corresponds to the level of menu to return to.
     */
    int (*func)(T *);

public:

    /**
     * Builds a new menu function.
     * @param name Name of the option.
     * @param func
     */
    Menu_Function(std::string n, int (*pFunction)(T *)) : Menu_Option<T>(n), func(pFunction) {}

    /**
     * Runs the function.
     * @param mc Menu's structure.
     * @return 0 if it stays in the same menu, other value returns to the main menu.
     */
    int run(T *mc) {
        return func(mc);
    }

};


#endif //MENU_LIB_MENU_FUCTION_H
