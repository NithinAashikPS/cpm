//
// Created by Aashik on 24-07-2024.
//

#pragma once

#include <string>

#ifdef _WIN32
#define SEPERATOR "\\"
#else
#define SEPERATOR "/"
#endif

namespace fs = std::filesystem;

class File
{
public:
    static std::string currentDir();
    static std::string currentFolder();
    static std::string currentFolder(const std::string&);
    static bool isEmpty(const std::string&);
    static bool exists(const std::string&);
    static void createDir(const std::string&);
    static void createDirH(const std::string&);
    static void write(const std::string&, const std::string&);
};
