#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <iostream>

extern string mapKey;

MainWindow::MainWindow(QWidget *parent) // constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
}

MainWindow::~MainWindow() // destructor
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked()
{
    /*ui->AdventureText->setText(currentRoom->longDescription());*/
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->AdventureText->setText("         [a]---[b]    [k]        \n"
                               "          |                |         \n"
                               "[d]---[c]      [l]---[j]---[m]  \n"
                               " |        |!              |         \n"
                               "[e]---[f]---[g]---[h]        \n"
                               "                          |         \n"
                               "                          [i]        \n"
                               "symbol key: \n"
                               "- or |:bidirectional \n"
                               "!- or -!, !| or |!: one directional \n"
                               );
}

