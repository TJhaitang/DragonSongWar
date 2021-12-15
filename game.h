#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <vector>
#include<QTimer>
#include"button.h"
#include"soldier.h"
#include"tower.h"

using namespace std;

extern int level;
extern bool cheat;
extern bool language;
extern int sd;

class imp:public QWidget{
public:
    imp(QWidget *parent=0);
    ~imp();
private:
    QImage fm;
    Button *bk=new Button(this);
    void back();
    void paintEvent(QPaintEvent *);
};

class Gy:public QWidget{
public:
    Gy(QWidget *parent=0);
    ~Gy(){}
private:
    bool is_music=false;
    QImage fm;
    QMediaPlayer player;
    QMediaPlayer ac;
    Button *bt2menu=new Button(this);
    Button *bt2bkstory=new Button(this);
    Button * bt2char=new Button(this);
    Button * bt2imp=new Button(this);
    Button *btlangch=new Button(this);
    Button *btcheach=new Button(this);
    QImage is_cheat;
    QImage langu;
    void draw();
    void back();
    void bkstory();
    void character();
    void important();
    void langChange();
    void cheatChange();
    void showlan();
    void showche();
    void enterEvent(QEvent *);
    void paintEvent(QPaintEvent *);
};


class Game:public QWidget {
public:
    Game(QWidget *parent = 0);
    void start();
private:
    Button *ks=new Button(this);
    Button *tc=new Button(this);
    Button *gy=new Button(this);
    Button *bk=new Button(this);
    Button *lv[8]={new Button(this),new Button(this),new Button(this),new Button(this),
                  new Button(this),new Button(this),new Button(this),new Button(this)};
    QImage fm;
    QMediaPlayer player;
        QMediaPlayer ac;
    bool is_music=false;
    void To_gy();
    void back();
    void draw();
    void IMload();
    void paintEvent(QPaintEvent *);
    void test();
    void blank();
    void togame1();
    void togame2();
    void togame3();
    void togame4();
    void togame5();
    void togame6();
    void togame7();
    void togame8();
};

class chapter:public QWidget{
    Q_OBJECT
public:
    explicit chapter(QWidget *parent = 0);
    ~chapter();
protected:
    int when=0;
    int Bo[51]={0};
    int blood=100;
    int bloodCD=200;
    int bloodCdCheck=0;
    int money=1000+10000*cheat;
    int moneyCD=40;
    int moneyCdCheck=0;
    int DorY;
    vector<QPoint *> p;
    QImage fm;
    QMediaPlayer player;
    QMediaPlayer ac;
    QRectF *r=NULL;
    vector<Soldier *> s;
    vector<Tower *> t;
    vector<Bullet *> b;
    QTimer *time;
    QTimer *singer;
    Button *bk=new Button(this);
    int ingame;
    void draw();
    void TimeCheck();
    void search();
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    virtual void gameover(int a)=0;
protected slots:
    void paint();
    void bk2Lv();
    virtual void sing()=0;
};

class C1:public chapter{
public:
    C1();
    void gameover(int a){if(a==1&&level<=1){level=1;}}
    void sing();


};

class C2:public chapter{
    Q_OBJECT
public:
    C2();
    void gameover(int a){if(a==1&&level<=2)level=2;}
    void sing();
protected:


};

class C3:public chapter{
public:
    C3();
    void gameover(int a){if(a==1&&level<=3)level=3;}
    void sing();

protected:


};

class C4:public chapter{
public:
    C4();
    void gameover(int a){if(a==1&&level<=4)level=4;}
    void sing();

protected:


};

class C5:public chapter{
public:
    C5();
    void gameover(int a){if(a==1&&level<=5)level=5;}
    void sing();

protected:


};

class C6:public chapter{
public:
    C6();
    void gameover(int a){if(a==1&&level<=6)level=6;}
    void sing();

protected:


};

class C7:public chapter{
public:
    C7();
    void gameover(int a){if(a==1&&level<=7)level=7;}
    void sing();

protected:


};

class C8:public chapter{
public:
    C8();
    void gameover(int a){}
    void sing();

protected:


};
#endif // GAME_H
