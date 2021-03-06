#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZorkUL.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ZorkUL* zork;
    void setPictures();
    void endGame();

private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    //ZorkUL* zork;
};
#endif // MAINWINDOW_H
