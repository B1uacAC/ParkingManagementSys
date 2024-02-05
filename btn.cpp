//
// Created by ASinclair on 2022/6/19.
//

#include "btn.h"

btn::btn(const std::string &t, int x, int y, int w, int h): basic(x,y,w,h),text(t) {

}

void btn::show() {
        setfillcolor(curr);
        ::fillroundrect(m_x,m_y,m_w+m_x,m_h+m_y,10,10);
    settextcolor(BLACK);
    int tx = m_x+(m_w - textwidth(text.c_str()))/2;
    int ty = m_y+(m_h - textheight(text.c_str()))/2;
        //ÏÔÊ¾ÎÄ×Ö
        ::outtextxy(tx,ty,text.c_str());
}

bool btn::isin() {
    if(msg.x>=m_x && msg.x<=m_x+m_w && msg.y >=m_y&&msg.y<=m_y+m_h){
          return true;
    }
    return false;
}

bool btn::isclicked() {
    if(isin()){
        if(msg.message ==WM_LBUTTONDOWN){
            return true;
        }
    }
    return false;
}

void btn::eventloop(const ExMessage &tmsg) {
     msg = tmsg;
     if(!isin()){
         curr = normal;
     }else{
         curr = hover;
     }
}

void btn::setBKC(COLORREF c) {
  normal = c;

}

void btn::setHoverColor(COLORREF c) {
   hover = c;
}
