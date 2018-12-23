/* Copyright 2018 HuaTsai */
#ifndef QT_TEST_H_
#define QT_TEST_H_

#include <QMainWindow>
#include <ros/ros.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 public slots:
  void SetNum1();
  void SetNum2();
  void PrintText();

 private:
  Ui::MainWindow *ui;
  ros::NodeHandle nh_;
};

#endif  // QT_TEST_H_
