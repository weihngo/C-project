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
    cout << "ְ����ţ�" << this->m_id
         << "\tְ�����ƣ�" << this->m_name
         << "\tְ����λ��" << this->getDeptName()
         << "\t��λְ��" << "������������"
         << endl;

}
string boss::getDeptName(){
    return string("�ϰ�");
}