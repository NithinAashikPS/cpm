//
// Created by Aashik on 24-07-2024.
//

#pragma once

#include <string>
#include <memory>
#include <map>

#include <commands/command.hpp>

class Application
{
public:
    Application();
    void registerCommand(const std::string&, const std::shared_ptr<Command>&);
    void runCommand(const std::string&);

private:
    std::map<std::string, std::shared_ptr<Command>> commands;
};
