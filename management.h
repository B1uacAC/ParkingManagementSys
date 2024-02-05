//
// Created by ASinclair on 2022/6/14.
//

#ifndef PARKSYSDESIGN_MANAGEMENT_H
#define PARKSYSDESIGN_MANAGEMENT_H

#endif //PARKSYSDESIGN_MANAGEMENT_H
#pragma once
#include<iostream>
#include<string>
#include"easyx.h"
#include"graphics.h"
#include<conio.h>
#include"Window.h"
#include<fstream>
#include<vector>
#include"btn.h"
#include"table.h"
#include<sstream> //用于string在stream流上的库
using namespace std;

class management{
public:
    enum Operator{
        Display,
        Add,
        Del,
        Modify,
        Menu = 66,
    };
    management();

    int menu();
    //启动函数
    void run();
    //展示用户登录并
    void display();
    //添加user
    void add();
    //删除user
    void del();
    // change pw
    void modify();


    //display模块
    void display_action(int &i);


    void eventloop();
    void readfile(const string &thisurl);
    void savefile();



    void drawBK();//设置背景图

public://数据
    AVLtree<user> users;
    int device_num = 0;
    static int op ;
private://
    ExMessage msg;
    IMAGE bk;
    vector<btn*>  menu_btn;
    string m_header = "用户账号          用户密码";
private://table数据
    table *m_showTable;
    string url = "data\\users.txt";
};
