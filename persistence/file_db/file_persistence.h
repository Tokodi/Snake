#pragma once

#include "persistence_interface.h"
#include "score.h"

#include <fstream>

namespace Snake {
namespace Persistence {

class FilePersistence final : public PersistenceInterface {
public:
    FilePersistence();
    ~FilePersistence();

    void SaveScore(std::string name, unsigned int score) final;

private:
    static const std::string _fileName;
    std::fstream _scoreFile;
};

} // ns Persistence
} // ns Snake
