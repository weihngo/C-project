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
    cout << "*************欢迎使用职工管理系统*************" << endl;
    cout << "************** 0.退出管理程序 **************" << endl;
    cout << "************** 1.增加职工信息 **************" << endl;
    cout << "************** 2.显示职工信息 **************" << endl;
    cout << "************** 3.删除离职职工 **************" << endl;
    cout << "************** 4.修改职工信息 **************" << endl;
    cout << "************** 5.查找职工信息 **************" << endl;
    cout << "************** 6.按照编号排序 **************" << endl;
    cout << "************** 7.清空所有文档 **************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}

workManager::workManager() {
    ifstream ifs;
    ifs.open(filename,ios::in);
    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }
    int num = this->get_EmpNum();
    cout << "文件内职工人数为：" << num << endl;
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
    cout << "请输入需要添加职工数量：";
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0){
        int new_size = this->m_EmpNum + addNum;
        Person ** newSpace = new Person*[new_size];
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
            cout << "表中已有 " << this->m_EmpNum << " 个职工" << endl;
        }
        for(int i = this->m_EmpNum; i < new_size; i++){
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i+1 << " 个职工的编号" << endl;
            cin >> id;
            cout << "请输入第 " << i+1 << " 个职工的姓名" << endl;
            cin >> name;
            cout << "请输入第 " << i+1 << " 个职工所属部门" << endl
                << "1.老板 2.经理 3.普通职员" << endl;
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
                cout << "输入的所属部门有误，请重新输入" << endl;
                i--;
                continue;
            }
            cout << "添加成功" << endl;
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
        cout << "列表为空，请先添加后显示" << endl;
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
    cout << "无法查找到该职员" << endl;
    return -1;
}

void workManager::deleteEmp(){
    if(this->m_EmpNum == 0){
        cout << "列表为空，请先添加后再删除" << endl;
        return;
    }
    cout << "请输入你要删除的职员的编号" << endl;
    int id;
    cin >> id;
    int new_id = s_findEmp(id);
    if (new_id == -1){
        return;
    }
    this->m_EmpArray[new_id]->showInfo();
    cout << "根据编号查找到该职员信息，确定删除吗？ 1：是 0：否" << endl;
    int temp;
    cin >> temp;
    switch (temp) {
        case 0:
            cout << "取消删除" << endl;
            return;
        case 1:
            delete this->m_EmpArray[new_id];
            for (int i = new_id; i < this->m_EmpNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpArray[m_EmpNum - 1] = NULL;
            this->m_EmpNum -= 1;
            cout << "删除成功" << endl;
            this->save();
            break;
        default:
            cout << "输入选择有误，删除失败" << endl;
            break;
    }
}

void workManager::editEmp(){
    if(this->m_EmpNum == 0){
        cout << "列表为空，请先添加后再修改" << endl;
        return;
    }
    cout << "请输入你要修改的职员的编号：" << endl;
    int id;
    cin >> id;
    int array_id = s_findEmp(id);
    if (array_id == -1){
        return;
    }
    this->m_EmpArray[array_id]->showInfo();
    cout << "根据编号查找到该职员信息，确定进行修改吗？ 1：是 0：否" << endl;
    int temp;
    cin >> temp;
    switch (temp) {
        case 0:
            cout << "取消修改" << endl;
            break;
        case 1:
        {
            int new_id;
            string new_name;
            int new_dSelect;
            Person * p = NULL;
            cout << "请输入修改后的编号" << endl;
            cin >> new_id;
            cout << "请输入修改后的姓名" << endl;
            cin >> new_name;
            cout << "请输入修改后的职工所属部门" << endl
                 << "1.老板 2.经理 3.普通职员" << endl;
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
                cout << "输入的所属部门有误，修改失败" << endl;
                break;
            }
            this->m_EmpArray[array_id] = p;
            this->save();
            cout << "修改成功" << endl;
            break;
        }
        default:
            cout << "输入选择有误，修改失败" << endl;
            break;
    }
}

void workManager::findEmp() {
    if(this->m_EmpNum == 0){
        cout << "列表为空，请先添加后再查找" << endl;
        return;
    }
    cout << "请输入你要查找的职员的编号：" << endl;
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
        cout << "列表为空，请先添加后再查找" << endl;
        return;
    }
    int select = 0;
    cout << "请选择根据编号排序还是姓名排序：编号（0），姓名（1）" << endl;
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
            cout << "您输入的选项有误，排序失败" << endl;
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
    cout << "欢迎下次使用" << endl;
}