//
// Created by lwh on 2020/10/25.
//

#ifndef TEXT01_BOSS_H
#define TEXT01_BOSS_H
#include "Person.h"

class boss : public Person {
public:
    boss(int id, string name, int did);
    ~boss();

    void showInfo();
    string getDeptName();
};


#endif //TEXT01_BOSS_H
