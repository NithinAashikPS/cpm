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

    Application cpm;
    CLI::App cli{""};
    argv = cli.ensure_utf8(argv);

    initCommand = std::make_shared<Init>(cli);
    cpm.registerCommand("init", initCommand);

    if (argc < 2) {
        char* a[] = {argv[0], static_cast<char*>("--help")};
        CLI11_PARSE(cli, 2, a);
        return 1;
    }
    CLI11_PARSE(cli, argc, argv);

    cpm.runCommand(argv[1]);
    Console::printBlue("Done.");

    return 0;
}
