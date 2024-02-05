//
// Created by ASinclair on 2022/12/8.
//
#include "user.h"

void user::changePW(string pw) {
    this->password = pw;
}

bool user::operator<(user right) {
    if(this->account < right.account){
        return true;
    }
    return false;
}

bool user::operator>(user right) {
    if(this->account > right.account){
        return true;
    }
    return false;
}

string user::getPW() {
    return password;
}

string user::getAC() {
    return account;
}

bool user::operator==(user right) {
    if(this->account == right.account && this->password == right.password){
        return true;
    }
    return false;
}

ostream &operator<<(ostream &out, user temp) {
    out<<temp.getAC()<<","<<temp.getPW()<<endl;
    return out;
}

bool user::ac_equal(user right) {
    if(account == right.account) return true;
    return false;
}
