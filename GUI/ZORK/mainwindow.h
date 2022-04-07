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

private slots:
    string NorthButton();
    void EastButton();
    void SouthButton();
    void WestButton();
    void TeleportButton();
    void MapButton();
    void UseItem();
    void TakeItem();

private:
    Ui::MainWindow *ui;
    ZorkUL* zork;
};
#endif // MAINWINDOW_H
