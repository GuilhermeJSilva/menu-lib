//
// Created by guilherme on 15-04-2018.
//

#include "Menu.h"

Menu::Menu(std::string n) : Menu_Option(n) {}

Menu::~Menu(){
    for(Menu_Option* mo : this->options) {
        delete(mo);
    }
}


int Menu::add_sub_menu(Menu sub_menu, size_t index = options.size()) {
    Menu_Option *new_mo = new Menu(sub_menu);
    if (new_mo == NULL) {
        return -1;
    }
    this->options.insert(this->options.begin() + index, new_mo);
    return (int) index;
}

void Menu::remove_menu_option(size_t index) {
    if(index >= options.size()) {
        return;
    }

    options.erase(options.begin() + index);
}

int Menu::add_menu_function(Menu_Fuction function, size_t index = options.size()) {
    Menu_Option *new_mo = new Menu_Fuction(function);
    if (new_mo == NULL) {
        return -1;
    }
    this->options.insert(this->options.begin() + index, new_mo);
    return (int) index;
}