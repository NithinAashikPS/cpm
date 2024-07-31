//
// Created by Aashik on 27-07-2024.
//

#include <thread>
#include <core/vcpkg/vcpkg.hpp>

VcpkgCore::VcpkgCore() : state(std::make_shared<VcpkgState>())
{}

void VcpkgCore::download()
{
    state->running = true;
    state->message = "Downloading Started...";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    state->message = "Downloading...";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    state->message = "Downloading Finished...";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    state->running = false;
}

std::shared_ptr<VcpkgState> VcpkgCore::getState()
{
    return state;
}
