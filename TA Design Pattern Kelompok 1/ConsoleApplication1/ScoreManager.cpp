// ScoreManager.cpp
#include "ScoreManager.h"

ScoreManager* ScoreManager::instance = nullptr;

ScoreManager* ScoreManager::GetInstance() {
    if (!instance) instance = new ScoreManager();
    return instance;
}

void ScoreManager::AddScore(int value) {
    score += value;
    for (auto obs : observers) obs->Update(score);
}

int ScoreManager::GetScore() const {
    return score;
}

void ScoreManager::ResetScore() {
    score = 0;
    for (auto obs : observers) obs->Update(score);
}

void ScoreManager::AddObserver(IObserver* observer) {
    observers.push_back(observer);
}

void ScoreManager::RemoveObserver(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
