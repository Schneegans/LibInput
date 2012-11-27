#ifndef LIBINPUT_OIS_BACKEND_HPP
#define LIBINPUT_OIS_BACKEND_HPP

#include <OIS.h>

namespace input {

class OISBackend {
    public:
        OISBackend(int xwindow);
        ~OISBackend();

        OIS::InputManager& get();

    private:
        OIS::InputManager *input_manager_;
};

}

#endif //LIBINPUT_OIS_BACKEND_HPP



