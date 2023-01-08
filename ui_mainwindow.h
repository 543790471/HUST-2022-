/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ptn_Read;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_ID;
    QLabel *label_ID_2;
    QLabel *label_Name;
    QLabel *label_Name_2;
    QPushButton *ptn_Exam;
    QLabel *label_Score;
    QLabel *label_Score_2;
    QLabel *label_Subject;
    QLabel *label_Subject_2;
    QWidget *widget1;
    QFormLayout *formLayout;
    QLabel *label_Choice_num;
    QLineEdit *lineEdit_Choice_num;
    QLabel *label_Completion_num;
    QLineEdit *lineEdit_Completion_num;
    QLabel *label_Answer_num;
    QLineEdit *lineEdit_Answer_num;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(353, 275);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ptn_Read = new QPushButton(centralwidget);
        ptn_Read->setObjectName(QString::fromUtf8("ptn_Read"));
        ptn_Read->setGeometry(QRect(120, 200, 111, 23));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 20, 261, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_ID = new QLabel(widget);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));

        gridLayout->addWidget(label_ID, 0, 0, 1, 1);

        label_ID_2 = new QLabel(widget);
        label_ID_2->setObjectName(QString::fromUtf8("label_ID_2"));

        gridLayout->addWidget(label_ID_2, 0, 1, 1, 1);

        label_Name = new QLabel(widget);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));

        gridLayout->addWidget(label_Name, 1, 0, 1, 1);

        label_Name_2 = new QLabel(widget);
        label_Name_2->setObjectName(QString::fromUtf8("label_Name_2"));

        gridLayout->addWidget(label_Name_2, 1, 1, 1, 1);

        ptn_Exam = new QPushButton(widget);
        ptn_Exam->setObjectName(QString::fromUtf8("ptn_Exam"));

        gridLayout->addWidget(ptn_Exam, 2, 2, 1, 1);

        label_Score = new QLabel(widget);
        label_Score->setObjectName(QString::fromUtf8("label_Score"));

        gridLayout->addWidget(label_Score, 1, 2, 1, 1);

        label_Score_2 = new QLabel(widget);
        label_Score_2->setObjectName(QString::fromUtf8("label_Score_2"));

        gridLayout->addWidget(label_Score_2, 1, 3, 1, 1);

        label_Subject = new QLabel(widget);
        label_Subject->setObjectName(QString::fromUtf8("label_Subject"));

        gridLayout->addWidget(label_Subject, 0, 2, 1, 1);

        label_Subject_2 = new QLabel(widget);
        label_Subject_2->setObjectName(QString::fromUtf8("label_Subject_2"));

        gridLayout->addWidget(label_Subject_2, 0, 3, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(80, 120, 213, 74));
        formLayout = new QFormLayout(widget1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_Choice_num = new QLabel(widget1);
        label_Choice_num->setObjectName(QString::fromUtf8("label_Choice_num"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Choice_num);

        lineEdit_Choice_num = new QLineEdit(widget1);
        lineEdit_Choice_num->setObjectName(QString::fromUtf8("lineEdit_Choice_num"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Choice_num);

        label_Completion_num = new QLabel(widget1);
        label_Completion_num->setObjectName(QString::fromUtf8("label_Completion_num"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_Completion_num);

        lineEdit_Completion_num = new QLineEdit(widget1);
        lineEdit_Completion_num->setObjectName(QString::fromUtf8("lineEdit_Completion_num"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Completion_num);

        label_Answer_num = new QLabel(widget1);
        label_Answer_num->setObjectName(QString::fromUtf8("label_Answer_num"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_Answer_num);

        lineEdit_Answer_num = new QLineEdit(widget1);
        lineEdit_Answer_num->setObjectName(QString::fromUtf8("lineEdit_Answer_num"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Answer_num);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 353, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ptn_Read->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\351\242\230\345\272\223", nullptr));
        label_ID->setText(QCoreApplication::translate("MainWindow", "\350\200\203\347\224\237\345\217\267\357\274\232", nullptr));
        label_ID_2->setText(QCoreApplication::translate("MainWindow", "123456", nullptr));
        label_Name->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_Name_2->setText(QCoreApplication::translate("MainWindow", "\345\274\240\344\270\211", nullptr));
        ptn_Exam->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\200\203\350\257\225", nullptr));
        label_Score->setText(QCoreApplication::translate("MainWindow", "\344\270\212\346\254\241\350\200\203\350\257\225\346\210\220\347\273\251\357\274\232", nullptr));
        label_Score_2->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_Subject->setText(QCoreApplication::translate("MainWindow", "\347\247\221\347\233\256\357\274\232", nullptr));
        label_Subject_2->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262", nullptr));
        label_Choice_num->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\351\242\230\346\225\260\351\207\217\357\274\232", nullptr));
        lineEdit_Choice_num->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        label_Completion_num->setText(QCoreApplication::translate("MainWindow", "\345\241\253\347\251\272\351\242\230\346\225\260\351\207\217\357\274\232", nullptr));
        lineEdit_Completion_num->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        label_Answer_num->setText(QCoreApplication::translate("MainWindow", "\347\256\200\347\255\224\351\242\230\346\225\260\351\207\217\357\274\232", nullptr));
        lineEdit_Answer_num->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
