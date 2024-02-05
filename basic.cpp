//
// Created by ASinclair on 2022/6/19.
//

#include "basic.h"

basic::basic(int x, int y, int w, int h):m_x(x),m_y(y),m_h(h),m_w(w){

}

int basic::width() {
    return m_w;
}

int basic::height() {
    return m_h;
}

void basic::setsize(int w, int h) {
    m_w =w;
    m_h = h;
}

int basic::getx() {
    return m_x;
}

int basic::gety() {
    return m_y;
}

void basic::move(int x, int y) {
     m_x=x;
     m_y=y;
}
