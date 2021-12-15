#include"game.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QMediaPlayer>


chapter::chapter(QWidget *parent):QWidget(parent){
    resize(1000,700);
    this->bk->set(":/image/image/gy/back_norm.png",":/image/image/gy/back_prs.png",":/image/image/gy/back_rls.png",860,20);
    bk->setFunc(this,my_selector(bk2Lv));
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(paint()));
    time->start(50);
    time->setInterval(25);
    singer=new QTimer(this);
    connect(singer,SIGNAL(timeout()),this,SLOT(sing()));
    singer->start(sd);
    singer->setInterval(315000);
    ingame=1;
}

chapter::~chapter(){
    delete(time);
    delete(bk);
    delete(singer);
    delete(r);
}

void chapter::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    if(ingame==1){
    search();
    this->TimeCheck();
    this->draw();

    if(this->blood<=0)
    {
        this->player.stop();
        this->ac.setVolume(sd);
        ac.setMedia(QUrl("qrc:/sound/sound/action/lose.mp3"));
        this->ac.play();
        ingame=false;
    }
    else if(s.size()==0)
    {
        this->player.stop();
        this->ac.setVolume(sd);
        QPainter pa;
        fm.load(":/image/image/win.jpg");
        pa.begin(this);
        pa.drawImage(0,0,fm);
        ac.setMedia(QUrl("qrc:/sound/sound/action/win.mp3"));
        this->ac.play();
        gameover(1);
        ingame=3;
    }
    }
    else if(ingame==0){
        QPainter pa;
        if(DorY==0)
        fm.load(":/image/image/lose.jpg");
        else if(DorY==1)
            fm.load(":/image/image/lose_y.jpg");
        pa.begin(this);
        pa.drawImage(0,0,fm);
    }
    else if(ingame=3)
    {
        QPainter pa;
        fm.load(":/image/image/win.jpg");
        pa.begin(this);
        pa.drawImage(0,0,fm);
    }
}

void chapter::draw(){
    QPainter *pa;
    QRectF rec(QPoint(51,67),QPoint(200,200));
    pa = new QPainter();
    pa->begin(this);
    pa->drawImage(0,0,fm);
    pa->drawText(rec,QString("%1/%2").arg(this->money).arg(2000+10000*cheat));
    pa->drawText(*r,QString("blood %1").arg(this->blood));
    int Num=this->t.size();
    for(int i=0;i<Num;i++){
        t[i]->draw(pa);
    }
    if(s.size()!=0){
    vector<Soldier *>::iterator it;
    it=s.begin();
    while (it!=s.end()) {
        if((*it)->GetTurn()==0||(Bo[(*it)->GetTurn()-1]==0))
        {
        if((*it)->GetWhen()<=when){
        if(/*(*it)->GetWho()==3&&*/(*it)->isAReady()==true)
        {
            vector<Soldier *>::iterator go;
            vector<Soldier *>::iterator min;
            go=s.begin();
            min=s.begin();
            Road a;
            while (a.leng((*it)->Getpos(),(*min)->Getpos())>=200||min==it) {
                min++;
            }
            if(min!=s.end())
            {
                while (go!=s.end()) {
                    if(a.leng((*it)->Getpos(),(*go)->Getpos())<200&&go!=it)
                        if((*go)->GetBld()<(*min)->GetBld())
                        {
                            min=go;
                        }
                    go++;
                }
                if(a.leng((*it)->Getpos(),(*min)->Getpos())<200&&min!=it){
                    (*min)->GotAtk(-20,true);
                    this->ac.setVolume(55);
                    ac.setMedia(QUrl("qrc:/sound/sound/action/heal.mp3"));
                    this->ac.play();

                }
            }
            (*it)->outA();
        }
        (*it)->goahead();
        if((*it)->isdeath())
        {
            Bo[(*it)->GetTurn()]-=1;
            if(Bo[(*it)->GetTurn()]==0&&s.size()!=0)
            {
                when=(*(it+1))->GetWhen();
            }
            delete(*it);
            it=this->s.erase(it);
            this->money+=150;

//            Soldier *s1=new Soldier(0);//测试用
//            s1->SetRoad(p);//
//            this->s.push_back(s1);//

        }
        else if((*it)->isover())//可能附带伤害
        {
            this->blood-=(*it)->Atk();
            Bo[(*it)->GetTurn()]-=1;
            if(Bo[(*it)->GetTurn()]==0&&s.size()!=0)
            {
                when=(*(it+1))->GetWhen();
            }
            it=this->s.erase(it);
        }
        else{
        (*it)->draw(pa);
        it++;}
        }
        else
            break;
        }
        else
            break;
    }
    }
    vector<Bullet *>::iterator bit;
    bit=b.begin();
    while (bit!=b.end()) {
        (*bit)->draw(pa);
        (*bit)->goahead();
        if((*bit)->L()<4)
        {
            (*bit)->atk();
            if((*bit)->GetLv()>=2&&(*bit)->GetM()==false)
            {
                vector<Soldier *>::iterator it;
                it=s.begin();
                while (it!=s.end()) {
                     if((*bit)->leng((*bit)->GetPos(),(*it)->Getpos())<60)
                     {
                         (*it)->GotAtk(5,true);
                     }
                     it++;
                }
            }
            delete(*bit);
            bit=this->b.erase(bit);
        }
        else
            bit++;
    }
    bit=b.begin();
    while (bit!=b.end()) {
        if((*bit)->GetT()->GetBld()<=0)
        {
            delete(*bit);
            bit=this->b.erase(bit);
        }
        else
        bit++;
    }
    pa->end();
    delete pa;
}

void chapter::TimeCheck(){
    if(moneyCdCheck>0)
    {
        moneyCdCheck--;
    }
    if(moneyCdCheck==0)
    {
        this->money+=20;
        moneyCdCheck=moneyCD;
    }
    if(this->money>2000+10000*cheat){
        this->money=2000+10000*cheat;
    }
    if(bloodCdCheck>0)
    {
        bloodCdCheck--;
    }
    if(bloodCdCheck==0)
    {
        this->blood+=5;
        bloodCdCheck=bloodCD;
    }
    if(this->blood>100)
    {
        this->blood=100;
    }
}

void chapter::paint(){
//    nor.goahead();
    when++;
    this->repaint();
}

void chapter::bk2Lv(){
    this->player.stop();
    Game * tgame=new Game();
    tgame->show();
    tgame->start();
    this->close();
    delete(this);
}


void chapter::search(){
    int sNum=s.size();
    int tNum=t.size();
    for(int i=0;i<tNum;i++)
    {
        for(int j=0;j<sNum;j++)
        {
            if(s[j]->isStart())
            if(t[i]->isIn(s[j]->Getpos())&&t[i]->is_Cd())
            {
//                qDebug()<<"yes";
                t[i]->CD();
                Bullet *nb=new Bullet(t[i]->GetCM(),t[i]->GetPos()+QPoint(44,-63)/*调整出现位置*/,t[i]->GetLv());
                nb->SetTarget(s[j]);
                nb->SetAtk(t[i]->GetDps()+cheat*40);
                nb->SetMagic(t[i]->GetCM());
                b.push_back(nb);
            }
        }
        t[i]->CDdown();
    }
}

void chapter::mousePressEvent(QMouseEvent *event){
    Q_UNUSED(event);
}

void chapter::mouseReleaseEvent(QMouseEvent *event){
    int mx=event->x();
    int my=event->y();
//    qDebug()<<mx<<my;
    vector<Soldier *>::iterator it;
    it=s.begin();
    while (it!=s.end()) {
        if((*it)->GetWho()==0)
        {
            QPoint p=(*it)->Getpos();
            if(mx<p.x()+16&&mx>p.x()-16&&my<p.y()+30&&my>p.y()-30)
            {
                this->ac.setVolume(80);
                ac.setMedia(QUrl("qrc:/sound/sound/action/999.mp3"));
                this->ac.play();
                break;
            }
        }
        it++;
    }
    vector<Tower *>::iterator tow;
    tow=t.begin();
    while (tow!=t.end()) {
        QPoint p=(*tow)->GetPos();
        if(mx>p.x()-54&&mx<p.x()+60&&my>p.y()-80&&my<p.y()-24){
            if((*tow)->GetLv()>=1)
            {
                this->money+=500+100*(*tow)->GetCM();
                (*tow)->place();

            }
        }
        if(mx>p.x()-54&&mx<p.x()+60&&my<p.y()+31&&my>p.y()-24)
        {
            if((*tow)->GetLv()==0)
            {
            if(mx<p.x()-3)//物理
            {
                if(this->money>=800)
                {
                (*tow)->LvUp(0);
                    this->money-=800;
                }
            }
            else if(mx>p.x()+4)//魔法
            {
                if(this->money>=1200)
                {
                (*tow)->LvUp(1);
                this->money-=1200;
                }
            }
            }
            else
            {
                if(this->money>=900+100*(*tow)->GetCM())
                {
                    (*tow)->LvUp();
                    this->money-=900+100*(*tow)->GetCM();
                }
            }
        }
        tow++;
    }
}




