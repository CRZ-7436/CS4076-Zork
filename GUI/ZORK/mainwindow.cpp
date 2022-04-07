#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
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


string MainWindow::NorthButton()
{
    Command dir = Command("go", "north");
}

void MainWindow::EastButton()
{

}

void MainWindow::SouthButton()
{

}


void MainWindow::WestButton()
{

}


void MainWindow::TeleportButton()
{

}


void MainWindow::MapButton()
{

}

void MainWindow::UseItem()
{

}


void MainWindow::TakeItem()
{

}

