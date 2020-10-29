//
// Created by lwh on 2020/10/25.
//

#ifndef TEXT01_WORKMANAGER_H
#define TEXT01_WORKMANAGER_H

#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

class workManager {
public:
    //记录职工人数
    int m_EmpNum;
    Person ** m_EmpArray;
    bool m_fileisempty;

    workManager();
    ~workManager();

    void showMenu();
    void exitsystem();
    void Add_Emp();
    void showEmp();
    void deleteEmp();
    int s_findEmp(int id);
    void editEmp();
    void findEmp();
    void sortEmp();
    void swap(int i, int j);
    void clearEmp();

    void save();
    int get_EmpNum();
    void init_Emp();

};


#endif //TEXT01_WORKMANAGER_H
