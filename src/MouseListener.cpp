#include "MouseListener.hpp"

#include "Mouse.hpp"

#include <iostream>

MouseListener::MouseListener(Mouse* mouse):
    mouse_(mouse) {}

MouseListener::~MouseListener() {}

bool MouseListener::mouseMoved(OIS::MouseEvent const& arg) {
    mouse_->x_ = arg.state.X.abs;
    mouse_->y_ = arg.state.Y.abs;
    mouse_->on_mouse_move_.emit(arg.state.X.abs, arg.state.Y.abs);

    return true;
}

bool MouseListener::mousePressed(OIS::MouseEvent const& arg, OIS::MouseButtonID id) {
    mouse_->buttons_[id] = true;
    mouse_->on_button_press_.emit(id);

    return true;
}

bool MouseListener::mouseReleased(OIS::MouseEvent const& arg, OIS::MouseButtonID id) {
    mouse_->buttons_[id] = false;
    mouse_->on_button_release_.emit(id);

    return true;
}

