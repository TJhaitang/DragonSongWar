#ifndef BULLET_H
#define BULLET_H

#include"soldier.h"
#include <QWidget>
#include <QMediaPlayer>

class Bullet{
public:
    Bullet(bool, QPoint p, int lv);
    void SetTarget(Soldier *);
    void SetAtk(double atk);
    void SetMagic(bool isM){this->ismagic=isM;}
    void draw(QPainter * p);
    int L();
    void goahead();
    void atk();
    double leng(QPoint,QPoint);
    int GetLv()const{return this->lv;}
    bool GetM()const{return this->ismagic;}
    QPoint GetPos()const{return this->pos;}
    Soldier * GetT()const{return this->target;}
protected:
    double dps;
    double speed;//伤害越高，速度越慢，在setatk中改变；
    bool ismagic;//魔法子弹破防,以后再用
    int lv;
    QMediaPlayer player;
    QImage blt;
    QPoint pos;
    Soldier * target;
};




#endif // BULLET_H
