#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_examination
{
public:
    QLabel *label_Title;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *btn_Submit;
    QLabel *label_score;

    void setupUi(QWidget *Frm_examination)
    {
        if (Frm_examination->objectName().isEmpty())
            Frm_examination->setObjectName(QString::fromUtf8("Frm_examination"));
        Frm_examination->resize(508, 458);
        label_Title = new QLabel(Frm_examination);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(20, 160, 321, 51));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_Title->setFont(font);
        gridLayoutWidget = new QWidget(Frm_examination);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 481, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Frm_examination);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 220, 491, 231));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        btn_Submit = new QPushButton(Frm_examination);
        btn_Submit->setObjectName(QString::fromUtf8("btn_Submit"));
        btn_Submit->setGeometry(QRect(370, 160, 121, 23));
        label_score = new QLabel(Frm_examination);
        label_score->setObjectName(QString::fromUtf8("label_score"));
        label_score->setGeometry(QRect(380, 190, 111, 16));

        retranslateUi(Frm_examination);

        QMetaObject::connectSlotsByName(Frm_examination);
    } // setupUi

    void retranslateUi(QWidget *Frm_examination)
    {
        Frm_examination->setWindowTitle(QCoreApplication::translate("Frm_examination", "Form", nullptr));
        label_Title->setText(QCoreApplication::translate("Frm_examination", "TextLabel", nullptr));
        btn_Submit->setText(QCoreApplication::translate("Frm_examination", "\346\217\220\344\272\244\346\211\200\346\234\211\347\255\224\346\241\210", nullptr));
        label_score->setText(QCoreApplication::translate("Frm_examination", "\346\200\273\345\210\206\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_examination: public Ui_Frm_examination {};
} // namespace Ui

QT_END_NAMESPACE

