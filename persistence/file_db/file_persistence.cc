#include "file_persistence.h"

using std::fstream;
using std::string;

namespace Snake {
namespace Persistence {

const string FilePersistence::_fileName = "scores.dat";

FilePersistence::FilePersistence() {
    _scoreFile.open(_fileName, fstream::out);
}

FilePersistence::~FilePersistence() {
    _scoreFile.close();
}

void FilePersistence::SaveScore(string name, unsigned int score) {
    Score scoreQ(name, score);
    _scoreFile << scoreQ;
}

} // ns Persistence
} // ns Snake
