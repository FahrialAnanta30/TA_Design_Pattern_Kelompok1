#pragma once// GameManager.h
#pragma once
#include "Enemy.h"
#include "EnemyFactory.h"
#include "HUD.h"
#include "ScoreManager.h"
#include "LeaderboardManager.h"
#include "Command.h"
#include <memory>
#include <vector>


class GameManager {
private:
    Vector2 playerPos;
    std::unique_ptr<Command> moveCmd;
    std::vector<std::unique_ptr<Enemy>> enemies;
    float spawnTimer;
    bool gameOver;
    HUD hud;

    GameManager();
    static GameManager* instance;

    void Update();
    void Draw();
    void Reset();

public:
    static GameManager* GetInstance();
    void Run();
};
