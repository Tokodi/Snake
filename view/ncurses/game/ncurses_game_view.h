#pragma once

#include "view_interface.h"
#include "window.h"

#include <memory>

namespace Snake {
namespace UI {

class NcursesView final : public ViewInterface {
public:
    NcursesView(unsigned int width,
                unsigned int height);

    unsigned int GetWidth() const final;
    unsigned int GetHeight() const final;

    Direction GetStartDirection() const final;
    Direction GetUserInputNonBlocking() const final;

    void Draw(const std::shared_ptr<const Model::Table> table) final;
    void UpdateLifeCount(int lifeCount) final;
    void UpdateScore(int score) final;

    void Show() final;
    void Hide() final;

    static constexpr unsigned int SCORE_WINDOW_WIDTH = 15;
    static constexpr unsigned int SCORE_WINDOW_HEIGHT = 4;

    static constexpr unsigned int LIFE_WINDOW_WIDTH = 15;
    static constexpr unsigned int LIFE_WINDOW_HEIGHT = 4;

private:
    void Initialize();

private:
    const unsigned int _width;
    const unsigned int _height;

    std::unique_ptr<Common::Window> _gameWindow;
    std::unique_ptr<Common::Window> _lifeWindow;
    std::unique_ptr<Common::Window> _scoreWindow;
};

} // ns UI
} // ns Snake
