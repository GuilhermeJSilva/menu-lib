//
// Created by guilherme on 15-04-2018.
//

#ifndef MENU_LIB_MENU_H
#define MENU_LIB_MENU_H


#include <vector>
#include <ostream>

#include "Menu_Option.h"
#include "Menu_Fuction.h"

class Menu: public Menu_Option {
private:
    /**
     * Contains all active options.
     */
    std::vector<Menu_Option*> options;

public:

    /**
     * Creates a new menu with a given name.
     * @param n Name of the menu.
     */
    explicit Menu(std::string n);

    /**
     * Destructor of the menu, deletes all options.
     */
    explicit ~Menu();

    /**
     * Adds a new sub menu.
     * @param sub_menu  Sub menu to add.
     * @return Option number of the new sub menu, -1 if it there is an error.
     */
    int add_sub_menu(Menu sub_menu, size_t index = options.size());

    /**
     * Removes an option from a menu.
     * @param index Index of the option to be removed.
     */
    void remove_menu_option(size_t index);

    /**
     * Adds a menu function to the Menu.
     * @param fuction Function to add.
     * @return Option number of the new
     */
    int add_menu_function(Menu_Fuction function, size_t index = options.size());
};


#endif //MENU_LIB_MENU_H
