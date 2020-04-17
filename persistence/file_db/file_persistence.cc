#include "file_persistence.h"

namespace Snake {
namespace Persistence {

FilePersistence::FilePersistence(std::string fileName)
    : _fileName(fileName) {
    _scoreFile.open(_fileName);
}


FilePersistence::~FilePersistence() {
    _scoreFile.close();
}

void FilePersistence::SaveScore(std::string name, unsigned int score) {
    Score scoreQ(name, score);
    _scoreFile << scoreQ << std::endl;
}

} // ns Persistence
} // ns Snake
