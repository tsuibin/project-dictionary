#include <QtSql/QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QtGui>
#include <QTimer>
#include <qfiledialog.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtXml>
#include <QXmlDefaultHandler>
#include <QWebView>
#include "dictionary.h"
#include "ui_dictionary.h"


dictionary::dictionary(QWidget *parent) :
    QWidget(parent),/*QXmlDefaultHandler(),*/
    ui(new Ui::dictionary)
{
    ui->setupUi(this);
//layout
    this->dic_layout();
//the system tray
    this->system_tray();
    this->init_db();
    fd = new QFileDialog(this,"file dialog","/home/",NULL);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    manager = new QNetworkAccessManager(this);
    init_translate();
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    myprocess = new QProcess;
}

dictionary::~dictionary()
{
    delete ui;
    db.close();
}

void dictionary::on_listWidget_itemClicked(QListWidgetItem* item)
{
    QString sql,temp;
    ui->MeanBrowser->clear();
    this->word_selected = item->text();
    ui->WordIput->setText(this->word_selected);
    if(isCN == 'N')
    {
        sql = "select * from dicc where word='" + this->word_selected+"';";
        query->exec(sql);
        query->next();
        temp += "["+query->value(3).toString()+"]"+"\n";
        temp += query->value(4).toString()+"\n";
        ui->MeanBrowser->setText(temp);

    }
    else
    {
        sql = "select * from dicc where mean='" + this->word_selected+"';";
//        qDebug() <<sql;
        query->exec(sql);
        query->next();
        temp += "["+query->value(3).toString()+"]"+"\n";
        temp += query->value(2).toString()+"\n";
        ui->MeanBrowser->setText(temp);
        this->word_selected = query->value(2).toString();
    }
    on_WebSearchButton_clicked();
    myprocess->kill();
}

void dictionary::timeout_slot()
{
    QString sql;
    ui->listWidget->clear();
    if(!var.isEmpty())
    {
        QStringList strlist;
        QString tmp1;
       if((var.at(0) >= 'A' && var.at(0) <= 'Z') ||(var.at(0) >= 'a' && var.at(0) <= 'z'))
       {
           isCN = 'N';
            sql = "select * from dicc where word like '" + var + "%';";
            query->exec(sql);
            while(query->next())
            {
                tmp1 = query->value(2).toString();
                if(!strlist.contains(tmp1))
                strlist.append(tmp1);
            }
       }
       else
       {
           isCN = 'Y';
            sql = "select * from dicc where mean like '" + var + "%';";
            query->exec(sql);
            while(query->next())
            {
                tmp1 = query->value(4).toString();
                if(!strlist.contains(tmp1))
                strlist.append(tmp1);
            }
       }
        qDebug()<<sql;
        ui->listWidget->addItems(strlist);
        tmp1.clear();

        if(ui->listWidget->item(0) != 0)
        {
            this->word_selected = ui->listWidget->item(0)->text();
            if(isCN == 'N')
            {
                sql = "select * from dicc where word='"+this->word_selected+"';";
                query->exec(sql);
                query->next();
                tmp1 = "["+query->value(3).toString()+"]"+"\n";
                tmp1 +=query->value(4).toString()+"\n";
                ui->MeanBrowser->setText(tmp1);
            }
            else
            {
                sql = "select * from dicc where mean='"+this->word_selected+"';";
                qDebug()<<sql;
                query->exec(sql);
                query->next();
                tmp1 = "["+query->value(3).toString()+"]"+"\n";
                tmp1 +=query->value(2).toString()+"\n";
                ui->MeanBrowser->setText(tmp1);
                this->word_selected = query->value(2).toString();
                qDebug()<<"this the word";
            }
            on_WebSearchButton_clicked();
        }
        else
        {
            ui->listWidget->addItem(tr("没有你要查的单词"));
            ui->MeanBrowser->setText(tr("以下是网络查询结果！"));
            this->word_selected = ui->WordIput->text();
            on_WebSearchButton_clicked();
        }
    }
    else
        ui->MeanBrowser->clear();
}

void dictionary::on_WordIput_textEdited(QString w)
{
    var = w;
    timer->stop();
    timer->setSingleShot(true);
    timer->start(500);
}

void dictionary::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_Enter)
    {
        this->timeout_slot();
    }
}

bool dictionary::load_dic(QString path)
{
    int nFiles = 0;
    QDir dir(path);
    if (!dir.exists())
    return false;
    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int i=0;
    do{
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")
        {
            i++;
            continue;
        }
        bool bisDir=fileInfo.isDir();
        if(bisDir)
        {
            nFiles++;
          //  std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<endl;

            load_dic(fileInfo.filePath());
        }
        else
        {
            nFiles++;
            if(fileInfo.fileName().endsWith(".bok"))
            {
                QString file_path;
                file_path = fileInfo.path()+"/"+fileInfo.fileName();
                QFile file(file_path);
                if(file.open(QIODevice::ReadOnly))
                {
                    QTextStream stream(&file);
                    QString line,sql;
                    line = stream.readLine();
                    QString id;
                    int a,b;
                    a = line.indexOf("[N]");
                    b = line.indexOf("[C]");
                    sql = "insert into dicname(dicname) values('"+line.mid(a+3,b-a-3)+"');";
                    this->query->exec(sql);
                    sql.clear();
                    sql = "select id from dicname where dicname='"+line.mid(a+3,b-a-3)+"';";
                    this->query->exec(sql);
                    this->query->next();
                    id = this->query->value(0).toString();
                    sql.clear();
                    while(!stream.atEnd())
                    {
                        line.clear();
                        line = stream.readLine();
                        int w_index,t_index,m_index;
                        QString w,t,m;
                        w_index = line.indexOf("[W]");
                        if(line.contains("[T]"))
                        {
                            t_index = line.indexOf("[T]");
                            m_index = line.indexOf("[M]");
                            t = line.mid(t_index+3,m_index-t_index-3);
                            w = line.mid(w_index+3,t_index-w_index-3);
                        }
                        else
                        {
                            t = "";
                            m_index = line.indexOf("[M]");
                            w = line.mid(w_index+3,m_index-w_index-3);
                        }
                            m = line.mid(m_index+3,line.length()-m_index-1);
                        sql = "insert into dicc(dicid,word,t,mean) values("+id+",'";
                            sql += w+"','";
                            sql += t+"','";
                        sql += m+"');";
                        this->query->exec(sql);
                    }
                }
                file.close();
            }
        //    std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<endl;
        }
        i++;
    }while(i<list.size());
}

void dictionary::insertWord(QString word)
{
    ui->WordIput->clear();
    ui->WordIput->insert(word.trimmed());
    qDebug()<<ui->WordIput->text();
}

void dictionary::on_WebSearchButton_clicked()
{
    QString str="http://dict-co.iciba.com/api/dictionary.php?w=";
    str += this->word_selected;
    qDebug()<<str;
    manager->get(QNetworkRequest(QUrl(str)));
}

void dictionary::replyFinished(QNetworkReply *reply)
{
    QTextCodec* gbk_codec = QTextCodec::codecForName("utf8");
    QString str = gbk_codec->toUnicode(reply->readAll().data());
    this->sound_url.clear();
    if(!str.isEmpty())
    {
        ui->MeanBrowser->append(tr("<font color=red size=4> 金山词霸 </font>\n"));
        qDebug()<<str;
        doc.setContent(str);
        QDomElement docElem = doc.documentElement();
        QDomNode n = docElem.firstChild();
        while(!n.isNull())
        {
    //        qDebug()<<n.hasChildNodes();
//            qDebug()<<n.toElement().tagName()+"child";
            QString type1 = this->word_selected.replace(0,1,this->word_selected.at(0).toUpper());
            QString type2 = this->word_selected.replace(0,1,this->word_selected.at(0).toLower());
            if(!n.firstChild().toElement().tagName().isEmpty())
            {
                QDomNodeList list = n.childNodes();
                for(int i = 0; i < list.size();i++)
                {
                    QDomNode node = list.at(i);
                    if(node.isElement() && (!node.toElement().tagName().contains("pron")) && n.toElement().text().contains(type1))
                    {
                        QString temp = node.toElement().text().replace(type1,"<font color=blue>"+type1+"</font>");
                        ui->MeanBrowser->append(temp);
                    }
                    else if(node.isElement() && (!node.toElement().tagName().contains("pron")) && n.toElement().text().contains(type2))
                    {
                        QString temp = node.toElement().text().replace(type2,"<font color=blue>"+type2+"</font>");
                        ui->MeanBrowser->append(temp);
                    }
                    else if(node.isElement() && !node.toElement().tagName().contains("pron"))
                        ui->MeanBrowser->append(node.toElement().text());
                    else if(node.isElement()&&node.toElement().tagName().contains("pron"))
                        this->sound_url.append(node.toElement().text());
                }
            }
            else if(n.toElement().tagName().compare("ps") == 0)
            {
                ui->MeanBrowser->append("["+n.toElement().text()+"]");

            }
            else if(n.toElement().tagName().contains("pron"))
            {
                this->sound_url.append(n.toElement().text());
            }
            else if(!n.toElement().tagName().contains("pron"))
            {
                if(n.toElement().text().contains(type1))
                {
                    qDebug()<<"type1"<<n.toElement().text();
                    QString temp = n.toElement().text().replace(type1,"<font color=blue>"+type1+"</font>");
                    ui->MeanBrowser->append(temp);
                }
                else if(n.toElement().text().contains(type2))
                {
                    qDebug()<<"type2"<<n.toElement().text();
                    QString temp = n.toElement().text().replace(type2,"<font color=blue>"+type2+"</font>");
                    ui->MeanBrowser->append(temp);
                }
                else
                    ui->MeanBrowser->append(n.toElement().text());
                qDebug()<<n.toElement().text();
            }
            n = n.nextSibling();
        }
    }
    else
    {
        ui->MeanBrowser->append(tr("<font color=blue size=3>>>网络查询失败</font>"));
    }
}


void dictionary::closeEvent(QCloseEvent *event)
{
    emit dic_window_close();
    this->myprocess->kill();
    this->exitDialog->show();
    event->ignore();
}


void dictionary::on_hwinput_bt_clicked()
{
    emit this->openHanw();
}

void dictionary::on_set_bt_clicked()
{
    emit set_open();
}

void dictionary::on_sound_bt_clicked()
{
    myprocess->kill();
    QString mplayer_path("/usr/bin/mplayer");
    myprocess->start(mplayer_path,this->sound_url);
}

void dictionary::on_loaddic_bt_clicked()
{

    fd->setModal(QFileDialog::DirectoryOnly);
    fd->setViewMode(QFileDialog::Detail);
    QDir filename;
     QString path;
    if(fd->exec()== QDialog::Accepted)
    {
        filename = fd->directory();
        path = filename.absolutePath();
       this->load_dic(path);
    }
}

void dictionary::createActions()
{
    minimizeAction = new QAction(tr("最小化 (&I)"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("最大化 (&X)"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("还原(&R)"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("退出 (&Q)"), this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void dictionary::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayIconMenu);
}

void dictionary::showMessage(QString msg)
{
    QString titlec = msg;
    QString textc=QString(tr("双击打开词典,点击右键弹出选择菜单"));
    trayIcon->showMessage(titlec, textc, QSystemTrayIcon::Information, 5000);
}

void dictionary::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Trigger:
            showMessage(tr("鼠标单击！"));
            break;
        case QSystemTrayIcon::DoubleClick:
            showMessage(tr("鼠标单击！"));
            this->show();
            break;
        case QSystemTrayIcon::MiddleClick:
            showMessage(tr("鼠标中键！"));
            break;
        default:
            break;
    }

}

void dictionary::exitDialogWindow()
{
    if(this->miniButton->isChecked())
    {
        if(this->trayIcon->isVisible())
        {
            this->exitDialog->hide();
            this->hide();
        }
    }
    else
    {
        this->exitDialog->close();
        this->~dictionary();
    }
}

void dictionary::dic_layout()
{
    ui->listWidget->setMinimumSize(200,400);
    ui->MeanBrowser->setMinimumSize(390,400);
    ui->WordIput->setMaximumWidth(450);
    ui->listWidget->setMaximumWidth(450);
    this->topLayout = new QGridLayout();
    this->midLayout = new QGridLayout();
    this->bottomLayout = new QHBoxLayout();
    this->mainLayout = new QVBoxLayout(this);
    this->topLayout->addWidget(ui->WordIput,0,0,1,4);
    this->topLayout->addWidget(ui->hwinput_bt,0,4);
    this->topLayout->addWidget(ui->loaddic_bt,0,5);
    this->topLayout->addWidget(ui->page_bt,0,6);
    this->topLayout->addWidget(ui->add_dic_bt,0,7);
    this->topLayout->addWidget(ui->save_bt,0,8);
    this->topLayout->addWidget(ui->sound_bt,0,9);
    this->topLayout->addWidget(ui->set_bt,0,10);
    this->midLayout->addWidget(ui->listWidget,0,0);
    this->midLayout->addWidget(ui->MeanBrowser,0,1);
    this->bottomLayout->addWidget(ui->label);
    this->bottomLayout->addStretch();
    this->bottomLayout->addWidget(ui->label_2);
    this->mainLayout->setMargin(5);
    this->mainLayout->setSpacing(5);
    this->mainLayout->addLayout(this->topLayout);
    this->mainLayout->addLayout(this->midLayout);
    this->mainLayout->addLayout(this->bottomLayout);
}

void dictionary::system_tray()
{
    QIcon icon = QIcon(QPixmap(":/image/Dictionary.png"));
    this->setWindowIcon(icon);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip(tr("AKA多功能词典"));
    this->createActions();
    this->createTrayIcon();
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    this->exitDialog = new QDialog;
    this->closeButton = new QRadioButton(this->exitDialog);
    this->closeButton->setText(tr("退出程序"));
    this->miniButton = new QRadioButton(this->exitDialog);
    this->miniButton->setText(tr("最小化到托盘"));
    this->sureButton = new QPushButton(this->exitDialog);
    this->sureButton->setText(tr("确定"));
    this->exitDialog->setWindowTitle(tr("可最小化到托盘"));
    this->miniButton->setChecked(true);
    this->exitDialog->setMaximumSize(150,120);
    this->exitDialog->setMinimumSize(150,120);
    QVBoxLayout * vMain = new QVBoxLayout(this->exitDialog);
    vMain->addWidget(this->miniButton);
    vMain->addWidget(this->closeButton);
    vMain->addWidget(this->sureButton);
    this->exitDialog->setLayout(vMain);
    connect(this->sureButton,SIGNAL(clicked()),this,SLOT(exitDialogWindow()));
}

void dictionary::init_db()
{
    db = QSqlDatabase::addDatabase("QSQLITE");//
    db.setHostName("localhost");
    db.setDatabaseName("dic.db");
    db.setUserName("root");
    db.setPassword("dearmoe");
    if(!db.open())
    {
        QMessageBox::warning(this,tr("waring"),tr("open db faile!"),QMessageBox::Yes,QMessageBox::Yes);
    }
    query = new QSqlQuery(db);
}

void dictionary::dic_init()
{
//    this->dic_setting = new QSettings(QApplication::applicationDirPath()+"start.ini",QSettings::IniFormat);
//    QColor dic_color = this->dic_setting->value("windowColor").value<QColor>();
//    QPalette palette;
//    palette.setBrush(QPalette::Background,dic_color);
//    this->setPalette(palette);
//    this->set.setPalette(palette);
}


void dictionary::on_page_bt_clicked()
{
    translate->show();
}

void dictionary::set_wordcolor(QColor wc)
{
    ui->MeanBrowser->setTextColor(wc);
}

void dictionary::word_sort(QString sort)
{
    if(sort == "按单词首字母排序")
    {
        ui->listWidget->sortItems(Qt::AscendingOrder);
    }
}

void dictionary::init_translate()
{
    translate = new QWidget;
    translate->setWindowTitle(tr("全文翻译"));
//    translate->resize(450,500);
    translate->setGeometry(0, 0, 580, 490);
    QVBoxLayout *translate_mainLayout = new QVBoxLayout(translate);
    translate->setMaximumSize(580,490);
    translate->setMinimumSize(580,490);

    QWebView *web = new QWebView(translate);
    web->setUrl(QUrl("translate.html"));
    translate_mainLayout->addWidget(web);
    connect(this, SIGNAL(dic_window_close()), translate, SLOT(close()));
}

void dictionary::on_save_bt_clicked()
{
    this->wordSaveDialog = new QDialog();
    this->wordSaveDialog->setWindowTitle(tr("保存至生词薄"));
    this->wordSaveDialog->setModal(true);
    QPushButton *isSure = new QPushButton(tr("保存"));
    QPushButton *isCancel = new QPushButton(tr("取消"));
    QLabel *label1 = new QLabel(tr("保存位置"));
    QLineEdit *savePath = new QLineEdit();
    QVBoxLayout *savePath_mainLayout = new QVBoxLayout(this->wordSaveDialog);
    QHBoxLayout  *topLayout = new  QHBoxLayout();
    QHBoxLayout  *bottomLayout = new  QHBoxLayout();
    topLayout->addWidget(label1);
    topLayout->addWidget(savePath);
    bottomLayout->addStretch();
    bottomLayout->addWidget(isSure);
    bottomLayout->addStretch();
    bottomLayout->addWidget(isCancel);
    bottomLayout->addStretch();
    savePath_mainLayout->addLayout(topLayout);
    savePath_mainLayout->addLayout(bottomLayout);
    this->wordSaveDialog->show();
}
