#ifndef LIBINPUT_INPUT_MANAGER_HPP
#define LIBINPUT_INPUT_MANAGER_HPP

#include <loop.hpp>
#include <memory>

#include "Mouse.hpp"

namespace input {

class InputManager {
    public:
        InputManager(int xwindow);
        ~InputManager();

        std::shared_ptr<Mouse> get_mouse() const;
        //std::shared_ptr<Keyboard> get_keyboard() const;

    private:
        void poll_events();

        OISBackend ois_backend_;

        loop::Timer event_loop_;

        std::shared_ptr<Mouse> mouse_;
};

}

#endif //LIBINPUT_INPUT_MANAGER_HPP
