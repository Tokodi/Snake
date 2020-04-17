#pragma once

#include "view_interface.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace Snake {
namespace UI {

class SDLView final : public ViewInterface {
public:
    SDLView(unsigned int width, unsigned int height);
    ~SDLView();

    Direction GetStartDirection() const final;
    Direction GetUserInputNonBlocking() const final;

    void Draw(const std::shared_ptr<const Model::Table> table) final;
    void UpdateLifeCount(int lifeCount) final;
    void UpdateScore(int score) final;

    void Show() final;
    void Hide() final;

    static constexpr unsigned int WIDTH = 440;
    static constexpr unsigned int HEIGHT = 440;

private:
    void Initialize();
    void DrawRectangle(const unsigned int x, const unsigned int y, Model::FieldType fieldType);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

} // ns UI
} // ns Snake
