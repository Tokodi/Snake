#include "notifyer.h"
#include "utils.h"

#include <utility>
#include <chrono>
#include <thread>

using Snake::UI::Common::Window;
using std::make_unique;
using std::string;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

Notifyer::Notifyer() {
}

//TODO: create center window, and ingerit from it...
void Notifyer::Notify(string text, int durationInSec) {
    int posX = COLS/2 - NOTIFICATION_WINDOW_WIDTH/2;
    int posY = LINES/2 - NOTIFICATION_WINDOW_HEIGHT/2;
    _window = make_unique<Window>(Position(posX, posY), NOTIFICATION_WINDOW_WIDTH, NOTIFICATION_WINDOW_HEIGHT);
    _window->PrintToCenter(text, NOTIFICATION_WINDOW_HEIGHT/2);

    std::this_thread::sleep_for(std::chrono::seconds(durationInSec));

    Clear();
    _window.reset();
}

} // ns UI
} // ns Snake
