//
// Created by Aashik on 27-07-2024.
//

#pragma once
#include <memory>

struct VcpkgState
{
    bool running;
    std::string message;
};

class VcpkgCore
{
public:
    VcpkgCore();
    void download();
    std::shared_ptr<VcpkgState> getState();

private:
    std::shared_ptr<VcpkgState> state;
};
