#include "XiTong.h"
void XiTong()
{
    cout << "      ******************************************" << endl;
    cout << "                   С����ҵ����ϵͳ             " << endl;
    cout << "      ******************************************" << endl;
    cout << "              **************************" << endl;
    cout << "              *   ���˵�����������ʾ�� *" << endl;
    cout << "              *     1��ҵ������        *" << endl;
    cout << "              *     2����ҵ��Ա����    *" << endl;
    cout << "              *     3�����ù���      ��*" << endl;
    cout << "              *     4��ͣ������        *" << endl;
    cout << "              *     5���˳�ϵͳ        *" << endl;
    cout << "              **************************" << endl;
    cout << "               ����������ָ�����֣�1~5��" << endl;
    cout << "?";
    char Choice;
    do
    {
        cin >> Choice;
        switch (Choice) //�ж�ָ��
        {
        case '1': //ҵ������
            break;
        case '2': //��ҵ��Ա����
            break;
        case '3': //���ù���
            break;
        case '4': //ͣ������
            TingChe();
            break;
        case '5': //�˳�ϵͳ
            return;
        default:
            cout << "              ����ָ����������������" << endl;
        }
    } while (1);
}