//
// Created by Aashik on 24-07-2024.
//

#pragma once

#include <core/service/vcpkg.hpp>
#include <commands/command.hpp>

#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>

using Json = nlohmann::ordered_json;

class Init final : public Command
{
public:
    explicit Init(CLI::App&);
    void execute() override;

private:
    Json getProjectDetails(const std::string&);

    std::unique_ptr<Vcpkg> vcpkg;

    std::string name;

    std::string projectName;
    std::string projectDescription;
    std::string projectVersion = "v0.1";
};
