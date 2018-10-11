//
// Created by GuilhermeJSilva on 15-04-2018.
//

#ifndef MENU_LIB_MENU_FUCTION_H
#define MENU_LIB_MENU_FUCTION_H


#include <functional>
#include "Menu_Option.hpp"

template<class T>
class Menu_Function : public Menu_Option<T> {
private:
    /**
     * Stores a function that receives a pointer with the menu's main class
     * and returns an int that corresponds to the level of menu to return to.
     */
    int (*func)(T *, int call_menu);

public:

    /**
     * Builds a new menu function.
     * @param name Name of the option.
     * @param func Function
     */
    Menu_Function(std::string n, int (*pFunction)(T *, int call_menu)) : Menu_Option<T>(n), func(pFunction) {}

    /**
     * Runs the function.
     * @param mc Menu's structure.
     * @param call_menu Level of the menu that called the function.
     * @return 0 if it stays in the same menu, other value returns to the main menu.
     */
    int run(T *mc, int call_menu) {
        return func(mc, call_menu);
    }

};


#endif //MENU_LIB_MENU_FUCTION_H
