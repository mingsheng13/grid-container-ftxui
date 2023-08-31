#ifndef GRIDCONTAINER_GRIDCONTAINER_H
#define GRIDCONTAINER_GRIDCONTAINER_H

#include <vector>
#include "ftxui/component/component_base.hpp"

namespace ftxui
{
    Component GridContainer(const std::vector<Components>& lines);
    Component GridContainer(const std::vector<Components>& lines, int* x, int* y);
}

#endif //GRIDCONTAINER_GRIDCONTAINER_H
