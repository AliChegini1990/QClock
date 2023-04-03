/********************************************************************************
** Form generated from reading UI file 'clocksetting.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCKSETTING_H
#define UI_CLOCKSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clocksetting
{
public:
    QCheckBox *checkBox;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *clocksetting)
    {
        if (clocksetting->objectName().isEmpty())
            clocksetting->setObjectName(QString::fromUtf8("clocksetting"));
        clocksetting->resize(131, 309);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clocksetting->sizePolicy().hasHeightForWidth());
        clocksetting->setSizePolicy(sizePolicy);
        clocksetting->setAutoFillBackground(false);
        clocksetting->setStyleSheet(QString::fromUtf8("QWidget\n"
" {\n"
"    /*  background-color:transparent;*/\n"
"	\n"
"	background-color: rgb(213, 207, 255);\n"
"\n"
" }\n"
""));
        checkBox = new QCheckBox(clocksetting);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setGeometry(QRect(40, 200, 54, 17));
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setLayoutDirection(Qt::LeftToRight);
        checkBox->setAutoFillBackground(false);
        frame = new QFrame(clocksetting);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1, 0, 129, 171));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	/* background-color:transparent; \n"
"	background-image: url(:/images/pic/clock.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;*/\n"
"\n"
"             border-image: url(:/images/pic/clock3.png);\n"
"			  border-top: 10px transparent;\n"
"   			 border-bottom: 10px transparent;\n"
"             border-right: 5px transparent;\n"
"             border-left: 5px transparent;\n"
"\n"
"	  \n"
"\n"
"}\n"
"\n"
"QFrame:hover	\n"
"{\n"
"			border-image: url(:/images/pic/clock3.png);\n"
" 			border-top: 0px transparent;\n"
"   			 border-bottom: 0px transparent;\n"
"             border-right: 0px transparent;\n"
"             border-left: 0px transparent;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(clocksetting);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 240, 129, 33));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"             color: black;\n"
"             border-image: url(:/images/pic/button.png);\n"
"             border-top: 10px transparent;\n"
"             border-bottom: 10px transparent;\n"
"             border-right: 10px transparent;\n"
"             border-left: 10px transparent;\n"
"         }\n"
"QPushButton:hover\n"
"{\n"
"  			color: yellow;\n"
"            \n"
"}\n"
"QPushButton:hover:pressed\n"
"{\n"
"  			color: green;\n"
"            \n"
"}"));
        pushButton_2 = new QPushButton(clocksetting);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 270, 129, 33));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"             color:black;\n"
"             border-image: url(:/images/pic/button.png) 10 10 10 10;\n"
"             border-top: 10px transparent;\n"
"             border-bottom: 10px transparent;\n"
"             border-right: 10px transparent;\n"
"             border-left: 10px transparent;\n"
"\n"
"         }\n"
"QPushButton:hover\n"
"{\n"
"  			color: yellow;\n"
"            \n"
"}\n"
"QPushButton:hover:pressed\n"
"{\n"
"  			color: green;\n"
"            \n"
"}"));

        retranslateUi(clocksetting);
        QObject::connect(pushButton, &QPushButton::clicked, clocksetting, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(clocksetting);
    } // setupUi

    void retranslateUi(QWidget *clocksetting)
    {
        clocksetting->setWindowTitle(QCoreApplication::translate("clocksetting", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("clocksetting", "on top", nullptr));
        pushButton->setText(QCoreApplication::translate("clocksetting", "close", nullptr));
        pushButton_2->setText(QCoreApplication::translate("clocksetting", "exit application", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clocksetting: public Ui_clocksetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCKSETTING_H
