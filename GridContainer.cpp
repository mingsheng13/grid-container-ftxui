#include <utility>
#include <vector>

#include <ftxui/component/component.hpp>
#include "ftxui/component/component_base.hpp"
#include "ftxui/dom/elements.hpp"

#include "GridContainer.h"

namespace ftxui
{
namespace
{
    class Impl : public ComponentBase
    {
    private:
        std::vector<Components> lines_;
        Component mainContainer_;
        int* mainSelector_ = nullptr;
        Components horizontalComponents_;
        int* sharedSelector_ = nullptr;

    public:
//        NOLINTNEXTLINE
        Impl(std::vector<Components> lines, int* mainSelector, int* sharedSelector) :
            lines_(std::move(lines)), mainSelector_(mainSelector), sharedSelector_(sharedSelector)
        {
            horizontalComponents_.reserve(lines_.size());
            for (const auto &line: lines_)
            {
                horizontalComponents_.push_back(Container::Horizontal(line, sharedSelector_));
            }
            mainContainer_ = Container::Vertical(horizontalComponents_, mainSelector_);
            Add(mainContainer_);
        }

        bool Focusable() const override
        {
            return true;
        }
    };
}//namespace
Component GridContainer(const std::vector<Components>& lines, int* x, int* y)
{
    return Make<Impl>(lines, x, y);
}

Component GridContainer(const std::vector<Components>& lines)
{
    int x = 0;
    int y = 0;
    return Make<Impl>(lines, &x, &y);
}
} //namspace ftxui
