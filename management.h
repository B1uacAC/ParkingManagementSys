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
#include<sstream> //����string��stream���ϵĿ�
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
    //��������
    void run();
    //չʾ�û���¼��
    void display();
    //���user
    void add();
    //ɾ��user
    void del();
    // change pw
    void modify();


    //displayģ��
    void display_action(int &i);


    void eventloop();
    void readfile(const string &thisurl);
    void savefile();



    void drawBK();//���ñ���ͼ

public://����
    AVLtree<user> users;
    int device_num = 0;
    static int op ;
private://
    ExMessage msg;
    IMAGE bk;
    vector<btn*>  menu_btn;
    string m_header = "�û��˺�          �û�����";
private://table����
    table *m_showTable;
    string url = "data\\users.txt";
};
