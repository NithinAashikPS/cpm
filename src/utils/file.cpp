//
// Created by Aashik on 24-07-2024.
//

#include <iostream>
#include <filesystem>

#include <utils/file.hpp>

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
    fs::create_directory(path);
}
