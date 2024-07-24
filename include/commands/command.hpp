//
// Created by Aashik on 24-07-2024.
//

#pragma once

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};
