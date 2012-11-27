#include "OISBackend.hpp"

#include <iostream>
#include <sstream>

namespace input {

OISBackend::OISBackend(int xwindow):
    input_manager_() {

    std::ostringstream wnd;
	wnd << xwindow;

	OIS::ParamList pl;
    pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));
	pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
	pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));

	input_manager_ = OIS::InputManager::createInputSystem(pl);
}

OISBackend::~OISBackend() {
    OIS::InputManager::destroyInputSystem(input_manager_);
}

OIS::InputManager& OISBackend::get() {
    return *input_manager_;
}

}



