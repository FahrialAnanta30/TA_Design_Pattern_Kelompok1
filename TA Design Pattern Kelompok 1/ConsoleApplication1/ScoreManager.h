// ScoreManager.h
#pragma once
#include <vector>
#include <algorithm>

class IObserver {
public:
    virtual void Update(int newScore) = 0;
    virtual ~IObserver() = default;
};

class ScoreManager {
private:
    int score;
    std::vector<IObserver*> observers;

    ScoreManager() : score(0) {}
    static ScoreManager* instance;

public:
    static ScoreManager* GetInstance();
    void AddScore(int value);
    int GetScore() const;
    void ResetScore();
    void AddObserver(IObserver* observer);
    void RemoveObserver(IObserver* observer);
};
