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
    init->add_option("-n,--name", projectName, "Project name.");
}

void Init::execute()
{
    if (projectName.empty())
        projectName = File::currentFolder();

    std::cout << "Project Name : " << projectName << std::endl;
}
