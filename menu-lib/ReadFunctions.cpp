//
// Created by GuilhermeJSilva on 26-04-2018.
//

#include <iostream>
#include <ostream>
#include <limits>

int read_int(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.") {
    int read_value;
    do {
        if (std::cin.fail()) {
            std::cout << error_message << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << prompt_message << std::endl;
        std::cin >> read_value;
        std::cin.ignore();
    } while (std::cin.fail());
    return read_value;
}

double read_double(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.") {
    double read_value;
    do {
        if (std::cin.fail()) {
            std::cout << error_message << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << prompt_message << std::endl;
        std::cin >> read_value;
        std::cin.ignore();
    } while (std::cin.fail());
    return read_value;
}

std::string read_string(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.") {
    std::string read_value;
    do {
        if (std::cin.fail()) {
            std::cout << error_message << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << prompt_message << std::endl;
        std::cin >> read_value;
        std::cin.ignore();
    } while (std::cin.fail());
    return read_value;
}
