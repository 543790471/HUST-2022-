#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "frm_examination.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    vector<int> randPern(int num);
    class Questiontext//题目类
    {
        public:
            QString title,answer;//题目、答案
            vector<QString> choice;//选择题的选项
    };
    vector<Questiontext> selected_Choice,selected_Completion,selected_Answer;//被抽选的题目容器
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Frm_examination *frm_examination;//初始化Frm_examination窗口，实例化对象，可以在mainwindow中调用Frm_examination的函数

signals:
    void sendSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>);//发送抽选的题目给答题窗口

private slots:
    void abstractTitle();//导入题库，抽题
    void on_ptn_Exam_clicked();//开始考试
    void getScore(int score);//取得答题窗口发送的最终分数
};
#endif // MAINWINDOW_H
