#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    frm_examination = new Frm_examination();

    //根据输入数据，生成试卷
    connect(ui->ptn_Read, SIGNAL(clicked()), this, SLOT(abstractTitle()));
    //向考试界面发送数据
    connect(this,SIGNAL(sendSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>)),frm_examination,SLOT(getSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>)));
    //接收成绩数据
    connect(frm_examination,SIGNAL(sendScore(int)),this,SLOT(getScore(int)));
}

//抽题
void MainWindow::abstractTitle()
{
    //重置答题窗口，清除上次数据
    if(frm_examination==NULL)
    {
        frm_examination = new Frm_examination();
        frm_examination->setAttribute(Qt::WA_DeleteOnClose,true);//关闭答题窗口时清理内存
    }
    //选择题库文件txt
    QString file_path = QFileDialog::getOpenFileName(this,QStringLiteral("导入数据"),"",tr("Text Files(*.txt)"));//打开文件窗口
    QFile f(file_path);//路径类
    if(! f.open(QIODevice::ReadOnly|QIODevice::Text))//打开失败
          qDebug()<<f.errorString();
    else//打开成功
           qDebug()<<"openok";
    f.seek(0);

    //将输入的题目数量参数的格式由string转为int
    QString str_Choice_num=ui->lineEdit_Choice_num->text();
    QString str_Completion_num=ui->lineEdit_Completion_num->text();
    QString str_Answer_num=ui->lineEdit_Answer_num->text();
    int int_Choice_num=str_Choice_num.toInt();
    int int_Completion_num=str_Completion_num.toInt();
    int int_Answer_num=str_Answer_num.toInt();

    //建立储存题目相关文字的结构体容器
    vector<Questiontext> questiontext_Choice(20),questiontext_Completion(20),questiontext_Answer(10);
    //不同种类题目总数计数器
    int flag_Choice=0,flag_Completion=0,flag_Answer=0;
    //读取文字流，建立所有题目的索引
    QTextStream txtInput(&f);
    txtInput.setCodec("UTF-8");//设置UTF-8编码
    QString lineStr;
    while(!txtInput.atEnd())
    {
        QString line=txtInput.readLine();//读取一行
        QStringList strlist=line.split(" ");//以“ ”分割字符串
        if(strlist[0]=="CH")//存储选择题信息
        {
            questiontext_Choice[flag_Choice].title=strlist[1];//存入题目文本
            for(int i=2;i<=5;i++)
                questiontext_Choice[flag_Choice].choice.push_back(strlist[i]);//分别存入4个备选项
            questiontext_Choice[flag_Choice].answer=strlist[6];//存入正确选项
            flag_Choice++;
        }
        else if(strlist[0]=="CO")//存储填空题信息
        {
            questiontext_Completion[flag_Completion].title=strlist[1];//存入题目文本
            questiontext_Completion[flag_Completion].answer=strlist[2];//存入正确答案
            flag_Completion++;
        }
        else if(strlist[0]=="AN")//存储简答题信息
        {
            questiontext_Answer[flag_Answer].title=strlist[1];
            flag_Answer++;
        }
    }

    //根据填写数据，抽题目号
    vector<int> rand_flag1=randPern(10);//从该类型题库里抽选择题，此处定数量为10
    vector<int> rand_flag2=randPern(10);//从该类型题库里抽填空题，此处定数量为10
    vector<int> rand_flag3=randPern(5);//从该类型题库里抽简答题，此处定数量为10
    //先将被抽选的题目容器之前的旧记录元素和内存清空
    vector <Questiontext>().swap(selected_Choice);//清除容器并最小化它的容量
    vector <Questiontext>().swap(selected_Completion);
    vector <Questiontext>().swap(selected_Answer);
    //取抽取结果的前n位，存入被抽选的题目容器
    for(int i=0;i<int_Choice_num;i++) selected_Choice.push_back(questiontext_Choice[rand_flag1[i]]);
    for(int i=0;i<int_Completion_num;i++) selected_Completion.push_back(questiontext_Completion[rand_flag2[i]]);
    for(int i=0;i<int_Answer_num;i++) selected_Answer.push_back(questiontext_Answer[rand_flag3[i]]);
}

//生成随机整数并排序
vector<int> MainWindow::randPern(int num)
{
    srand((int)time(0));//时间因子
    vector<int> temp;
    for (int i = 0; i < num; i++)
    {
        temp.push_back(i);
    }
    random_shuffle(temp.begin(), temp.end());//随机排列
    return temp;
}

//接收成绩数据
void MainWindow::getScore(int score)
{
    ui->label_Score_2->setText(QString::number(score));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//点击开始按钮，打开答题界面，并将被抽选的题目容器传递
void MainWindow::on_ptn_Exam_clicked()
{
    emit sendSelected(selected_Choice,selected_Completion,selected_Answer);//发送数据，使用emit
    frm_examination->show();
}
