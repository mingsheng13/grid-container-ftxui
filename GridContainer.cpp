#include <utility>
#include <vector>

#include <ftxui/component/component.hpp>
#include "ftxui/component/component_base.hpp"
#include "ftxui/dom/elements.hpp"

#include "GridContainer.h"

namespace ftxui
{
Component GridContainer(const std::vector<Components>& lines)
{
    class Impl : public ComponentBase
    {
    private:
        std::vector<Components> lines_;
        Component mainContainer_;
        int mainSelector_ = 0;
        Components horizontalComponents_;
        int sharedSelector_ = 0;

    public:
        //NOLINTNEXTLINE
        Impl(std::vector<Components> lines) : lines_(std::move(lines))
        {
            horizontalComponents_.reserve(lines_.size());
            for (const auto & line : lines_)
            {
                horizontalComponents_.push_back(Container::Horizontal(line, &sharedSelector_));
            }
            mainContainer_ = Container::Vertical(horizontalComponents_, &mainSelector_);
            Add(mainContainer_);
        }

        bool Focusable() const override
        {
            return true;
        }
    };
    return Make<Impl>(lines);
}
}
