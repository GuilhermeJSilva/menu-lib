//
// Created by GuilhermeJSilva on 15-04-2018.
//

#ifndef MENU_LIB_MENU_OPTION_H
#define MENU_LIB_MENU_OPTION_H

#include <string>

template<class T>
class Menu_Option {
protected:
    /**
     * Name to be displayed when printOption is called.
     */
    std::string name;

public:

    /**
    * Creates a Menu Option with a given name.
    * @param name Name of the menu option.
    */
    Menu_Option(std::string n) : name(n) {}

    /**
     * Returns the name of the option.
     * @return Name of the option.
     */
    const std::string &getName() const {
        return name;
    }

    /**
     * Changes the name of the Menu Option.
     * @param name New name for the menu option.
     */
    void setName(const std::string &name) {
        Menu_Option::name = name;
    }


};


#endif //MENU_LIB_MENU_OPTION_H
