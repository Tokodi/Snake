#pragma once

#include <iostream>

namespace Snake {
namespace Persistence {

class ScoreRecord {
public:
    ScoreRecord(std::string name, unsigned int score);

    std::string GetName() const;
    unsigned int GetScore() const;

    friend std::ostream& operator<<(std::ostream& os, const ScoreRecord& score);

private:
    const std::string _name;
    const unsigned int _score;
};

} // ns Persistence
} // ns Snake
