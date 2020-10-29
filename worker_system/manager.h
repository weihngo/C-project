//
// Created by lwh on 2020/10/25.
//

#ifndef TEXT01_MANAGER_H
#define TEXT01_MANAGER_H
#include <iostream>
#include "Person.h"

class manager : public Person {
public:
    manager(int id, string name, int did);
    ~manager();

    void showInfo();
    string getDeptName();

};


#endif //TEXT01_MANAGER_H
