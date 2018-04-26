//
// Created by guilherme on 26-04-2018.
//

#ifndef MENU_LIB_READFUNCTIONS_H
#define MENU_LIB_READFUNCTIONS_H

int read_int(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.");
double read_double(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.");
std::string read_string(std::string const &prompt_message, std::string const &error_message = "Invalid choice try again.");

#endif //MENU_LIB_READFUNCTIONS_H
