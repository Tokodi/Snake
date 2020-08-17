#pragma once

#include <string>
#include <score_record.h>

namespace Snake {
namespace Persistence {

class PersistenceInterface {
public:
    virtual void SaveScore(std::string name, unsigned int score) = 0;
    //virtual std::vector<ScoreRecord> GetNScores(unsigned int scoreCount) const = 0;
};

} // ns Persistence
} // ns Snake
