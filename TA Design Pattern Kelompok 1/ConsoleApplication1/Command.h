// Command.h
#pragma once
#include "raylib.h"

class Command {
public:
    virtual void Execute(Vector2& pos) = 0;
    virtual ~Command() = default;
};

class MouseFollowCommand : public Command {
public:
    void Execute(Vector2& pos) override {
        pos = GetMousePosition();
    }
};
