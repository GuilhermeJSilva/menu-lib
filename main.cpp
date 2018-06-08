#include <iostream>
#include <string>
#include "Menu.hpp"
#include "ReadFunctions.hpp"

int func(int *p, int menu_call) {
    std::string str = read_string("String: ");
    std::cout << "Function #1 with string " << str << " and a global variable of " <<  *p << std::endl;
    return menu_call;
}

int func2(int *p, int menu_call) {
    auto num = read_value<int>("Int: ", "Error try again", [](int i){ return i < 0 ;});
    std::cout << "Function #2 with number " << num << " and a global variable of " <<  *p << std::endl;
    return menu_call - 1;
}

int main() {
    auto *test = new int;
    *test = 2;
    Menu<int> menu("Test menu", test);
    Menu<int> *menu1 =  new Menu<int>("Test menu #1", test);
    menu.add_sub_menu(menu1);
    menu1->add_menu_function(new Menu_Function<int>("Test function #2", func2));

    Menu<int> *menu2 =  new Menu<int>("Test menu #2", test);
    menu1->add_sub_menu(menu2);
    menu2->add_menu_function(new Menu_Function<int>("Test function #1", func));


    menu.menu_loop();
    delete test;
    return 0;
}