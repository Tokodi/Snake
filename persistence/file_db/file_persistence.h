#pragma once

#include "persistence_interface.h"
#include "score_record.h"

#include <fstream>
#include <vector>

namespace Snake {
namespace Persistence {

class FilePersistence final : public PersistenceInterface {
public:
    FilePersistence();
    ~FilePersistence();

    void SaveScore(std::string name, unsigned int score) final;
    //std::vector<ScoreRecord> GetNScores(unsigned int scoreCount) const final;

private:
    static const std::string _fileName;
    std::fstream _scoreFile;
};

} // ns Persistence
} // ns Snake
