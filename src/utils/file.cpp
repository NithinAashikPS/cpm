//
// Created by Aashik on 24-07-2024.
//

#include <filesystem>

#include <utils/file.hpp>

std::string File::currentDir()
{
    const std::filesystem::path current_path = std::filesystem::current_path();
    return current_path.string();
}

std::string File::currentFolder()
{
    const std::string path_str = currentDir();
    const std::size_t pos = path_str.find_last_of("\\/");
    std::string last_part = (pos != std::string::npos) ? path_str.substr(pos + 1) : path_str;

    return last_part;
}
