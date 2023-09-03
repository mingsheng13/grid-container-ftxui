#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

#include "ftxui-grid-container/grid-container.hpp"

using namespace ftxui;

int main() {
  auto screen = ScreenInteractive::TerminalOutput();
  std::string output;

  auto style = size(WIDTH, EQUAL, 5);

  auto f = [&](const std::string& input) { output += input; };

  auto button0 = Button("0", [&] { f("0"); }) | style;
  auto button1 = Button("1", [&] { f("1"); }) | style;
  auto button2 = Button("2", [&] { f("2"); }) | style;
  auto button3 = Button("3", [&] { f("3"); }) | style;
  auto button4 = Button("4", [&] { f("4"); }) | style;
  auto button5 = Button("5", [&] { f("5"); }) | style;
  auto button6 = Button("6", [&] { f("6"); }) | style;
  auto button7 = Button("7", [&] { f("7"); }) | style;
  auto button8 = Button("8", [&] { f("8"); }) | style;
  auto button9 = Button("9", [&] { f("9"); }) | style;

  auto backButton = Button("B",
                           [&] {
                             if (output.length() != 0) {
                               output.pop_back();
                             }
                           }) |
                    style;

  auto resetButton = Button("R", [&] { output = ""; }) | style;

  auto grid = GridContainer({{button1, button2, button3},
                             {button4, button5, button6},
                             {button7, button8, button9},
                             {resetButton, button0, backButton}});

  auto renderer = Renderer(grid, [&] {
    return window(text("keypad") | center,
                  {
                      vbox({
                          text(output) | border,
                          grid->Render() | center | flex,
                      }),
                  }) |
           size(WIDTH, EQUAL, 30) | center;
  });

  screen.Loop(renderer);
}
