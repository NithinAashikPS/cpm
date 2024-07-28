//
// Created by Aashik on 28-07-2024.
//

#pragma once

class MessageInterface {
public:
    virtual ~MessageInterface() = default;
    virtual void execute() = 0;
};
