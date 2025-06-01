// Enemy.h
#pragma once
#include "raylib.h"

class Enemy {
public:
    virtual void Update(Vector2 playerPos) = 0;
    virtual void Draw() = 0;
    virtual bool CheckCollision(Vector2 playerPos) = 0;
    virtual bool IsExpired() const = 0;
    virtual ~Enemy() = default;
};

class BasicEnemy : public Enemy {
public:
    BasicEnemy(Vector2 pos);
    void Update(Vector2 playerPos) override;
    void Draw() override;
    bool CheckCollision(Vector2 playerPos) override;
    bool IsExpired() const override;

private:
    Vector2 position;
    float speed;
};

class ChaserEnemy : public Enemy {
public:
    ChaserEnemy(Vector2 pos);
    void Update(Vector2 playerPos) override;
    void Draw() override;
    bool CheckCollision(Vector2 playerPos) override;
    bool IsExpired() const override;

private:
    Vector2 position;
    float speed;
    float lifetime;
    float elapsed;
};
