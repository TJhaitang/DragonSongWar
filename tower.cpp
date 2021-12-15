#include "tower.h"
#include<QPainter>
#include<QDebug>

Tower::Tower(QPoint p,int dy){
    this->DorY=dy;
    if(this->DorY==1)
    {
        this->Rup();
    }
    this->SetPos(p);
    this->t.load(":/image/image/things/T.png");
}

double Tower::leng(QPoint a, QPoint b){
    return sqrt(1.0*((a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y())));
}

bool Tower::isIn(QPoint p){
    return (range>=leng(pos,p));
}

void Tower::draw(QPainter * p){
        p->drawImage(this->pos.x()-67,this->pos.y()-121,this->t);
}

void Tower::SetPos(QPoint p){
    this->pos=p;
}

bool Tower::is_Cd(){
    if(cdCheck==0){
        return true;
    }
    return false;
}

void Tower::LvUp(bool ismagic){
    if(this->lv==0)
    {
        this->ismagic=ismagic;
        if(this->ismagic==false)
            {
            if(this->DorY==0)
                this->t.load(":/image/image/things/DT.png");
            else
                this->t.load(":/image/image/things/DT_y.png");
            this->speed=2;
            this->cd=15;
            this->dps=10;
            }
        else
        {
            if(this->DorY==0)
            this->t.load(":/image/image/things/MT.png");
            else
                this->t.load(":/image/image/things/MT_y.png");
            this->speed=5;
            this->cd=30;
            this->dps=15;
        }
        this->cdCheck=cd;
        this->range=150+this->Rp*50;
        this->lv=1;
        repaint();
    }
    else//真正的升级
    {
    this->dps+=5;
        this->lv+=1;
    }
}

void Tower::place(){
    this->t.load(":/image/image/things/T.png");
    this->lv=0;
    this->range=0;
}
