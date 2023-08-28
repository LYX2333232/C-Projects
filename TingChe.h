#ifndef TINGCHE_H
#define TINGCHE_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Parking //车位信息
{
    string Number;             //车位号
    string Owner = "NULL";     //车位所属业主的姓名
    string Telephone = "NULL"; //业主电话
    string ID = "NULL";        //业主身份证
    int statu = 2;             //车位状态（0：售出；1：租赁；2：闲置）
    double FeiYong = 0;        //需缴费用
    int FeiYong_statu = 1;     //缴费状态(0：未交费 1：已缴费)
public:
    Parking *Next = NULL;                                //下一车位
    static int count;                                    //总车位数
    void set_Number(string num);                         //写入车位号
    void set_YeZhu(string o, string t, string i, int s); //写入业主信息
    void set_FeiYong(double f);                          //写入待缴费用
    void Submit();                                       //缴费成功
    void Clean();                                        //清除业主信息
    string get_Number();                                 //读出车位号
    string get_YeZhu();                                  //读出业主姓名
    double get_FeiYong();                                //读出待缴费用
    int get_FeiYong_statu();                             //读出缴费状态
    int get_statu();                                     //读出车位状态
    void output();                                       //输出车位信息
    void output(fstream &f);                             //输出车位信息
    void JiaoFei_output();                               //输出缴费信息
    void JiaoFei_output(fstream &f);                     //输出缴费信息
};
Parking *head;
void SheLiCheWei(int n); //设立车位
void XiuGai(Parking *x); //修改信息
void Search_CheWei();    //按车位查找
void Search_XingMing();  //按姓名查找
void Search_Statu();     //按状态查找
void ChaZhao();
void ZengJia();                  //增加车位
void JiaoFei_XiuGai(Parking *x); //修改缴费信息
void Submit(Parking *x);         //清除缴费信息
void JiaoFei_CheWei();           //按车位号查找
void JiaoFei_XingMing();         //按姓名查找
void JiaoFei_Statu();            //按缴费状态查找
void JiaoFei();                  //查询缴费
void CunRu();                    //将数据放入TingChe.txt文件
void TingChe();
#endif