#ifndef MOUSE_LISTENER_HPP
#define MOUSE_LISTENER_HPP

#include <OIS.h>

class Mouse;

class MouseListener: public OIS::MouseListener {
    public:
        MouseListener(Mouse* mouse);
        ~MouseListener();

        bool mouseMoved(OIS::MouseEvent const& arg);
        bool mousePressed(OIS::MouseEvent const& arg, OIS::MouseButtonID id);
        bool mouseReleased(OIS::MouseEvent const& arg, OIS::MouseButtonID id);

    private:
        Mouse* mouse_;
};

#endif //MOUSE_LISTENER_HPP


