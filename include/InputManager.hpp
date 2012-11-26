#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <OIS.h>
#include <loop.hpp>
#include <memory>

#include "Mouse.hpp"

namespace OIS {
    class InputManager;
}

class InputManager {
    public:
        InputManager(int for_xwindow);
        ~InputManager();

        std::shared_ptr<Mouse> get_mouse() const;

    private:
        void poll_events();

        OIS::InputManager *input_manager_;
        loop::Timer event_loop_;

        std::shared_ptr<Mouse> mouse_;
};

#endif //INPUT_MANAGER_HPP
