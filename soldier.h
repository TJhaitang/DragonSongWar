#ifndef SOLDIER_H
#define SOLDIER_H
#include<QWidget>
#include<vector>
#include<QTimer>
#include<QMediaPlayer>

using namespace std;

class Road{
public:
    Road(){}
    void setRoad(vector<QPoint *> );
    QPoint nextPos(double speed);
    QPoint NowP()const{return NowPos;}
    bool isOver();
    double leng(QPoint,QPoint);
    double L();
protected:
    vector<QPoint *> point;
    QPoint NowPos;
    int num=0;
    bool over=false;
};

class Soldier{
protected:
    double blood=100;
    double dps=0;
    int armor=0;//护甲值，1~100
    double speed=3;
    int here=0;//这个有啥用来着
    int who;//兵种
    int WhenAper;//出现时机  输入时是秒
    int turn;//出现波次
    bool start=false;
    int cd1=0;//技能时长
    int cd2=0;//技能cd
    int c1C=0;
    int c2C=0;
    int DorY;
    bool inA=false;
    bool AReady=false;
    QMediaPlayer player;
    Road road;
    QImage iden;
    QPoint pos;
public:
    int GetWho()const{return this->who;}
    Soldier(int who, double when, int Turn,int DY=0);//0,1,2,3/近战、ndhg、t、奶
    int GetWhen()const{return this->WhenAper;}
    int GetBld()const{return this->blood;}
    int GetTurn()const{return this->turn;}
    void SetRoad(vector<QPoint *> p);
    void draw(QPainter * p);
    void goahead();
    void GotAtk(double atk, bool ismagic);
    void outA(){this->AReady=false;}
    int Atk();
    void Heal();
    void Arm();
    bool isdeath();
    bool isStart()const{return this->start;}
    bool isover();
    bool isAReady()const{return this->AReady;}
    QPoint Getpos();
};

#endif // SOLDIER_H
