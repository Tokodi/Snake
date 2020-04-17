#include "file_persistence.h"
#include "game.h"
#include "game_controller.hpp"
#include "menu_window.h"
#include "ncurses_game_view.h"
#include "sdl_game_view.h"
#include "notifyer.h"
#include "size_getter_window.h"
#include "utils.h"

using namespace Snake;

using Position = std::pair<int, int>;

int main() {
    Controller::GameController<UI::SDLView, Persistence::FilePersistence> gameController;
    gameController.StartGame(20, 20);
    return 0;
}
