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
    cout << "ְ����ţ�" << this->m_id
        << "\tְ�����ƣ�" << this->m_name
        << "\tְ����λ��" << this->getDeptName()
        << "\t��λְ��" << "��ɾ�����������"
        << endl;

}
string employee::getDeptName(){
    return string("Ա��");
}