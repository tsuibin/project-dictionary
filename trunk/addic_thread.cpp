#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QVariant>
#include "addic_thread.h"

addic_thread::addic_thread(QObject *parent) :
    QThread(parent)
{

}
addic_thread::addic_thread(QSqlDatabase tmp_db, QSqlQuery *tmp_query, QObject *parent):
        QThread(parent)
{
    this->db1 = tmp_db;
    this->query1 = tmp_query;
}

void addic_thread::run()
{
    QFileDialog *fd = new QFileDialog(0,"file dialog","/home/",NULL);
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

bool addic_thread::load_dic(QString path)
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
                    this->query1->exec(sql);
                    sql.clear();
                    sql = "select id from dicname where dicname='"+line.mid(a+3,b-a-3)+"';";
                    this->query1->exec(sql);
                    this->query1->next();
                    id = this->query1->value(0).toString();
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
                        this->query1->exec(sql);
                    }
                }
                file.close();
            }
        //    std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10).arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<endl;
        }
        i++;
    }while(i<list.size());
}

//void addic_thread::open_adDialog(QSqlDatabase tmp_db, QSqlQuery *tmp_query)
//{
//    this->db1 = tmp_db;
//    this->query1 = tmp_query;
//    this->run();
//}
