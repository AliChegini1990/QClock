#include "analogclock.h"
#include <QApplication>

analogclock::analogclock(QWidget *parent) : QWidget(parent) {
  size_w = 150;
  size_h = 150;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));

  setWindowTitle(tr("Clock"));
  resize(size_w, size_h);
  timer->start(1000);

  setStyleSheet("background:transparent;");
  setAttribute(Qt::WA_TranslucentBackground);
  setWindowFlags(Qt::FramelessWindowHint);

  QSettings setting("setting.ini", QSettings::IniFormat, this);
  if (setting.value("check1", false).toBool()) {
    ontop(true);
  }
}

analogclock::~analogclock() {}

void analogclock::closeEvent(QCloseEvent *event) {
  if(timer)  delete timer;
  if(clkset) delete clkset;
  delete this;
  event->accept();
}
bool analogclock::isontop() {
  Qt::WindowFlags flag = this->windowFlags();
  if (flag == (flag & Qt::WindowStaysOnTopHint)) {
    return true;
  } else {
    return false;
  }
}

void analogclock::ontop(bool cheked) {
  Qt::WindowFlags flag = this->windowFlags();
  if (cheked == true) {
    setWindowFlags(flag | Qt::WindowStaysOnTopHint);
    this->show();
  } else {
    setWindowFlags(flag ^ Qt::WindowStaysOnTopHint);
    this->show();
  }
}

void analogclock::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    move(event->globalPosition().toPoint() - dragPosition);
    // magnet();
    event->accept();
  }
}
void analogclock::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() & Qt::LeftButton) {
    //magnet();
    event->accept();
  }
}

void analogclock::mousePressEvent(QMouseEvent *event) {

  if (event->button() == Qt::LeftButton) {
    dragPosition =
        event->globalPosition().toPoint() - frameGeometry().topLeft();
    event->accept();
  }
  if (event->button() == Qt::RightButton) {
    clkset = new clocksetting(this);
    clkset->setParent(this, Qt::Window);
    clkset->setAttribute(Qt::WA_SetStyle);
    clkset->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    clkset->show();
    clkset->move(this->x(), this->y());
    event->accept();
  }
}

void analogclock::paintEvent(QPaintEvent *event) {
  QPainter painter(this);

  painter.begin(this);
  painter.setRenderHints(QPainter::SmoothPixmapTransform |
                         QPainter::Antialiasing);
  QPixmap knob = QPixmap(":/images/pic/knob1.png");
  QPixmap imgclk(":/images/pic/clock3.png");
  imgclk = imgclk.scaled(size_w, size_h);
  painter.drawPixmap(0, 0, size_w, size_h, imgclk);

  int side = qMin(width(), height());
  QTime time = QTime::currentTime();

  painter.translate(imgclk.rect().width() / 2, imgclk.rect().height() / 2);
  painter.scale(1, 1);
  knob = QPixmap(":/images/pic/knob1_h.png");
  painter.save();

  painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));

  painter.drawPixmap(-(knob.width() / 2), -(knob.height() / 2), knob.width(),
                     knob.height(), knob, 0, 0, knob.width(), knob.height());
  painter.restore();

  knob = QPixmap(":/images/pic/knob1_m.png");
  painter.save();
  painter.rotate(6.0 * (time.minute() + time.second() / 60.0));

  painter.drawPixmap(-(knob.width() / 2), -(knob.height() / 2), knob.width(),
                     knob.height(), knob, 0, 0, knob.width(), knob.height());
  painter.restore();

  knob = QPixmap(":/images/pic/knob1.png");
  painter.save();
  painter.rotate((6.0 * (time.second())));

  painter.drawPixmap(-(knob.width() / 2), -(knob.height() / 2), knob.width(),
                     knob.height(), knob, 0, 0, knob.width(), knob.height());

  painter.restore();
  painter.end();
  event->accept();
}
void analogclock::magnet(bool enablemagnet) {
  QScreen *screen = QGuiApplication::primaryScreen();
  QRect screenGeometry = screen->geometry();
  int height = screenGeometry.height();
  int width = screenGeometry.width();

  if (enablemagnet) {
    int w = this->width() + this->pos().x();
    int h = this->height() + this->pos().y();

    if (w > width) {
      for (;;) {

        w = this->pos().x() - 1;
        move(w, y());
        w = this->width() + this->pos().x();
        if (w < width)
          break;
      }
    }

    w = this->pos().x();
    if (w < 0) {
      for (;;) {

        w = this->pos().x() + 1;
        move(w, y());
        w = this->pos().x();
        if (w > 0)
          break;
      }
    }

    h = this->height() + this->pos().y();
    if (h > height) {
      for (;;) {

        h = this->pos().y() - 1;
        move(x(), h);
        h = this->height() + this->pos().y();
        if (h < height)
          break;
      }
    }
    h = this->pos().y();
    if (h < 0) {
      for (;;) {

        h = this->pos().y() + 1;
        move(x(), h);
        h = this->pos().y();
        if (h > 0)
          break;
      }
    }
  }
}
