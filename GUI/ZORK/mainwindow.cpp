#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
}

MainWindow::~MainWindow()
{
    delete ui;
}

