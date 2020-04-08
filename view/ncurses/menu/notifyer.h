#pragma once

#include "window.h"

#include <memory>
#include <string>

namespace Snake {
namespace UI {

class Notifyer {
public:
    Notifyer();

    void Notify(std::string text, int durationInSec);

private:
    static constexpr unsigned int NOTIFICATION_WINDOW_WIDTH = 21;
    static constexpr unsigned int NOTIFICATION_WINDOW_HEIGHT = 7;

    std::unique_ptr<Common::Window> _window;
};

} // UI
} // ns Snake
