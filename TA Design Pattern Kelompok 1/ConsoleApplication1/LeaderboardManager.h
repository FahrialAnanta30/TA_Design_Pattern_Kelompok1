// LeaderboardManager.h
#pragma once
#include <vector>
#include <string>

class LeaderboardManager {
private:
    std::vector<int> scores;
    const char* filename = "leaderboard.txt";

    LeaderboardManager();
    static LeaderboardManager* instance;

public:
    static LeaderboardManager* GetInstance();
    void LoadScores();
    void SaveScore(int score);
    const std::vector<int>& GetScores() const;
};
