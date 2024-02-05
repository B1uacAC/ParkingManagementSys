//
// Created by ASinclair on 2022/6/19.
//
#include"management.h"
int management::menu() {
   //给run中返回一个可操作值当作choice

   for(int i=0;i<menu_btn.size();i++){
       menu_btn[i]->show();
       menu_btn[i]->eventloop(msg);
       if(menu_btn[i]->isclicked()){
            return i;
       }
   }
   return Menu;

}

void management::run() {
    //获取菜单返回
    op = Menu;

    readfile(url);
    Window::beginDraw();

    while(1){
        Window::clear();
        drawBK();
//        eventloop();
        //如果有消息则获取消息
        if(Window::hasMeg()){
            msg = Window::getMsg();
            switch(msg.message){
                case WM_KEYDOWN:
                    if(msg.vkcode == VK_ESCAPE){
                        op = Menu;
                    }
                    break;
                default:
                    break;
          }
        }

         switch(op){

             case management::Menu:
                 op = menu();
                 break;
             case management::Display:
                 display();
                 break;
             case management::Add:
                 add();
                 break;
             case management::Del:
                 del();
                 break;
             case management::Modify:
                 modify();
                 break;
            default:
                 savefile();
                 exit(666);
        }

        Window::flushDraw();
    }
    Window::endDraw();
}



void management::display() {
    char buf1[30];
    bool flag = true;
    while(flag){
        InputBox(buf1,30,"请输入你要登录的账号");
        if(buf1 == "") {
            op = Menu;
            return;
        }
        user temp(buf1, "test");
        AVLnode<user> *current = users.root;
        while(current!= nullptr){
            if(current->data.ac_equal(temp)){
                break;
            }else if(current->data>temp){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        if(current == nullptr) { outtextxy(400,400,"账号不存在");}
        char buf2[30];
        InputBox(buf2,30,"请输入密码");
        temp.changePW(buf2);
        AVLnode<user> *judge = users.search(temp,users.root);
        if(judge != nullptr){
            outtextxy(400,400,"登录成功");
            cout<<"success"<<endl;
            flag = false;
        }else{
            outtextxy(400,400,"登陆失败");
            cout<<"fail"<<endl;
        }


    }
    op = Menu;
    return;
}

void management::add() {
    char buf1[30] = "";
    InputBox(buf1, 30, "请输入需要注册的账号:");
    string ac = buf1;
    if(buf1 == "") {
        op = Menu;
        return;
    }
    user temp(buf1, "test");
    AVLnode<user> *current = users.root;
    while(current!= nullptr){
        if(current->data.ac_equal(temp)){
            op = Menu;
            cout<<"existed"<<endl;
            return;
        }else if(current->data>temp){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    InputBox(buf1, 30, "请输入密码");
    temp.changePW(buf1);
    users.root = users.insert(temp, users.root);
    op = Menu;
    users.OrderPrint(users.root);
    return;
}

void management::del() {
    int f=0;
    char buf1[30] = "";
    InputBox(buf1, 30, "请输入所要删除的账号：");
    string ac_ = buf1;
    InputBox(buf1, 30 ,"请输入账户密码:");
    string pw_ = buf1;
    user temp(ac_ , pw_);
    AVLnode<user> *obj = users.search(temp,users.root);
    if(obj == nullptr){
        op = Menu;
        return;
    }
    users.root = users.del(temp, users.root);
    op = Menu;
    users.OrderPrint(users.root);
    return;
}

void management::modify() {
    char buf1[30] = "";
    InputBox(buf1,30,"请输入你要修改密码的账户：");
    char buf2[30]="";
    InputBox(buf2,30,"请输入原账户密码：");
    user temp(buf1,buf2);
    AVLnode<user> *obj = users.search(temp,users.root);
    if(obj == nullptr){
        cout<<"fail"<<endl;
       op = Menu;
       return;
    }
    InputBox(buf2,30,"请输入新密码：");
    obj->data.changePW(buf2);
    cout<<"change!"<<endl;
    op = Menu;
    return;
}


void management::drawBK() {
::putimage(0,0,&bk);
}

management::management() {
::loadimage(&bk,"D:/programming_related/ParkSysDesign/images/bk.png",Window::width(),Window::height());
//菜单按钮初始化
    settextstyle(26,8,_T("微软雅黑"));
//
    menu_btn.push_back(new btn("用户登录"));
    menu_btn.push_back(new btn("添加用户"));
    menu_btn.push_back(new btn("删除用户"));
    menu_btn.push_back(new btn("修改用户密码"));
    menu_btn.push_back(new btn("退出"));
    for(int i=0;i<menu_btn.size();i++){
        menu_btn[i]->setsize(250,50);
        int bx = (Window::width() - menu_btn[i]->width())/2;
        int vspace = (Window::height()- menu_btn.size()*menu_btn[i]->height())/2;
        int by = i * menu_btn[i]->height()+vspace;
        menu_btn[i]->move(bx,by);
    }

    //展示模块按钮


    //初始化table
    m_showTable = new table;
    m_showTable->setRowCount(16);

    m_showTable->setHeader(management::m_header);
    m_showTable->move(100,100);
}

void management::eventloop() {
  m_showTable->show();
}

void management::readfile(const string &thisurl) {
     fstream read(url,ios::in);
     if(!read.is_open()){
         cout<<"open error!"<<endl;
         return;
     }
     //对第一个元素进行处理
     string buf;
     string info[2];
     int j=0;
     getline(read,buf);
     if(buf=="") return;
     for(int i=0;i<buf.length();i++){
         if(buf[i]==','){
             j++;
             continue;
         }
         info[j]+=buf[i];
     }
     user temp(info[0],info[1]);
     users.root = users.insert(temp,users.root);
     while(!read.eof()){
         j = 0;
         info[0]=info[1]=info[2]="";
         getline(read,buf);
         for(int i=0;i<buf.length();i++){
             if(buf[i]==','){
                 j++;
                 continue;
             }
             info[j]+=buf[i];
         }
         user temp(info[0],info[1]);
         users.root = users.insert(temp,users.root);
         device_num++;
     }
     users.OrderPrint(users.root);
     read.close();
}

void management::savefile() {

    fstream outfile;
    outfile.open(url,ios::out);
    users.outFile(outfile, users.root);
    outfile.close();
}

void management::display_action(int &i) {


}
int management::op = Menu;

