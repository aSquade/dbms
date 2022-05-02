/********************************************************************************
** Form generated from reading UI file 'tbl_createwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TBL_CREATEWINDOW_H
#define UI_TBL_CREATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TBL_CreateWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *TBL_Name;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label_2;
    QLineEdit *columnName;
    QLabel *label_3;
    QLineEdit *columnType;
    QLabel *label_4;
    QLineEdit *checkName;
    QLabel *label_5;
    QTextEdit *check;
    QLabel *label_6;
    QLineEdit *DB_Name;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TBL_CreateWindow)
    {
        if (TBL_CreateWindow->objectName().isEmpty())
            TBL_CreateWindow->setObjectName(QString::fromUtf8("TBL_CreateWindow"));
        TBL_CreateWindow->resize(462, 467);
        centralwidget = new QWidget(TBL_CreateWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 171, 16));
        TBL_Name = new QLineEdit(centralwidget);
        TBL_Name->setObjectName(QString::fromUtf8("TBL_Name"));
        TBL_Name->setGeometry(QRect(240, 40, 181, 31));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(140, 390, 80, 31));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(240, 390, 80, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 101, 16));
        columnName = new QLineEdit(centralwidget);
        columnName->setObjectName(QString::fromUtf8("columnName"));
        columnName->setGeometry(QRect(40, 120, 181, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 90, 54, 12));
        columnType = new QLineEdit(centralwidget);
        columnType->setObjectName(QString::fromUtf8("columnType"));
        columnType->setGeometry(QRect(240, 120, 181, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 170, 54, 12));
        checkName = new QLineEdit(centralwidget);
        checkName->setObjectName(QString::fromUtf8("checkName"));
        checkName->setGeometry(QRect(40, 200, 181, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 250, 61, 16));
        check = new QTextEdit(centralwidget);
        check->setObjectName(QString::fromUtf8("check"));
        check->setGeometry(QRect(40, 280, 381, 91));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 10, 171, 16));
        DB_Name = new QLineEdit(centralwidget);
        DB_Name->setObjectName(QString::fromUtf8("DB_Name"));
        DB_Name->setGeometry(QRect(40, 40, 181, 31));
        TBL_CreateWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TBL_CreateWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 462, 22));
        TBL_CreateWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TBL_CreateWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TBL_CreateWindow->setStatusBar(statusbar);

        retranslateUi(TBL_CreateWindow);

        QMetaObject::connectSlotsByName(TBL_CreateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TBL_CreateWindow)
    {
        TBL_CreateWindow->setWindowTitle(QCoreApplication::translate("TBL_CreateWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("TBL_CreateWindow", "\350\241\250\345\220\215\347\247\260\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("TBL_CreateWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("TBL_CreateWindow", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("TBL_CreateWindow", "\345\255\227\346\256\265\345\220\215\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("TBL_CreateWindow", "\345\255\227\346\256\265\347\261\273\345\236\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("TBL_CreateWindow", "\347\272\246\346\235\237\345\220\215\347\247\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("TBL_CreateWindow", "\347\272\246\346\235\237\345\206\205\345\256\271\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("TBL_CreateWindow", "\345\272\223\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TBL_CreateWindow: public Ui_TBL_CreateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TBL_CREATEWINDOW_H
