#include"game.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QtCore/qmath.h>

int level=0;
bool language=false;
bool cheat=false;
int sd=40;


Game::Game(QWidget *parent) : QWidget(parent){
    this->setWindowTitle("DragonSong_War");
    IMload();
    resize(1000,700);
    player.setMedia(QUrl("qrc:/sound/sound/DraSon.mp3"));
    player.setVolume(sd);
    player.play();
}

void Game::IMload(){
    fm.load(":/image/image/lszz.jpg");
    ks->set(":/image/image/test.png",":/image/image/ks_prs.jpg",":/image/image/ks_rls.jpg",330,277);
    tc->set(":/image/image/tc_norm.jpg",":/image/image/tc_prs.jpg",":/image/image/tc_rls.jpg",330,277+116+116);
    gy->set(":/image/image/gy_norm.jpg",":/image/image/gy_prs.jpg",":/image/image/gy_rls.jpg",330,277+116);
    bk->set(":/image/image/gy/back_norm.png",":/image/image/gy/back_prs.png",":/image/image/gy/back_rls.png",16,23);
    tc->setFunc(this,my_selector(test));
    ks->setFunc(this,my_selector(start));
    gy->setFunc(this,my_selector(To_gy));
    bk->setFunc(this,my_selector(back));
    for(int i=0;i<=level*!cheat+7*cheat;i++){
        QString num=QString::number(i+1);
        QString str1=QString(":/image/image/level/%1_norm.jpg").arg(num);
        QString str2=QString(":/image/image/level/%1_prs.jpg").arg(num);
        QString str3=QString(":/image/image/level/%1_rls.jpg").arg(num);
        lv[i]->set(str1,str2,str3,94+95*i,89-3*i);
        lv[i]->setFunc(this,my_selector(blank));
        lv[i]->close();
    }
    lv[0]->setFunc(this,my_selector(togame1));
    lv[1]->setFunc(this,my_selector(togame2));
    lv[2]->setFunc(this,my_selector(togame3));
    lv[3]->setFunc(this,my_selector(togame4));
    lv[4]->setFunc(this,my_selector(togame5));
    lv[5]->setFunc(this,my_selector(togame6));
    lv[6]->setFunc(this,my_selector(togame7));
    lv[7]->setFunc(this,my_selector(togame8));
    bk->close();
}

void Game::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    draw();
}

void Game::draw(){
    QPainter pt(this);
    pt.drawImage(0,0,fm);
}

void Game::test(){
    exit(1);
}

void Game::To_gy(){
    Gy *tgy=new Gy();
    tgy->show();
    player.stop();
    this->close();
    delete(this);
}

void Game::start(){
    ks->close();
    gy->close();
    tc->close();
    fm.load(":/image/image/level/fm.jpg");
    bk->show();
    for(int i=0;i<8;i++)
        lv[i]->show();
    repaint();
}
void Game::back(){
    bk->close();
    for(int i=0;i<8;i++)
        lv[i]->close();
    fm.load(":/image/image/lszz.jpg");
    ks->show();
    gy->show();
    tc->show();
    repaint();
}

void Game::blank(){
    ac.setVolume(70);
    ac.setMedia(QUrl("qrc:/sound/sound/action/blank.mp3"));
    ac.play();
}


void Game::togame1(){
    C1 *w=new C1();
    player.stop();
    w->show();
    this->close();
    delete(this);
}

void Game::togame2(){
    C2 *w=new C2();
    player.stop();
    w->show();
    this->close();
    delete(this);
}

void Game::togame3(){
    C3 *w=new C3();
    player.stop();
    w->show();
    this->close();
    delete(this);
}
void Game::togame4(){
    C4 *w=new C4();
    player.stop();
    w->show();
    this->close();
    delete(this);
}
void Game::togame5(){
    C5 *w=new C5();
    player.stop();
    w->show();
    this->close();
    delete(this);
}
void Game::togame6(){
    C6 *w=new C6();
    player.stop();
    w->show();
    this->close();
    delete(this);
}
void Game::togame7(){
    C7 *w=new C7();
    player.stop();
    w->show();
    this->close();
    delete(this);
}
void Game::togame8(){
    C8 *w=new C8();
    player.stop();
    w->show();
    this->close();
    delete(this);
}
