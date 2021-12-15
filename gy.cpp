#include"game.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QMediaPlayer>

Gy::Gy(QWidget *parent):QWidget(parent){
    fm.load(":/image/image/gy.jpg");
    this->setWindowTitle("DragonSong_War");
    resize(1000,700);
    bt2menu->set(":/image/image/gy/back_norm.png",":/image/image/gy/back_prs.png",":/image/image/gy/back_rls.png",811,15);
    bt2bkstory->set(":/image/image/gy/bks_norm.jpg",":/image/image/gy/bks_prs.jpg",":/image/image/gy/bks_rls.jpg",175,114);
    bt2char->set(":/image/image/gy/cha_norm.jpg",":/image/image/gy/cha_prs.jpg",":/image/image/gy/cha_rls.jpg",175,275);
    bt2imp->set(":/image/image/gy/imp_norm.jpg",":/image/image/gy/imp_prs.jpg",":/image/image/gy/imp_rls.jpg",175,413);
    btcheach->set(":/image/image/gy/che_norm.jpg",":/image/image/gy/che_prs.jpg",":/image/image/gy/che_rls.jpg",498,275);
    btlangch->set(":/image/image/gy/lan_norm.jpg",":/image/image/gy/lan_prs.jpg",":/image/image/gy/lan_rls.jpg",498,413);

    bt2menu->setFunc(this,my_selector(back));
    bt2bkstory->setFunc(this,my_selector(bkstory));
    bt2char->setFunc(this,my_selector(character));
    bt2imp->setFunc(this,my_selector(important));
    btcheach->setFunc(this,my_selector(cheatChange));
    btlangch->setFunc(this,my_selector(langChange));
    showche();
    showlan();
}

void Gy::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    this->draw();
}

void Gy::enterEvent(QEvent*){
    if(!is_music)
    {
        player.setMedia(QUrl("qrc:/sound/sound/lxn.mp3"));
        player.setVolume(sd);
        player.play();
        is_music=!is_music;

    }
}

void Gy::draw(){
    QPainter pt(this);
    pt.drawImage(0,0,fm);
    pt.drawImage(740,305,is_cheat);
    pt.drawImage(615,437,langu);
}

void Gy::back(){
    Game *w=new Game();
    player.stop();
    w->show();
    this->close();
    delete(this);
}

void Gy::bkstory(){this->ac.setVolume(70);
                   ac.setMedia(QUrl("qrc:/sound/sound/action/blank.mp3"));
                   this->ac.play();}
void Gy::character(){this->ac.setVolume(70);
                     ac.setMedia(QUrl("qrc:/sound/sound/action/blank.mp3"));
                     this->ac.play();}
void Gy::important(){
    imp *w=new imp(this);
    w->show();
                    }

void Gy::cheatChange(){
    cheat=!cheat;
    showche();
}

void Gy::showche(){
    if(cheat){
        is_cheat.load(":/image/image/gy/true.jpg");
    }
    else
    {
        is_cheat.load((":/image/image/gy/false.jpg"));
    }
    repaint();
}

void Gy::langChange(){
    language=!language;
    showlan();
}

void Gy::showlan(){
    if(language){
        langu.load(":/image/image/gy/rby.jpg");
    }
    else{
        langu.load(":/image/image/gy/zw.jpg");
    }
    repaint();
}

imp::imp(QWidget *parent):QWidget(parent){
    fm.load(":/image/image/gy/gybyx.jpg");
    this->setWindowTitle("DragonSong_War");
    resize(1000,700);
    this->bk->set(":/image/image/gy/back_norm.png",":/image/image/gy/back_prs.png",":/image/image/gy/back_rls.png",811,15);
    bk->setFunc(this,my_selector(back));
}

void imp::back(){
    this->close();
    delete(this);
}

imp::~imp(){
    delete(bk);
}

void imp::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawImage(0,0,fm);
}
