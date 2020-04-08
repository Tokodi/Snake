#pragma once

namespace Snake {
namespace UI {

enum class Direction { NONE, LEFT, RIGHT, UP, DOWN };

static constexpr int COLOR_BLACK_IDX = 1;
static constexpr int COLOR_GREEN_IDX = 2;
static constexpr int COLOR_RED_IDX = 3;
static constexpr int COLOR_BLINK_IDX = 4;

void Initialize();
void Terminate();
void Refresh();
void Clear();

} // ns UI
} // ns Snake
