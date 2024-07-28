//
// Created by Aashik on 26-07-2024.
//

#pragma once

#include <string>
#include <functional>

const std::string BLUE = "\033[38;2;29;99;237m";
const std::string DARK_BLUE = "\033[38;2;0;8;77m";
const std::string RED = "\033[38;2;237;29;29m";
const std::string WHITE = "\033[38;2;229;242;252m";
const std::string RESET = "\033[0m";
const std::string CLEAR_LINE = "\033[K";
const std::string CLEAR_CURSOR = "\e[?25l";

inline auto indicators = "|/-\\";

using Progress = std::function<bool(std::string&)>;

class Console
{
public:
    static void readString(const std::string&, std::string&);
    static void progress(const Progress&);
    static void print(const std::string&);
    static void error(const std::string&);
    static void clear();
};