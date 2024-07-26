//
// Created by Aashik on 26-07-2024.
//

#include <iostream>

#include <utils/console.hpp>

void Console::readString(const std::string& prompt, std::string& input)
{
    std::cout << BLUE << prompt << RESET;
    std::getline(std::cin, input);
    std::cout << "\033[A" << CLEAR_LINE << WHITE << prompt << input << RESET << std::endl;
}

void Console::print(const std::string& prompt)
{
    std::cout << WHITE << prompt << RESET << std::endl;
}

void Console::error(const std::string& prompt)
{
    std::cout << RED << prompt << RESET << std::endl;
}

void Console::clear()
{
    std::cout << "\x1B[2J\x1B[H";
}
