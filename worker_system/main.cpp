#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "workManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

//ְ������ϵͳ

int main(){
    workManager user;
    int input;
    while(1){
        user.showMenu();
        cout << "����������ѡ��";
        cin >> input;
        switch (input) {
            case 0: //�˳�����
                user.exitsystem();
                system("pause");
                system("cls");
                break;
            case 1: //����
                user.Add_Emp();
                system("pause");
                system("cls");
                break;
            case 2: //��ʾ
                user.showEmp();
                system("pause");
                system("cls");
                break;
            case 3: //ɾ��
                user.deleteEmp();
                system("pause");
                system("cls");
                break;
            case 4: //�޸�
                user.editEmp();
                system("pause");
                system("cls");
                break;
            case 5: //����
                user.findEmp();
                system("pause");
                system("cls");
                break;
            case 6: //����
                user.sortEmp();
                system("pause");
                system("cls");
                break;
            case 7: //���
                user.clearEmp();
                system("pause");
                system("cls");
                break;
            default:
                cout << "����Ĳ����������������룺" << endl;
                break;
        }
        if (input == 0){
            break;
        }
    }

    return 0;
}