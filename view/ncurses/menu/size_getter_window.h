#pragma once

#include "window.h"
#include "input_field.h"

#include <memory>

namespace Snake {
namespace UI {

class SizeGetterWindow : public Common::Window {
public:
    SizeGetterWindow();

    void Show() final;
    void Hide() final;

    int GetTableWidth();
    int GetTableHeight();

private:
    static constexpr unsigned int SIZE_GETTER_WINDOW_WIDTH = 35;
    static constexpr unsigned int SIZE_GETTER_WINDOW_HEIGHT = 12;

    void CreateInputFields();

    std::unique_ptr<Common::InputField> _widthInput;
    std::unique_ptr<Common::InputField> _heightInput;
};

} // ns UI
} // ns Snake
