#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Подключаем сигнал от кнопки к слоту
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Получаем год из виджета QDateEdit
    int year = ui->dateEdit->date().year();
    int day = ui->dateEdit->date().dayOfWeek();
    // Проверяем, является ли год високосным
    bool isLeapYear = CheckYear(year);

    // Отображаем результат в Label_2
    if (isLeapYear) {
        ui->label_2->setText(QString::number(year) + " год является високосным.");
    } else {
        ui->label_2->setText(QString::number(year) + " год не является високосным.");
    }
    switch(day){
    case 1:
        ui->label_3->setText("Понедельник - день бездельник");
        break;
    case 2:
        ui->label_3->setText("Вторник - повторник");
        break;
    case 3:
    ui->label_3->setText("Среда - тамада");
    break;
    case 4:
    ui->label_3->setText("Четверг-я заботы все отверг");
    break;
    case 5:
    ui->label_3->setText("Пятница-пьяница");
    break;
    case 6:
    ui->label_3->setText("Суббота-безработа");
    break;
    case 7:
    ui->label_3->setText("Воскресенье-день веселья!");
    break;
    }
}

bool MainWindow::CheckYear(int year) {
    // Проверка на високосность года
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
