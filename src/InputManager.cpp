#include "InputManager.hpp"

#include <iostream>
#include <sstream>

InputManager::InputManager(int for_xwindow):
    event_loop_(0.01),
    mouse_(NULL) {

    event_loop_.on_tick.connect(std::bind(&InputManager::poll_events, this));

    OIS::ParamList pl;
    std::ostringstream wnd;
	wnd << for_xwindow;
    pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));

	pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
	pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));

	input_manager_ = OIS::InputManager::createInputSystem(pl);

	OIS::Mouse* m = static_cast<OIS::Mouse*>(input_manager_->createInputObject(OIS::OISMouse, true ));
    mouse_ = std::shared_ptr<Mouse>(new Mouse(m));
}

InputManager::~InputManager() {
    OIS::InputManager::destroyInputSystem(input_manager_);
}

std::shared_ptr<Mouse> InputManager::get_mouse() const {
    return mouse_;
}

void InputManager::poll_events() {
    if (mouse_) mouse_->poll();
}
