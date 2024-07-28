//
// Created by Aashik on 28-07-2024.
//

#pragma once

#include <core/service/service.hpp>

struct VcpkgState;

class Vcpkg final : public Service
{
public:
    Vcpkg();
    ~Vcpkg() override;
    void download() const;
    [[nodiscard]] std::shared_ptr<VcpkgState> getState() const;

private:
    class Impl;
    const std::unique_ptr<Impl> impl;
};
