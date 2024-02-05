//
// Created by ASinclair on 2022/6/19.
//

#include "Window.h"
#include <iostream>



int Window::exec() {
    return getchar();
}

Window::Window(int w, int h, int f) {
//用easyx去做窗口，调用全局函数来初始化
   m_handle = initgraph(w,h,f);
    ::setbkmode(TRANSPARENT);
}

void Window::setWindowTitle(const string &title) {
    //将title转换为c风格字符串传入
    ::SetWindowText(m_handle,title.c_str());
}

int Window::width() {
    return ::getwidth();
}

int Window::height() {
    return ::getheight();
}

void Window::clear() {
      ::cleardevice();
}

void Window::beginDraw() {
     ::BeginBatchDraw();
}

void Window::flushDraw() {
      ::FlushBatchDraw();
}

void Window::endDraw() {
      ::EndBatchDraw();
}
