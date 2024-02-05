//
// Created by ASinclair on 2022/6/19.
//

#include "Window.h"
#include <iostream>



int Window::exec() {
    return getchar();
}

Window::Window(int w, int h, int f) {
//��easyxȥ�����ڣ�����ȫ�ֺ�������ʼ��
   m_handle = initgraph(w,h,f);
    ::setbkmode(TRANSPARENT);
}

void Window::setWindowTitle(const string &title) {
    //��titleת��Ϊc����ַ�������
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
