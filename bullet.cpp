#include "bullet.h"
#include<QPainter>

Bullet::Bullet(bool i, QPoint p, int lv){
    this->pos=p;
    this->ismagic=i;
    this->lv=lv;
    if(i)
    {
    blt.load(":/image/image/things/mblt.png");
    player.setMedia(QUrl("qrc:/sound/sound/action/mb.mp3"));

    }
    else
    {
        blt.load(":/image/image/things/dblt.png");
        player.setMedia(QUrl("qrc:/sound/sound/action/db.mp3"));
    }
    player.setVolume(50);
    player.play();
}

double Bullet::leng(QPoint a, QPoint b){
    return sqrt(1.0*((a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y())));
}

void Bullet::SetTarget(Soldier * t){
    this->target=t;
}

void Bullet::SetAtk(double atk){
    this->dps=atk;
    this->speed=10-5*this->ismagic;//以后再调整
}

void Bullet::draw(QPainter * p){
    p->drawImage(this->pos.x(),this->pos.y(),blt);
}

void Bullet::goahead(){
    this->pos+=QPoint(speed*(target->Getpos().x()-this->pos.x())/leng(target->Getpos(),this->pos),
                      speed*(target->Getpos().y()-this->pos.y())/leng(target->Getpos(),this->pos));
}

void Bullet::atk(){
    target->GotAtk(this->dps,this->ismagic);
}

int Bullet::L(){
    return leng(this->pos,target->Getpos());
}
