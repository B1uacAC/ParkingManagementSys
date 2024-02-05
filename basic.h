//
// Created by ASinclair on 2022/6/19.
//

#ifndef PARKSYSDESIGN_BASIC_H
#define PARKSYSDESIGN_BASIC_H


class basic {
public:
    basic(int x,int y,int w,int h);
    int width();
    int height();
    void setsize(int w,int h);

    int getx();
    int gety();
    void move(int x,int y);
    virtual void show() = 0;

protected:
    int m_x,m_y,m_w,m_h;
};


#endif //PARKSYSDESIGN_BASIC_H
