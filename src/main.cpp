//
// Created by Aashik on 24-07-2024.
//


#include <main.hpp>
#include <core/application.hpp>

#include <CLI/CLI.hpp>

#include "utils/console.hpp"

int main(const int argc, char** argv)
{
    Console::clear();
    if (argc < 2) {
        Console::error("Usage: " + std::string(argv[0]) + " <command>" );
        return 1;
    }

    Application cpm;
    CLI::App cli{"App description"};
    argv = cli.ensure_utf8(argv);

    initCommand = std::make_shared<Init>(cli);
    cpm.registerCommand("init", initCommand);

    CLI11_PARSE(cli, argc, argv);

    cpm.runCommand(argv[1]);

    return 0;
}
