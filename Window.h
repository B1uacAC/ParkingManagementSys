//
// Created by ASinclair on 2022/6/19.
//

#ifndef PARKSYSDESIGN_WINDOW_H
#define PARKSYSDESIGN_WINDOW_H
#include"easyx.h"
#include "graphics.h"
#include<string>
#include"btn.h"

using namespace std;
class Window {
public:
    //window操作
    Window(int w, int h, int f);
    int exec();
    void setWindowTitle(const string &title);
    static int width();
    static int height();
    static void clear();
    static void beginDraw();
    static void flushDraw();
    static void endDraw();

    //按键操作
    inline static bool hasMeg(){return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY);}//判断是否有消息
    inline static CONST ExMessage getMsg(){return m_msg;}//用easyx获取消息

private:
    HWND m_handle; //窗口句柄 其中HWND为一个结构体指针
    inline static ExMessage m_msg; //input 消息


};


#endif //PARKSYSDESIGN_WINDOW_H
