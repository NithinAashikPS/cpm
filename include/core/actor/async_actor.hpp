//
// Created by Aashik on 28-07-2024.
//

#pragma once

#include <core/actor/actor.hpp>

template<typename ActorType>
class AsyncActor
{
public:
    template<typename... Args>
    explicit AsyncActor(Args&&... args)
    {
        thread = std::thread([&]()
        {
            m_actor = std::make_shared<Actor<ActorType>>(std::forward<Args>(args)...);
        });
    }

    std::shared_ptr<Actor<ActorType>> actor()
    {
        return m_actor;
    }
private:
    std::thread thread;
    std::shared_ptr<Actor<ActorType>> m_actor;
};
