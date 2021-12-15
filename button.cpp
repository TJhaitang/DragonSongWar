#include"button.h"

Button::Button(QWidget *parent):QLabel(parent)
{
}

void Button::set(QString norm, QString prs, QString rls, int x, int y){
    this->norm.load(norm);
    this->prs.load(prs);
    this->rls.load(rls);
    this->setPixmap(this->norm);
    this->move(x,y);
}

void Button::mousePressEvent(QMouseEvent *e){
    if(Qt::LeftButton == e->button()){
    setPixmap(this->prs);
    }
}
void Button::leaveEvent(QEvent *){
    setPixmap(this->norm);
}
void Button::mouseReleaseEvent(QMouseEvent *e){
    if(Qt::LeftButton == e->button()){
        player.setMedia(QUrl("qrc:/sound/sound/action/rls.mp3"));
        player.setVolume(50);
        player.play();
        setPixmap(this->rls);
        if(where&&func)
        (where->*func)();
    }
}
void Button::enterEvent(QEvent *){
    setPixmap(this->rls);
}

void Button::setFunc(QObject *obj, FUNC_PTR func){
    where = obj;
    this->func = func;
}
