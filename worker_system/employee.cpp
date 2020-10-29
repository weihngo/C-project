//
// Created by lwh on 2020/10/25.
//

#include "employee.h"

employee::employee(int id, string name, int did) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}

employee::~employee() {

}

void employee::showInfo(){
    cout << "职工编号：" << this->m_id
        << "\t职工名称：" << this->m_name
        << "\t职工岗位：" << this->getDeptName()
        << "\t岗位职责：" << "完成经理交给的任务"
        << endl;

}
string employee::getDeptName(){
    return string("员工");
}