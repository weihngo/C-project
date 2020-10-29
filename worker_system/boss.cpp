//
// Created by lwh on 2020/10/25.
//

#include "boss.h"

boss::boss(int id, string name, int did) {
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}

boss::~boss() {

}

void boss::showInfo(){
    cout << "职工编号：" << this->m_id
         << "\t职工名称：" << this->m_name
         << "\t职工岗位：" << this->getDeptName()
         << "\t岗位职责：" << "管理所有事务"
         << endl;

}
string boss::getDeptName(){
    return string("老板");
}