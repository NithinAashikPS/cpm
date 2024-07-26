//
// Created by Aashik on 26-07-2024.
//

#pragma once

#include <string>

const std::string BLUE = "\033[38;2;29;99;237m";
const std::string RED = "\033[38;2;237;29;29m";
const std::string WHITE = "\033[38;2;229;242;252m";
const std::string RESET = "\033[0m";
const std::string CLEAR_LINE = "\033[K";

class Console
{
public:
    static void readString(const std::string&, std::string&);
    static void print(const std::string&);
    static void error(const std::string&);
    static void clear();
};