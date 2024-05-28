#include "fun.h"
#include "ui_fun.h"


fun::fun(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fun)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请输入你的问题");
    ui->lineEdit->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px");
    ui->pushButton->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px");
    ui->textEdit->setStyleSheet("border-style:solid;border-width:1px;border-color:black");
}


fun::~fun()
{
    delete ui;
    delete m_reply;
    delete m_ager;
}

void fun::Main_Ui(QWidget *q)     //主界面
{
    QMainWindow  *p=qobject_cast <QMainWindow *>(q);   //数据类型强转      Qmainwindow  类提供菜单栏 状态栏 界面完整
    if(!p)    //窗口不存在
    {
        return ;
    }
    p->setWindowTitle("印刷排版系统---Version 1.1.0");
    QMenuBar  *menubar=new QMenuBar(p);      //菜单栏添加到窗口中
    p->setMenuBar(menubar);
    File_Ui(*menubar,p);
    Ctrl_Ui(*menubar,p);
    Typography_Ui(*menubar,p);
    Image_Ui(*menubar,p);
    Page_Layout(*menubar,p);
    Ai_Ui(*menubar,p);
    p->show();
}

void fun::File_Ui(QMenuBar  &menubar,QWidget *q)     //文件菜单
{
    QMenu  *file=new QMenu("文件",q);
    menubar.addMenu(file);     //菜单加入到菜单栏中
    QAction  *newfile=new QAction("新建文件",q);      //菜单项加入到菜单中
    file->addAction(newfile);
    connect(newfile,SIGNAL(triggered()), this,SLOT(New_file()));    //新建
    QAction  *openfile=new QAction("打开文件",q);      //菜单项加入到菜单中
    file->addAction(openfile);
    connect(openfile,SIGNAL(triggered()), this,SLOT(Open_file()));
    QAction  *savefile=new QAction("保存文件",q);      //菜单项加入到菜单中
    file->addAction(savefile);
    connect(savefile,SIGNAL(triggered()), this,SLOT(Save_file()));
    QAction  *q2=new QAction("导入",q);      //菜单项加入到菜单中
    file->addAction(q2);
    connect(q2,SIGNAL(triggered()), this,SLOT(IN_file()));
    QAction *m=new QAction("导出",q);      //菜单项加入到菜单中
    file->addAction(m);
    connect(m,SIGNAL(triggered()), this,SLOT(Out_file()));
    QAction  *exitfile=new QAction("退出",q);      //菜单项加入到菜单中
    file->addAction(exitfile);
    connect(exitfile,SIGNAL(triggered()), this,SLOT(Exit_file()));
}

void fun::Ctrl_Ui(QMenuBar &menubar,QWidget *q)     //编辑菜单
{
    QMenu  *ctrl=new QMenu("编辑",q);
    menubar.addMenu(ctrl);     //菜单加入到菜单栏中
    QAction  *v=new QAction("剪切",q);      //菜单项加入到菜单中
    ctrl->addAction(v);
    connect(v,SIGNAL(triggered()), this,SLOT(Ctrl_t()));
    QAction  *c=new QAction("复制",q);      //菜单项加入到菜单中
    ctrl->addAction(c);
    connect(c,SIGNAL(triggered()), this,SLOT(Ctrl_c()));
    QAction  *z=new QAction("粘贴",q);      //菜单项加入到菜单中
    ctrl->addAction(z);
    connect(z,SIGNAL(triggered()), this,SLOT(Ctrl_v()));
    QAction  *a=new QAction("撤回",q);      //菜单项加入到菜单中
    ctrl->addAction(a);
    connect(a,SIGNAL(triggered()), this,SLOT(Ctrl_z()));
    QAction  *l=new QAction("清除",q);      //菜单项加入到菜单中
    ctrl->addAction(l);
    connect(l,SIGNAL(triggered()), this,SLOT(Ctrl_p()));
}

void fun::Typography_Ui(QMenuBar &menubar,QWidget *q)     //文字排版
{
    QMenu  *par=new QMenu("文字排版",q);
    menubar.addMenu(par);     //菜单加入到菜单栏中
    QAction  *v=new QAction("文字字体",q);      //菜单项加入到菜单中
    par->addAction(v);
    connect(v,SIGNAL(triggered()), this,SLOT(Font()));
    QAction  *c=new QAction("文字左对齐",q);      //菜单项加入到菜单中
    par->addAction(c);
    connect(c,SIGNAL(triggered()), this,SLOT(Font_Left_Pare()));
    QAction  *c2=new QAction("文字右对齐",q);      //菜单项加入到菜单中
    par->addAction(c2);
    connect(c2,SIGNAL(triggered()), this,SLOT(Font_Rigth_Pare()));
    QAction  *c3=new QAction("文字居中对齐",q);      //菜单项加入到菜单中
    par->addAction(c3);
    connect(c3,SIGNAL(triggered()), this,SLOT(Font_Centor_Pare()));
    QAction  *z=new QAction("文字颜色",q);      //菜单项加入到菜单中
    par->addAction(z);
    connect(z,SIGNAL(triggered()), this,SLOT(Font_Color()));
}

void fun::Image_Ui(QMenuBar &menubar,QWidget *q)    //图像处理
{
    QMenu  *par=new QMenu("图像处理",q);
    menubar.addMenu(par);     //菜单加入到菜单栏中
    QAction  *v=new QAction("彩色图像",q);      //菜单项加入到菜单中
    par->addAction(v);
    connect(v,SIGNAL(triggered()), this,SLOT(Image_1()));
    QAction  *c=new QAction("灰色图像",q);      //菜单项加入到菜单中
    par->addAction(c);
    connect(c,SIGNAL(triggered()), this,SLOT(Image_2()));
    QAction  *z=new QAction("对比度调整",q);      //菜单项加入到菜单中
    par->addAction(z);
    connect(z,SIGNAL(triggered()), this,SLOT(Image_3()));
    QAction  *q2=new QAction("亮度调整",q);      //菜单项加入到菜单中
    par->addAction(q2);
    connect(q2,SIGNAL(triggered()), this,SLOT(Image_4()));
    QAction  *a=new QAction("旋转",q);      //菜单项加入到菜单中
    par->addAction(a);
    connect(a,SIGNAL(triggered()), this,SLOT(Image_5()));
    QAction  *l=new QAction("缩放",q);      //菜单项加入到菜单中
    par->addAction(l);
    connect(l,SIGNAL(triggered()), this,SLOT(Image_6()));
    QAction  *n=new QAction("色彩空间转换",q);      //菜单项加入到菜单中
    par->addAction(n);
    connect(n,SIGNAL(triggered()), this,SLOT(Image_7()));
    QAction  *b=new QAction("裁剪",q);      //菜单项加入到菜单中
    par->addAction(b);
    connect(b,SIGNAL(triggered()), this,SLOT(Image_8()));
    QAction  *k=new QAction("图像分割",q);      //菜单项加入到菜单中
    par->addAction(k);
    connect(k,SIGNAL(triggered()), this,SLOT(Image_9()));
}

void fun::Page_Layout(QMenuBar &menubar,QWidget *q)    //页面布局
{
    QMenu  *par=new QMenu("页面布局",q);
    menubar.addMenu(par);     //菜单加入到菜单栏中
    QAction  *v=new QAction("页面文字排版",q);      //菜单项加入到菜单中
    par->addAction(v);
    connect(v,SIGNAL(triggered()), this,SLOT(Pare()));
    QAction  *v2=new QAction("页面图像排版",q);      //菜单项加入到菜单中
    par->addAction(v2);
    connect(v2,SIGNAL(triggered()), this,SLOT(Pare_2()));
    QAction  *v3=new QAction("导出",q);      //菜单项加入到菜单中
    par->addAction(v3);
    connect(v3,SIGNAL(triggered()), this,SLOT(Pare_3()));
}

void fun::Ai_Ui(QMenuBar &menubar,QWidget *q)     //AI识别   解答
{
    QMenu  *par=new QMenu("AI",q);
    menubar.addMenu(par);     //菜单加入到菜单栏中
    QAction  *v=new QAction("AI识别",q);      //菜单项加入到菜单中
    par->addAction(v);
    connect(v,SIGNAL(triggered()), this,SLOT(AI_1()));
    QAction  *c=new QAction("Chat-Boot ",q);      //菜单项加入到菜单中
    par->addAction(c);
    connect(c,SIGNAL(triggered()), this,SLOT(AI_2()));
}


void fun::on_pushButton_clicked()      //上传图片
{
    QString  str=QFileDialog::getOpenFileName(this,tr("选择图片"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        QImage  image(str);    //加载图片
        if(!image.isNull())   //加载成功
        {
           QTextCursor p=ui->textEdit->textCursor();   //获取光标
           p.movePosition(QTextCursor::NoMove);
           QTextImageFormat mat;     //在富文本框中嵌入图像
           mat.setName(str);
           p.insertImage(mat);
        }
        else
        {
            QMessageBox::warning(this,tr("选择图片"),tr("图片加载失败"));
        }
    }
    else
    {
        QMessageBox::warning(this,tr("选择图片"),tr("上传图片失败"));
    }
}



void fun::New_file()     //新建
{
    QString  str=QFileDialog::getSaveFileName(this,tr("新建文件"),"",tr("All Files(*)"));
    if(!str.isEmpty())   //路径存在
    {
        QFile file(str);
        if(file.open(QIODevice::WriteOnly))    //文件打开成功
        {
            QTextStream out(&file);   //文本流
            QString  str_file=ui->lineEdit->text();     //获取文本框中的文本
            out <<str_file;   //输出
            file.close();
            ui->lineEdit->clear();     //新建成功后清除文本框数据
        }
        else
        {
            QMessageBox::warning(this,tr("新建文件"),tr("新建文件失败"));
        }
    }
    else
    {
        return ;
    }
}



void fun::Open_file()    //打开
{
    QString  str=QFileDialog::getOpenFileName(this,tr("打开文件"),"",tr("All Files(*)"));
    if(!str.isEmpty())   //路径存在
    {
        QFile file(str);
        if(file.open(QIODevice::ReadOnly))    //文件打开成功
        {
            QTextStream in(&file);   //文本流
            QString  file_str=in.readAll();   //读取文件中的数据
            ui->textEdit->setText(file_str);
            file.close();
        }
        else
        {
            QMessageBox::warning(this,tr("打开文件"),tr("打开文件失败"));
        }
    }
}

void fun::Save_file()    //保存文件
{
    QString  str=QFileDialog::getSaveFileName(this,tr("保存文件"),"",tr("All Files(*)"));
    if(!str.isEmpty())   //路径存在
    {
        QFile file(str);
        if(file.open(QIODevice::WriteOnly))    //文件打开成功
        {
            QTextStream out(&file);   //文本流
            QString  str_file=ui->lineEdit->text();     //获取文本框中的文本
            out <<str_file;   //输出
            file.close();
        }
        else
        {
            QMessageBox::warning(this,tr("保存文件"),tr("保存文件失败"));
        }
    }
    else
    {
        return ;
    }
}

void fun::IN_file()    //导入文件
{
    QString  str=QFileDialog::getOpenFileName(this,tr("导入文件"),"",tr("All Files(*)"));
    if(!str.isEmpty())   //路径存在
    {
        QFile file(str);
        if(file.open(QIODevice::ReadOnly))    //文件打开成功
        {
            QTextStream in(&file);   //文本流
            QString  file_str=in.readAll();   //读取文件中的数据
            ui->textEdit->append(file_str);    //导入是在原来基础上增加数据
            file.close();
        }
        else
        {
            QMessageBox::warning(this,tr("导入文件"),tr("导入文件失败"));
        }
    }
}

void fun::Out_file()   //导出文件
{
    QString  str=QFileDialog::getSaveFileName(this,tr("导出文件"),"",tr("All Files(*)"));
    if(!str.isEmpty())   //路径存在
    {
        QFile file(str);
        if(file.open(QIODevice::WriteOnly))    //文件打开成功
        {
            QTextStream out(&file);   //文本流
            QString  str_file=ui->lineEdit->text();     //获取文本框中的文本
            out <<str_file;   //输出
            QString  str2=ui->textEdit->toPlainText();
            out <<str2;
            file.close();
            ui->lineEdit->clear();     //新建成功后清除文本框数据
            ui->textEdit->clear();
        }
        else
        {
            QMessageBox::warning(this,tr("导出文件"),tr("导出文件失败"));
        }
    }
    else
    {
        return ;
    }
}

void fun::Exit_file()   //退出
{
    QMessageBox   box;
    int ret=box.warning(this,"退出","是否需要退出",QMessageBox::No,QMessageBox::Yes);
    if(ret==QMessageBox::Yes)
    {
        ui->lineEdit->clear();
        ui->textEdit->clear();
        this->close();
    }
}


void fun::Ctrl_t()    //剪切
{
    if((ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()==nullptr)||(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()!=nullptr)||(ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()!=nullptr))
    {
        ui->lineEdit->cut();
        ui->textEdit->textCursor().selectedText();
    }
    else if(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()==nullptr)
    {
        QMessageBox  box;
        int ret=box.warning(this,"剪切","当前文本为空!请输入数据",QMessageBox::Yes);
        if(ret==QMessageBox::Yes)
        {
            box.close();
        }
    }
}


void fun::Ctrl_c()    //复制
{
    if((ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()==nullptr)||(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()!=nullptr)||(ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()!=nullptr))
    {
        ui->lineEdit->copy();
        ui->textEdit->copy();
    }
    else if(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()==nullptr)
    {
        QMessageBox  box;
        int ret=box.warning(this,"复制","当前文本为空!请输入数据",QMessageBox::Yes);
        if(ret==QMessageBox::Yes)
        {
            box.close();
        }
    }
}


void fun::Ctrl_v()    //粘贴
{
    if((ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()==nullptr)||(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()!=nullptr)||(ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()!=nullptr))
    {
        ui->lineEdit->paste();
        ui->textEdit->paste();
    }
    else if(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()==nullptr)
    {
        QMessageBox  box;
        int ret=box.warning(this,"粘贴","当前文本为空!请输入数据",QMessageBox::Yes);
        if(ret==QMessageBox::Yes)
        {
            box.close();
        }
    }
}

void fun::Ctrl_z()    //撤回
{
    if((ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()==nullptr)||(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()!=nullptr)||(ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()!=nullptr))
    {
        ui->lineEdit->undo();
        ui->textEdit->undo();
    }
    else if(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()==nullptr)
    {
        QMessageBox  box;
        int ret=box.warning(this,"撤回","当前文本为空!请输入数据",QMessageBox::Yes);
        if(ret==QMessageBox::Yes)
        {
            box.close();
        }
    }
}


void fun::Ctrl_p()     //清除
{
    if((ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()==nullptr)||(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()!=nullptr)||(ui->lineEdit->text()!=nullptr&&ui->textEdit->toPlainText()!=nullptr))
    {
        ui->lineEdit->clear();
        ui->textEdit->clear();
    }
    else if(ui->lineEdit->text()==nullptr&&ui->textEdit->toPlainText()==nullptr)
    {
        QMessageBox  box;
        int ret=box.warning(this,"清除","当前文本为空!",QMessageBox::Yes);
        if(ret==QMessageBox::Yes)
        {
            box.close();
        }
    }
}


void fun::Font()    //文字字体
{
    bool  ok;
    QFont  font=QFontDialog::getFont(&ok,this);
    if(ok)     //确定
    {
        ui->lineEdit->setFont(font);
        ui->textEdit->setFont(font);
    }
}


void fun::Font_Left_Pare()    //左对齐
{
    ui->lineEdit->setAlignment(Qt::AlignLeft);
    ui->textEdit->setAlignment(Qt::AlignLeft);
}


void fun::Font_Rigth_Pare()    //右对齐
{
    ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->textEdit->setAlignment(Qt::AlignRight);
}


void fun::Font_Centor_Pare()   //居中对齐
{
    ui->lineEdit->setAlignment(Qt::AlignHCenter);
    ui->textEdit->setAlignment(Qt::AlignHCenter);
}


void fun::Font_Color()   //颜色
{
    QPalette  p=ui->lineEdit->palette();    //获取文本框  高级文本框的校色板
    QPalette  q=ui->textEdit->palette();
    QColor  color=QColorDialog::getColor();
    if(color.isValid())    //选取了颜色
    {
        p.setColor(QPalette::Text,color);   //设置校色板的颜色
        q.setColor(QPalette::Text,color);
        ui->lineEdit->setPalette(p);   //设置字体颜色
        ui->textEdit->setPalette(q);
    }
}

void fun::Image_1()    //彩色图像
{
    QString  str=QFileDialog::getOpenFileName(this,tr("彩色图像"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            namedWindow("彩色图像",WINDOW_NORMAL);
            imshow("彩色图像",mat);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("彩色图像"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("彩色图像"),tr("图像路径不存在"));
    }
}

void fun::Image_2()   //灰色图像
{
    QString  str=QFileDialog::getOpenFileName(this,tr("灰色图像"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_GRAYSCALE);
        if(!mat.empty())   //图像存在
        {
            namedWindow("灰色图像",WINDOW_NORMAL);
            imshow("灰色图像",mat);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("灰色图像"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("灰色图像"),tr("图像路径不存在"));
    }
}

void fun::Image_3()    //对比度
{
    QString  str=QFileDialog::getOpenFileName(this,tr("对比度"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            Mat m;
            cvtColor(mat,m,COLOR_RGB2GRAY);    //彩色图像转换为灰色图像    //空间转换
            double min,max;
            minMaxLoc(m,&min,&max);
            double temp=255.0/(max-min);    //缩放因子  调整对比度
            Mat finall;
            m.convertTo(finall,-1,temp,-min*temp);   //数据类型转换 32bite F
            namedWindow("对比度",WINDOW_NORMAL);
            imshow("对比度",finall);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("对比度图像"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("对比度图像"),tr("图像路径不存在"));
    }
}

void fun::Image_4()   //亮度
{
    QString  str=QFileDialog::getOpenFileName(this,tr("亮度"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            Mat m;
            cvtColor(mat,m,COLOR_RGB2HSV);    //彩色图像转换为HSV图像 对V通道修改   //空间转换
            for(int i=0;i<m.rows;++i)     //对每个像素点进行修改   （二维矩阵）
            {
                for(int j=0;j<m.cols;++j)
                {
                    Vec3b &p=m.at<Vec3b>(i,j);   //获取图像RGB的向量
                    int v=min(255,p[2]+5);   //图像亮度增强
                    p[2]=static_cast<uchar>(v);    //数据类型强转    对所有通道都增强
                }
            }
            namedWindow("亮度",WINDOW_NORMAL);
            imshow("亮度",m);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("亮度图像"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("亮度图像"),tr("图像路径不存在"));
    }
}

void fun::Image_5()  //旋转
{
    QString  str=QFileDialog::getOpenFileName(this,tr("旋转"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            double  p=-90.0;   //旋转角度
            Point centor(mat.rows/2,mat.cols/2);   //图像中心点
            Mat m=getRotationMatrix2D(centor,p,1.0);   //计算旋转矩阵 （不缩放）  （图像）
            Mat finall;
            warpAffine(mat,finall,m,mat.size());   //旋转后的图像
            namedWindow("旋转",WINDOW_NORMAL);
            imshow("旋转",finall);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("旋转图像"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("旋转图像"),tr("图像路径不存在"));
    }
}

void fun::Image_6()   //缩放
{
    QString  str=QFileDialog::getOpenFileName(this,tr("缩放"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            double p=2.0;   //缩放因子
            int new_width=cvRound(mat.cols*p);     //图像新尺寸
            int new_high=cvRound(mat.rows*p);
            Mat finall;
            cv::resize(mat,finall,cv::Size(new_width,new_high),0,0,cv::INTER_LINEAR);   //缩放图像   防止命名冲突
            namedWindow("缩放",WINDOW_NORMAL);
            imshow("缩放",finall);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("缩放图像"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("缩放图像"),tr("图像路径不存在"));
    }
}

void fun::Image_7()   //空间转换
{
    QString  str=QFileDialog::getOpenFileName(this,tr("空间转换"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            Mat m;
            cvtColor(mat,m,COLOR_RGB2Lab);   //RGB转换为LAB
            namedWindow("空间转换",WINDOW_NORMAL);
            imshow("空间转换",m);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("空间转换"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("空间转换"),tr("图像路径不存在"));
    }
}

void fun::Image_8()   //裁剪
{
    QString  str=QFileDialog::getOpenFileName(this,tr("裁剪"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            int x=100;    //裁剪区域
            int y=100;
            int width=200;
            int high=200;
            int x2=x+width;
            int y2=y+high;
            x2=min(x2,mat.cols);    //区域限制
            y2=min(y2,mat.rows);
            Mat m=mat(cv::Rect(x,y,x2-x,y2-y));   //裁剪图像
            namedWindow("裁剪",WINDOW_NORMAL);
            imshow("裁剪",m);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("裁剪"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("裁剪"),tr("图像路径不存在"));
    }
}

void fun::Image_9()   //分割
{
    QString  str=QFileDialog::getOpenFileName(this,tr("分割"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        Mat  mat=imread(str.toStdString(),IMREAD_COLOR);
        if(!mat.empty())   //图像存在
        {
            Mat p,q,mask;
            cvtColor(mat,p,COLOR_RGB2BGR);
            threshold(p,q,127,255,THRESH_BINARY);    //图像分割
            q.convertTo(mask,CV_8U);
            p.setTo(Scalar(0,0,0),mask);   //setto填充   Scalar四个元素向量（通道）
            namedWindow("分割",WINDOW_NORMAL);
            imshow("分割",p);
            waitKey(0);
        }
        else
        {
            QMessageBox::warning(this,tr("分割"),tr("加载失败"));
        }
    }
    else   //不存在
    {
        QMessageBox::warning(this,tr("分割"),tr("图像路径不存在"));
    }
}


void fun::Pare()    //页面文字设置
{
    QVBoxLayout  *p=new QVBoxLayout;    //垂直布局
    QTextEdit *r=new QTextEdit;
    p->addWidget(r);
    QFrame *w=new QFrame;
    w->setFrameShape(QFrame::HLine);   //设置框架形状  水平线
    w->setFrameShadow(QFrame::Plain);   //设置窗口的阴影样式   无阴影
    w->setStyleSheet("border:1px solid black;");
    p->addWidget(w);
    QScrollArea *area=new QScrollArea;     //滚动条
    area->setWidgetResizable(true);    //可以拖动窗口
    QWidget *q=new QWidget(area);
    q->setLayout(p);
    area->setWidget(q);
    setCentralWidget(area);
    const   int pare_high=300;   //页面阈值   高度
    connect(area->verticalScrollBar(),&QScrollBar::valueChanged,[this,area,pare_high]()    //QScrollBar 类可以滚动内容
    {
        int curhigh=area->viewport()->height();   //获取窗口区域的部件   当前高度
        int curlocation=area->verticalScrollBar()->value();     //当前位置
        int high=area->widget()->height();   //页面总高度
        if(curhigh+curlocation>=pare_high&&curhigh+curlocation<high)   //进入下一个页面
        {
            area->widget()->adjustSize();   //调整窗口大小
        }
    });
}


void fun::Pare_2()   //页面图像设置
{
    QString  str=QFileDialog::getOpenFileName(this,tr("图像"),"",tr("image File(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        QImage  image(str);    //加载图片
        if(!image.isNull())   //加载成功
        {
           QTextCursor p=ui->textEdit->textCursor();   //获取光标
           p.movePosition(QTextCursor::NoMove);
           QTextImageFormat mat;     //在富文本框中嵌入图像
           mat.setName(str);
           p.insertImage(mat);
        }
        else
        {
            QMessageBox::warning(this,tr("图像"),tr("图片加载失败"));
        }
    }
    else
    {
        QMessageBox::warning(this,tr("图像"),tr("上传图片失败"));
    }
}

void fun::Pare_3()   //导出排版图像
{
    QString  str=QFileDialog::getSaveFileName(this,tr("导出"),"",tr("Image Files(*.png *.jpg)"));
    if(!str.isEmpty())   //路径存在
    {
        QSize  p=ui->textEdit->document()->size().toSize();    //获取文档大小   并进行类型转换
        QPixmap  image(p);
        image.fill(Qt::white);
        QPainter  m(&image);
        ui->textEdit->document()->drawContents(&m);  //绘制内容
        bool  ok=image.save(str);
        if(ok)
        {
            ;
        }
        else
        {
            qDebug() <<"save  failed";
        }
    }
    else
    {
        QMessageBox::warning(this,tr("导出图像"),tr("导出图像失败"));
    }
}


void fun::AI_1()    //图像识别
{
    QString  str2=QFileDialog::getOpenFileName(this,tr("AI识别"),"",tr("image File(*.png *.jpg)"));
    if(!str2.isEmpty())   //路径存在
    {
        QImage  image(str2);    //加载图片
        if(!image.isNull())   //加载成功
        {
           QTextCursor p=ui->textEdit->textCursor();   //获取光标
           p.movePosition(QTextCursor::NoMove);
           QTextImageFormat mat;     //在富文本框中嵌入图像
           mat.setName(str2);
           p.insertImage(mat);
        }
        else
        {
            QMessageBox::warning(this,tr("AI识别"),tr("图像识别失败"));
        }
    }
    else
    {
        QMessageBox::warning(this,tr("AI识别"),tr("图像识别失败"));
    }
    QString  str="https://api-cn.faceplusplus.com/imagepp/beta/detectsceneandobject";   //url
    QUrl url(str);
    QNetworkRequest  quest(url);    //请求
    quest.setHeader(QNetworkRequest::ContentTypeHeader,"multipart/form-data");    //请求头
    QHttpMultiPart  *p=new QHttpMultiPart(QHttpMultiPart::FormDataType);    //表单数据请求    多个数据
    QHttpPart   apikey;    //单个数据请求
    apikey.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"api_key\""));
    QString  key="npLodWMK19bkzln3FpRyMjSpQm7UyzBr";
    QByteArray key_data=key.toUtf8();
    apikey.setBody(key_data);    //key
    p->append(apikey);    //加入到表单数据中
    QHttpPart   apisecret;    //单个数据请求
    apisecret.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"api_secret\""));
    QString  secret="lwpGdsjQH8HGhYapBhjvd4mzEqwGkDMb";
    QByteArray secret_data=secret.toUtf8();
    apisecret.setBody(secret_data);    //secret
    p->append(apisecret);    //加入到表单数据中
    QFile file(str2);    //文件路径
    if(file.open(QIODevice::ReadOnly))    //打开成功
    {
        QByteArray  data=file.readAll();
        QByteArray   data_base64=QUrl::toPercentEncoding(data.toBase64());
                //Qudata.toBase64();
        //qDebug() <<"image data=" <<data_base64;
        //QByteArray finall = QUrl::toPercentEncoding(.toBase64());
        QHttpPart  image;
        //image.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("image.jpg"));    //类型是图片
        image.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"image_base64\""));
        image.setBody(data_base64);
        p->append(image);
        file.close();
    }
    else
    {
        qDebug() <<"file  path failed";
    }
    m_ager=new QNetworkAccessManager(this);    //网络请求
    m_reply=m_ager->post(quest,p);     //响应
    connect(m_reply,SIGNAL(finished()),this,SLOT(Read_data()));
}

void fun::AI_2()    //chat  boot
{

}

void fun::Read_data()   //AI响应后的数据
{
    qDebug() <<"11111";
    qDebug() << "Error code:" << m_reply->errorString();
    if(m_reply->error()==QNetworkReply::NoError)    //响应成功
    {
       qDebug() <<"2222";
       QString   data=m_reply->readAll();
       qDebug() <<data;
       qDebug() <<"3333";
       ui->textEdit->setText(data);
       qDebug() <<"4444";
    }
}



