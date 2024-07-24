//
// Created by Aashik on 24-07-2024.
//


#include <main.hpp>
#include <core/application.hpp>


#include <CLI/CLI.hpp>

// #include <ftxui/component/component.hpp> // for Component
// #include <ftxui/component/screen_interactive.hpp> // for ScreenInteractive
// #include <ftxui/dom/elements.hpp>
//     using namespace ftxui;

int main(const int argc, char** argv)
{

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <command>" << std::endl;
        return 1;
    }

    Application cpm;
    CLI::App cli{"App description"};
    argv = cli.ensure_utf8(argv);

    initCommand = std::make_shared<Init>(cli);
    cpm.registerCommand("init", initCommand);

    CLI11_PARSE(cli, argc, argv);

    cpm.runCommand(argv[1]);

    // auto screen = Screen::Create(
    //     Dimension::Full(), Dimension::Full()
    // );
    // Render(screen, text("Hello"));
    // screen.Print();

    return 0;
}
