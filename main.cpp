#include <iostream>
#include "management.h"
#include "Window.h"



int main() {
    Window w(960,640,EW_SHOWCONSOLE);
    w.setWindowTitle("User Login System");
    management obj;
    obj.run();
}
