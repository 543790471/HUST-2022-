#include "frm_examination.h"
#include "ui_frm_examination.h"
#include "mainwindow.h"
#include <QButtonGroup>
#include <QLayoutItem>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QTextEdit>
#include <vector>
#include <QVBoxLayout>
#include <iostream>
#include <QByteArray>
using namespace std;

Frm_examination::Frm_examination(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Frm_examination)
{
    ui->setupUi(this);

    //在窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源
    this->setAttribute(Qt::WA_DeleteOnClose);
}

Frm_examination::~Frm_examination()
{
    delete ui;
}

//接收主窗口发来的题目信息,并创建按钮等控件
void Frm_examination::getSelected(vector<Questiontext> selected_Choice,vector<Questiontext> selected_Completion,vector<Questiontext> selected_Answer)
{
    //将主窗口发送的题目信息存到全局函数里，便于各函数间调用
    Choice=selected_Choice;
    Completion=selected_Completion;
    Answer=selected_Answer;
    //获取不同种类题目号数的界限flag
    flag_CH=Choice.size();
    flag_CHtoCO=Choice.size()+Completion.size();
    titleNum=Choice.size()+Completion.size()+Answer.size();

    //预定义题目作答界面控件
    for (int i=0;i<flag_CH;i++ ) //选择题作答界面
    {
        //初始化各控件
        groupBox[i]=new QGroupBox("Choose");
        ui->stackedWidget->addWidget(groupBox[i]);
        rtnGroup_Option[i]=new QButtonGroup();
        rtn_Option[4*i]=new QRadioButton();
        rtn_Option[4*i+1]=new QRadioButton();
        rtn_Option[4*i+2]=new QRadioButton();
        rtn_Option[4*i+3]=new QRadioButton();
        vBoxLayout[i]=new QVBoxLayout;
        //设置按键文本
        rtn_Option[4*i]->setText(Choice[i].choice[0]);
        rtn_Option[4*i+1]->setText(Choice[i].choice[1]);
        rtn_Option[4*i+2]->setText(Choice[i].choice[2]);
        rtn_Option[4*i+3]->setText(Choice[i].choice[3]);
        //向按键组里添加按键
        rtnGroup_Option[i]->setExclusive(true);  //设置这一组按钮只能单选
        rtnGroup_Option[i]->addButton(rtn_Option[4*i]);
        rtnGroup_Option[i]->addButton(rtn_Option[4*i+1]);
        rtnGroup_Option[i]->addButton(rtn_Option[4*i+2]);
        rtnGroup_Option[i]->addButton(rtn_Option[4*i+3]);
        //向布局组里添加按键，易忘
        vBoxLayout[i]->addWidget(rtn_Option[4*i]);
        vBoxLayout[i]->addWidget(rtn_Option[4*i+1]);
        vBoxLayout[i]->addWidget(rtn_Option[4*i+2]);
        vBoxLayout[i]->addWidget(rtn_Option[4*i+3]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for (int i=flag_CH;i<flag_CHtoCO;i++ ) //填空题作答界面
    {
        //初始化各控件
        groupBox[i]=new QGroupBox("fill in");
        vBoxLayout[i]=new QVBoxLayout;
        //向栈窗里添加按键
        ui->stackedWidget->addWidget(groupBox[i]);
        textEdit_Completion[i-flag_CH]=new QTextEdit;
        //向布局组里添加文本框，易忘
        vBoxLayout[i]->addWidget(textEdit_Completion[i-flag_CH]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for (int i=flag_CHtoCO;i<titleNum;i++ ) //简答题作答界面
    {
        //初始化各控件
        groupBox[i]=new QGroupBox("fill in");
        vBoxLayout[i]=new QVBoxLayout;
        //向栈窗里添加按键
        ui->stackedWidget->addWidget(groupBox[i]);
        textEdit_Answer[i-flag_CHtoCO]=new QTextEdit;
        //向布局组里添加文本框，易忘
        vBoxLayout[i]->addWidget(textEdit_Answer[i-flag_CHtoCO]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }

    //收到信号消息后，再创建按钮等控件
    QButtonGroup* button_group = new QButtonGroup(this);//按钮组
    button_group->setExclusive(true);  //设置这一组按钮只能单选
    //每运行一次都要清空QVBoxLayout内的控件，不然会累积
    QLayoutItem* child;
    while ((child = ui->gridLayout->takeAt(0)) != 0)
    {
        //setParent为NULL，防止删除之后界面不消失
        if (child->widget())
        {
            child->widget()->setParent(NULL);
        }
        delete child;
    }
    //布置按键和标签
    for (int i = 0; i < titleNum; i++)
    {
        //初始化各控件，并设置初始文本
        button[i]=new QPushButton;
        button[i]->setText(QString::number(i+1));
        label[i]=new QLabel;
        label[i]->setText("null");
        //将控件加入布局组，此处间隔排列，每道题占用上下两格，分别存放按钮和标签
        ui->gridLayout->addWidget(button[i], 2*(i/6), i%6);
        ui->gridLayout->addWidget(label[i], 2*(i/6)+1, i%6);
//        ui->verticalLayout->addStretch(0);//每个按钮（前）后增加一个伸缩量，保证按钮均匀分布
        button_group->addButton(button[i]);  //按钮分组，这里只有一组
        //根据不同题型
        if(i<Choice.size())//选择题
        {
            //点击哪个按键，显示对应的题目内容
            connect(button[i], &QPushButton::clicked, this, [=]() {
            //自己要想实现的Lambda槽函数，此处为显示题目
               showTitle(Choice[i],i);
            });
        }
        else if(i>=Choice.size()&&i<(Choice.size()+Completion.size()))//填空题
        {
            connect(button[i], &QPushButton::clicked, this, [=]() {showTitle(Completion[i-flag_CH],i);});
        }
        else//简答题
        {
            connect(button[i], &QPushButton::clicked, this, [=]() {showTitle(Answer[i-flag_CHtoCO],i);});
        }
    }
}

//显示题目文本以及答题框体
void Frm_examination::showTitle(Questiontext question,int flag)
{
    ui->label_Title->setText(question.title);//将题目文字导入题目标签
    ui->stackedWidget->setCurrentIndex(flag+2);//打开对应的答题界面.stackedWidget控件创建时本身就自带两个widget(page1,page2)
    groupBox[flag]->show();
}

//点击交卷，判卷
void Frm_examination::on_btn_Submit_clicked()
{
    for(int i=0;i<flag_CH;i++)//选择题
    {
        //设置按键的状态ID，找到组中被点选的按键
        rtnGroup_Option[i]->setId(rtn_Option[4*i],0);//rtn_Option[4*i]的Id设为0
        rtnGroup_Option[i]->setId(rtn_Option[4*i+1],1);
        rtnGroup_Option[i]->setId(rtn_Option[4*i+2],2);
        rtnGroup_Option[i]->setId(rtn_Option[4*i+3],3);
        int id=rtnGroup_Option[i]->checkedId();//通过checkedId去判断
        if(id!=-1)//如果有按键被选中，即id非-1
        {
            if(id==int(Choice[i].answer.toStdString().at(0))-65)//转码，由QString到int(ascii)
            {
                label[i]->setText("true");//标签显示为对
                label[i]->setStyleSheet("color:green;");//正确，绿色
                score+=5;//得分+5
            }
            else
            {
                label[i]->setText("false");//标签显示为错
                label[i]->setStyleSheet("color:red;");//错误，红色
            }
        }
        else
        {
            label[i]->setText("false");//标签显示为错
            label[i]->setStyleSheet("color:red;");//错误，红色
        }
        //显示正确答案
        lab_Answer[i]=new QLabel();
        lab_Answer[i]->setText(QString::fromLocal8Bit("正确选项：")+Choice[i].answer.at(0));//取出答案第一个字符即为正确选项
        vBoxLayout[i]->addWidget(lab_Answer[i]);//将答案标签导入布局组
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for(int i=flag_CH;i<flag_CHtoCO;i++)//填空题
    {
        if(textEdit_Completion[i-flag_CH]->toPlainText()==Completion[i-flag_CH].answer)
        {
            label[i]->setText("true");//标签显示为对
            label[i]->setStyleSheet("color:green;");//正确，绿色
            score+=5;//得分+5
        }
        else
        {
            label[i]->setText("false");//标签显示为错
            label[i]->setStyleSheet("color:red;");//错误，红色
        }
        //显示正确答案
        lab_Answer[i]=new QLabel();
        lab_Answer[i]->setText(QString::fromLocal8Bit("正确答案：")+Completion[i-flag_CH].answer);//显示正确答案
        vBoxLayout[i]->addWidget(lab_Answer[i]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for(int i=flag_CHtoCO;i<titleNum;i++)//简答题
    {
        label[i]->setText("true");//标签显示为对
        label[i]->setStyleSheet("color:green;");//正确，绿色
        score+=10;//得分+10
    }
    ui->label_score->setText(QString::fromLocal8Bit("总分：")+QString::number(score));//显示最终得分
    ui->btn_Submit->setDisabled(true);//提交过答案后，不能重复点击提交

    //传递分数给主界面
    sendScore(score);
}
