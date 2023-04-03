#ifndef CLOCKSETTING_H
#define CLOCKSETTING_H

#include <QPainter>
#include <QSettings>
#include <QTimer>
#include <QWidget>
#include <QtGui>

namespace Ui {
class clocksetting;
}

class clocksetting : public QWidget {
  Q_OBJECT

public:
  explicit clocksetting(QWidget *parent = 0);
  ~clocksetting();
  void magnet(bool enablemagnet = true);

protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void closeEvent(QCloseEvent *event);
  void paintEvent(QPaintEvent *event);
  void showEvent(QShowEvent *);
  void readsetting();

private:
  Ui::clocksetting *ui;
  QPoint dragPosition;
  QSettings *setting;
public slots:
  void checkchange();
};

#endif // CLOCKSETTING_H
