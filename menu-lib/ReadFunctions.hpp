//
// Created by GuilhermeJSilva on 26-04-2018.
//

#include <iostream>
#include <ostream>
#include <limits>

template <class T>
T read_value(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.", bool (*f)(T) = [](T i){return true;}) {
    T read_value;
    std::cout << prompt_message << std::endl;
    std::cin >> read_value;

    while (std::cin.fail() || !f(read_value)) {
        std::cout << error_message << std::endl;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << prompt_message << std::endl;
        std::cin >> read_value;
        std::cin.ignore();
    }
    return read_value;
}
