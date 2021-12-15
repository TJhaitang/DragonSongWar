#ifndef TOWER_H
#define TOWER_H
#include "bullet.h"
#include "button.h"
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

class Tower:public QWidget
{
public:
    Tower(QPoint,int DY=0);
    bool isIn(QPoint);
    void draw(QPainter * p);//ͬʱ��Ҫ׼������һ֡��
    double leng(QPoint,QPoint);
    void SetPos(QPoint);
    void LvUp(bool ismagic=0);
    void Rup(){this->Rp+=1;}
    void place();
    bool is_Cd();
    void CD(){cdCheck=cd;}
    void CDdown(){if(cdCheck>0)cdCheck--;}
    int GetLv()const{return this->lv;}
    bool GetCM()const{return this->ismagic;}
    double GetDps()const{return dps;}
    QPoint GetPos()const{return this->pos;}
protected:
    QImage t;//���Ǵ������ϵ��·�
    QImage file[3];//���Ƿ����¹�����·�  //Ҳ���Ƕ���������ôдע�͹����쿴������
    QPoint pos;
    int lv=0;//�������ȼ�
    int DorY;
    double speed;//�˺�Խ���ٶ�Խ��cdԽ��
    int cd;
    int cdCheck;
    int Rp=0;
    bool ismagic;//�Ƿ��Ʒ�  0���� 1ħ��
    double dps;
    double range=0;//������Χ�뾶
};


#endif // TOWER_H
