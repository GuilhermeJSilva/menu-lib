//
// Created by GuilhermeJSilva on 15-04-2018.
//

#ifndef MENU_LIB_MENU_H
#define MENU_LIB_MENU_H


#include <vector>
#include <ostream>
#include <cstddef>
#include <limits>
#include <iostream>
#include <stddef.h>

#include "Menu_Option.hpp"
#include "Menu_Function.hpp"

template<class T>
class Menu : public Menu_Option<T> {
private:
    /**
     * Contains all active sub menus.
     */
    std::vector<Menu<T> *> sub_menus;

    /**
     * Contains all function calls.
     */
    std::vector<Menu_Function<T> *> functions;

    /**
     * Class to mange.
     */
    T *main_class;

    /**
     * True if this is the main menu.
     */
    int level_of_menu;
public:

    /**
     * Creates a new menu with a given name.
     * @param n Name of the menu.
     */
    explicit Menu(std::string n, T *mc) : Menu_Option<T>(n), main_class(mc), level_of_menu(0) {}


    /**
     * Destructor of the menu, deletes all options.
     */
    ~Menu() {
        for (Menu<T> *mo : this->sub_menus) {
            delete (mo);
        }

        for (Menu_Function<T> *mo : this->functions) {
            delete (mo);
        }
    }

    /**
     * Adds a new sub menu.
     * @param sub_menu  Sub menu to add.
     * @return Option number of the new sub menu, -1 if it there is an error.
     */
    int add_sub_menu(Menu<T> *sub_menu, int index = -1) {
        if (sub_menu == NULL) {
            return -1;
        }
        if (index < 0) {
            index = (int) sub_menus.size();
        }
        this->sub_menus.insert(this->sub_menus.begin() + index, sub_menu);
        sub_menu->level_of_menu = this->level_of_menu + 1;
        sub_menu->update_levels();
        return index;
    }

    /**
     * Updates of all sub menu's level numbers.
     */
    void update_levels(){
        for(Menu<T>* m : sub_menus) {
            m->level_of_menu = this->level_of_menu + 1;
            m->main_class = this->main_class;
            m->update_levels();
        }
    }

    /**
     * Removes an option from a menu.
     * @param index Index of the option to be removed.
     */
    void remove_menu_option(size_t index) {
        if (index > sub_menus.size() - 1 + functions.size() || index < 0) {
            return;
        }
        if (index < sub_menus.size())
            sub_menus.erase(sub_menus.begin() + index);
        else
            functions.erase(functions.begin() + index - sub_menus.size());
    }

    /**
     * Adds a menu function to the Menu.
     * @param fuction Function to add.
     * @return Option number of the new
     */
    int add_menu_function(Menu_Function<T> *function, int index = -1) {
        if (function == NULL) {
            return -1;
        }
        if (index < 0) {
            index = (int) functions.size();
        }
        this->functions.insert(this->functions.begin() + index, function);
        return index;
    }


    /**
     * Main menu loop, call to pick an option from the loop.
     */
    int menu_loop() {
        int option;
        int ret;
        do {
            print();
            option = getInt();
            ret = pick_option(option - 1);
        } while ((option > 0 && option < functions.size() + sub_menus.size()) || (ret == this->level_of_menu));
    }

    /**
     * Prints the menu to the standard output.
     */
    void print() {
        std::cout << std::endl << this->name << std::endl;
        int i;
        for (i = 1; i <= sub_menus.size(); ++i) {
            if (i - 1 < sub_menus.size())
                std::cout << i << ": " << sub_menus.at(i - 1)->getName() << std::endl;

        }

        for (int j = 0; j < functions.size(); ++j, i++) {
            std::cout << i << ": " << functions.at(j)->getName() << std::endl;
        }
        if (level_of_menu == 0)
            std::cout << i << ": " << "Exit" << std::endl;
        else
            std::cout << i << ": " << "Back" << std::endl;
    }

protected:
    /**
     * Runs the respective code for a given option.
     * @param option Option to run.
     * @return 0 if the option exists, -1 otherwise.
     */
    int pick_option(int option) {
        unsigned long max = sub_menus.size() + functions.size() - 1;
        if (option < 0 || option > max)
            return -1;
        if (option < sub_menus.size())
            return this->sub_menus.at(option)->menu_loop();
        else
            return functions.at(option - sub_menus.size())->run(main_class);

    }

    /**
     * Gets an int in the range [1, options.size() + 1].
     * @return Read value.
     */
    int getInt() {
        int read_value;
        do {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin >> read_value;
            std::cin.ignore();
        } while (std::cin.fail() || !(read_value > 0 && read_value <= sub_menus.size() + 1 + functions.size()));
        return read_value;

    }
};


#endif //MENU_LIB_MENU_H
