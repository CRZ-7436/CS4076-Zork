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
    zork = new ZorkUL();
}

MainWindow::~MainWindow() // destructor
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked() // north button
{
    setPictures();
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
    setPictures();
    zork->go("west");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_6_clicked() // east button
{
    setPictures();
    zork->go("east");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_4_clicked() // south button
{
    setPictures();
    zork->go("south");
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_pushButton_5_clicked() // random teleport
{
    zork->randTeleport();
    ui->AdventureText->setText(QString::fromStdString(zork->currentRoom->longDescription()));
    setPictures();
}

void MainWindow::setPictures(){
    if (zork->currentRoom->shortDescription() == "a"){
        QPixmap pix(":/images/images/treehouse.png");
        ui->picture->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if (zork->currentRoom->shortDescription() == "b"){
        QPixmap pix2(":/images/images/cave.png");
        ui->picture->setPixmap(pix2.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if (zork->currentRoom->shortDescription() == "c"){
        QPixmap pix3("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix3.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "d"){
        QPixmap pix4("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix4.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "e"){
        QPixmap pix5("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix5.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "f"){
        QPixmap pix6("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix6.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "g"){
        QPixmap pix7("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix7.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "h"){
        QPixmap pix8("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix8.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "i"){
        QPixmap pix9("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix9.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if (zork->currentRoom->shortDescription() == "j"){
        QPixmap pix10("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix10.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "k"){
        QPixmap pix11("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix11.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "l"){
        QPixmap pix12("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix12.scaled(250,250,Qt::KeepAspectRatio));
    }
    else if(zork->currentRoom->shortDescription() == "m"){
        QPixmap pix13("C:/Users/mount/OneDrive/Uni Stuff/sem 4/CS4076/Zork Stuff/CS4076-Zork/CS4076-Zork/pictures/treehouse.png");
        ui->picture->setPixmap(pix13.scaled(250,250,Qt::KeepAspectRatio));
    }
}

