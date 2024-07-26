//
// Created by Aashik on 24-07-2024.
//

#ifdef _WIN32
#include <windows.h>
#endif
#include <filesystem>
#include <fstream>
#include <cstring>

#include <utils/file.hpp>
#include <utils/console.hpp>

std::string File::currentDir()
{
    const fs::path current_path = fs::current_path();
    return current_path.string();
}

std::string File::currentFolder(const std::string& path)
{
    const std::size_t pos = path.find_last_of("\\/");
    std::string last_part = (pos != std::string::npos) ? path.substr(pos + 1) : path;

    return last_part;
}

std::string File::currentFolder()
{
    const std::string path_str = currentDir();
    return currentFolder(path_str);
}

bool File::isEmpty(const std::string& path) {
    return fs::is_empty(path);
}

bool File::exists(const std::string& path)
{
    return fs::exists(path);
}

void File::createDir(const std::string& path)
{
    fs::create_directories(path);
}

void File::createDirH(const std::string& path)
{
#ifdef _WIN32
    if (!CreateDirectory(path.c_str(), nullptr))
        Console::error("Error: " + GetLastError());

    if (!SetFileAttributes(path.c_str(), FILE_ATTRIBUTE_HIDDEN))
        Console::error("Error: " + GetLastError());
#else
    if (mkdir(path.c_str(), 0755) == -1)
        Console::error("Error: " + std::string(strerror(errno)));
#endif
}

void File::write(const std::string& path, const std::string& data)
{
    if (std::ofstream outFile(path); outFile.is_open()) {
        outFile << data; outFile.close();
    } else {
        Console::error("Unable to open file : " + path);
    }
}
