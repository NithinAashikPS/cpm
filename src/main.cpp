//
// Created by Aashik on 24-07-2024.
//


#include <main.hpp>
#include <core/application.hpp>

#include <CLI/CLI.hpp>

int main(const int argc, char** argv)
{
    Application cpm;
    CLI::App cli{"App description"};
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

    return 0;
}
