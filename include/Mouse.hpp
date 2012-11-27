#ifndef LIBINPUT_MOUSE_HPP
#define LIBINPUT_MOUSE_HPP

#include <OIS.h>
#include <loop.hpp>
#include <vector>

#include "Device.hpp"
#include "OISBackend.hpp"

namespace OIS {
    class Mouse;
}

namespace input {

class MouseListener;

class Mouse: public Device {
    public:
        Mouse(OISBackend& backend);
        ~Mouse();

        loop::Signal<int, int, int, int> const& on_move();
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

        loop::Signal<int, int, int, int> on_move_;
        loop::Signal<int> on_button_press_;
        loop::Signal<int> on_button_release_;

        loop::Int x_;
        loop::Int y_;

        std::vector<loop::Bool> buttons_;
};

}

#endif //LIBINPUT_MOUSE_HPP

