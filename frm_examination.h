#ifndef FRM_EXAMINATION_H
#define FRM_EXAMINATION_H

#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTextEdit>
#include <QVBoxLayout>

using namespace std;

namespace Ui {
class Frm_examination;
}

class Frm_examination : public QWidget
{
    Q_OBJECT

public:
    explicit Frm_examination(QWidget *parent = nullptr);

    int flag_CH,flag_CHtoCO,titleNum,score=0;//计算题目数量的flag文件
    class Questiontext//定义一个与Mainwindow::Questiontext相同的类，方能接受题目内容
    {
        public:
            QString title,answer;
            vector<QString> choice;
    };
    vector<Questiontext> Choice,Completion,Answer;//被抽选的题目容器
    //假设一张试卷最多有30个题目，不考虑开销的话可以往大了些，下列容器和题目都有关
    QPushButton* button[30];//跳转至题目的按钮
    QLabel* label[30];//显示题目对错的标签
    QGroupBox* groupBox[30];//答题区框格
    QRadioButton* rtn_Option[120];//选择题选项按钮
    QButtonGroup* rtnGroup_Option[30];//选择题按钮组合
    QVBoxLayout* vBoxLayout[30];//按钮-标签区布局
    QTextEdit* textEdit_Completion[30];//填空题的输入框
    QTextEdit* textEdit_Answer[30];//简答题输入框
    QLabel* lab_Answer[30];//判分后显示的题目答案

    ~Frm_examination();

private:
    Ui::Frm_examination *ui;

signals://信号
    void sendScore(int score);//发送分数给主窗口

private slots://槽
    void getSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>);//获取主窗口传来的题目
    void showTitle(Questiontext question,int flag);//显示题目
    void on_btn_Submit_clicked();//点击提交按钮
};

#endif // FRM_EXAMINATION_H
