#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox *mes = new QMessageBox();
    QMessageBox::StandardButton reply = mes->question(this,"this diolog","hello",mes->Yes | mes->No);
        if (reply == QMessageBox::Yes) {
            QApplication::quit();
        }
        else {
            qDebug() << "кнопка была нажата";        }
}

