#ifndef TINGCHE_H
#define TINGCHE_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Parking //��λ��Ϣ
{
    string Number;             //��λ��
    string Owner = "NULL";     //��λ����ҵ��������
    string Telephone = "NULL"; //ҵ���绰
    string ID = "NULL";        //ҵ�����֤
    int statu = 2;             //��λ״̬��0���۳���1�����ޣ�2�����ã�
    double FeiYong = 0;        //��ɷ���
    int FeiYong_statu = 1;     //�ɷ�״̬(0��δ���� 1���ѽɷ�)
public:
    Parking *Next = NULL;                                //��һ��λ
    static int count;                                    //�ܳ�λ��
    void set_Number(string num);                         //д�복λ��
    void set_YeZhu(string o, string t, string i, int s); //д��ҵ����Ϣ
    void set_FeiYong(double f);                          //д����ɷ���
    void Submit();                                       //�ɷѳɹ�
    void Clean();                                        //���ҵ����Ϣ
    string get_Number();                                 //������λ��
    string get_YeZhu();                                  //����ҵ������
    double get_FeiYong();                                //�������ɷ���
    int get_FeiYong_statu();                             //�����ɷ�״̬
    int get_statu();                                     //������λ״̬
    void output();                                       //�����λ��Ϣ
    void output(fstream &f);                             //�����λ��Ϣ
    void JiaoFei_output();                               //����ɷ���Ϣ
    void JiaoFei_output(fstream &f);                     //����ɷ���Ϣ
};
Parking *head;
void SheLiCheWei(int n); //������λ
void XiuGai(Parking *x); //�޸���Ϣ
void Search_CheWei();    //����λ����
void Search_XingMing();  //����������
void Search_Statu();     //��״̬����
void ChaZhao();
void ZengJia();                  //���ӳ�λ
void JiaoFei_XiuGai(Parking *x); //�޸Ľɷ���Ϣ
void Submit(Parking *x);         //����ɷ���Ϣ
void JiaoFei_CheWei();           //����λ�Ų���
void JiaoFei_XingMing();         //����������
void JiaoFei_Statu();            //���ɷ�״̬����
void JiaoFei();                  //��ѯ�ɷ�
void CunRu();                    //�����ݷ���TingChe.txt�ļ�
void TingChe();
#endif