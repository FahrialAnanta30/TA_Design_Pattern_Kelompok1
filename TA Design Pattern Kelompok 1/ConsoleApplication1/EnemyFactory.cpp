// Enemy.cpp
#include "Enemy.h"
#include "raymath.h"

BasicEnemy::BasicEnemy(Vector2 pos) : position(pos), speed(100.0f) {}

void BasicEnemy::Update(Vector2 playerPos) {
    Vector2 direction = Vector2Normalize(Vector2Subtract(playerPos, position));
    position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
}

void BasicEnemy::Draw() {
    DrawCircleV(position, 15, RED);
}

bool BasicEnemy::CheckCollision(Vector2 playerPos) {
    return CheckCollisionCircles(position, 15, playerPos, 10);
}

bool BasicEnemy::IsExpired() const {
    return false;
}

ChaserEnemy::ChaserEnemy(Vector2 pos) : position(pos), speed(120.0f), lifetime(5.0f), elapsed(0.0f) {}

void ChaserEnemy::Update(Vector2 playerPos) {
    elapsed += GetFrameTime();
    if (elapsed < lifetime) {
        Vector2 direction = Vector2Normalize(Vector2Subtract(playerPos, position));
        position = Vector2Add(position, Vector2Scale(direction, speed * GetFrameTime()));
    }
}

void ChaserEnemy::Draw() {
    if (elapsed < lifetime) {
        DrawCircleV(position, 15, PURPLE);
    }
}

bool ChaserEnemy::CheckCollision(Vector2 playerPos) {
    return elapsed < lifetime && CheckCollisionCircles(position, 15, playerPos, 10);
}

bool ChaserEnemy::IsExpired() const {
    return elapsed >= lifetime;
}
