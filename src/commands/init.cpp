//
// Created by Aashik on 24-07-2024.
//

#include <commands/init.hpp>
#include <utils/file.hpp>
#include <utils/console.hpp>

#include "core/vcpkg/vcpkg.hpp"

Init::Init(CLI::App& cli) : vcpkg(std::make_unique<Vcpkg>())
{
    const auto init = cli.add_subcommand("init", "Create/Initialize new `cpm` project.");
    init->add_option("-n,--name", name, "Project name.");
}

void Init::execute()
{
    name = name.empty() ? File::currentDir() : File::currentDir() + SEPERATOR + name;
    if (File::exists(name) && name != File::currentDir())
    {
        Console::error("Project already exists."); return;
    }
    if (!File::exists(name))
    {
        const Json projectDetails = getProjectDetails(name);
        File::createDir(name);
        File::write(name + "/cpm.json", projectDetails.dump(4));
        File::createDirH(name + "/.cpm");

        const std::shared_ptr<VcpkgState> state = vcpkg->getState();

        vcpkg->download();
        Console::progress([&](std::string& prompt) -> bool
        {
            prompt = state->message;
            return state->running;
        });
        return;
    }
    if (!File::isEmpty(name))
        Console::error("Directory should not contain any file/folder in it.");
}

Json Init::getProjectDetails(const std::string& name)
{
    projectName = File::currentFolder(name);
    std::string tempVersion;

    Console::print("Project Name : " + projectName);
    Console::readString("Project Description : ", projectDescription);
    Console::readString("Project Version (default: v0.1) : ", tempVersion);

    if (!tempVersion.empty()) {  projectVersion = tempVersion; }

    Json projectDetails;
    projectDetails["name"] = projectName;
    projectDetails["description"] = projectDescription;
    projectDetails["version"] = projectVersion;
    return projectDetails;
}
