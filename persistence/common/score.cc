#include "score.h"

using std::ostream;

namespace Snake {
namespace Persistence {

Score::Score(std::string name, unsigned int score)
    : _name(name), _score(score) {}

std::string Score::GetName() const {
    return _name;
}

unsigned int Score::GetScore() const {
    return _score;
}

ostream& operator<<(ostream& os, const Score& score) {
    os << score.GetName() << " " << score.GetScore() << std::endl;
    return os;
}

} // ns Persistence
} // ns Snake
