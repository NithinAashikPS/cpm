//
// Created by Aashik on 24-07-2024.
//

#include <iostream>

#include <commands/init.hpp>
#include <utils/file.hpp>

#include <CLI/CLI.hpp>

Init::Init(CLI::App& cli)
{
    const auto init = cli.add_subcommand("init", "Create/Initialize new `cpm` project.");
    init->add_option("-n,--name", name, "Project name.");
}

void Init::execute()
{

    name = name.empty() ? File::currentDir() : File::currentDir() + SEPERATOR + name;
    if (File::exists(name) && name != File::currentDir())
    {
        std::cout << "Project already exists." << std::endl;
        return;
    }
    File::createDir(name);
    if (!File::isEmpty(name))
    {
        std::cout << "Directory should not contain any file/folder in it." << std::endl;
        return;
    }

    projectName = File::currentFolder(name);
    std::cout << "Project Name : " << projectName << std::endl;
    std::cout << "Project Description : ";
    std::getline(std::cin, projectDescription);
    std::cout << "Project Version (v0.1) : ";
    std::getline(std::cin, projectVersion);
    // std::cout << "Is Empty : " << File::isEmpty(name) << std::endl;
}
