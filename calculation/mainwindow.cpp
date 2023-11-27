#include "mainwindow.h"
#include "./ui_mainwindow.h"

double first_num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_procent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_swap_znak,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ac,SIGNAL(clicked()),this,SLOT(on_pushButton_ac_clicked()));
    connect(ui->pushButton_ravno,SIGNAL(clicked()),this,SLOT(on_pushButton_ravno_clicked()));
    connect(ui->pushButton_slesh,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_umnojenie,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_slesh->setCheckable(true);
    ui->pushButton_umnojenie->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();

    QString new_label;

    if (ui->result_show->text().contains(".") && button->text() == "0") {
        new_label = ui->result_show->text() + button->text();
    }else {
        double all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers,'g',15);
    }
    ui->result_show->setText(new_label);
    if (ui->result_show->text() != "0"){
        ui->pushButton_ac->setText("C");
    }

}


void MainWindow::on_pushButton_point_clicked()
{
    if(!ui->result_show->text().contains("."))
        ui->result_show->setText(ui->result_show->text() + ".");
}


void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    QStringList myOptions;
    myOptions << "+/-" << "%";
    switch ( myOptions.indexOf(button->text()) )
    {
        case 0:
            all_numbers = (ui->result_show->text()).toDouble();
            all_numbers = all_numbers * -1;
            new_label = QString::number(all_numbers,'g',15);
            ui->result_show->setText(new_label);
            break;

        case 1:
            all_numbers = (ui->result_show->text()).toDouble();
            all_numbers = all_numbers * 0.01;
            new_label = QString::number(all_numbers,'g',15);
            ui->result_show->setText(new_label);
            break;
    }
}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_slesh->setChecked(false);
    ui->pushButton_umnojenie->setChecked(false);

    ui->result_show->setText("0");
    ui->pushButton_ac->setText("AC");
}

void MainWindow::on_pushButton_ravno_clicked()
{
    double label,second_num;
    QString new_lable;
    second_num = ui->result_show->text().toDouble();
    if (ui->pushButton_plus->isChecked()){
            label = first_num + second_num;
            ui->pushButton_plus->setChecked(false);
            new_lable = QString::number(label,'g',15);
            ui->result_show->setText(new_lable);
    } else if (ui->pushButton_minus->isChecked()){
            label = first_num - second_num;
            ui->pushButton_minus->setChecked(false);
            new_lable = QString::number(label,'g',15);
            ui->result_show->setText(new_lable);
    } else if (ui->pushButton_umnojenie->isChecked()){
            label = first_num * second_num;
            ui->pushButton_point->setChecked(false);
            new_lable = QString::number(label,'g',15);
            ui->result_show->setText(new_lable);
    } else if (ui->pushButton_slesh->isChecked()){
            if (second_num == 0){
                ui->result_show->setText("0");
                ui->pushButton_slesh->setChecked(false);

            }else{
                label = first_num / second_num;
                ui->pushButton_slesh->setChecked(false);
                new_lable = QString::number(label,'g',15);
                ui->result_show->setText(new_lable);
            }
    }
}

void MainWindow::math_operations(){
    QPushButton *button = (QPushButton *)sender();
    first_num = ui->result_show->text().toDouble();
    button->setChecked(true);
    ui->result_show->setText("");

}
