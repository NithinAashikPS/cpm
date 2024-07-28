//
// Created by Aashik on 28-07-2024.
//

#include <core/service/vcpkg.hpp>
#include <core/impl/vcpkg.hpp>

Vcpkg::Vcpkg() : impl(std::make_unique<Impl>()) {}

Vcpkg::~Vcpkg() = default;

void Vcpkg::download() const
{
    impl->download();
}

std::shared_ptr<VcpkgState> Vcpkg::getState() const
{
    return impl->getState();
}
