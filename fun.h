#ifndef FUN_H
#define FUN_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QMetaObject>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <iostream>
#include <opencv2/core/core.hpp>       //opencv库图像处理
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QPalette>
#include <QTextImageFormat>
#include <QTextCursor>
#include <QTextDocument>
#include <QPixmap>
#include <QTextDocumentFragment>
#include <QImage>
#include <QByteArray>
#include <QPoint>
#include <QLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QFrame>
#include <QPixmap>
#include <QPainter>
#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QHttpMultiPart>
#include <QProgressBar>
#include <QSslSocket>


using namespace cv;
using namespace std;




namespace Ui {                           //主界面
class fun;
}

class fun : public QMainWindow
{
    Q_OBJECT

public:
    explicit fun(QWidget *parent = nullptr);
    ~fun();
    void Main_Ui(QWidget *w =nullptr);     //主界面
    void File_Ui(QMenuBar  &menubar,QWidget *q =nullptr);
    void Ctrl_Ui(QMenuBar  &menubar,QWidget *q =nullptr);
    void Typography_Ui(QMenuBar  &menubar,QWidget *q =nullptr);
    void Image_Ui(QMenuBar  &menubar,QWidget *q =nullptr);
    void Page_Layout(QMenuBar  &menubar,QWidget *q =nullptr);
    void Ai_Ui(QMenuBar  &menubar,QWidget *q =nullptr);

signals:
    void triggered();
    void finished();
protected slots:
    void New_file();
    void Open_file();
    void Save_file();
    void IN_file();
    void Out_file();
    void Exit_file();
    void Ctrl_t();
    void Ctrl_c();
    void Ctrl_v();
    void Ctrl_z();
    void Ctrl_p();
    void Font();
    void Font_Left_Pare();
    void Font_Rigth_Pare();
    void Font_Centor_Pare();
    void Font_Color();
    void Image_1();
    void Image_2();
    void Image_3();
    void Image_4();
    void Image_5();
    void Image_6();
    void Image_7();
    void Image_8();
    void Image_9();
    void Pare();
    void Pare_2();
    void Pare_3();
    void AI_1();
    void AI_2();
    void Read_data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::fun *ui;
    QNetworkAccessManager * m_ager;
    QNetworkReply  *m_reply;
};




#endif // FUN_H
