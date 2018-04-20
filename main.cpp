#include <iostream>
#include <string>
#include "Menu.h"


int func(int *p) {
    std::cout << "Function #1 with number " << *p << std::endl;
    return 0;
}

int func2(int *p) {
    std::cout << "Function #2 with number " << *p << std::endl;
    return 1;
}

int main() {
    int *test = new int;
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