//
// Created by guilherme on 15-04-2018.
//

#ifndef MENU_LIB_MENU_OPTION_H
#define MENU_LIB_MENU_OPTION_H

#include <string>

class Menu_Option {
private:
    /**
     * Name to be displayed when printOption is called.
     */
    std::string name;

public:

    /**
     * Returns the name of the option.
     * @return Name of the option.
     */
    const std::string &getName() const;

    /**
     * Changes the name of the Menu Option.
     * @param name New name for the menu option.
     */
    void setName(const std::string &name);

    /**
     * Creates a Menu Option with a given name.
     * @param name Name of the menu option.
     */
    explicit Menu_Option(const std::string &name);
};


#endif //MENU_LIB_MENU_OPTION_H
