#include "mycell.h"
#include <QPushButton>
#include <QString>
#include <QDebug>

myCell::myCell(QWidget *parent) : QPushButton(parent)
{
    // 初始化单个
    setText("");
    resize(50,50);
    connect(this,&QPushButton::clicked,[=]() mutable
    {
//        qDebug()<<getX()<<getY();
        // 分发坐标
        emit isClicked(getX() ,getY());
    });
}


void myCell::setPlace(int x,int y)
{

        this->move(x,y);
}
void myCell::setImage(int count)
{
       // 因为只有7张图
        count = count % 8;

        QString countString = QString::number(count,10);
        this -> count = countString;

        // 设置图片背景
        QString currentStyle = "QPushButton{background-image:url(:/new/prefix1/img/logo("+countString+").png);background-position:center;border:2px solid red;}";
        setStyleSheet(currentStyle);
}
void myCell::delImage(){
   this->hide();
}

void myCell::setX(int x)
{
    this->x =x;
}
void myCell::setY(int y)
{
    this->y = y;
}
int myCell::getX(){
    return this->x;
}

int myCell::getY(){
    return this->y;
}

// 设置点击反馈
void myCell::setColor(bool flag)
{
    if(flag){
        this->setStyleSheet( "QPushButton{background-image:url(:/new/prefix1/img/logo("+count+").png);background-position:center;border:2px solid red;}");
    }
    else{

    }
}
