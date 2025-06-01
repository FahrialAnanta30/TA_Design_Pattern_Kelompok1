// HUD.cpp
#include "HUD.h"

HUD::HUD() : displayedScore(0) {}

void HUD::Update(int newScore) {
    displayedScore = newScore;
}

void HUD::Draw() {
    DrawText(TextFormat("Score: %i", displayedScore), 20, 20, 30, DARKBLUE);
}
