#include "sdl_game_view.h"

using std::shared_ptr;
using Snake::Model::Table;

using Position = std::pair<int, int>;

namespace Snake {
namespace UI {

SDLView::SDLView(unsigned int width, unsigned int height)
    : ViewInterface(width, height) {
    Initialize();
}

SDLView::~SDLView() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Direction SDLView::GetStartDirection() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    return Direction::LEFT;
                case SDLK_RIGHT:
                    return Direction::RIGHT;
                case SDLK_UP:
                    return Direction::UP;
                case SDLK_DOWN:
                    return Direction::DOWN;
                default:
                    continue;
            }
        }
    }
    return Direction::NONE;
}


Direction SDLView::GetUserInputNonBlocking() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    return Direction::LEFT;
                    break;
                case SDLK_RIGHT:
                    return Direction::RIGHT;
                    break;
                case SDLK_UP:
                    return Direction::UP;
                    break;
                case SDLK_DOWN:
                    return Direction::DOWN;
                    break;
                default:
                    continue;
            }
        }
    }
    return Direction::NONE;
}

void SDLView::Draw(const shared_ptr<const Table> table) {
    //TODO: Create a clear function in parent
    Show();
    for (unsigned int i = 0; i < table->GetWidth() + 2; ++i) {
        DrawRectangle(i, 0, Model::FieldType::EMPTY);
        DrawRectangle(i, table->GetHeight() + 1, Model::FieldType::EMPTY);
    }

    for (unsigned int x = 0; x < table->GetWidth(); ++x) {
        for (unsigned int y = 0; y < table->GetHeight(); ++y) {
            DrawRectangle(0, x + 1, Model::FieldType::EMPTY);
            if (table->GetField(Position(x, y)) != Model::FieldType::EMPTY) {
                DrawRectangle(x + 1, y + 1, table->GetField(Position(x, y)));
            }
            DrawRectangle(table->GetWidth() + 1, x + 1, Model::FieldType::EMPTY);
        }
    }
    SDL_RenderPresent(renderer);
}

void SDLView::UpdateLifeCount(int /*lifeCount*/) {
}

void SDLView::UpdateScore(int /*score*/) {
}

void SDLView::Show() {
    SDL_SetRenderDrawColor(renderer, 51, 51, 51, 255);
    SDL_RenderClear(renderer);
}

void SDLView::Hide() {
}

void SDLView::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &window, &renderer);
    SDL_SetWindowTitle(window, "S_N_A_K_E");
    TTF_Init();
    //font = TTF_OpenFont("ocraext.ttf", HEIGHT / 30);
    //if (font == nullptr) {
        //Error
    //}
}

void SDLView::DrawRectangle(const unsigned int x, const unsigned int y, Model::FieldType fieldType) {
    static constexpr unsigned int RECT_SIZE = 20;
    static constexpr unsigned int BORDER_SIZE = 1;
    static SDL_Rect rect;
    rect.x = x * RECT_SIZE + BORDER_SIZE;
    rect.y = y * RECT_SIZE + BORDER_SIZE;
    rect.h = RECT_SIZE - 2 * BORDER_SIZE;
    rect.w = RECT_SIZE - 2 * BORDER_SIZE;
    switch (fieldType) {
        //TODO: THIS SHOULD BE WALL...
        case Model::FieldType::EMPTY:
            SDL_SetRenderDrawColor(renderer, 90, 90, 90, 0);
            break;
        case Model::FieldType::FOOD:
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
            break;
        case Model::FieldType::SNAKE:
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);
            break;
    }
    SDL_RenderFillRect(renderer, &rect);
}

} // ns UI
} // ns Snake
