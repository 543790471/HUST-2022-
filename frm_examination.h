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

    int flag_CH,flag_CHtoCO,titleNum,score=0;//������Ŀ������flag�ļ�
    class Questiontext//����һ����Mainwindow::Questiontext��ͬ���࣬���ܽ�����Ŀ����
    {
        public:
            QString title,answer;
            vector<QString> choice;
    };
    vector<Questiontext> Choice,Completion,Answer;//����ѡ����Ŀ����
    //����һ���Ծ������30����Ŀ�������ǿ����Ļ�����������Щ��������������Ŀ���й�
    QPushButton* button[30];//��ת����Ŀ�İ�ť
    QLabel* label[30];//��ʾ��Ŀ�Դ�ı�ǩ
    QGroupBox* groupBox[30];//���������
    QRadioButton* rtn_Option[120];//ѡ����ѡ�ť
    QButtonGroup* rtnGroup_Option[30];//ѡ���ⰴť���
    QVBoxLayout* vBoxLayout[30];//��ť-��ǩ������
    QTextEdit* textEdit_Completion[30];//�����������
    QTextEdit* textEdit_Answer[30];//����������
    QLabel* lab_Answer[30];//�зֺ���ʾ����Ŀ��

    ~Frm_examination();

private:
    Ui::Frm_examination *ui;

signals://�ź�
    void sendScore(int score);//���ͷ�����������

private slots://��
    void getSelected(vector<Questiontext>,vector<Questiontext>,vector<Questiontext>);//��ȡ�����ڴ�������Ŀ
    void showTitle(Questiontext question,int flag);//��ʾ��Ŀ
    void on_btn_Submit_clicked();//����ύ��ť
};

#endif // FRM_EXAMINATION_H
