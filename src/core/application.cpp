//
// Created by Aashik on 24-07-2024.
//

#include <iostream>
#include <core/application.hpp>

Application::Application() = default;

void Application::registerCommand(const std::string& name, const std::shared_ptr<Command>& command) {
    commands[name] = command;
}

void Application::runCommand(const std::string& name) {
    if (commands.contains(name)) {
        commands[name]->execute();
    } else {
        std::cerr << "Command not found: " << name << std::endl;
    }
}