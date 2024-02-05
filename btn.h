//
// Created by ASinclair on 2022/6/19.
//

#ifndef PARKSYSDESIGN_BTN_H
#define PARKSYSDESIGN_BTN_H
#include"basic.h"
#include"config.h"

class btn :public basic{
public:
    btn(const std::string &t,int x=0, int y=0, int w=195 ,int h=30);
    void show() override;
    bool isin(); //判断鼠标是不是在当前按钮上
    bool isclicked();//判断是否点击
    void eventloop(const ExMessage &tmsg);

    void setBKC(COLORREF c);
    void setHoverColor(COLORREF c);

private:
    std::string text;
    ExMessage msg;
    COLORREF curr ;
    COLORREF normal = RGB(245,245,245);
    COLORREF hover = RGB(220,220,220);

};


#endif //PARKSYSDESIGN_BTN_H
