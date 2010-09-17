#include <QPainter>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>
#include <QTextCodec>
#include <QTimer>
#include "zinnia.h"
#include "hand_wdialog.h"
#include "ui_hand_wdialog.h"

hand_wdialog::hand_wdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hand_wdialog)
{
    ui->setupUi(this);
    this->pix = QPixmap(200,200);
    this->pix.fill(Qt::white);
    this->recognizer = zinnia::Recognizer::create();
      if (!recognizer->open("/usr/local/lib/zinnia/model/tomoe/handwriting-ja.model")) {
        std::cerr << recognizer->what() << std::endl;

      }
      character = zinnia::Character::create();
      timer = new QTimer(this);
      connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
}

hand_wdialog::~hand_wdialog()
{
    delete ui;
}

void hand_wdialog::on_clearbt_clicked()
{
    QPainter c_p(&pix);
    c_p.eraseRect(0,0,200,200);
    ui->wordlist->clear();
    last_list.clear();
    end_list.clear();
    update();
}

void hand_wdialog::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);
    pp.translate(-20,-10);
    pp.drawLine(lastPoint,endPoint);
//    pp.drawLine(150,30,150,230);
//    pp.drawLine(50,130,250,130);
    lastPoint = endPoint;
//    pp.drawPoint(lastPoint.x(),lastPoint.y());
    QPainter painter(this);
    painter.translate(20,10);
    painter.drawPixmap(0,0,pix);

}

void hand_wdialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        lastPoint = event->pos();
        last_list.append(lastPoint);

}

void hand_wdialog::mouseMoveEvent(QMouseEvent *event)
{
//    QCursor my(QPixmap("/home/huguohu/svn/hand-write-input/hand_input/images.jpg"));
//    QApplication::setOverrideCursor(my);
    if(event->buttons()&Qt::LeftButton)
    {
       endPoint = event->pos();
       update();
    }
}

void hand_wdialog::timeout_slot()
{
    int i;
    QString str;

    ui->wordlist->clear();
    QTextCodec* gbk_codec = QTextCodec::codecForLocale();
    character->clear();
    character->set_width(200);
    character->set_height(200);
    for(i = 0;i < last_list.size();i++)
    {
        character->add(i,last_list.at(i).x()-20,last_list.at(i).y()-10);
    }
    for(i = 0; i < end_list.size(); i++)
    {
        character->add(i,end_list.at(i).x()-20,end_list.at(i).y()-10);
    }
    result = recognizer->classify(*character,last_list.size()+2);
    if (!result) {
       std::cerr << recognizer->what() << std::endl;
    }
    for (size_t i = 0; i < result->size(); ++i)
    {
        str = gbk_codec->toUnicode(result->value(i));
        str += " ";
        ui->wordlist->addItem(str);
    //result->value(i) << "\t" << result->score(i) << std::endl;
    }
}

void hand_wdialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        endPoint = event->pos();
        if(end_list.isEmpty())
        end_list.append(endPoint);
        else if(last_list.last() == endPoint)
        {
            last_list.removeLast();
        }
        else
        {
            end_list.append(endPoint);
        }
        update();
        qDebug()<<"mouserelease";
        qDebug()<<last_list.last().x();
        qDebug()<<end_list.last().x();
        qDebug()<<last_list.last().y();
        qDebug()<<end_list.last().y();
        qDebug()<<last_list.size();
        qDebug()<<end_list.size();
        if(endPoint != last_list.last())
        {
            timer->stop();
            timer->setSingleShot(true);
            timer->start(500);

        }
    }
}

//void hand_wdialog::on_wordlist_itemClicked(QListWidgetItem* item)
//{
////    dictionary::get_handinput(item->text());
//}

