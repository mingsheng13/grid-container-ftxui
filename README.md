# grid-container-ftxui

A [FTXUI](https://github.com/ArthurSonzogni/FTXUI) component implementing an
easy grid container using `Container::Horizontal` and `Container::Vertical`.

![gridcontainer](https://github.com/mingsheng13/grid-container-ftxui/assets/102264706/3f23e87b-ba5f-4200-8485-17e7cf979769)

## API

```cpp
namespace ftxui {
Component GridContainer(const std::vector<Components>& lines);
Component GridContainer(const std::vector<Components>& lines, int* x, int* y);
}  // namespace ftxui
```

## Example

See [./example](./example).

```cpp
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui-grid-container/grid-container.h"

using namespace ftxui;

int main() {
  auto button0 = Button({.label = "0"});
  auto button1 = Button({.label = "1"});
  auto button2 = Button({.label = "2"});
  auto button3 = Button({.label = "3"});

  auto grid = GridContainer({
    { button0, button1 },
    { button1, button2 },
  })

  auto screen = ScreenInteractive::TerminalOutput();
  screen.Loop(grid);
  return 0;
}
```

```cmake
cmake_minimum_required (VERSION 3.14)
project(my-app LANGUAGES CXX VERSION 1.0.0)

include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)

FetchContent_Declare(ftxui-grid-input
  GIT_REPOSITORY https://github.com/mingsheng13/grid-container-ftxui
  GIT_TAG master
)

FetchContent_MakeAvailable(ftxui)
FetchContent_MakeAvailable(ftxui-grid-input)
add_executable(my-app src/main.cpp)
target_link_libraries(my-app
  PRIVATE ftxui-grid-container
)
```
