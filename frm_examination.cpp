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

    //�ڴ��ڽ����˹ر��¼���Qt���ͷ����������ռ�õ���Դ
    this->setAttribute(Qt::WA_DeleteOnClose);
}

Frm_examination::~Frm_examination()
{
    delete ui;
}

//���������ڷ�������Ŀ��Ϣ,��������ť�ȿؼ�
void Frm_examination::getSelected(vector<Questiontext> selected_Choice,vector<Questiontext> selected_Completion,vector<Questiontext> selected_Answer)
{
    //�������ڷ��͵���Ŀ��Ϣ�浽ȫ�ֺ�������ڸ����������
    Choice=selected_Choice;
    Completion=selected_Completion;
    Answer=selected_Answer;
    //��ȡ��ͬ������Ŀ�����Ľ���flag
    flag_CH=Choice.size();
    flag_CHtoCO=Choice.size()+Completion.size();
    titleNum=Choice.size()+Completion.size()+Answer.size();

    //Ԥ������Ŀ�������ؼ�
    for (int i=0;i<flag_CH;i++ ) //ѡ�����������
    {
        //��ʼ�����ؼ�
        groupBox[i]=new QGroupBox("Choose");
        ui->stackedWidget->addWidget(groupBox[i]);
        rtnGroup_Option[i]=new QButtonGroup();
        rtn_Option[4*i]=new QRadioButton();
        rtn_Option[4*i+1]=new QRadioButton();
        rtn_Option[4*i+2]=new QRadioButton();
        rtn_Option[4*i+3]=new QRadioButton();
        vBoxLayout[i]=new QVBoxLayout;
        //���ð����ı�
        rtn_Option[4*i]->setText(Choice[i].choice[0]);
        rtn_Option[4*i+1]->setText(Choice[i].choice[1]);
        rtn_Option[4*i+2]->setText(Choice[i].choice[2]);
        rtn_Option[4*i+3]->setText(Choice[i].choice[3]);
        //�򰴼�������Ӱ���
        rtnGroup_Option[i]->setExclusive(true);  //������һ�鰴ťֻ�ܵ�ѡ
        rtnGroup_Option[i]->addButton(rtn_Option[4*i]);
        rtnGroup_Option[i]->addButton(rtn_Option[4*i+1]);
        rtnGroup_Option[i]->addButton(rtn_Option[4*i+2]);
        rtnGroup_Option[i]->addButton(rtn_Option[4*i+3]);
        //�򲼾�������Ӱ���������
        vBoxLayout[i]->addWidget(rtn_Option[4*i]);
        vBoxLayout[i]->addWidget(rtn_Option[4*i+1]);
        vBoxLayout[i]->addWidget(rtn_Option[4*i+2]);
        vBoxLayout[i]->addWidget(rtn_Option[4*i+3]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for (int i=flag_CH;i<flag_CHtoCO;i++ ) //������������
    {
        //��ʼ�����ؼ�
        groupBox[i]=new QGroupBox("fill in");
        vBoxLayout[i]=new QVBoxLayout;
        //��ջ������Ӱ���
        ui->stackedWidget->addWidget(groupBox[i]);
        textEdit_Completion[i-flag_CH]=new QTextEdit;
        //�򲼾���������ı�������
        vBoxLayout[i]->addWidget(textEdit_Completion[i-flag_CH]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for (int i=flag_CHtoCO;i<titleNum;i++ ) //������������
    {
        //��ʼ�����ؼ�
        groupBox[i]=new QGroupBox("fill in");
        vBoxLayout[i]=new QVBoxLayout;
        //��ջ������Ӱ���
        ui->stackedWidget->addWidget(groupBox[i]);
        textEdit_Answer[i-flag_CHtoCO]=new QTextEdit;
        //�򲼾���������ı�������
        vBoxLayout[i]->addWidget(textEdit_Answer[i-flag_CHtoCO]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }

    //�յ��ź���Ϣ���ٴ�����ť�ȿؼ�
    QButtonGroup* button_group = new QButtonGroup(this);//��ť��
    button_group->setExclusive(true);  //������һ�鰴ťֻ�ܵ�ѡ
    //ÿ����һ�ζ�Ҫ���QVBoxLayout�ڵĿؼ�����Ȼ���ۻ�
    QLayoutItem* child;
    while ((child = ui->gridLayout->takeAt(0)) != 0)
    {
        //setParentΪNULL����ֹɾ��֮����治��ʧ
        if (child->widget())
        {
            child->widget()->setParent(NULL);
        }
        delete child;
    }
    //���ð����ͱ�ǩ
    for (int i = 0; i < titleNum; i++)
    {
        //��ʼ�����ؼ��������ó�ʼ�ı�
        button[i]=new QPushButton;
        button[i]->setText(QString::number(i+1));
        label[i]=new QLabel;
        label[i]->setText("null");
        //���ؼ����벼���飬�˴�������У�ÿ����ռ���������񣬷ֱ��Ű�ť�ͱ�ǩ
        ui->gridLayout->addWidget(button[i], 2*(i/6), i%6);
        ui->gridLayout->addWidget(label[i], 2*(i/6)+1, i%6);
//        ui->verticalLayout->addStretch(0);//ÿ����ť��ǰ��������һ������������֤��ť���ȷֲ�
        button_group->addButton(button[i]);  //��ť���飬����ֻ��һ��
        //���ݲ�ͬ����
        if(i<Choice.size())//ѡ����
        {
            //����ĸ���������ʾ��Ӧ����Ŀ����
            connect(button[i], &QPushButton::clicked, this, [=]() {
            //�Լ�Ҫ��ʵ�ֵ�Lambda�ۺ������˴�Ϊ��ʾ��Ŀ
               showTitle(Choice[i],i);
            });
        }
        else if(i>=Choice.size()&&i<(Choice.size()+Completion.size()))//�����
        {
            connect(button[i], &QPushButton::clicked, this, [=]() {showTitle(Completion[i-flag_CH],i);});
        }
        else//�����
        {
            connect(button[i], &QPushButton::clicked, this, [=]() {showTitle(Answer[i-flag_CHtoCO],i);});
        }
    }
}

//��ʾ��Ŀ�ı��Լ��������
void Frm_examination::showTitle(Questiontext question,int flag)
{
    ui->label_Title->setText(question.title);//����Ŀ���ֵ�����Ŀ��ǩ
    ui->stackedWidget->setCurrentIndex(flag+2);//�򿪶�Ӧ�Ĵ������.stackedWidget�ؼ�����ʱ������Դ�����widget(page1,page2)
    groupBox[flag]->show();
}

//��������о�
void Frm_examination::on_btn_Submit_clicked()
{
    for(int i=0;i<flag_CH;i++)//ѡ����
    {
        //���ð�����״̬ID���ҵ����б���ѡ�İ���
        rtnGroup_Option[i]->setId(rtn_Option[4*i],0);//rtn_Option[4*i]��Id��Ϊ0
        rtnGroup_Option[i]->setId(rtn_Option[4*i+1],1);
        rtnGroup_Option[i]->setId(rtn_Option[4*i+2],2);
        rtnGroup_Option[i]->setId(rtn_Option[4*i+3],3);
        int id=rtnGroup_Option[i]->checkedId();//ͨ��checkedIdȥ�ж�
        if(id!=-1)//����а�����ѡ�У���id��-1
        {
            if(id==int(Choice[i].answer.toStdString().at(0))-65)//ת�룬��QString��int(ascii)
            {
                label[i]->setText("true");//��ǩ��ʾΪ��
                label[i]->setStyleSheet("color:green;");//��ȷ����ɫ
                score+=5;//�÷�+5
            }
            else
            {
                label[i]->setText("false");//��ǩ��ʾΪ��
                label[i]->setStyleSheet("color:red;");//���󣬺�ɫ
            }
        }
        else
        {
            label[i]->setText("false");//��ǩ��ʾΪ��
            label[i]->setStyleSheet("color:red;");//���󣬺�ɫ
        }
        //��ʾ��ȷ��
        lab_Answer[i]=new QLabel();
        lab_Answer[i]->setText(QString::fromLocal8Bit("��ȷѡ�")+Choice[i].answer.at(0));//ȡ���𰸵�һ���ַ���Ϊ��ȷѡ��
        vBoxLayout[i]->addWidget(lab_Answer[i]);//���𰸱�ǩ���벼����
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for(int i=flag_CH;i<flag_CHtoCO;i++)//�����
    {
        if(textEdit_Completion[i-flag_CH]->toPlainText()==Completion[i-flag_CH].answer)
        {
            label[i]->setText("true");//��ǩ��ʾΪ��
            label[i]->setStyleSheet("color:green;");//��ȷ����ɫ
            score+=5;//�÷�+5
        }
        else
        {
            label[i]->setText("false");//��ǩ��ʾΪ��
            label[i]->setStyleSheet("color:red;");//���󣬺�ɫ
        }
        //��ʾ��ȷ��
        lab_Answer[i]=new QLabel();
        lab_Answer[i]->setText(QString::fromLocal8Bit("��ȷ�𰸣�")+Completion[i-flag_CH].answer);//��ʾ��ȷ��
        vBoxLayout[i]->addWidget(lab_Answer[i]);
        groupBox[i]->setLayout(vBoxLayout[i]);
    }
    for(int i=flag_CHtoCO;i<titleNum;i++)//�����
    {
        label[i]->setText("true");//��ǩ��ʾΪ��
        label[i]->setStyleSheet("color:green;");//��ȷ����ɫ
        score+=10;//�÷�+10
    }
    ui->label_score->setText(QString::fromLocal8Bit("�ܷ֣�")+QString::number(score));//��ʾ���յ÷�
    ui->btn_Submit->setDisabled(true);//�ύ���𰸺󣬲����ظ�����ύ

    //���ݷ�����������
    sendScore(score);
}
