#include "TingChe.h"
void Parking::set_Number(string num) //д�복λ��
{
    Number = num;
}
void Parking::set_YeZhu(string o, string t, string i, int s) //д��ҵ����Ϣ
{
    Owner = o;
    Telephone = t;
    ID = i;
    statu = s;
}
void Parking::set_FeiYong(double f) //д����ɷ���
{
    FeiYong = f;
    if (abs(f) > 1e-8)
        FeiYong_statu = 0; //�ɷ�״̬��Ϊδ�ɷ�
    return;
}
void Parking::Submit() //�ɷѳɹ�
{
    FeiYong = 0;
    FeiYong_statu = 1; //��սɷ���Ϣ
    return;
}
void Parking::Clean() //���ҵ����Ϣ
{
    Owner = "NULL";
    Number = "NULL";
    ID = "NULL";
    statu = 2;
}
string Parking::get_Number() //������λ��
{
    return Number;
}
string Parking::get_YeZhu() //����ҵ������
{
    return Owner;
}
double Parking::get_FeiYong() //�������ɷ���
{
    return FeiYong;
}
int Parking::get_FeiYong_statu() //�����ɷ�״̬
{
    return FeiYong_statu;
}
int Parking::get_statu() //������λ״̬
{
    return statu;
}
void Parking::output() //�����λ��Ϣ
{
    cout << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << ID << endl;
}
void Parking::output(fstream &f) //�����λ��Ϣ
{
    f << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << ID << endl;
}
void Parking::JiaoFei_output() //����ɷ���Ϣ
{
    cout << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << JiaoFei_Statu << "\t\t\t\t\t\t\t\t" << JiaoFei << endl;
}
void Parking::JiaoFei_output(fstream &f) //����ɷ���Ϣ
{
    f << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << JiaoFei_Statu << "\t\t\t\t\t\t\t\t" << JiaoFei << endl;
}
int Parking::count = 0; //�ó�ֵ
void SheLiCheWei(int n) //������λ
{
    Parking::count += n;
    Parking *p = NULL, *s = NULL;
    p = new Parking[n];
    int i;
    ofstream Out_Number("Loading.txt", ios::out); //��д�ķ�ʽ��
    for (i = 0; i < n; i++)
    { // iΪ��λ���룬��ǰ�油��0
        if (i < 10)
            Out_Number << "000";
        else if (i < 100)
            Out_Number << "00";
        else if (i < 1000)
            Out_Number << "0";
        Out_Number << i << endl;
    }
    fstream In_Parking("Loading.txt", ios::in); //��д�ķ�ʽ��
    string num;
    for (i = 0; i < n; i++)
    {
        In_Parking >> num;
        p->set_Number(num);
        if (head == NULL)
        {
            head = p;
            s = head;
        }
        else
        {
            s->Next = p;
            s = p;
        }
    }
    delete p;
}
void XiuGai(Parking *x) //�޸���Ϣ
{
    string o, t, i;
    int s;
    cout << "�������µ�ҵ����Ϣ��" << endl;
    cout << "ҵ��������";
    cin >> o;
    cout << "ҵ���绰��";
    cin >> t;
    cout << "ҵ�����֤��";
    cin >> i;
    cout << "��λ����״̬��0���۳� 1������ 2�����ã���";
    cin >> s;
    x->set_YeZhu(o, t, i, s);
    cout << "�޸���Ϣ�ɹ�!" << endl;
    cout << "�µĳ�λ��ϢΪ��" << endl;
    cout << "��λ��  ��λ״̬(0:�۳� 1������ 2������)      ҵ������    ҵ���绰    ҵ�����֤����" << endl;
    x->output();
    return;
}
void Search_CheWei() //����λ����
{
    cout << "������Ҫ���ҵĳ�λ�ţ�" << endl;
    cout << "?";
    string Search;     //����ĳ�λ��
    Parking *x = head; //���ҵ�ָ��
L:
    cin >> Search;
    int q = 0; //�ж��Ƿ��ҵ���λ
    while (x)  //����
    {
        if (x->get_Number().compare(Search) == 0) //�ҵ���λ
        {
            q = 1;
            break;
        }
        else
            x = x->Next;
    }
    if (q == 0)
    {
        cout << "δ���ҵ���Ӧ�ĳ�λ�������ԣ�" << endl;
        goto L;
    }
    else
    {
        cout << "��Ӧ�ĳ�λ��Ϣ��" << endl;
        cout << "��λ��  ��λ״̬(0���۳� 1������ 2������)      ҵ������    ҵ���绰    ҵ�����֤����" << endl;
        x->output();
        cout << endl;
        cout << "              **************************" << endl;
        cout << "              *        �����������     *" << endl;
        cout << "              *      1���޸�ҵ����Ϣ    *" << endl;
        cout << "              *      2�����ҵ����Ϣ    *" << endl;
        cout << "              *      3�����ز���ϵͳ    *" << endl;
        cout << "              *     ������ָ�1-3��   *" << endl;
        int choice;
        do
        {
            cout << "?";
            cin >> choice; //����ָ��
            switch (choice)
            {
            case '1': //�޸�ҵ����Ϣ
                XiuGai(x);
                break;
            case '2': //���ҵ����Ϣ
                x->Clean();
                break;
            case '3': //�����ϼ�
                return;
            default:
                cout << "ָ�����������ԣ�" << endl;
            }
        } while (1);
    }
}
void Search_XingMing() //����������
{
    cout << "������Ҫ���ҵ�ҵ����������" << endl;
    cout << "?";
    string Search;     //�����ҵ������
    Parking *x = head; //���ҵ�ָ��
    int q = 0;         //�ж��Ƿ��ҵ���λ
    cin >> Search;
    while (x) //����
    {
        if (x->get_YeZhu().compare(Search) == 0) //�ҵ���λ
        {
            if (q == 0)
            {
                q = 1;
                cout << "��Ӧ�ĳ�λ��Ϣ��" << endl;
                cout << "��λ��  ��λ״̬(0���۳� 1������ 2������)      ҵ������    ҵ���绰    ҵ�����֤����" << endl;
            }
            x->output(); //�����Ϣ
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "δ���ҵ���Ӧ�ĳ�λ�������ԣ�" << endl;
    }
    return;
}
void Search_Statu() //��״̬����
{
    cout << "������Ҫ���ҵĳ�λ��״̬��0���۳� 1������ 2�����У���" << endl;
    cout << "?";
    int Search;        //����ĳ�λ״̬
    Parking *x = head; //���ҵ�ָ��
    int q = 0;         //�ж��Ƿ��ҵ���λ
    cin >> Search;
    while (x != NULL) //����
    {
        if (x->get_statu() == Search) //�ҵ���λ
        {
            if (q == 0)
            {
                cout << "��Ӧ�ĳ�λ��Ϣ��" << endl;
                cout << "��λ��  ��λ״̬(0���۳� 1������ 2������)      ҵ������    ҵ���绰    ҵ�����֤����" << endl;
                q = 1;
            }
            x->output(); //�����Ϣ
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "δ���ҵ���Ӧ�ĳ�λ�������ԣ�" << endl;
    }
    return;
}
void ChaZhao()
{
    do
    {
        cout << "              ******************************" << endl;
        cout << "              *     ��������ҷ�ʽ��        *" << endl;
        cout << "              *1������λ�Ų��ң�ͬʱ�޸���Ϣ��*" << endl;
        cout << "              *   2����ҵ����������         *" << endl;
        cout << "              *   3������λ״̬����         *" << endl;
        cout << "              *   4������ͣ��ϵͳ����       *" << endl;
        cout << "              *   ������ָ�1-4��         *" << endl;
        cout << "?";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //����λ�Ų���
            Search_CheWei();
            break;
        case '2': //��ҵ����������
            Search_XingMing();
            break;
        case '3': //����λ״̬����
            Search_Statu();
            break;
        case '4': //����ͣ��ϵͳ
            return;
        default:
            cout << "����ָ���������������룡" << endl;
        }
    } while (1);
}
void ZengJia() //���ӳ�λ
{
    cout << "              **************************" << endl;
    cout << "              *     ���������ӵĳ�λ���� *" << endl;
    cout << "?";
    int n;
    cin >> n;          //���������ĳ�λ��
    Parking *x = head; //���ҵ�ָ��
    while (x)
    {
        x = x->Next;
    }
    Parking *p = NULL, *s = NULL;
    int i;
    ofstream Out_Number("Loading.txt", ios::out); //��д�ķ�ʽ��
    for (i = 0; i < n; i++)
    {                               // i��ѭ��
        int q = i + Parking::count; // qΪ��λ�ţ���ǰ�油��0
        if (q < 10)
            Out_Number << "000";
        else if (q < 100)
            Out_Number << "00";
        else if (q < 1000)
            Out_Number << "0";
        Out_Number << q << endl;
    }
    fstream In_Parking("Loading.txt", ios::in); //��д�ķ�ʽ��
    string num;
    for (i = 0; i < n; i++)
    {
        In_Parking >> num;
        p->set_Number(num);
        if (head == NULL)
        {
            head = p;
            s = head;
        }
        else
        {
            s->Next = p;
            s = p;
        }
    }
    delete p;
}

void JiaoFei_XiuGai(Parking *x) //�޸Ľɷ���Ϣ
{
    double f; //�µĴ��ɷ���
    cout << "�������µĴ��ɽ�" << endl;
    cin >> f;
    x->set_FeiYong(f);
    return;
}
void Submit(Parking *x) //����ɷ���Ϣ
{
    x->Submit();
}
void JiaoFei_CheWei() //����λ�Ų���
{
    cout << "������Ҫ���ҵĳ�λ�ţ�" << endl;
    cout << "?";
    string Search;     //����ĳ�λ��
    Parking *x = head; //���ҵ�ָ��
L:
    cin >> Search;
    int q = 0; //�ж��Ƿ��ҵ���λ
    while (x)  //����
    {
        if (x->get_Number().compare(Search) == 0) //�ҵ���λ
        {
            q = 1;
            break;
        }
        else
            x = x->Next;
    }
    if (q == 0)
    {
        cout << "δ���ҵ���Ӧ�ĳ�λ�������ԣ�" << endl;
        goto L;
    }
    else
    {
        cout << "��Ӧ�ĳ�λ��Ϣ��" << endl;
        cout << "��λ��  ��λ״̬(0:�۳� 1������ 2������)      ҵ������    ҵ���绰    �ɷ�״̬��0��δ�ɷ� 1���ѽɷѣ�   ���ɽ��" << endl;
        x->output();
        cout << endl;
        cout << "              **************************" << endl;
        cout << "              *        �����������     *" << endl;
        cout << "              *      1�������ɷ���Ϣ    *" << endl;
        cout << "              *      2������ɷ���Ϣ    *" << endl;
        cout << "              *      3�����ؽɷ�ϵͳ    *" << endl;
        cout << "              *     ������ָ�1-3��   *" << endl;
        int choice;
        do
        {
            cout << "?";
            cin >> choice; //����ָ��
            switch (choice)
            {
            case '1': //�޸�ҵ����Ϣ
                JiaoFei_XiuGai(x);
                break;
            case '2': //����ɷ���Ϣ
                Submit(x);
                break;
            case '3':
                return;
            default:
                cout << "ָ�����������ԣ�" << endl;
            }
        } while (1);
    }
}
void JiaoFei_XingMing() //����������
{
    cout << "������Ҫ���ҵ�ҵ����������" << endl;
    cout << "?";
    string Search;     //�����ҵ������
    Parking *x = head; //���ҵ�ָ��
    int q = 0;         //�ж��Ƿ��ҵ���λ
    cin >> Search;
    while (x) //����
    {
        if (x->get_YeZhu().compare(Search) == 0) //�ҵ���λ
        {
            if (q == 0)
            {
                q = 1;
                cout << "��Ӧ�ĳ�λ��Ϣ��" << endl;
                cout << "��λ��  ��λ״̬(0:�۳� 1������ 2������)      ҵ������    ҵ���绰    �ɷ�״̬��0��δ�ɷ� 1���ѽɷѣ�   ���ɽ��" << endl;
            }
            x->JiaoFei_output(); //�����Ϣ
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "δ���ҵ���Ӧ�ĳ�λ�������ԣ�" << endl;
    }
    return;
}
void JiaoFei_Statu() //���ɷ�״̬����
{
    cout << "������Ҫ���ҵĳ�λ�Ľɷ�״̬��0��δ�ɷ� 1���ѽɷѣ���" << endl;
    cout << "?";
    int Search;        //����ĳ�λ״̬
    Parking *x = head; //���ҵ�ָ��
    int q = 0;         //�ж��Ƿ��ҵ���λ

    cin >> Search;
    while (x != NULL) //����
    {
        if (x->get_FeiYong_statu() == Search) //�ҵ���λ
        {
            if (q == 0)
            {
                cout << "��Ӧ�ĳ�λ��Ϣ��" << endl;
                cout << "��λ��  ��λ״̬(0:�۳� 1������ 2������)      ҵ������    ҵ���绰    �ɷ�״̬��0��δ�ɷ� 1���ѽɷѣ�   ���ɽ��" << endl;
                q = 1;
            }
            x->JiaoFei_output(); //�����Ϣ
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "δ���ҵ���Ӧ�ĳ�λ�������ԣ�" << endl;
    }
    return;
}
void JiaoFei() //
{
    do
    {
        cout << "              ******************************" << endl;
        cout << "              *     ��������ҷ�ʽ��        *" << endl;
        cout << "              *1������λ�Ų��ң�ͬʱ�޸���Ϣ��*" << endl;
        cout << "              *   2����ҵ����������         *" << endl;
        cout << "              *   3�����ɷ�״̬����         *" << endl;
        cout << "              *   4������ͣ��ϵͳ����       *" << endl;
        cout << "              *   ������ָ�1-4��         *" << endl;
        cout << "?";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //����λ�Ų���
            JiaoFei_CheWei();
            break;
        case '2': //��ҵ����������
            JiaoFei_XingMing();
            break;
        case '3': //���ɷ�״̬����
            JiaoFei_Statu();
            break;
        case '4': //����ͣ��ϵͳ
            return;
        default:
            cout << "����ָ���������������룡" << endl;
        }
    } while (1);
}
void CunRu() //�����ݷ���TingChe.txt�ļ���JiaoFei.txt�ļ�
{
    fstream outT("TingChe.txt", ios::out); //��д�ķ�ʽ��
    Parking *p = head;
    cout << "��λ��  ��λ״̬(0:�۳� 1������ 2������)      ҵ������    ҵ���绰    ҵ�����֤����" << endl; //��һ�б�ע
    while (p != NULL)                                                                                       //�����λ����
    {
        p->output(outT);
        p = p->Next;
    }
    outT.close();                          //�ر��ļ�
    fstream outJ("JiaoFei.txt", ios::out); //��д�ķ�ʽ���ļ�
    p = head;
    cout << "��λ��  ��λ״̬(0:�۳� 1������ 2������)      ҵ������    ҵ���绰    �ɷ�״̬��0��δ�ɷ� 1���ѽɷѣ�   ���ɽ��" << endl; //��һ�б�ע
    while (p != NULL)                                                                                                                   //�����λ����
    {
        p->JiaoFei_output(outJ);
        p = p->Next;
    }
    outJ.close(); //�ر��ļ�
    return;
}
void TingChe()
{
    fstream ifs("TingChe.txt", ios::in); //�ж��ļ��Ƿ�Ϊ��
    char ch, S[80];
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "              **************************" << endl;
        cout << "              *   ��һ�ε�¼�ý���      *" << endl;
        cout << "              * �����복λ����(<10000)��*" << endl;
        cout << "?";
        int n;
        cin >> n; //��λ����
        SheLiCheWei(n);
    }
    else
    {
        string n, o, t, I;
        int st;
        Parking *s = NULL, *p = NULL;
        ifs.seekp(-long(sizeof(char)), ios::cur); //��귵��
        ifs.getline(S, 80);                       //��ȥ��һ��
        while (ifs >> n)
        {
            ifs >> st >> o >> t >> I; //�Ӵ洢�ж�ȡ��Ϣ
            p = new Parking;
            p->set_Number(n);
            p->set_YeZhu(o, t, I, st); //д��ԭ�洢����Ϣ
            if (head == NULL)
            {
                head = p;
                s = head;
            }
            else
            {
                s->Next = p;
                s = p;
            }
        }
        delete p;
    }
    cout << "              *************************" << endl;
    cout << "              *  ͣ��ϵͳ����������ʾ�� *" << endl;
    cout << "              *     1����ѯ��λ        *" << endl;
    cout << "              *     2�����ӳ�λ        *" << endl;
    cout << "              *     2����ѯ�ɷ�        *" << endl;
    cout << "              *     3������ϵͳ����    *" << endl;
    cout << "              *************************" << endl;
    cout << "               ����������ָ�����֣�1~3��" << endl;
    cout << "?";
    char Choice;
    do
    {
        cin >> Choice;
        switch (Choice) //�ж�ָ��
        {
        case '1': //��ѯ��λ
            ChaZhao();
            break;
        case '2': //���ӳ�λ
            ZengJia();
            break;
        case '3': //��ѯ�ɷ�
            JiaoFei();
            break;
        case '4':    //�˳�ϵͳ
            CunRu(); //�����ݷ���TingChe.txt�ļ���
            return;
        default:
            cout << "              ����ָ����������������" << endl;
        }
    } while (1);
}
