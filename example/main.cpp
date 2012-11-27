#include "input.hpp"
#include "loop.hpp"

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <iostream>

Window open_window();

int main() {
    input::InputManager input(open_window());

    auto mouse = input.get_mouse();
    mouse->on_move().connect([](int x, int y, int dx, int dy){
        std::cout << "Move to: " << x << ", " << y << " (" << dx << ", " << dy << ")" << std::endl;
    });

    mouse->on_button_press().connect([](int button){
        std::cout << "Button: " << button << std::endl;
    });

    loop::MainLoop l;
    l.start();

    return 0;
}

Window open_window() {
    Display* xDisp = XOpenDisplay(0);
	Window xWin = XCreateSimpleWindow(xDisp, DefaultRootWindow(xDisp), 0, 0, 100, 100, 0, 0, 0);

	XMapWindow(xDisp, xWin);
	XSelectInput(xDisp, xWin, StructureNotifyMask | SubstructureNotifyMask);
	Atom wmProto = XInternAtom(xDisp, "WM_PROTOCOLS", False);
	Atom wmDelete = XInternAtom(xDisp, "WM_DELETE_WINDOW", False);
	XChangeProperty(xDisp, xWin, wmProto, XA_ATOM, 32, 0, (const unsigned char*)&wmDelete, 1);
	XEvent evtent;
	do {
        XNextEvent(xDisp, &evtent);
	} while(evtent.type != MapNotify);

	return xWin;
}
