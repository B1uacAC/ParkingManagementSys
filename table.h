//
// Created by ASinclair on 2022/6/23.
//

#ifndef PARKSYSDESIGN_TABLE_H
#define PARKSYSDESIGN_TABLE_H
#include"basic.h"
#include<iostream>
#include<string>
#include"config.h"
#include<algorithm>
#include "user.h"
#include "AVLtree.h"

class table :public basic{
public:
    table(int row = 0,int col = 0);
    void setRowCount(int row);
    void setColCount(int col);
    void setHeader(const std::string &header);

    void show() ;
    void drawTableGrid();
    void drawTableData(int i,AVLtree<user> &tree);



public:



private:
    int m_rows;
    int m_cols;

    int m_gridW;
    int m_gridH;


    std::string m_header;
};


#endif //PARKSYSDESIGN_TABLE_H
