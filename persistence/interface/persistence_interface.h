#pragma once

#include <string>

namespace Snake {
namespace Persistence {

class PersistenceInterface {
public:
    virtual void SaveScore(std::string name, unsigned int score) = 0;
    //virtual void unsigned int> GetScores() const = 0;
    //virtual void GetNScores(unsigned int scoreCount) const = 0;
};

} // ns Persistence
} // ns Snake
