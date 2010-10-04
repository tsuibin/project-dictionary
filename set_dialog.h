#ifndef SET_DIALOG_H
#define SET_DIALOG_H
#include <QListWidgetItem>
#include <QDialog>
#include <QSettings>
namespace Ui {
    class set_Dialog;
}

class set_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit set_Dialog(QWidget *parent = 0);
    ~set_Dialog();
    QColor set_windowColor;
    QColor set_wordColor;
    int set_windowWith;
    int set_windowLen;
    int set_windowClarity;
    QFont set_wordFont;
    int set_wordSort;
    QString set_wordSavePath;
    bool set_ifOpenWebSearch;
    QStringList set_webName;
    QStringList set_URL;
    QStringList own_name;
    QStringList own_URL;
    QColor windowColor;
    void set_tbaleWidget_color(QColor);

private:
    Ui::set_Dialog *ui;
    QString web_selected;
    QSettings *setting;
    QListWidgetItem* webMove_selected;
    int webMove_selectedId;
    void init();
signals:
    void window_color(QColor);
    void dictionary_wid_changed(int);
    void dictionary_hight_changed(int);
    void all_tm_changed(int);
    void set_cancel();

private slots:
    void on_webSet_listWidget_clicked(QModelIndex index);
    void on_webSet_listWidget_itemClicked(QListWidgetItem* item);
    void on_moveWeb_pushButton_clicked();
    void on_fontComboBox_currentFontChanged(QFont f);
    void on_windowColor_pushButton_clicked();
    void on_w_len_valueChanged(int );
    void on_w_with_valueChanged(int );
    void on_cancel_bt_clicked();
    void on_tm_horizontalSlider_valueChanged(int value);
    void on_save_bt_clicked();
    void on_handAdd_bt_clicked();
    void on_webURL_listWidget_itemClicked(QListWidgetItem* item);
    void on_add_bt_clicked();
    void on_word_color_clicked();
    void on_browse_bt_clicked();

};

#endif // SET_DIALOG_H
