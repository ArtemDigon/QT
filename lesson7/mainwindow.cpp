#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item_1 = new QListWidgetItem(QIcon(":/img/show 2.png"), "Audi");
    ui->listWidget->addItem(item_1);
    QListWidgetItem *item_2 = new QListWidgetItem(QIcon(":/img/show 2.png"), "BMW");
    ui->listWidget->addItem(item_2);
    QListWidgetItem *item_3 = new QListWidgetItem(QIcon(":/img/show 2.png"), "Volvo");
    ui->listWidget->addItem(item_3);
    QListWidgetItem *item_4 = new QListWidgetItem(QIcon(":/img/show 2.png"), "Mercedec");
    ui->listWidget->addItem(item_4);
    QListWidgetItem *item_5 = new QListWidgetItem(QIcon(":/img/show 2.png"), "Ford");
    ui->listWidget->addItem(item_5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_2_triggered()
{
    ui->statusbar->showMessage("Открыть новый проект");
}


void MainWindow::on_action_triggered()
{
    ui->statusbar->showMessage("Создать новый проект");
}


void MainWindow::on_action_3_triggered()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->showMessage("выбран " + ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackground(Qt::black);
    ui->listWidget->currentItem()->setForeground(Qt::white);

}

