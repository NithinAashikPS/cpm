//
// Created by Aashik on 28-07-2024.
//

#pragma once

#include <core/vcpkg/vcpkg.hpp>
#include <core/actor/async_actor.hpp>

class Vcpkg::Impl
{
public:
    Impl() : core(std::make_unique<AsyncActor<VcpkgCore>>()) {}

    void download() const
    {
        core->actor()->invoke(VcpkgCore::download);
    }

    [[nodiscard]] std::shared_ptr<VcpkgState> getState() const
    {
        return core->actor()->ask(VcpkgCore::getState).get();
    }

private:
    const std::unique_ptr<AsyncActor<VcpkgCore>> core;
};

