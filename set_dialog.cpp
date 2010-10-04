#include <QColorDialog>
#include <QFileDialog>
#include <QDebug>
#include "set_dialog.h"
#include "ui_set_dialog.h"

set_Dialog::set_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::set_Dialog)
{
    ui->setupUi(this);
    this->init();
    this->setModal(true);;
}

set_Dialog::~set_Dialog()
{
    delete ui;
}


void set_Dialog::on_browse_bt_clicked()
{
    QFileDialog *fd = new QFileDialog(this,tr("保存生词"),"/home/",NULL);
    fd->setModal(QFileDialog::DirectoryOnly);
    fd->setViewMode(QFileDialog::Detail);
//    QDir filename;
     QString path;
     path.clear();
    if(fd->exec()== QDialog::Accepted)
    {
        path = fd->getSaveFileName();
 //       path = filename.absolutePath();

        qDebug()<<"path"<<path;
        this->ui->WordSavePath_lineEdit->setText(path);
    }
}

void set_Dialog::on_word_color_clicked()
{
     this->set_wordColor = QColorDialog::getColor(Qt::white,this);

}

void set_Dialog::on_add_bt_clicked()
{
    if(!this->web_selected.isEmpty())
    {
        this->ui->webSet_listWidget->addItem(new QListWidgetItem(this->web_selected));
        this->set_webName.append(this->web_selected.section(':',0,0));
        this->set_URL.append(this->web_selected.section(':',1,2));
    }
}

void set_Dialog::on_webURL_listWidget_itemClicked(QListWidgetItem* item)
{
    this->web_selected = item->text();
}

void set_Dialog::on_handAdd_bt_clicked()
{
    if(!this->ui->Name_lineEdit->text().isEmpty()&&!this->ui->URL_lineEdit->text().isEmpty())
    {
        QString tmp_str = this->ui->Name_lineEdit->text()+":"+this->ui->URL_lineEdit->text();
        this->ui->webURL_listWidget->addItem(new QListWidgetItem(tmp_str));
        this->own_name.append(this->ui->Name_lineEdit->text());
        this->own_URL.append(this->ui->URL_lineEdit->text());
    }
}

void set_Dialog::on_save_bt_clicked()
{
    this->set_wordSort = ui->wordsort_comboBox->currentIndex();
    this->set_wordSavePath = ui->WordSavePath_lineEdit->text();
    this->set_ifOpenWebSearch = ui->WebisOpen_checkBox->isChecked();
    this->setting = new QSettings(QApplication::applicationDirPath()+"/start.ini",QSettings::IniFormat);
    this->setting->setValue("windowColor",this->set_windowColor);
    this->setting->setValue("wordFont",this->set_wordFont);
    this->setting->setValue("windowWidth",this->set_windowWith);
    this->setting->setValue("windowHeight",this->set_windowLen);
    this->setting->setValue("wordColor",this->set_wordColor);
    this->setting->setValue("windowClarity",this->set_windowClarity);
    this->setting->setValue("wordSort",this->set_wordSort);
    this->setting->setValue("wordSavePath",this->set_wordSavePath);
    this->setting->setValue("ifOpenWebSearch",this->set_ifOpenWebSearch);
    this->setting->setValue("webNameList",this->set_webName);
    this->setting->setValue("webUrlList",this->set_URL);
    this->setting->setValue("ownWebName",this->own_name);
    this->setting->setValue("ownUrl",this->own_URL);
    this->close();
}

void set_Dialog::on_tm_horizontalSlider_valueChanged(int value)
{
    emit all_tm_changed(value);
    this->ui->tm_label->setText(QString::number(value));
    this->set_windowClarity = value;
}

void set_Dialog::on_cancel_bt_clicked()
{
    this->init();
    emit set_cancel();
    this->close();
}

void set_Dialog::on_w_with_valueChanged(int a)
{
    this->set_windowWith = a;
    emit dictionary_wid_changed(a);
}

void set_Dialog::on_w_len_valueChanged(int b)
{
    this->set_windowLen = b;
    emit dictionary_hight_changed(b);
}

void set_Dialog::on_windowColor_pushButton_clicked()
{
    this->set_windowColor = QColorDialog::getColor(Qt::white,this);
    emit this->window_color(this->set_windowColor);
}

void set_Dialog::on_fontComboBox_currentFontChanged(QFont f)
{
    this->set_wordFont = f;
}

void set_Dialog::set_tbaleWidget_color(QColor tc)
{
    qDebug()<<tc;
    QPalette palette1;
    palette1.setColor(QPalette::Base,tc);
    palette1.setBrush(QPalette::Background,tc);
    ui->tab->setPalette(palette1);
    ui->tab_2->setPalette(palette1);
    ui->tab_3->setPalette(palette1);

}

void set_Dialog::init()
{
    this->setting = new QSettings(QApplication::applicationDirPath()+"/start.ini",QSettings::IniFormat);
    this->set_windowColor = this->setting->value("windowColor").value<QColor>();
    this->set_wordFont = this->setting->value("wordFont").value<QFont>();
    ui->fontComboBox->setCurrentFont(this->set_wordFont);
    this->set_windowWith = this->setting->value("windowWidth").toInt();
    ui->w_with->setValue(this->set_windowWith);
    this->set_windowLen = this->setting->value("windowHeight").toInt();
    ui->w_len->setValue(this->set_windowLen);
    this->set_windowClarity = this->setting->value("windowClarity").toInt();
    ui->tm_horizontalSlider->setValue(this->set_windowClarity);
    this->set_wordColor = this->setting->value("wordColor").value<QColor>();

    this->set_wordSort = this->setting->value("wordSort").toInt();
    ui->wordsort_comboBox->setCurrentIndex(this->set_wordSort);

    this->set_wordSavePath = this->setting->value("wordSavePath").toString();
    qDebug()<<"set_wordSavePath"<<this->set_wordSavePath;
    ui->WordSavePath_lineEdit->setText(this->set_wordSavePath);
    this->set_ifOpenWebSearch = this->setting->value("wordSavePath").toBool();
    ui->WebisOpen_checkBox->setChecked(this->set_ifOpenWebSearch);

    this->own_name = this->setting->value("ownWebName").toStringList();
    this->own_URL = this->setting->value("ownUrl").toStringList();
    this->set_webName = this->setting->value("webNameList").toStringList();
    this->set_URL = this->setting->value("webUrlList").toStringList();
    int i;
    QStringList ownWebList;
    QString f,b;
    ui->webURL_listWidget->clear();
    ui->webSet_listWidget->clear();
    for(i = 0;i < this->own_name.length();i++)
    {
        f = this->own_name.value(i);
        b = this->own_URL.value(i);
        ownWebList.append(f+":"+b);
        qDebug()<<"i="<<i;
    }
    qDebug()<<"ownWebList"<<ownWebList;
    ui->webURL_listWidget->addItems(ownWebList);

    QStringList setWebList;
    for(i = 0;i < this->set_webName.length();i++)
    {
        f = this->set_webName.at(i);
        b = this->set_URL.at(i);
        setWebList.append(f+":"+b);
    }
    ui->webSet_listWidget->addItems(setWebList);

}

void set_Dialog::on_moveWeb_pushButton_clicked()
{
    ui->webSet_listWidget->takeItem(this->webMove_selectedId);
    ui->webSet_listWidget->removeItemWidget(this->webMove_selected);
    ui->webSet_listWidget->update();
    QString web = this->webMove_selected->text();
    this->set_webName.removeOne(web.section(":",0,0));
    this->set_URL.removeOne(web.section(":",1,2));

    qDebug()<<"why"<<ui->webSet_listWidget->count();
}

void set_Dialog::on_webSet_listWidget_itemClicked(QListWidgetItem* item)
{
    this->webMove_selected = item;
    qDebug()<<"item"<<item->text();
}

void set_Dialog::on_webSet_listWidget_clicked(QModelIndex index)
{
    qDebug()<<index.row();
    this->webMove_selectedId = index.row();
    qDebug()<<index.data(3).toString();
    //this->webMove_selectedId = index;
}
