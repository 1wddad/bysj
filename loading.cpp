#include "loading.h"
#include "ui_loading.h"
#include "fun.h"


loading::loading(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loading)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);    //密码不回显
    ui->lineEdit_user->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px");
    ui->lineEdit_password->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px");
    ui->pushButton_loading->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px;background-color:gray");
    ui->pushButton_load1->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px;background-color:gray");
    ui->pushButton_3->setStyleSheet("border-style:solid;border-width:1px;border-color:black;border-radius:10px;background-color:gray");
}



loading::~loading()
{
    delete ui;
}


void loading::Create_Table()    //创建表
{
    QSqlQuery   query(p);
    //qDebug() <<"create table success";
    query.exec("CREATE TABLE IF NOT EXISTS User_Card(name VARCHAR(20) PRIMARY KEY,password VARCHAR(20))");     //字段+数据类型+约束条件
}


void loading::Add_Data(QString &str1,QString &str2)    //向表中添加数据
{
    QSqlQuery  query(p);
    query.prepare("INSERT INTO User_Card(name,password) VALUES(?,?)");    //准备插入语句
    query.addBindValue(str1);    //用户名和密码添加到数据库里面
    query.addBindValue(str2);
    //qDebug() <<"add data success";
    query.exec();
}



int loading::Find_Data(QString &str1, QString &str2)    //查询数据
{
    QSqlQuery query(p);
    query.prepare("SELECT name,password FROM  User_Card WHERE name= :name AND password= :password");    //准备插入语句
    query.bindValue(":name",str1);    //绑定值
    query.bindValue(":password",str2);
    query.exec();
    if(query.next())    //数据存在
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void loading::on_pushButton_load1_clicked()    //注册
{
    QString  user=ui->lineEdit_user->text();
    QString  password=ui->lineEdit_password->text();    //用户名和密码
    p=QSqlDatabase::addDatabase("QSQLITE");
    p.setDatabaseName("D:/qttest/sql/Userinfo.sql");
    if(p.open())    //数据库打开成功
    {
        //qDebug() <<"DataBase  open success" ;
        Create_Table();     //创建表
        int ret=Find_Data(user,password);
        QMessageBox  box;
        if(ret==1)    //注册失败
        {
             box.setText("你已经注册过，请直接登录");
        }
        else  if(ret==0)    //注册成功
        {
            Add_Data(user,password);
            box.setText("注册成功");
        }
        box.resize(200,200);
        box.setWindowTitle("注册用户信息");
        box.exec();
    }
    else
    {
        qDebug() <<"DataBase open failed";
        return ;
    }
    p.close();
    ui->lineEdit_user->clear();
    ui->lineEdit_password->clear();
}


void loading::on_pushButton_loading_clicked()    //登录
{
    QString  user=ui->lineEdit_user->text();
    QString  password=ui->lineEdit_password->text();    //用户名和密码
    p=QSqlDatabase::addDatabase("QSQLITE");
    p.setDatabaseName("D:/qttest/sql/Userinfo.sql");
    QMessageBox  box;
    if(p.open())    //数据库打开成功
    {
        //qDebug() <<"DataBase  open success" ;
        int ret=Find_Data(user,password);
        if(ret==1)
        {
            box.setText("登录成功");
            fun  *w=new fun;      //登录成功后   界面更新
            w->Main_Ui(w);
            w->setAttribute(Qt::WA_DeleteOnClose);    //当前窗口为登录窗口的子窗口
            p.close();
        }
        else
        {
            box.setText("登录失败,请检查用户名或密码");
        }
        box.setWindowTitle("登录用户信息");
        box.exec();
    }
    else
    {
        qDebug() <<"DataBase open failed";
        return ;
    }
}


void loading::on_pushButton_3_clicked()     //退出
{
    this->close();
}
