// GameManager.cpp
#include "GameManager.h"
#include "raylib.h"
#include <ctime>

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : playerPos({ 800, 500 }), spawnTimer(0.0f), gameOver(false) {
    InitWindow(1600, 1000, "Dot Dodger");
    SetTargetFPS(60);
    moveCmd = std::make_unique<MouseFollowCommand>();
    ScoreManager::GetInstance()->AddObserver(&hud);
    LeaderboardManager::GetInstance()->LoadScores();
    srand(static_cast<unsigned>(time(nullptr)));
}

GameManager* GameManager::GetInstance() {
    if (!instance) instance = new GameManager();
    return instance;
}

void GameManager::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
    CloseWindow();
}

void GameManager::Update() {
    float dt = GetFrameTime();
    if (!gameOver) {
        moveCmd->Execute(playerPos);
        spawnTimer += dt;
        if (spawnTimer > 1.0f) {
            enemies.push_back(EnemyFactory::CreateRandomEnemy());
            spawnTimer = 0;
        }
        for (auto& e : enemies) {
            e->Update(playerPos, dt);
            if (e->CheckCollision(playerPos, 20)) {
                gameOver = true;
                LeaderboardManager::GetInstance()->SaveScore(ScoreManager::GetInstance()->GetScore());
            }
        }
        enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](auto& e) { return e->IsDead(); }), enemies.end());
        ScoreManager::GetInstance()->AddScore(1);
    }
    else if (IsKeyPressed(KEY_R)) {
        Reset();
    }
}

void GameManager::Draw() {
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawCircleV(playerPos, 20, YELLOW);
    for (auto& e : enemies) e->Draw();
    hud.Draw();
    if (gameOver) {
        DrawText("GAME OVER - Press R to Restart", 550, 400, 30, RED);
        const auto& scores = LeaderboardManager::GetInstance()->GetScores();
        for (size_t i = 0; i < scores.size(); ++i) {
            DrawText(TextFormat("%d", scores[i]), 750, 450 + i * 30, 20, LIGHTGRAY);
        }
    }
    EndDrawing();
}

void GameManager::Reset() {
    playerPos = { 800, 500 };
    enemies.clear();
    ScoreManager::GetInstance()->ResetScore();
    gameOver = false;
    spawnTimer = 0.0f;
}