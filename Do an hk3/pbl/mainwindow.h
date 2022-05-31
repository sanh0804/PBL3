#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QCloseEvent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QStringList>
#include <bits/stdc++.h>
    using namespace std;
#include <nhanvien.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_logined_btn_clicked();

    void on_pushButton_h_1_clicked();

    void on_pushButton_h_2_clicked();

    void on_pushButton_h_3_clicked();

    void on_pushButton_h_4_clicked();

    void on_pushButton_h_5_clicked();

    void on_pushButton_h_6_clicked();


    void on_pushButton_l_1_clicked();

    void on_pushButton_l_2_clicked();

    void on_pushButton_l_3_clicked();

    void on_pushButton_l_4_clicked();

    void on_pushButton_l_5_clicked();
    void on_pushButton_l_6_clicked();


    void on_pushButton_a_1_clicked();

    void on_pushButton_a_2_clicked();

    void on_pushButton_a_3_clicked();

    void on_pushButton_a_4_clicked();

    void on_pushButton_a_5_clicked();
    void on_pushButton_a_6_clicked();


    void on_pushButton_r_1_clicked();

    void on_pushButton_r_2_clicked();

    void on_pushButton_r_3_clicked();

    void on_pushButton_r_4_clicked();

    void on_pushButton_r_5_clicked();
    void on_pushButton_r_6_clicked();


    void on_pushButton_s_1_clicked();

    void on_pushButton_s_2_clicked();

    void on_pushButton_s_3_clicked();

    void on_pushButton_s_4_clicked();

    void on_pushButton_s_5_clicked();
    void on_pushButton_s_6_clicked();



   // void on_tableWidget_cellClicked(int row, int column);

    void on_search_btn_clicked();
    void on_listStaff_cellDoubleClicked(int row, int column);


    void on_toolButton_clicked();

    void on_back_btn_clicked();

    void on_pushButton_2_clicked();

    void on_listStaff_2_cellDoubleClicked(int row, int column);

    void on_back_btn_2_clicked();

    void on_remove_btn_clicked();

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent*);


protected:
    void addDataToListStaff();
    void addDataToRemoveStaff();
    void statistic();
    void InforStaff(NHANVIEN* );
    template<class T>
    int Getposition(vector<T> nv,QString id);
    template<class T>
    int Getpositioncv(vector<T> cv,QString mcv);
private:
    Ui::MainWindow *ui;
    bool logined = 0;
    QSqlDatabase myDB;
    vector<NHANVIEN* > listnv;
    vector<LUONG*> listluong;
    vector<PHUCAP*> listphucap;
    vector<THUCLINH*> listthuclinh;
    vector<CHUCVU*> listchucvu;
    vector<Date*> date;
};

#endif // MAINWINDOW_H
