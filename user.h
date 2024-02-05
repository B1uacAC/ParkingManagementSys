//
// Created by ASinclair on 2022/12/8.
//

#ifndef PARKSYSDESIGN_USER_H
#define PARKSYSDESIGN_USER_H

#endif //PARKSYSDESIGN_USER_H
#include <string>
#include <iostream>
using namespace std;
class user{
private:
    string account;
    string password;
public:
    user(string ac, string pw):account(ac), password(pw){};
    void changePW(string pw);
    bool operator<( user right);
    bool operator>(user right);
    bool operator==(user right);
    friend  ostream &operator<<(ostream &out, user temp);
    bool ac_equal(user right);
    string getPW();
    string getAC();
};
