#include <iostream>
#include "XiTong.h"
using namespace std;
int main()
{
    cout << "      ******************************************" << endl;
    cout << "               ��ӭ��¼С����ҵ����ϵͳ         " << endl;
    cout << "      ******************************************" << endl;
    //��¼����
    cout << "      ������ȷ!��������һ��ָ��:" << endl;
    cout << "              *************************" << endl;
    cout << "              *     0���޸�����       *" << endl;
    cout << "              *     1������ϵͳ       *" << endl;
    cout << "              *     2���˳�ϵͳ       *" << endl;
    cout << "              *************************\n\n";
    char Choice;
    do
    {
        cout << "     ����������ָ��(0~2):" << endl;
        cin >> Choice;
        switch (Choice)
        {
        case '0':
            cout << 0; //�޸�����
            break;
        case '1':
            XiTong(); //����ϵͳ
        case '2':     //�˳�ϵͳ
        {
            cout << "     ллʹ�ñ�С����ҵ����ϵͳ!   " << endl;
            cout << "     See you next time!" << endl;
            return 0;
        }
        default:
            cout << "     ����ָ����������������:" << endl;
            break;
        }
        break;
    } while (Choice < 0 || Choice > 2); //������������
    return 0;
}