#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <analogclock.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  analogclock *clock;
};

#endif // MAINWINDOW_H
