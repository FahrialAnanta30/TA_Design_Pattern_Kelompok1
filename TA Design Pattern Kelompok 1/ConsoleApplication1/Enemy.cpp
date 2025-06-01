// Enemy.cpp
#include "Enemy.h"
#include <cmath>

BasicEnemy::BasicEnemy(Vector2 pos) {
    position = pos;
    speed = 100.0f;
}

void BasicEnemy::Update(Vector2 playerPos) {
    Vector2 direction = { playerPos.x - position.x, playerPos.y - position.y };
    float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    position.x += direction.x * speed * GetFrameTime();
    position.y += direction.y * speed * GetFrameTime();
}

void BasicEnemy::Draw() {
    DrawCircleV(position, 20, RED);
}

bool BasicEnemy::CheckCollision(Vector2 playerPos, float radius) {
    float dx = playerPos.x - position.x;
    float dy = playerPos.y - position.y;
    float distance = sqrtf(dx * dx + dy * dy);
    return distance < radius + 20;
}

bool BasicEnemy::IsExpired() const {
    return false; // Basic enemies do not expire
}

ChaserEnemy::ChaserEnemy(Vector2 pos) {
    position = pos;
    speed = 150.0f;
    lifetime = 5.0f;
    elapsed = 0.0f;
}

void ChaserEnemy::Update(Vector2 playerPos) {
    elapsed += GetFrameTime();
    Vector2 direction = { playerPos.x - position.x, playerPos.y - position.y };
    float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    position.x += direction.x * speed * GetFrameTime();
    position.y += direction.y * speed * GetFrameTime();
}

void ChaserEnemy::Draw() {
    if (!IsExpired()) {
        DrawCircleV(position, 15, PURPLE);
    }
}

bool ChaserEnemy::CheckCollision(Vector2 playerPos, float radius) {
    if (IsExpired()) return false;
    float dx = playerPos.x - position.x;
    float dy = playerPos.y - position.y;
    float distance = sqrtf(dx * dx + dy * dy);
    return distance < radius + 15;
}

bool ChaserEnemy::IsExpired() const {
    return elapsed >= lifetime;
}
