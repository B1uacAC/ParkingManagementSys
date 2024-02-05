//
// Created by ASinclair on 2022/6/23.
//

#include "table.h"
table::table(int row, int col): basic(0,0,0,0),m_cols(col),m_rows(row){

}

void table::setRowCount(int row) {
   m_rows= row;
}

void table::setColCount(int col) {
m_cols=col;
}

void table::show() {

  drawTableGrid();

}

void table::setHeader(const std::string &header) {
    m_header = header;

     int tw = ::textwidth("这个是c++课程设计");
     int th = ::textheight("asdasd");
     m_cols = 2;
     m_gridW = tw;
     m_gridH = th;
}

void table::drawTableGrid() {
//确定表格
    setlinecolor(RGB(	130,130, 130));
//横线
    for(int i = 0;i<m_rows+1;i++){
        line(m_x,m_y+i*m_gridH,m_x+m_cols*m_gridW,m_y+i*m_gridH);
    }
    //竖线
    for(int i=0;i<m_cols+1;i++){
        line(m_x+i*m_gridW,m_y,m_x+i*m_gridW,m_y+m_rows*m_gridH);
    }
}


void table::drawTableData(int i, AVLtree<user> &tree) {
    list<user> user_list;
    //user_list = getInOderList(tree.root,user_list);
    int xt = 0,yt=0;
    list<user>::iterator iter = user_list.begin();
    if(i==0){
        xt = 0;
        while(iter!=user_list.end()){
            outtextxy(m_x+xt*m_gridW,m_y+yt*m_gridH,(*iter).getAC().c_str());
            xt++;
            outtextxy(m_x+xt*m_gridW,m_y+yt*m_gridH,(*iter).getPW().c_str());
            xt = 0;
            iter++;
        }
    }
}
