#include "file_persistence.h"

using std::fstream;
using std::getline;
using std::string;
using std::stoi;
using std::vector;

namespace Snake {
namespace Persistence {

const string FilePersistence::_fileName = "scores.dat";

FilePersistence::FilePersistence() {
    _scoreFile.open(_fileName, fstream::out | fstream::app);
}

FilePersistence::~FilePersistence() {
    _scoreFile.close();
}

void FilePersistence::SaveScore(string name, unsigned int score) {
    ScoreRecord record(name, score);
    _scoreFile << record;
}

//TODO: Refactor this mess...
//vector<ScoreRecord> FilePersistence::GetNScores(unsigned int scoreCount) const {
//    vector<ScoreRecord> scores;
//
//    unsigned int i = scoreCount;
//    string line;
//    string username;
//    unsigned int score;
//
//    while (getline(_scoreFile, line) && i-- > scoreCount) {
//        username = line.substr(0, line.find(':'));
//        score = stoi(line.substr(line.find(':'), line.length()));
//        scores.push_back(ScoreRecord(username, score));
//    }
//
//    return scores;
//}

} // ns Persistence
} // ns Snake
