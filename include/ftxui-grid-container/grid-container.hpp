#ifndef FTXUI_COMPONENT_GRID_CONTAINER_HPP
#define FTXUI_COMPONENT_GRID_CONTAINER_HPP

#include <vector>
#include "ftxui/component/component_base.hpp"

namespace ftxui {
Component GridContainer(const std::vector<Components>& lines);
Component GridContainer(const std::vector<Components>& lines, int* x, int* y);
}  // namespace ftxui

#endif /* end of include guard: FTXUI_COMPONENT_GRID_CONTAINER_HPP */
