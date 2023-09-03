#include <utility>
#include <vector>

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>

#include <ftxui-grid-container/grid-container.hpp>

namespace ftxui {
namespace {
class Impl : public ComponentBase {
 private:
  std::vector<Components> rows_;
  Ref<int> selector_vertical_;
  Ref<int> selector_horizontal_;

 public:
  //        NOLINTNEXTLINE
  Impl(std::vector<Components> lines,
       Ref<int> selector_vertical,
       Ref<int> selector_horizontal)
      : rows_(std::move(lines)),
        selector_vertical_(selector_vertical),
        selector_horizontal_(selector_horizontal) {
    Components horizontalComponents_;
    for (const auto& line : rows_) {
      horizontalComponents_.push_back(
          Container::Horizontal(line, &selector_horizontal_()));
    }
    Add(Container::Vertical(horizontalComponents_, &selector_vertical_()));
  }
};

}  // namespace

Component GridContainer(const std::vector<Components>& lines, int* x, int* y) {
  return Make<Impl>(lines, x, y);
}

Component GridContainer(const std::vector<Components>& lines) {
  return Make<Impl>(lines, 0, 0);
}

}  // namespace ftxui
