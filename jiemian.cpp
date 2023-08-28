#include <iostream>
using namespace std;
void setWindowsStyle()
{
    system("title 登录");
    system("color f0");
    system("mode con cols=40 lines=8");
}
int main()
{
    setWindowsStyle();
    system("pause");
}