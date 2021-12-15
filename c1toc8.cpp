#include"game.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QMediaPlayer>

C1::C1(){
    this->DorY=0;
    this->fm.load(":/image/image/level/c1.png");
    player.setMedia(QUrl("qrc:/sound/sound/c1.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(100,281),QPoint(200,350));
    //塔
    Tower *t1=new Tower(QPoint(486+67,362+121));
    Tower *t2=new Tower(QPoint(566+67,129+121));
    Tower *t3=new Tower(QPoint(733+67,344+121));
    Tower *t4=new Tower(QPoint(636+67,538+121));
    Tower *t5=new Tower(QPoint(326+67,529+121));
    Tower *t6=new Tower(QPoint(417+67,38+121));
    Tower *t7=new Tower(QPoint(236+67,300+121));
    this->t.push_back(t1);
    this->t.push_back(t2);
    this->t.push_back(t3);
    this->t.push_back(t4);
    this->t.push_back(t5);
    this->t.push_back(t6);
    this->t.push_back(t7);
    //路线
    p.push_back(new QPoint(919,388));
    p.push_back(new QPoint(808,349));
    p.push_back(new QPoint(760,259));
    p.push_back(new QPoint(638,580));
    p.push_back(new QPoint(474,587));
    p.push_back(new QPoint(355,212));
    p.push_back(new QPoint(188,387));
    //    qDebug()<<p.size()<<")";
    //士兵

    int bo=0;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);
        s1->SetRoad(p);
        this->s.push_back(s1);
    }

    bo=1;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<2;i++){
        Soldier *s2=new Soldier(2,3+2*i,bo);
        s2->SetRoad(p);
        this->s.push_back(s2);
    }

    bo=2;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);//1 4 7 10 13
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<4;i++){
        Soldier *s1=new Soldier(0,2+3*i,bo);//2  5   8  11
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<2;i++){
        Soldier *s2=new Soldier(2,4+2*i,bo);//4  6
        s2->SetRoad(p);
        this->s.push_back(s2);
    }
    Soldier *s3=new Soldier(3,3,bo);
    s3->SetRoad(p);
    this->s.push_back(s3);

    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C2::C2(){
    this->DorY=0;
    this->fm.load(":/image/image/level/c2.png");
    player.setMedia(QUrl("qrc:/sound/sound/c2.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(54,90),QPoint(200,350));
    //塔
    Tower *t1=new Tower(QPoint(710+67,56+121));
    Tower *t2=new Tower(QPoint(706+67,230+121));
    Tower *t3=new Tower(QPoint(542+67,374+121));
    Tower *t4=new Tower(QPoint(242+67,546+121));
    Tower *t5=new Tower(QPoint(225+67,246+121));
    Tower *t6=new Tower(QPoint(386+67,68+121));
    Tower *t7=new Tower(QPoint(170+67,71+121));
    this->t.push_back(t1);
    this->t.push_back(t2);
    this->t.push_back(t3);
    this->t.push_back(t4);
    this->t.push_back(t5);
    this->t.push_back(t6);
    this->t.push_back(t7);
    //路线
    p.push_back(new QPoint(860,595));
    p.push_back(new QPoint(446,597));
    p.push_back(new QPoint(280,521));
    p.push_back(new QPoint(563,407));
    p.push_back(new QPoint(662,266));
    p.push_back(new QPoint(544,113));
    p.push_back(new QPoint(166,133));
    //士兵

    int bo=0;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);
        s1->SetRoad(p);
        this->s.push_back(s1);
    }

    bo=1;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<2;i++){
        Soldier *s2=new Soldier(2,3+2*i,bo);
        s2->SetRoad(p);
        this->s.push_back(s2);
    }

    bo=2;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);//1 4 7 10 13
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<4;i++){
        Soldier *s1=new Soldier(0,2+3*i,bo);//2  5   8  11
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<2;i++){
        Soldier *s2=new Soldier(2,4+2*i,bo);//4  6
        s2->SetRoad(p);
        this->s.push_back(s2);
    }
    Soldier *s3=new Soldier(3,3,bo);
    s3->SetRoad(p);
    this->s.push_back(s3);

    bo=3;
    for(int i=0;i<10;i++){
        Soldier *s1=new Soldier(0,1+3*i,bo);//1 4 7 10 13
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<8;i++){
        Soldier *s1=new Soldier(0,5+3*i,bo);//2  5   8  11
        s1->SetRoad(p);
        this->s.push_back(s1);
    }
    for(int i=0;i<4;i++){
        Soldier *s2=new Soldier(2,4+2*i,bo);//4  6
        s2->SetRoad(p);
        this->s.push_back(s2);
    }
    for(int i=0;i<4;i++){
        Soldier *s2=new Soldier(2,9+2*i,bo);//4  6
        s2->SetRoad(p);
        this->s.push_back(s2);
    }
    for(int i=0;i<5;i++)
    {
        Soldier *s3=new Soldier(3,4*i,bo);
        s3->SetRoad(p);
        this->s.push_back(s3);
    }

    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C3::C3(){
    this->DorY=1;
    this->fm.load(":/image/image/level/c3.png");
    player.setMedia(QUrl("qrc:/sound/sound/c3.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(464,14),QPoint(600,50));
    //塔
    this ->t.push_back(new Tower(QPoint(376+67,-76+121),1));
    this ->t.push_back(new Tower(QPoint(741+67,131+121),1));
    this ->t.push_back(new Tower(QPoint(507+67,73+121),1));
    this ->t.push_back(new Tower(QPoint(180+67,230+121),1));
    this ->t.push_back(new Tower(QPoint(322+67,384+121),1));
    this ->t.push_back(new Tower(QPoint(655+67,346+121),1));
    this ->t.push_back(new Tower(QPoint(644+67,542+121),1));
    this ->t.push_back(new Tower(QPoint(227+67,546+121),1));
    //路线
    vector<QPoint *> p1;
    p1.push_back(new QPoint(890,119));
    p1.push_back(new QPoint(160,127));
    vector<QPoint *>p2;
    p2.push_back(new QPoint(885,340));
    p2.push_back(new QPoint(657,317));
    p2.push_back(new QPoint(433,269));
    p2.push_back(new QPoint(175,271));
    vector <QPoint *>p3;
    p3.push_back(new QPoint(885,340));
    p3.push_back(new QPoint(641,376));
    p3.push_back(new QPoint(483,420));
    p3.push_back(new QPoint(174,438));
    vector<QPoint *>p4;
    p4.push_back(new QPoint(901,577));
    p4.push_back(new QPoint(169,595));
    //士兵
    int bo=0;
    for(int i=0;i<4;i++)
    {
        Soldier *s1=new Soldier(0,1+5*i,bo,1);
        s1->SetRoad(p4);
        s.push_back(s1);
    }
    bo=1;
    for(int i=0;i<4;i++)
    {
        Soldier *s1=new Soldier(0,4+5*i,bo,1);
        s1->SetRoad(p2);
        s.push_back(s1);
    }
    for(int i=0;i<3;i++)
    {
        Soldier *s1=new Soldier(0,11+5*i,bo,1);
        s1->SetRoad(p1);
        s.push_back(s1);
    }
    if(1){
    Soldier *s1=new Soldier(2,3,bo,1);
    s1->SetRoad(p3);
    s.push_back(s1);
    }
    bo=2;
    for(int i=0;i<9;i++)
    {
        Soldier *s2=new Soldier(0,4+3*i,bo,1);
        s2->SetRoad(p2);
        s.push_back(s2);
        Soldier *s1=new Soldier(0,2+3*i,bo,1);
        s1->SetRoad(p3);
        s.push_back(s1);
    }
    if(1)
    {
        Soldier *s2=new Soldier(2,6,bo,1);
        s2->SetRoad(p1);
        s.push_back(s2);
        Soldier *s1=new Soldier(2,4,bo,1);
        s1->SetRoad(p4);
        s.push_back(s1);
    }
    bo=3;
    for(int i=0;i<4;i++)
    {
        Soldier *s2=new Soldier(2,6+2*i,bo,1);
        s2->SetRoad(p4);
        s.push_back(s2);
        Soldier *s1=new Soldier(2,5+2*i,bo,1);
        s1->SetRoad(p3);
        s.push_back(s1);
    }
    for(int i=0;i<10;i++)
    {
        Soldier *s2=new Soldier(0,4+3*i,bo,1);
        s2->SetRoad(p2);
        s.push_back(s2);
    }
    for(int i=0;i<3;i++){
        Soldier *s2=new Soldier(0,5+2*i,bo,1);
        s2->SetRoad(p2);
        s.push_back(s2);
    }
    //
    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C4::C4(){
    this->DorY=0;
    this->fm.load(":/image/image/level/c4.png");
    player.setMedia(QUrl("qrc:/sound/sound/c4.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(29,558),QPoint(200,650));
    //塔
    //路线
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    //士兵
    Soldier *s1=new Soldier(0,1,0);
    s1->SetRoad(p);
    s.push_back(s1);
    //
    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C5::C5(){
    this->DorY=0;
    this->fm.load(":/image/image/level/c5.png");
    player.setMedia(QUrl("qrc:/sound/sound/c5.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(29,558),QPoint(200,650));
    //塔
    //路线
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    //士兵
    Soldier *s1=new Soldier(0,1,0);
    s1->SetRoad(p);
    s.push_back(s1);
    //
    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C6::C6(){
    this->DorY=0;
    this->fm.load(":/image/image/level/c6.png");
    player.setMedia(QUrl("qrc:/sound/sound/c6.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(438,227),QPoint(550,350));
    //塔
    //路线
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    //士兵
    Soldier *s1=new Soldier(0,1,0);
    s1->SetRoad(p);
    s.push_back(s1);
    //
    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C7::C7(){
    this->DorY=0;
    this->fm.load(":/image/image/level/c7.png");
    player.setMedia(QUrl("qrc:/sound/sound/c7.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(26,301),QPoint(200,650));
    //塔
    //路线
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    p.push_back(new QPoint(901,577));
    p.push_back(new QPoint(169,595));
    //士兵
    Soldier *s1=new Soldier(0,1,0);
    s1->SetRoad(p);
    s.push_back(s1);
    //
    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

C8::C8(){
    this->DorY=1;
    this->fm.load(":/image/image/level/c8.png");
    player.setMedia(QUrl("qrc:/sound/sound/c8.mp3"));
    player.setVolume(sd);
    player.play();
    //关卡血量位置
    this->r=new QRectF(QPoint(25,246),QPoint(200,650));
    //塔 range up
    this ->t.push_back(new Tower(QPoint(814+67,364+121),1));
    this ->t.push_back(new Tower(QPoint(598+67,377+121),1));
    this ->t.push_back(new Tower(QPoint(384+67,364+121),1));
    this ->t.push_back(new Tower(QPoint(201+67,363+121),1));
    this ->t.push_back(new Tower(QPoint(200+67,98+121),1));
    this ->t.push_back(new Tower(QPoint(488+67,88+121),1));
    this ->t.push_back(new Tower(QPoint(724+67,90+121),1));
    //路线
    p.push_back(new QPoint(957,360));
    p.push_back(new QPoint(957,266));
    p.push_back(new QPoint(850,266));
    p.push_back(new QPoint(850,444));
    p.push_back(new QPoint(750,444));
    p.push_back(new QPoint(750,266));
    p.push_back(new QPoint(650,266));
    p.push_back(new QPoint(650,444));
    p.push_back(new QPoint(550,444));
    p.push_back(new QPoint(550,266));
    p.push_back(new QPoint(450,266));
    p.push_back(new QPoint(450,444));
    p.push_back(new QPoint(350,444));
    p.push_back(new QPoint(350,266));
    p.push_back(new QPoint(250,266));
    p.push_back(new QPoint(250,444));
    p.push_back(new QPoint(180,444));
    p.push_back(new QPoint(180,360));
    p.push_back(new QPoint(150,360));
    vector<QPoint *>p1;
    p1.push_back(new QPoint(957,360));
    p1.push_back(new QPoint(150,360));
    //士兵
    int bo=0;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+5*i,bo,1);
        s1->SetRoad(p1);
        this->s.push_back(s1);
    }
    bo=1;
    for(int i=0;i<5;i++){
        Soldier *s1=new Soldier(0,1+5*i,bo,1);
        s1->SetRoad(p1);
        this->s.push_back(s1);
    }
    for(int i=0;i<7;i++){
        Soldier *s1=new Soldier(0,8+3*i,bo,1);
        s1->SetRoad(p1);
        this->s.push_back(s1);
    }
    for(int i=0;i<3;i++)
    {
    Soldier *s1=new Soldier(2,19+2*i,bo,1);
    s1->SetRoad(p1);
    this->s.push_back(s1);
    }
    bo=2;
    Soldier *s1=new Soldier(1,1,2);//尼德霍格
    s1->SetRoad(p);
    s.push_back(s1);
    for(int i=0;i<7;i++){
        Soldier *s1=new Soldier(0,8+3*i,bo,1);
        s1->SetRoad(p1);
        this->s.push_back(s1);
    }
    for(int i=0;i<3;i++)
    {
    Soldier *s1=new Soldier(2,23+2*i,bo,1);
    s1->SetRoad(p1);
    this->s.push_back(s1);
    }
    //
    for(int i=0;i<s.size();i++)
    {
        Bo[s[i]->GetTurn()]++;
    }
}

void C1::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c1.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C2::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c2.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C3::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c3.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C4::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c4.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C5::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c5.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C6::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c6.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C7::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c7.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
void C8::sing(){
    player.setMedia(QUrl("qrc:/sound/sound/c8.mp3"));
    this->player.setVolume(sd);
    this->player.play();
}
