//
// Created by Aashik on 24-07-2024.
//

#pragma once

#include <commands/command.hpp>

#include <CLI/CLI.hpp>

class Init final : public Command
{
public:
    explicit Init(CLI::App&);
    void execute() override;
private:
    std::string projectName;
};
