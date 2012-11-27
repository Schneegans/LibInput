#include "InputManager.hpp"

#include <iostream>
#include <sstream>

namespace input {

InputManager::InputManager(int xwindow):
    ois_backend_(xwindow),
    event_loop_(1.0/60.0),
    mouse_(NULL) {

    event_loop_.on_tick.connect(std::bind(&InputManager::poll_events, this));

    mouse_ = std::shared_ptr<Mouse>(new Mouse(ois_backend_));
}

InputManager::~InputManager() {}

std::shared_ptr<Mouse> InputManager::get_mouse() const {
    return mouse_;
}

void InputManager::poll_events() {
    if (mouse_) mouse_->poll();
}

}
