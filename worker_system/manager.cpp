//
// Created by lwh on 2020/10/25.
//

#include "manager.h"
manager::manager(int id, string name, int did) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}

manager::~manager() {

}

void manager::showInfo(){
    cout << "职工编号：" << this->m_id
         << "\t职工名称：" << this->m_name
         << "\t职工岗位：" << this->getDeptName()
         << "\t岗位职责：" << "完成老板交给的任务"
         << endl;

}
string manager::getDeptName(){
    return string("经理");
}
