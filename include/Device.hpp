#ifndef LIBINPUT_DEVICE_HPP
#define LIBINPUT_DEVICE_HPP

namespace input {

class Device {
    protected:
        virtual void poll() = 0;
};

}

#endif //LIBINPUT_DEVICE_HPP



