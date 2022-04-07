#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Room.h"
#include <iostream>

extern string mapKey;
extern

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

void MainWindow::on_pushButton_7_clicked() // north button
{
    zork->go("north");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_9_clicked() // map button
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


void MainWindow::on_pushButton_12_clicked() // info button
{
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_8_clicked() // west button
{
    zork->go("west");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_6_clicked() // east button
{
    zork->go("east");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_4_clicked() // south button
{
    zork->go("south");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_5_clicked() // random teleport
{
    zork->randTeleport();
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}

