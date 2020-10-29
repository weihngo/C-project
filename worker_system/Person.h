//
// Created by lwh on 2020/10/25.
//

#ifndef TEXT01_PERSON_H
#define TEXT01_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    int m_id;
    string m_name;
    int m_deptid;

    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;

};


#endif //TEXT01_PERSON_H
