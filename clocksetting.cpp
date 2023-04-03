#include "clocksetting.h"
#include "ui_clocksetting.h"

clocksetting::clocksetting(QWidget *parent)
    : QWidget(parent), ui(new Ui::clocksetting) {
  ui->setupUi(this);

  setting = new QSettings("setting.ini", QSettings::IniFormat, this);

  readsetting();

  connect(ui->pushButton_2, SIGNAL(clicked()), parent, SLOT(close()));
  connect(ui->checkBox, SIGNAL(clicked(bool)), parent, SLOT(ontop(bool)));
  connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(checkchange()));
}

clocksetting::~clocksetting() {}

void clocksetting::closeEvent(QCloseEvent *event) {

  delete ui;
  delete setting;
  delete this;
  event->accept();
}
void clocksetting::checkchange() {
  setting->setValue("check1", ui->checkBox->isChecked());
}
void clocksetting::readsetting() {

  if (setting->value("check1", false).toBool()) {
    ui->checkBox->setCheckState(Qt::Checked);

  } else {
    ui->checkBox->setCheckState(Qt::Unchecked);
  }
}

void clocksetting::paintEvent(QPaintEvent *event) {}
void clocksetting::showEvent(QShowEvent *event) {}

void clocksetting::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    this->move(event->globalPosition().toPoint() - dragPosition);
    // magnet();
    event->accept();
  }
}

void clocksetting::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() & Qt::LeftButton) {
    //magnet();
    event->accept();
  }
}
void clocksetting::mousePressEvent(QMouseEvent *event) {

  if (event->button() == Qt::LeftButton) {
    dragPosition =
        event->globalPosition().toPoint() - frameGeometry().topLeft();
    event->accept();
  }
  if (event->button() == Qt::RightButton) {

    event->accept();
  }
}
void clocksetting::magnet(bool enablemagnet) {
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
