//
// Created by lwh on 2020/10/25.
//

#include "workManager.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"
#define filename "data.txt"

void workManager::showMenu() {
    cout << "******************************************" << endl;
    cout << "*************��ӭʹ��ְ������ϵͳ*************" << endl;
    cout << "************** 0.�˳�������� **************" << endl;
    cout << "************** 1.����ְ����Ϣ **************" << endl;
    cout << "************** 2.��ʾְ����Ϣ **************" << endl;
    cout << "************** 3.ɾ����ְְ�� **************" << endl;
    cout << "************** 4.�޸�ְ����Ϣ **************" << endl;
    cout << "************** 5.����ְ����Ϣ **************" << endl;
    cout << "************** 6.���ձ������ **************" << endl;
    cout << "************** 7.��������ĵ� **************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}

workManager::workManager() {
    ifstream ifs;
    ifs.open(filename,ios::in);
    if (!ifs.is_open()){
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "�ļ�Ϊ��" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }
    int num = this->get_EmpNum();
    cout << "�ļ���ְ������Ϊ��" << num << endl;
    this->m_EmpNum = num;
    this->m_EmpArray = new Person*[this->m_EmpNum];
    this->init_Emp();
    this->showEmp();
}

int workManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(filename, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> did){
        num++;
    }
    return num;
}

void workManager::init_Emp() {
    ifstream ifs;
    ifs.open(filename, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> did){
        Person * p = NULL;
        if (did == 1){
            p = new employee(id, name, did);
        }
        else if (did == 2){
            p = new manager(id, name, did);
        }
        else{
            p = new boss(id, name, did);
        }
        this->m_EmpArray[num++] = p;
    }

}

workManager::~workManager() {
    if (this->m_EmpArray != NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void workManager::Add_Emp() {
    cout << "��������Ҫ���ְ��������";
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0){
        int new_size = this->m_EmpNum + addNum;
        Person ** newSpace = new Person*[new_size];
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
            cout << "�������� " << this->m_EmpNum << " ��ְ��" << endl;
        }
        for(int i = this->m_EmpNum; i < new_size; i++){
            int id;
            string name;
            int dSelect;

            cout << "������� " << i+1 << " ��ְ���ı��" << endl;
            cin >> id;
            cout << "������� " << i+1 << " ��ְ��������" << endl;
            cin >> name;
            cout << "������� " << i+1 << " ��ְ����������" << endl
                << "1.�ϰ� 2.���� 3.��ְͨԱ" << endl;
            cin >> dSelect;
            if(dSelect == 1){
                newSpace[i] = new boss(id, name, dSelect);
            }
            else if(dSelect == 2){
                newSpace[i] = new manager(id, name, dSelect);
            }
            else if(dSelect == 3){
                newSpace[i] = new employee(id, name, dSelect);
            }
            else{
                cout << "���������������������������" << endl;
                i--;
                continue;
            }
            cout << "��ӳɹ�" << endl;
        }
        this->m_fileisempty = false;
        this->m_EmpNum = new_size;
        delete [] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->save();
    }
}

void workManager::showEmp() {
    if(this->m_EmpNum == 0){
        cout << "�б�Ϊ�գ�������Ӻ���ʾ" << endl;
        return;
    }
    for(int i = 0; i < this->m_EmpNum; i++){
        this->m_EmpArray[i]->showInfo();
    }
}

int workManager::s_findEmp(int id) {
    for (int i = 0; i < this->m_EmpNum; i++){
        if (this->m_EmpArray[i]->m_id == id){
            return i;
        }
    }
    cout << "�޷����ҵ���ְԱ" << endl;
    return -1;
}

void workManager::deleteEmp(){
    if(this->m_EmpNum == 0){
        cout << "�б�Ϊ�գ�������Ӻ���ɾ��" << endl;
        return;
    }
    cout << "��������Ҫɾ����ְԱ�ı��" << endl;
    int id;
    cin >> id;
    int new_id = s_findEmp(id);
    if (new_id == -1){
        return;
    }
    this->m_EmpArray[new_id]->showInfo();
    cout << "���ݱ�Ų��ҵ���ְԱ��Ϣ��ȷ��ɾ���� 1���� 0����" << endl;
    int temp;
    cin >> temp;
    switch (temp) {
        case 0:
            cout << "ȡ��ɾ��" << endl;
            return;
        case 1:
            delete this->m_EmpArray[new_id];
            for (int i = new_id; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpArray[m_EmpNum - 1] = NULL;
            this->m_EmpNum -= 1;
            cout << "ɾ���ɹ�" << endl;
            this->save();
            break;
        default:
            cout << "����ѡ������ɾ��ʧ��" << endl;
            break;
    }
}

void workManager::editEmp(){
    if(this->m_EmpNum == 0){
        cout << "�б�Ϊ�գ�������Ӻ����޸�" << endl;
        return;
    }
    cout << "��������Ҫ�޸ĵ�ְԱ�ı�ţ�" << endl;
    int id;
    cin >> id;
    int array_id = s_findEmp(id);
    if (array_id == -1){
        return;
    }
    this->m_EmpArray[array_id]->showInfo();
    cout << "���ݱ�Ų��ҵ���ְԱ��Ϣ��ȷ�������޸��� 1���� 0����" << endl;
    int temp;
    cin >> temp;
    switch (temp) {
        case 0:
            cout << "ȡ���޸�" << endl;
            break;
        case 1:
        {
            int new_id;
            string new_name;
            int new_dSelect;
            Person * p = NULL;
            cout << "�������޸ĺ�ı��" << endl;
            cin >> new_id;
            cout << "�������޸ĺ������" << endl;
            cin >> new_name;
            cout << "�������޸ĺ��ְ����������" << endl
                 << "1.�ϰ� 2.���� 3.��ְͨԱ" << endl;
            cin >> new_dSelect;
            if (new_dSelect == 1) {
                p = new boss(new_id, new_name, new_dSelect);
            }
            else if (new_dSelect == 2) {
                p = new manager(new_id, new_name, new_dSelect);
            }
            else if (new_dSelect == 3) {
                p = new employee(new_id, new_name, new_dSelect);
            }
            else {
                cout << "������������������޸�ʧ��" << endl;
                break;
            }
            this->m_EmpArray[array_id] = p;
            this->save();
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        default:
            cout << "����ѡ�������޸�ʧ��" << endl;
            break;
    }
}

void workManager::findEmp() {
    if(this->m_EmpNum == 0){
        cout << "�б�Ϊ�գ�������Ӻ��ٲ���" << endl;
        return;
    }
    cout << "��������Ҫ���ҵ�ְԱ�ı�ţ�" << endl;
    int id;
    cin >> id;
    int array_id = s_findEmp(id);
    if (array_id == -1){
        return;
    }
    this->m_EmpArray[array_id]->showInfo();
}

void workManager::swap(int i, int j) {
    Person *p = this->m_EmpArray[i];
    this->m_EmpArray[i] = this->m_EmpArray[j];
    this->m_EmpArray[j] = p;
}

void workManager::sortEmp() {
    if(this->m_EmpNum == 0){
        cout << "�б�Ϊ�գ�������Ӻ��ٲ���" << endl;
        return;
    }
    int select = 0;
    cout << "��ѡ����ݱ���������������򣺱�ţ�0����������1��" << endl;
    cin >> select;
    switch(select){
        case 0:
            for (int i = 0; i < this->m_EmpNum; i++){
                for (int j = i+1; j < this->m_EmpNum; j++){
                    if(this->m_EmpArray[i]->m_id > this->m_EmpArray[j]->m_id){
                        swap(i, j);
                    }
                }
            }
            break;
        case 1:
            for (int i = 0; i < this->m_EmpNum; i++){
                for (int j = i+1; j < this->m_EmpNum; j++){
                    if(this->m_EmpArray[i]->m_name.compare(this->m_EmpArray[j]->m_name) < 0){
                        swap(i, j);
                    }
                }
            }
            break;
        default:
            cout << "�������ѡ����������ʧ��" << endl;
            return;
    }
    this->save();
}

void workManager::clearEmp() {
    ofstream ofs;
    ofs.open(filename, ios::out);
    ofs.close();
    if (this->m_EmpArray != NULL){
        delete [] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
    this->m_EmpNum = 0;
    this->m_fileisempty = true;
}

void workManager::save(){
    ofstream ofs;
    ofs.open(filename, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_id << "  "
            << this->m_EmpArray[i]->m_name << "  "
            << this->m_EmpArray[i]->m_deptid << endl;
    }
    ofs.close();
}

void workManager::exitsystem() {
    cout << "��ӭ�´�ʹ��" << endl;
}