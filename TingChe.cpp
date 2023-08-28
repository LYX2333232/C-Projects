#include "TingChe.h"
void Parking::set_Number(string num) //写入车位号
{
    Number = num;
}
void Parking::set_YeZhu(string o, string t, string i, int s) //写入业主信息
{
    Owner = o;
    Telephone = t;
    ID = i;
    statu = s;
}
void Parking::set_FeiYong(double f) //写入待缴费用
{
    FeiYong = f;
    if (abs(f) > 1e-8)
        FeiYong_statu = 0; //缴费状态改为未缴费
    return;
}
void Parking::Submit() //缴费成功
{
    FeiYong = 0;
    FeiYong_statu = 1; //清空缴费信息
    return;
}
void Parking::Clean() //清除业主信息
{
    Owner = "NULL";
    Number = "NULL";
    ID = "NULL";
    statu = 2;
}
string Parking::get_Number() //读出车位号
{
    return Number;
}
string Parking::get_YeZhu() //读出业主姓名
{
    return Owner;
}
double Parking::get_FeiYong() //读出待缴费用
{
    return FeiYong;
}
int Parking::get_FeiYong_statu() //读出缴费状态
{
    return FeiYong_statu;
}
int Parking::get_statu() //读出车位状态
{
    return statu;
}
void Parking::output() //输出车位信息
{
    cout << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << ID << endl;
}
void Parking::output(fstream &f) //输出车位信息
{
    f << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << ID << endl;
}
void Parking::JiaoFei_output() //输出缴费信息
{
    cout << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << JiaoFei_Statu << "\t\t\t\t\t\t\t\t" << JiaoFei << endl;
}
void Parking::JiaoFei_output(fstream &f) //输出缴费信息
{
    f << Number << "\t" << statu << "\t\t\t\t\t\t\t\t\t" << Owner << "\t\t" << Telephone << '\t' << JiaoFei_Statu << "\t\t\t\t\t\t\t\t" << JiaoFei << endl;
}
int Parking::count = 0; //置初值
void SheLiCheWei(int n) //设立车位
{
    Parking::count += n;
    Parking *p = NULL, *s = NULL;
    p = new Parking[n];
    int i;
    ofstream Out_Number("Loading.txt", ios::out); //以写的方式打开
    for (i = 0; i < n; i++)
    { // i为车位号码，在前面补足0
        if (i < 10)
            Out_Number << "000";
        else if (i < 100)
            Out_Number << "00";
        else if (i < 1000)
            Out_Number << "0";
        Out_Number << i << endl;
    }
    fstream In_Parking("Loading.txt", ios::in); //以写的方式打开
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
void XiuGai(Parking *x) //修改信息
{
    string o, t, i;
    int s;
    cout << "请输入新的业主信息：" << endl;
    cout << "业主姓名：";
    cin >> o;
    cout << "业主电话：";
    cin >> t;
    cout << "业主身份证：";
    cin >> i;
    cout << "车位的新状态（0：售出 1：租赁 2：闲置）：";
    cin >> s;
    x->set_YeZhu(o, t, i, s);
    cout << "修改信息成功!" << endl;
    cout << "新的车位信息为：" << endl;
    cout << "车位号  车位状态(0:售出 1：租赁 2：空闲)      业主姓名    业主电话    业主身份证号码" << endl;
    x->output();
    return;
}
void Search_CheWei() //按车位查找
{
    cout << "请输入要查找的车位号：" << endl;
    cout << "?";
    string Search;     //输入的车位号
    Parking *x = head; //查找的指针
L:
    cin >> Search;
    int q = 0; //判断是否找到车位
    while (x)  //遍历
    {
        if (x->get_Number().compare(Search) == 0) //找到车位
        {
            q = 1;
            break;
        }
        else
            x = x->Next;
    }
    if (q == 0)
    {
        cout << "未能找到对应的车位，请重试！" << endl;
        goto L;
    }
    else
    {
        cout << "对应的车位信息：" << endl;
        cout << "车位号  车位状态(0：售出 1：租赁 2：空闲)      业主姓名    业主电话    业主身份证号码" << endl;
        x->output();
        cout << endl;
        cout << "              **************************" << endl;
        cout << "              *        请输入操作：     *" << endl;
        cout << "              *      1、修改业主信息    *" << endl;
        cout << "              *      2、清除业主信息    *" << endl;
        cout << "              *      3、返回查找系统    *" << endl;
        cout << "              *     请输入指令（1-3）   *" << endl;
        int choice;
        do
        {
            cout << "?";
            cin >> choice; //输入指令
            switch (choice)
            {
            case '1': //修改业主信息
                XiuGai(x);
                break;
            case '2': //清除业主信息
                x->Clean();
                break;
            case '3': //返回上级
                return;
            default:
                cout << "指令有误，请重试！" << endl;
            }
        } while (1);
    }
}
void Search_XingMing() //按姓名查找
{
    cout << "请输入要查找的业主的姓名：" << endl;
    cout << "?";
    string Search;     //输入的业主姓名
    Parking *x = head; //查找的指针
    int q = 0;         //判断是否找到车位
    cin >> Search;
    while (x) //遍历
    {
        if (x->get_YeZhu().compare(Search) == 0) //找到车位
        {
            if (q == 0)
            {
                q = 1;
                cout << "对应的车位信息：" << endl;
                cout << "车位号  车位状态(0：售出 1：租赁 2：空闲)      业主姓名    业主电话    业主身份证号码" << endl;
            }
            x->output(); //输出信息
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "未能找到对应的车位，请重试！" << endl;
    }
    return;
}
void Search_Statu() //按状态查找
{
    cout << "请输入要查找的车位的状态（0：售出 1：租赁 2：空闲）：" << endl;
    cout << "?";
    int Search;        //输入的车位状态
    Parking *x = head; //查找的指针
    int q = 0;         //判断是否找到车位
    cin >> Search;
    while (x != NULL) //遍历
    {
        if (x->get_statu() == Search) //找到车位
        {
            if (q == 0)
            {
                cout << "对应的车位信息：" << endl;
                cout << "车位号  车位状态(0：售出 1：租赁 2：空闲)      业主姓名    业主电话    业主身份证号码" << endl;
                q = 1;
            }
            x->output(); //输出信息
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "未能找到对应的车位，请重试！" << endl;
    }
    return;
}
void ChaZhao()
{
    do
    {
        cout << "              ******************************" << endl;
        cout << "              *     请输入查找方式：        *" << endl;
        cout << "              *1、按车位号查找（同时修改信息）*" << endl;
        cout << "              *   2、按业主姓名查找         *" << endl;
        cout << "              *   3、按车位状态查找         *" << endl;
        cout << "              *   4、返回停车系统界面       *" << endl;
        cout << "              *   请输入指令（1-4）         *" << endl;
        cout << "?";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //按车位号查找
            Search_CheWei();
            break;
        case '2': //按业主姓名查找
            Search_XingMing();
            break;
        case '3': //按车位状态查找
            Search_Statu();
            break;
        case '4': //返回停车系统
            return;
        default:
            cout << "输入指令有误，请重新输入！" << endl;
        }
    } while (1);
}
void ZengJia() //增加车位
{
    cout << "              **************************" << endl;
    cout << "              *     请输入增加的车位数： *" << endl;
    cout << "?";
    int n;
    cin >> n;          //输入新增的车位数
    Parking *x = head; //查找的指针
    while (x)
    {
        x = x->Next;
    }
    Parking *p = NULL, *s = NULL;
    int i;
    ofstream Out_Number("Loading.txt", ios::out); //以写的方式打开
    for (i = 0; i < n; i++)
    {                               // i次循环
        int q = i + Parking::count; // q为车位号，在前面补足0
        if (q < 10)
            Out_Number << "000";
        else if (q < 100)
            Out_Number << "00";
        else if (q < 1000)
            Out_Number << "0";
        Out_Number << q << endl;
    }
    fstream In_Parking("Loading.txt", ios::in); //以写的方式打开
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

void JiaoFei_XiuGai(Parking *x) //修改缴费信息
{
    double f; //新的待缴费用
    cout << "请输入新的待缴金额：" << endl;
    cin >> f;
    x->set_FeiYong(f);
    return;
}
void Submit(Parking *x) //清除缴费信息
{
    x->Submit();
}
void JiaoFei_CheWei() //按车位号查找
{
    cout << "请输入要查找的车位号：" << endl;
    cout << "?";
    string Search;     //输入的车位号
    Parking *x = head; //查找的指针
L:
    cin >> Search;
    int q = 0; //判断是否找到车位
    while (x)  //遍历
    {
        if (x->get_Number().compare(Search) == 0) //找到车位
        {
            q = 1;
            break;
        }
        else
            x = x->Next;
    }
    if (q == 0)
    {
        cout << "未能找到对应的车位，请重试！" << endl;
        goto L;
    }
    else
    {
        cout << "对应的车位信息：" << endl;
        cout << "车位号  车位状态(0:售出 1：租赁 2：空闲)      业主姓名    业主电话    缴费状态（0：未缴费 1：已缴费）   代缴金额" << endl;
        x->output();
        cout << endl;
        cout << "              **************************" << endl;
        cout << "              *        请输入操作：     *" << endl;
        cout << "              *      1、新增缴费信息    *" << endl;
        cout << "              *      2、清除缴费信息    *" << endl;
        cout << "              *      3、返回缴费系统    *" << endl;
        cout << "              *     请输入指令（1-3）   *" << endl;
        int choice;
        do
        {
            cout << "?";
            cin >> choice; //输入指令
            switch (choice)
            {
            case '1': //修改业主信息
                JiaoFei_XiuGai(x);
                break;
            case '2': //清除缴费信息
                Submit(x);
                break;
            case '3':
                return;
            default:
                cout << "指令有误，请重试！" << endl;
            }
        } while (1);
    }
}
void JiaoFei_XingMing() //按姓名查找
{
    cout << "请输入要查找的业主的姓名：" << endl;
    cout << "?";
    string Search;     //输入的业主姓名
    Parking *x = head; //查找的指针
    int q = 0;         //判断是否找到车位
    cin >> Search;
    while (x) //遍历
    {
        if (x->get_YeZhu().compare(Search) == 0) //找到车位
        {
            if (q == 0)
            {
                q = 1;
                cout << "对应的车位信息：" << endl;
                cout << "车位号  车位状态(0:售出 1：租赁 2：空闲)      业主姓名    业主电话    缴费状态（0：未缴费 1：已缴费）   代缴金额" << endl;
            }
            x->JiaoFei_output(); //输出信息
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "未能找到对应的车位，请重试！" << endl;
    }
    return;
}
void JiaoFei_Statu() //按缴费状态查找
{
    cout << "请输入要查找的车位的缴费状态（0：未缴费 1：已缴费）：" << endl;
    cout << "?";
    int Search;        //输入的车位状态
    Parking *x = head; //查找的指针
    int q = 0;         //判断是否找到车位

    cin >> Search;
    while (x != NULL) //遍历
    {
        if (x->get_FeiYong_statu() == Search) //找到车位
        {
            if (q == 0)
            {
                cout << "对应的车位信息：" << endl;
                cout << "车位号  车位状态(0:售出 1：租赁 2：空闲)      业主姓名    业主电话    缴费状态（0：未缴费 1：已缴费）   代缴金额" << endl;
                q = 1;
            }
            x->JiaoFei_output(); //输出信息
        }
        x = x->Next;
    }
    if (q == 0)
    {
        cout << "未能找到对应的车位，请重试！" << endl;
    }
    return;
}
void JiaoFei() //
{
    do
    {
        cout << "              ******************************" << endl;
        cout << "              *     请输入查找方式：        *" << endl;
        cout << "              *1、按车位号查找（同时修改信息）*" << endl;
        cout << "              *   2、按业主姓名查找         *" << endl;
        cout << "              *   3、按缴费状态查找         *" << endl;
        cout << "              *   4、返回停车系统界面       *" << endl;
        cout << "              *   请输入指令（1-4）         *" << endl;
        cout << "?";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //按车位号查找
            JiaoFei_CheWei();
            break;
        case '2': //按业主姓名查找
            JiaoFei_XingMing();
            break;
        case '3': //按缴费状态查找
            JiaoFei_Statu();
            break;
        case '4': //返回停车系统
            return;
        default:
            cout << "输入指令有误，请重新输入！" << endl;
        }
    } while (1);
}
void CunRu() //将数据放入TingChe.txt文件和JiaoFei.txt文件
{
    fstream outT("TingChe.txt", ios::out); //以写的方式打开
    Parking *p = head;
    cout << "车位号  车位状态(0:售出 1：租赁 2：空闲)      业主姓名    业主电话    业主身份证号码" << endl; //第一行标注
    while (p != NULL)                                                                                       //输出车位数据
    {
        p->output(outT);
        p = p->Next;
    }
    outT.close();                          //关闭文件
    fstream outJ("JiaoFei.txt", ios::out); //以写的方式打开文件
    p = head;
    cout << "车位号  车位状态(0:售出 1：租赁 2：空闲)      业主姓名    业主电话    缴费状态（0：未缴费 1：已缴费）   代缴金额" << endl; //第一行标注
    while (p != NULL)                                                                                                                   //输出车位数据
    {
        p->JiaoFei_output(outJ);
        p = p->Next;
    }
    outJ.close(); //关闭文件
    return;
}
void TingChe()
{
    fstream ifs("TingChe.txt", ios::in); //判断文件是否为空
    char ch, S[80];
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "              **************************" << endl;
        cout << "              *   第一次登录该界面      *" << endl;
        cout << "              * 请输入车位数量(<10000)：*" << endl;
        cout << "?";
        int n;
        cin >> n; //车位数量
        SheLiCheWei(n);
    }
    else
    {
        string n, o, t, I;
        int st;
        Parking *s = NULL, *p = NULL;
        ifs.seekp(-long(sizeof(char)), ios::cur); //光标返回
        ifs.getline(S, 80);                       //略去第一行
        while (ifs >> n)
        {
            ifs >> st >> o >> t >> I; //从存储中读取信息
            p = new Parking;
            p->set_Number(n);
            p->set_YeZhu(o, t, I, st); //写入原存储的信息
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
    cout << "              *  停车系统命令如下所示： *" << endl;
    cout << "              *     1、查询车位        *" << endl;
    cout << "              *     2、增加车位        *" << endl;
    cout << "              *     2、查询缴费        *" << endl;
    cout << "              *     3、返回系统界面    *" << endl;
    cout << "              *************************" << endl;
    cout << "               请输入您的指令数字（1~3）" << endl;
    cout << "?";
    char Choice;
    do
    {
        cin >> Choice;
        switch (Choice) //判断指令
        {
        case '1': //查询车位
            ChaZhao();
            break;
        case '2': //增加车位
            ZengJia();
            break;
        case '3': //查询缴费
            JiaoFei();
            break;
        case '4':    //退出系统
            CunRu(); //将数据放入TingChe.txt文件中
            return;
        default:
            cout << "              输入指令有误，请重新输入" << endl;
        }
    } while (1);
}
