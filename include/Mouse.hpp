#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <OIS.h>
#include <loop.hpp>
#include <vector>

class MouseListener;

namespace OIS {
    class Mouse;
}

class Mouse {
    public:
        Mouse(OIS::Mouse* mouse);
        ~Mouse();

        loop::Signal<int, int> const& on_mouse_move();
        loop::Signal<int> const& on_button_press();
        loop::Signal<int> const& on_button_release();

        loop::Int const& x();
        loop::Int const& y();

        std::vector<loop::Bool> const& buttons();

        friend class MouseListener;
        friend class InputManager;

    private:
        void poll();

        OIS::Mouse* mouse_;
        MouseListener* listener_;

        loop::Signal<int, int> on_mouse_move_;
        loop::Signal<int> on_button_press_;
        loop::Signal<int> on_button_release_;

        loop::Int x_;
        loop::Int y_;

        std::vector<loop::Bool> buttons_;
};

#endif //MOUSE_HPP

