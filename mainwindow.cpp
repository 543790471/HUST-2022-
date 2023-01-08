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

    //�����������ݣ������Ծ�
    connect(ui->ptn_Read, SIGNAL(clicked()), this, SLOT(abstractTitle()));
    //���Խ��淢������
    connect(this,SIGNAL(sendSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>)),frm_examination,SLOT(getSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>)));
    //���ճɼ�����
    connect(frm_examination,SIGNAL(sendScore(int)),this,SLOT(getScore(int)));
}

//����
void MainWindow::abstractTitle()
{
    //���ô��ⴰ�ڣ�����ϴ�����
    if(frm_examination==NULL)
    {
        frm_examination = new Frm_examination();
        frm_examination->setAttribute(Qt::WA_DeleteOnClose,true);//�رմ��ⴰ��ʱ�����ڴ�
    }
    //ѡ������ļ�txt
    QString file_path = QFileDialog::getOpenFileName(this,QStringLiteral("��������"),"",tr("Text Files(*.txt)"));//���ļ�����
    QFile f(file_path);//·����
    if(! f.open(QIODevice::ReadOnly|QIODevice::Text))//��ʧ��
          qDebug()<<f.errorString();
    else//�򿪳ɹ�
           qDebug()<<"openok";
    f.seek(0);

    //���������Ŀ���������ĸ�ʽ��stringתΪint
    QString str_Choice_num=ui->lineEdit_Choice_num->text();
    QString str_Completion_num=ui->lineEdit_Completion_num->text();
    QString str_Answer_num=ui->lineEdit_Answer_num->text();
    int int_Choice_num=str_Choice_num.toInt();
    int int_Completion_num=str_Completion_num.toInt();
    int int_Answer_num=str_Answer_num.toInt();

    //����������Ŀ������ֵĽṹ������
    vector<Questiontext> questiontext_Choice(20),questiontext_Completion(20),questiontext_Answer(10);
    //��ͬ������Ŀ����������
    int flag_Choice=0,flag_Completion=0,flag_Answer=0;
    //��ȡ������������������Ŀ������
    QTextStream txtInput(&f);
    txtInput.setCodec("UTF-8");//����UTF-8����
    QString lineStr;
    while(!txtInput.atEnd())
    {
        QString line=txtInput.readLine();//��ȡһ��
        QStringList strlist=line.split(" ");//�ԡ� ���ָ��ַ���
        if(strlist[0]=="CH")//�洢ѡ������Ϣ
        {
            questiontext_Choice[flag_Choice].title=strlist[1];//������Ŀ�ı�
            for(int i=2;i<=5;i++)
                questiontext_Choice[flag_Choice].choice.push_back(strlist[i]);//�ֱ����4����ѡ��
            questiontext_Choice[flag_Choice].answer=strlist[6];//������ȷѡ��
            flag_Choice++;
        }
        else if(strlist[0]=="CO")//�洢�������Ϣ
        {
            questiontext_Completion[flag_Completion].title=strlist[1];//������Ŀ�ı�
            questiontext_Completion[flag_Completion].answer=strlist[2];//������ȷ��
            flag_Completion++;
        }
        else if(strlist[0]=="AN")//�洢�������Ϣ
        {
            questiontext_Answer[flag_Answer].title=strlist[1];
            flag_Answer++;
        }
    }

    //������д���ݣ�����Ŀ��
    vector<int> rand_flag1=randPern(10);//�Ӹ�����������ѡ���⣬�˴�������Ϊ10
    vector<int> rand_flag2=randPern(10);//�Ӹ���������������⣬�˴�������Ϊ10
    vector<int> rand_flag3=randPern(5);//�Ӹ��������������⣬�˴�������Ϊ10
    //�Ƚ�����ѡ����Ŀ����֮ǰ�ľɼ�¼Ԫ�غ��ڴ����
    vector <Questiontext>().swap(selected_Choice);//�����������С����������
    vector <Questiontext>().swap(selected_Completion);
    vector <Questiontext>().swap(selected_Answer);
    //ȡ��ȡ�����ǰnλ�����뱻��ѡ����Ŀ����
    for(int i=0;i<int_Choice_num;i++) selected_Choice.push_back(questiontext_Choice[rand_flag1[i]]);
    for(int i=0;i<int_Completion_num;i++) selected_Completion.push_back(questiontext_Completion[rand_flag2[i]]);
    for(int i=0;i<int_Answer_num;i++) selected_Answer.push_back(questiontext_Answer[rand_flag3[i]]);
}

//�����������������
vector<int> MainWindow::randPern(int num)
{
    srand((int)time(0));//ʱ������
    vector<int> temp;
    for (int i = 0; i < num; i++)
    {
        temp.push_back(i);
    }
    random_shuffle(temp.begin(), temp.end());//�������
    return temp;
}

//���ճɼ�����
void MainWindow::getScore(int score)
{
    ui->label_Score_2->setText(QString::number(score));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//�����ʼ��ť���򿪴�����棬��������ѡ����Ŀ��������
void MainWindow::on_ptn_Exam_clicked()
{
    emit sendSelected(selected_Choice,selected_Completion,selected_Answer);//�������ݣ�ʹ��emit
    frm_examination->show();
}
