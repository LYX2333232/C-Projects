#include "XiTong.h"
void XiTong()
{
    cout << "      ******************************************" << endl;
    cout << "                   小区物业管理系统             " << endl;
    cout << "      ******************************************" << endl;
    cout << "              **************************" << endl;
    cout << "              *   主菜单命令如下所示： *" << endl;
    cout << "              *     1、业主管理        *" << endl;
    cout << "              *     2、物业人员管理    *" << endl;
    cout << "              *     3、费用管理      　*" << endl;
    cout << "              *     4、停车管理        *" << endl;
    cout << "              *     5、退出系统        *" << endl;
    cout << "              **************************" << endl;
    cout << "               请输入您的指令数字（1~5）" << endl;
    cout << "?";
    char Choice;
    do
    {
        cin >> Choice;
        switch (Choice) //判断指令
        {
        case '1': //业主管理
            break;
        case '2': //物业人员管理
            break;
        case '3': //费用管理
            break;
        case '4': //停车管理
            TingChe();
            break;
        case '5': //退出系统
            return;
        default:
            cout << "              输入指令有误，请重新输入" << endl;
        }
    } while (1);
}