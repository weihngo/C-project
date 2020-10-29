//
// Created by lwh on 2020/10/25.
//

#ifndef TEXT01_EMPLOYEE_H
#define TEXT01_EMPLOYEE_H

#include <iostream>
#include "Person.h"
using namespace std;

class employee : public Person {
public:
    employee(int id, string name, int did);
    ~employee();

    void showInfo();
    string getDeptName();
};


#endif //TEXT01_EMPLOYEE_H
