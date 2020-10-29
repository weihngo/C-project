#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "workManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

//职工管理系统

int main(){
    workManager user;
    int input;
    while(1){
        user.showMenu();
        cout << "请输入您的选择：";
        cin >> input;
        switch (input) {
            case 0: //退出程序
                user.exitsystem();
                system("pause");
                system("cls");
                break;
            case 1: //增加
                user.Add_Emp();
                system("pause");
                system("cls");
                break;
            case 2: //显示
                user.showEmp();
                system("pause");
                system("cls");
                break;
            case 3: //删除
                user.deleteEmp();
                system("pause");
                system("cls");
                break;
            case 4: //修改
                user.editEmp();
                system("pause");
                system("cls");
                break;
            case 5: //查找
                user.findEmp();
                system("pause");
                system("cls");
                break;
            case 6: //排序
                user.sortEmp();
                system("pause");
                system("cls");
                break;
            case 7: //清空
                user.clearEmp();
                system("pause");
                system("cls");
                break;
            default:
                cout << "输入的操作有误，请重新输入：" << endl;
                break;
        }
        if (input == 0){
            break;
        }
    }

    return 0;
}