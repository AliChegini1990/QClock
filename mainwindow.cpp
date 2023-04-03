#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  clock = new analogclock();
  // clock->setParent(this,Qt::Window);
  clock->show();
}

MainWindow::~MainWindow() { delete ui; }
