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
    void draw(QPainter * p);//同时需要准备好下一帧；
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
    QImage t;//这是穿在身上的衣服
    QImage file[3];//这是放在衣柜里的衣服  //也就是动画，别这么写注释过几天看不懂了
    QPoint pos;
    int lv=0;//防御塔等级
    int DorY;
    double speed;//伤害越低速度越快cd越短
    int cd;
    int cdCheck;
    int Rp=0;
    bool ismagic;//是否破防  0物理 1魔法
    double dps;
    double range=0;//攻击范围半径
};


#endif // TOWER_H
