#include "table.h"
#include "user.h"
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <iostream>
#include <QTextStream>
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QMainWindow>
#include <string.h>
#include <io.h>


using namespace std;
table::table(QString usrname,QString dbname,QString tblname){
    databasename = dbname;
    username = usrname;
    tablename = tblname;
}
table::~table(){

}


int table::coltype_check(QString coltype){
    int x = QString::compare(coltype, "varchar", Qt::CaseInsensitive);
    int y = QString::compare(coltype, "number", Qt::CaseInsensitive);

    if(x==0){
        return 1;
    }else if(y==0){
        return 2;
    }else{
        return 0;
    }
}

int table::db_exists(QString usrname,QString dbname){
    QString dbName = dbname;
    QString usrName = usrname;
    QString pathName = "C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+usrName;//用户文件夹位置
    QString fileName = pathName+"/"+"database.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen()){
        //打开成功则进行遍历查询
        if(file.size()==0){
            return 0;       //文件为空，数据库不存在
        }else{
            QTextStream out(&file);
            QString data;
             while(!out.atEnd()){
                 data= out.readLine();
                 QStringList dbData=data.split("#");
                 if(dbName==dbData.at(0)){
                     //该数据库已存在
                     file.close();
                     return -1;
                 }
             }
             file.close();
             return 1;//该数据库不存在
        }
    }
    return -2;
}

int table::tbl_exists(QString usrname,QString dbname,QString tblname){
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QString pathName = "C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+usrName+"/"+dbName;//用户数据库位置
    QString fileName = pathName+"/"+"table.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    if(file.isOpen()){
        //打开成功则进行遍历查询
        if(file.size()==0){
            return 0;       //文件为空，表不存在，可以创建
        }else{
            QTextStream out(&file);
            QString data;
             while(!out.atEnd()){
                 data= out.readLine();
                 QStringList tblData=data.split("#");
                 if(tblName==tblData.at(0)){
                     //该表已存在
                     file.close();
                     return -1;
                 }
             }
             file.close();
             return 1;//该表不存在
        }
    }
    return -2;
}

int table::table_in(QString usrname,QString dbname,QString tblname,QString colname,QString coltype,QString check_name,QString check){
    QString dbName = dbname;
    QString usrName = usrname;
    QString tblName = tblname;
    QString colName = colname;
    QString colType = coltype;
    QString cheName = check_name;
    QString che = check;
    QString pathName = "C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+usrName+"/"+dbName;//用户文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    QFile file(fileName);
    QDir dir;
    dir.mkdir(pathName+"/"+tblName);//创建该表所属文件夹
    QFile systbl("C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+usrName+"/"+dbName+"/"+tblName+"/"+tblName+".tdf");
    file.open(QIODevice::Append|QIODevice::Text);
    systbl.open(QIODevice::Append|QIODevice::Text);
    if(file.isOpen()&&systbl.isOpen()){
         QFileInfo info(fileName);
         QString tblInfo = tblName+"#"+colName+"#"+colType+"#"+cheName+"#"+che;//#作为分隔符
         QString tblInfo2 = tblName+"#"+colName+"#"+colType+"#"+cheName+"#"+che;//#作为分隔符
         QTextStream out(&file);//写入
         QTextStream out2(&systbl);
         out << tblInfo<<endl;
         out2 << tblInfo2<<endl;

         file.close();
         systbl.close();
         return 0;
    }else{
        //打印信息：文件无法打开
        file.close();
        systbl.close();
        return -1;
    }
}

void table::table_out(QString usrname,QString dbname,QString tblname){
    QString userName = usrname;
    QString dbName = dbname;
    QString tblName = tblname;
    QString pathName = "C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+userName+"/"+dbName;//用户数据库文件夹位置
    QString fileName = pathName+"/"+"table.txt";
    QString delPath = QString(pathName+"/"+tblName);
    QFile inputfile(fileName);
    QFile systbl("C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblname+".tdf");
    QStringList lines;
    QStringList lines2;
    inputfile.open(QIODevice::ReadWrite|QIODevice::Text);
    systbl.open(QIODevice::ReadWrite|QIODevice::Text);
    if(inputfile.isOpen()&&systbl.isOpen()){
        QTextStream out(&inputfile);
        QTextStream out2(&inputfile);
        QString data;
        QString sysdata;
         while(!out.atEnd()){
             data = out.readLine();
             QStringList dbData=data.split("#");
             if(tblName!=dbData.at(0)){
                 //把不是该表的表信息复制到链里
                lines.push_back(data);
             }
        }
         while(!systbl.atEnd()){
             sysdata = systbl.readLine();
             QStringList systblData=sysdata.split("#");
             if(dbName!=systblData.at(1)){
                 //把不是该表的表信息复制到链里
                lines2.push_back(sysdata);
             }
         }
         inputfile.remove();
         systbl.remove();
         QFile outputfile(fileName);
         QFile systbl2("C:/Users/jarvis/Desktop/dbms2_ver2.0/dbms2/dbms2/dbms2/data/"+userName+"/"+dbName+"/"+tblName+"/"+tblName+".tdf");
         if(outputfile.open(QIODevice::WriteOnly | QIODevice::Text)){
                 QTextStream edit(&outputfile);
                 for(int i=0;i<lines.size();i++){
                 edit<<lines[i]<<endl;
        }
                 outputfile.close();
    }
         if(systbl2.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream edit2(&systbl2);
             for(int i=0;i<lines2.size();i++){
                 edit2<<lines[i]<<endl;
             }
             systbl2.close();
         }
         QDir dir;
         dir.setPath(delPath);
         dir.removeRecursively();//删除表文件夹
    }
}
