#include "Mouse.hpp"

#include "MouseListener.hpp"

#include <iostream>

Mouse::Mouse(OIS::Mouse* mouse):
    mouse_(mouse),
    listener_(new MouseListener(this)) {

    mouse_->setEventCallback(listener_);

    for (int i=0; i<8; ++i) {
        buttons_.push_back(loop::Bool(false));
    }
}

Mouse::~Mouse() {
    delete listener_;
}

loop::Signal<int, int> const& Mouse::on_mouse_move() {
    return on_mouse_move_;
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
