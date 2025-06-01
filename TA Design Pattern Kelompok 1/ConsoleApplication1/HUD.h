// HUD.h
#pragma once
#include "ScoreManager.h"
#include "raylib.h"
#include <string>

class HUD : public IObserver {
public:
    HUD();
    void Update(int newScore) override;
    void Draw();

private:
    int displayedScore;
};
