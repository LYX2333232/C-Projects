#include <iostream>
#include "XiTong.h"
using namespace std;
int main()
{
    cout << "      ******************************************" << endl;
    cout << "               欢迎登录小区物业管理系统         " << endl;
    cout << "      ******************************************" << endl;
    //登录管理
    cout << "      密码正确!请输入下一步指令:" << endl;
    cout << "              *************************" << endl;
    cout << "              *     0、修改密码       *" << endl;
    cout << "              *     1、进入系统       *" << endl;
    cout << "              *     2、退出系统       *" << endl;
    cout << "              *************************\n\n";
    char Choice;
    do
    {
        cout << "     请输入您的指令(0~2):" << endl;
        cin >> Choice;
        switch (Choice)
        {
        case '0':
            cout << 0; //修改密码
            break;
        case '1':
            XiTong(); //进入系统
        case '2':     //退出系统
        {
            cout << "     谢谢使用本小区物业管理系统!   " << endl;
            cout << "     See you next time!" << endl;
            return 0;
        }
        default:
            cout << "     输入指令有误，请重新输入:" << endl;
            break;
        }
        break;
    } while (Choice < 0 || Choice > 2); //重新输入密码
    return 0;
}