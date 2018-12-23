/* Copyright 2018 HuaTsai */
#include <QApplication>
#include "qt_test/qt_test.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "qt_test_main");
  QApplication app(argc, argv);
  MainWindow win;
  win.show();
  return app.exec();
}
