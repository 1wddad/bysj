#ifndef LOADING_H
#define LOADING_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>



namespace Ui {
class loading;
}

class loading : public QMainWindow
{
    Q_OBJECT

public:
    explicit loading(QWidget *parent = nullptr);
    ~loading();
    void Create_Table();
    void Add_Data(QString &str1,QString &str2);
    int Find_Data(QString &str1,QString &str2);


private slots:
    void on_pushButton_load1_clicked();

    void on_pushButton_loading_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::loading *ui;
    QSqlDatabase  p;
};

#endif // LOADING_H
