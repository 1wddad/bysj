//#include "file.h"


//File_Menu::File_Menu(QWidget *parent, Ui::fun *ui):
//    QMainWindow(parent),ui(new Ui::fun)
//{
//    ui->setupUi(this);
//}


//File_Menu::~File_Menu()
//{
//    delete  ui;
//}



//void File_Menu::New_file()     //新建
//{
//    ;
//}

//void File_Menu::Open_file()    //打开
//{
//    QString  str=QFileDialog::getOpenFileName(this,tr("打开文件"),"",tr("All Files(*)"));
//    if(!str.isEmpty())   //路径存在
//    {
//        QFile file(str);
//        if(file.open(QIODevice::ReadOnly))    //文件打开成功
//        {
//            QTextStream in(&file);   //文本输入流
//            QString  file_str=in.readAll();   //读取文件中的数据
//            ui->textEdit->setText(file_str);
//            file.close();
//        }
//        else
//        {
//            QMessageBox::warning(this,tr("打开文件"),tr("打开文件失败"));
//        }
//    }
//}
