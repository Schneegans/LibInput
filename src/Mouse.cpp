#include "Mouse.hpp"

#include "MouseListener.hpp"

#include <iostream>

namespace input {

Mouse::Mouse(OISBackend& backend):
    mouse_(NULL),
    listener_(new MouseListener(this)) {

    mouse_ = static_cast<OIS::Mouse*>(backend.get().createInputObject(OIS::OISMouse, true));
    mouse_->setEventCallback(listener_);

    for (int i=0; i<8; ++i) {
        buttons_.push_back(loop::Bool(false));
    }
}

Mouse::~Mouse() {
    delete listener_;
}

loop::Signal<int, int, int, int> const& Mouse::on_move() {
    return on_move_;
}

loop::Signal<int> const& Mouse::on_button_press() {
    return on_button_press_;
}

loop::Signal<int> const& Mouse::on_button_release() {
    return on_button_press_;
}

loop::Int const& Mouse::x() {
    return x_;
}

loop::Int const& Mouse::y() {
    return y_;
}

std::vector<loop::Bool> const& Mouse::buttons() {
    return buttons_;
}

void Mouse::poll() {
    mouse_->capture();
}

}
