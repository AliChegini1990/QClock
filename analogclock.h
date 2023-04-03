#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H
#include <QWidget>
#include <QtGui>
#include <clocksetting.h>

class QWidget;
class QPaintEvent;

class analogclock : public QWidget
{
    Q_OBJECT
public:
   explicit analogclock(QWidget *parent=0);
    ~ analogclock();
    void magnet(bool enablemagnet=true);
    bool isontop();

protected:
//    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

public slots:
    void ontop(bool cheked);
private:
    int size_w;
    int size_h;
  QTimer *timer{nullptr};
    QPoint dragPosition;
    QImage image;
  clocksetting *clkset{nullptr};
};

#endif // ANALOGCLOCK_H
