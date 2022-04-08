#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Room.h"
#include <iostream>
#include <QPixmap>
#include <QMessageBox>

extern string mapKey;

MainWindow::MainWindow(QWidget *parent) // constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/GUI/ZORK/images/treehouse.png");
    ui->picture->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
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
    setPictures();
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
                               "\n"
                               "[a]:is your house, goodluck \n"
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
    setPictures();
}


void MainWindow::on_pushButton_6_clicked() // east button
{
    zork->go("east");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
    setPictures();
}


void MainWindow::on_pushButton_4_clicked() // south button
{
    zork->go("south");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
    setPictures();
}


void MainWindow::on_pushButton_5_clicked() // random teleport
{
    zork->randTeleport();
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
    setPictures();
}

void MainWindow::setPictures(){
    cout << zork->currentRoom->shortDescription() << endl;
    cout << "bruh" << endl;
    if (zork->currentRoom->shortDescription() == "your house"){
        QPixmap pix(":/images/images/treehouse.png");
        ui->picture->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if (zork->currentRoom->shortDescription() == "your car"){
        QPixmap pix2(":/images/images/car.PNG");
        ui->picture->setPixmap(pix2.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if (zork->currentRoom->shortDescription() == "cave entrance"){
        QPixmap pix3(":/images/images/cave.png");
        ui->picture->setPixmap(pix3.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "upper mine"){
        QPixmap pix4(":/images/images/upperMine.PNG");
        ui->picture->setPixmap(pix4.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "lower mine"){
        QPixmap pix5(":/images/images/lowerMine.PNG");
        ui->picture->setPixmap(pix5.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "stairs"){
        QPixmap pix6(":/images/images/stairs.PNG");
        ui->picture->setPixmap(pix6.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "hall way"){
        QPixmap pix7(":/images/images/hallway.PNG");
        ui->picture->setPixmap(pix7.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "end of hall"){
        QPixmap pix7(":/images/images/endOfHall.PNG");
        ui->picture->setPixmap(pix7.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "glass room"){
        QPixmap pix8(":/images/images/glassRoom.PNG");
        ui->picture->setPixmap(pix8.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "ruined castle"){
        QPixmap pix9(":/images/images/castleRuins.PNG");
        ui->picture->setPixmap(pix9.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "portal home"){
        QPixmap pix11(":/images/images/portalhome.PNG");
        ui->picture->setPixmap(pix11.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "gleaming table"){
        QPixmap pix12(":/images/images/glassTable.PNG");
        ui->picture->setPixmap(pix12.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "wooden table"){
        QPixmap pix13(":/images/images/woodenTable.PNG");
        ui->picture->setPixmap(pix13.scaled(250,250,Qt::KeepAspectRatio));
    }
}

