#include "score_record.h"

using std::ostream;

namespace Snake {
namespace Persistence {

ScoreRecord::ScoreRecord(std::string name, unsigned int score)
    : _name(name), _score(score) {}

std::string ScoreRecord::GetName() const {
    return _name;
}

unsigned int ScoreRecord::GetScore() const {
    return _score;
}

ostream& operator<<(ostream& os, const ScoreRecord& score) {
    os << score.GetName() << ":" << score.GetScore() << std::endl;
    return os;
}

} // ns Persistence
} // ns Snake
