#ifndef BUTTON_H
#define BUTTON_H
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QEvent>
#include <QLabel>
#include <QMediaPlayer>

typedef void (QObject::*FUNC_PTR )();
#define my_selector(_SELECTOR) (FUNC_PTR)(&_SELECTOR)//网上copy的功能,后来知道了另外的实现方法但实在是懒得改了，有空再说8

class Button:public QLabel{
    Q_OBJECT
public:
    Button(QWidget *parent = 0);
    void set(QString norm,QString prs,QString rls,int x, int y);
    void setFunc(QObject * obj,FUNC_PTR func);
protected:
    int x;
    int y;
    FUNC_PTR func;
    QObject* where;
    QPixmap norm;
    QPixmap prs;
    QPixmap rls;
    QMediaPlayer player;
    void mousePressEvent(QMouseEvent *e);
    void leaveEvent(QEvent *);
    void enterEvent(QEvent *);
    void mouseReleaseEvent(QMouseEvent *e);
};
#endif // BUTTON_H
