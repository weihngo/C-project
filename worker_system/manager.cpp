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
    cout << "ְ����ţ�" << this->m_id
         << "\tְ�����ƣ�" << this->m_name
         << "\tְ����λ��" << this->getDeptName()
         << "\t��λְ��" << "����ϰ彻��������"
         << endl;

}
string manager::getDeptName(){
    return string("����");
}
