#include"soldier.h"
#include<cmath>
#include<Qpainter>
#include<QDebug>

double Road::leng(QPoint a, QPoint b){
    return sqrt(1.0*((a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y())));
}

void Road::setRoad(vector<QPoint *> p){
    this->point=p;
    this->NowPos=*p[0];
}

double Road::L(){
    return leng(NowPos,*point[num+1]);
}

QPoint Road::nextPos(double speed){
    if(leng(NowPos,*point[num+1])<speed)
    {
        speed-=leng(NowPos,*point[num+1]);
        NowPos=*point[num+1];
        num=num+1;
        if(num+1==point.size()){
            this->over=true;
            return NowPos;
        }
    }
    QPoint plus(speed*(point[num+1]->x()-NowPos.x())/L(),speed*(point[num+1]->y()-NowPos.y())/L());
    this->NowPos+=plus;
    return NowPos;
}

bool Road::isOver(){
    return this->over;
}

Soldier::Soldier(int who, double when, int Turn,int dy){
    this->pos.setX(0);
    this->pos.setY(0);
    this->who=who;
    this->WhenAper=when*40;
    this->turn=Turn;
    this->DorY=dy;
    if(who==0)//0,1,2,3/近战、尼德霍格、t、奶
    {
        cd1=0;
        cd2=1;
        if(this->DorY==0)
        this->iden.load(":/image/image/things/Dra.png");
        else
            this->iden.load(":/image/image/things/Dra_y.png");
        this->dps=20;
        this->speed=3;
    }
    if(who==1){
        cd1=0;
        cd2=1;
        this->iden.load(":/image/image/things/ndhg.png");
        this->dps=1000;
        this->speed=1;
        this->blood=1500;
        this->armor=25;
    }
    if(who==2){
        if(this->DorY==0)
        this->iden.load(":/image/image/things/Dk.png");
        else
            this->iden.load(":/image/image/things/Dk_y.png");
        this->speed=2.1;
        this->dps=10;
        this->armor=30;
        cd1=12;
        cd2=220;
    }
    if(who==3){
        this->iden.load(":/image/image/things/Heal.png");
        this->speed=2.2;
        this->dps=5;
        this->armor=20;
        cd1=9;
        cd2=200;
    }
//    c1C=cd1;
    c2C=cd2-1;
    c1C=0;
}

void Soldier::SetRoad(vector<QPoint *> p){
    this->road.setRoad(p);
    this->pos=road.NowP();
}

void Soldier::GotAtk(double atk,bool ismagic){
    atk-=!ismagic*atk*armor/100.0;
    this->blood-=atk;
}

bool Soldier::isdeath(){
    if(this->blood<0.01)
        return 1;
    else
        return 0;
}

bool Soldier::isover(){
    return road.isOver();
}

void Soldier::goahead(){
    if(c2C==0)
    {
        c2C=cd2;
        c1C=cd1;
        if(this->who==0){

        }
        else if(this->who==1)
        {

        }
        else if(this->who==2)
        {
            this->Arm();
        }
        else if(this->who==3)
        {
            this->Heal();
        }
    }
    if(c2C==cd2)
    {
        if(this->who==0){

        }
        else if(this->who==1)
        {

        }
        else if(this->who==2)
        {
            this->Arm();
        }
        else if(this->who==3)
        {
            this->Heal();
        }
    }
    if(c1C==0)
    {
        this->pos=this->road.nextPos(speed);
        c2C--;
        if(c2C<0)c2C=0;
    }
    else
    {
    }
}

void Soldier::draw(QPainter *p){
    start=true;
    p->drawImage(this->pos.x()-19-42*(this->who==1),pos.y()-28-240*(this->who==1),iden);
    QRectF rec(this->pos+QPoint(-13+(c1C!=0)*(10)+30*(this->who==1),-50-240*(this->who==1)),this->pos+QPoint(100,30));
    p->drawText(rec,QString("%1").arg(this->blood));
}

QPoint Soldier::Getpos(){
    return this->pos;
}

int Soldier::Atk(){
    //特效或者攻击方式
    return this->dps;
}
void Soldier::Arm(){
    if(inA==false)
    {
        if(c1C==cd1){
            if(this->DorY==0)
            this->iden.load(":/image/image/things/Dk_a.png");
            else
                this->iden.load(":/image/image/things/Dk_a_y.png");
            this->pos+=QPoint(-10,0);
            this->armor+=5;
            player.setMedia(QUrl("qrc:/sound/sound/action/arm.mp3"));
            player.setVolume(50);
            player.play();
        }
        c1C--;
        inA=(c1C==0);
    }
    if(inA==true)
    {
        inA=false;
        if(this->DorY==0)
        this->iden.load(":/image/image/things/Dk.png");
        else
            this->iden.load(":/image/image/things/Dk_y.png");
        this->pos+=QPoint(10,0);
    }
}
void Soldier::Heal(){
    if(inA==false)
    {
        if(c1C==cd1){
        this->iden.load(":/image/image/things/Heal_a.png");
            this->pos+=QPoint(-10,0);
            this->AReady=true;
        }
        c1C--;
        inA=(c1C==0);
    }
    if(inA==true)
    {
        inA=false;
        this->iden.load(":/image/image/things/Heal.png");
        this->pos+=QPoint(10,0);
    }
}
