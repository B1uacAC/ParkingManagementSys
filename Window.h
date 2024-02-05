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
    //window����
    Window(int w, int h, int f);
    int exec();
    void setWindowTitle(const string &title);
    static int width();
    static int height();
    static void clear();
    static void beginDraw();
    static void flushDraw();
    static void endDraw();

    //��������
    inline static bool hasMeg(){return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY);}//�ж��Ƿ�����Ϣ
    inline static CONST ExMessage getMsg(){return m_msg;}//��easyx��ȡ��Ϣ

private:
    HWND m_handle; //���ھ�� ����HWNDΪһ���ṹ��ָ��
    inline static ExMessage m_msg; //input ��Ϣ


};


#endif //PARKSYSDESIGN_WINDOW_H
