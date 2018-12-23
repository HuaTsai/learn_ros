/* Copyright 2018 HuaTsai */
#include "qt_test/qt_test.h"
#include "ui_qt_test.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetNum1() {
  nh_.setParam("num1", ui->le_num1->text().toUtf8().constData());
}

void MainWindow::SetNum2() {
  nh_.setParam("num2", ui->le_num2->text().toUtf8().constData());
}

void MainWindow::PrintText() {
  std::cout << "text: "
            << ui->le_text->text().toUtf8().constData() << std::endl;
}
