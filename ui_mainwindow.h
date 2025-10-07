/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <canvas.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *contactUsButton;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_19;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QComboBox *colorDropDown;
    QComboBox *widthDropDown;
    QComboBox *styleDropDown;
    QComboBox *capDropDown;
    QComboBox *joinStyleDropDown;
    QLabel *label_11;
    QLineEdit *shapeIdLineEdit;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_12;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_3;
    QComboBox *brushColorDrop;
    QComboBox *brushStyleDrop;
    QLabel *removeShapeLabel;
    QLineEdit *removeShapeLineEdit;
    QPushButton *removeShapeButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_4;
    QTextEdit *textEdit;
    QComboBox *comboBox_41;
    QComboBox *comboBox_42;
    QComboBox *comboBox_43;
    QComboBox *comboBox_44;
    QComboBox *comboBox_45;
    QComboBox *comboBox_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lengthLineEdit;
    QLineEdit *widthLineEdit;
    QLineEdit *radiusLineEdit;
    QLineEdit *semimajorLineEdit;
    QLineEdit *semiminorLineEdit;
    QVBoxLayout *verticalLayout_23;
    QPushButton *addPushButton;
    QVBoxLayout *verticalLayout_5;
    Canvas *canvasWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *toggleLine;
    QPushButton *togglePolyline;
    QPushButton *togglePolygon;
    QPushButton *toggleSquare;
    QPushButton *toggleRectangle;
    QPushButton *toggleCircle;
    QPushButton *toggleEllipse;
    QPushButton *toggleText;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1493, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        QPalette palette;
        QBrush brush(QColor(34, 12, 16, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        loginButton->setPalette(palette);
        loginButton->setStyleSheet(QString::fromUtf8("font: 10t \"OCR A Extended\";\n"
"background-color: rgb(34, 12, 16);"));

        horizontalLayout_3->addWidget(loginButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        contactUsButton = new QPushButton(centralwidget);
        contactUsButton->setObjectName("contactUsButton");
        contactUsButton->setStyleSheet(QString::fromUtf8("* {\n"
"background-color: green;\n"
"color: white;\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(contactUsButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_3->setPalette(palette1);
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 10t \"OCR A Extended\";\n"
"background-color: rgb(34, 12, 16);"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 140, 113);\n"
"font: 11pt \"Copperplate Gothic Light\";\n"
"color:rgb(0, 0, 0);"));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_19->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 28pt \"Sitka Heading\";\n"
"background-color: rgb(57, 77, 205);\n"
""));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_20->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_20->addItem(verticalSpacer_3);

        colorDropDown = new QComboBox(centralwidget);
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->addItem(QString());
        colorDropDown->setObjectName("colorDropDown");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorDropDown->sizePolicy().hasHeightForWidth());
        colorDropDown->setSizePolicy(sizePolicy1);
        colorDropDown->setMaximumSize(QSize(200, 20));
        colorDropDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_20->addWidget(colorDropDown);

        widthDropDown = new QComboBox(centralwidget);
        widthDropDown->addItem(QString());
        widthDropDown->addItem(QString());
        widthDropDown->addItem(QString());
        widthDropDown->setObjectName("widthDropDown");
        sizePolicy1.setHeightForWidth(widthDropDown->sizePolicy().hasHeightForWidth());
        widthDropDown->setSizePolicy(sizePolicy1);
        widthDropDown->setMaximumSize(QSize(200, 20));
        widthDropDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_20->addWidget(widthDropDown);

        styleDropDown = new QComboBox(centralwidget);
        styleDropDown->addItem(QString());
        styleDropDown->addItem(QString());
        styleDropDown->addItem(QString());
        styleDropDown->addItem(QString());
        styleDropDown->addItem(QString());
        styleDropDown->setObjectName("styleDropDown");
        styleDropDown->setEnabled(true);
        sizePolicy1.setHeightForWidth(styleDropDown->sizePolicy().hasHeightForWidth());
        styleDropDown->setSizePolicy(sizePolicy1);
        styleDropDown->setMaximumSize(QSize(200, 20));
        styleDropDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_20->addWidget(styleDropDown);

        capDropDown = new QComboBox(centralwidget);
        capDropDown->addItem(QString());
        capDropDown->addItem(QString());
        capDropDown->addItem(QString());
        capDropDown->setObjectName("capDropDown");
        sizePolicy1.setHeightForWidth(capDropDown->sizePolicy().hasHeightForWidth());
        capDropDown->setSizePolicy(sizePolicy1);
        capDropDown->setMaximumSize(QSize(200, 20));
        capDropDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_20->addWidget(capDropDown);

        joinStyleDropDown = new QComboBox(centralwidget);
        joinStyleDropDown->addItem(QString());
        joinStyleDropDown->addItem(QString());
        joinStyleDropDown->addItem(QString());
        joinStyleDropDown->setObjectName("joinStyleDropDown");
        sizePolicy1.setHeightForWidth(joinStyleDropDown->sizePolicy().hasHeightForWidth());
        joinStyleDropDown->setSizePolicy(sizePolicy1);
        joinStyleDropDown->setMaximumSize(QSize(200, 20));
        joinStyleDropDown->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_20->addWidget(joinStyleDropDown);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setStyleSheet(QString::fromUtf8("* {\n"
"font: 15pt \"Sitka Heading\";\n"
"background-color: rgb(57, 77, 205);\n"
"\n"
"\n"
"color: white;\n"
"}"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_20->addWidget(label_11);

        shapeIdLineEdit = new QLineEdit(centralwidget);
        shapeIdLineEdit->setObjectName("shapeIdLineEdit");
        shapeIdLineEdit->setEnabled(true);

        verticalLayout_20->addWidget(shapeIdLineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setCheckable(true);

        verticalLayout_20->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);

        verticalLayout_20->addItem(verticalSpacer);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        verticalLayout_20->addWidget(label_12);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(1);

        verticalLayout_20->addWidget(spinBox);


        horizontalLayout_5->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 77, 205);\n"
"\n"
"font: 20pt \"Sitka Heading\";\n"
""));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_21->addWidget(label_3);

        brushColorDrop = new QComboBox(centralwidget);
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->addItem(QString());
        brushColorDrop->setObjectName("brushColorDrop");
        sizePolicy1.setHeightForWidth(brushColorDrop->sizePolicy().hasHeightForWidth());
        brushColorDrop->setSizePolicy(sizePolicy1);
        brushColorDrop->setMaximumSize(QSize(200, 20));
        brushColorDrop->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_21->addWidget(brushColorDrop);

        brushStyleDrop = new QComboBox(centralwidget);
        brushStyleDrop->addItem(QString());
        brushStyleDrop->addItem(QString());
        brushStyleDrop->addItem(QString());
        brushStyleDrop->addItem(QString());
        brushStyleDrop->setObjectName("brushStyleDrop");
        sizePolicy1.setHeightForWidth(brushStyleDrop->sizePolicy().hasHeightForWidth());
        brushStyleDrop->setSizePolicy(sizePolicy1);
        brushStyleDrop->setMaximumSize(QSize(200, 20));
        brushStyleDrop->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_21->addWidget(brushStyleDrop);

        removeShapeLabel = new QLabel(centralwidget);
        removeShapeLabel->setObjectName("removeShapeLabel");

        verticalLayout_21->addWidget(removeShapeLabel);

        removeShapeLineEdit = new QLineEdit(centralwidget);
        removeShapeLineEdit->setObjectName("removeShapeLineEdit");

        verticalLayout_21->addWidget(removeShapeLineEdit);

        removeShapeButton = new QPushButton(centralwidget);
        removeShapeButton->setObjectName("removeShapeButton");

        verticalLayout_21->addWidget(removeShapeButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_21);


        horizontalLayout_11->addLayout(horizontalLayout_5);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName("verticalLayout_22");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 77, 205);\n"
"\n"
"font: 15pt \"Sitka Heading\";\n"
""));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_22->addWidget(label_4);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMaximumSize(QSize(200, 200));

        verticalLayout_22->addWidget(textEdit);

        comboBox_41 = new QComboBox(centralwidget);
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->addItem(QString());
        comboBox_41->setObjectName("comboBox_41");
        sizePolicy1.setHeightForWidth(comboBox_41->sizePolicy().hasHeightForWidth());
        comboBox_41->setSizePolicy(sizePolicy1);
        comboBox_41->setMaximumSize(QSize(200, 20));
        comboBox_41->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(comboBox_41);

        comboBox_42 = new QComboBox(centralwidget);
        comboBox_42->addItem(QString());
        comboBox_42->addItem(QString());
        comboBox_42->addItem(QString());
        comboBox_42->addItem(QString());
        comboBox_42->addItem(QString());
        comboBox_42->addItem(QString());
        comboBox_42->addItem(QString());
        comboBox_42->setObjectName("comboBox_42");
        sizePolicy1.setHeightForWidth(comboBox_42->sizePolicy().hasHeightForWidth());
        comboBox_42->setSizePolicy(sizePolicy1);
        comboBox_42->setMaximumSize(QSize(200, 20));
        comboBox_42->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(comboBox_42);

        comboBox_43 = new QComboBox(centralwidget);
        comboBox_43->setObjectName("comboBox_43");
        sizePolicy1.setHeightForWidth(comboBox_43->sizePolicy().hasHeightForWidth());
        comboBox_43->setSizePolicy(sizePolicy1);
        comboBox_43->setMaximumSize(QSize(200, 20));
        comboBox_43->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(comboBox_43);

        comboBox_44 = new QComboBox(centralwidget);
        comboBox_44->setObjectName("comboBox_44");
        sizePolicy1.setHeightForWidth(comboBox_44->sizePolicy().hasHeightForWidth());
        comboBox_44->setSizePolicy(sizePolicy1);
        comboBox_44->setMaximumSize(QSize(200, 20));
        comboBox_44->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(comboBox_44);

        comboBox_45 = new QComboBox(centralwidget);
        comboBox_45->addItem(QString());
        comboBox_45->addItem(QString());
        comboBox_45->addItem(QString());
        comboBox_45->setObjectName("comboBox_45");
        sizePolicy1.setHeightForWidth(comboBox_45->sizePolicy().hasHeightForWidth());
        comboBox_45->setSizePolicy(sizePolicy1);
        comboBox_45->setMaximumSize(QSize(200, 20));
        comboBox_45->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(comboBox_45);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);
        comboBox_2->setMaximumSize(QSize(200, 20));
        comboBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        verticalLayout_22->addWidget(comboBox_2);


        horizontalLayout_11->addLayout(verticalLayout_22);


        verticalLayout_3->addLayout(horizontalLayout_11);


        verticalLayout_19->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy4);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(223, 227, 0);\n"
"font: 13pt \"Sitka Heading\";\n"
""));
        label_9->setScaledContents(true);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(label_9);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(223, 227, 0);\n"
"font: 13pt \"Sitka Heading\";\n"
""));
        label_8->setScaledContents(true);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(label_8);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(223, 227, 0);\n"
"font: 13pt \"Sitka Heading\";\n"
""));
        label_7->setScaledContents(true);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(label_7);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(223, 227, 0);\n"
"font: 13pt \"Sitka Heading\";\n"
""));
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(label_6);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(223, 227, 0);\n"
"font: 13pt \"Sitka Heading\";\n"
""));
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_9->addWidget(label_5);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lengthLineEdit = new QLineEdit(centralwidget);
        lengthLineEdit->setObjectName("lengthLineEdit");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lengthLineEdit->sizePolicy().hasHeightForWidth());
        lengthLineEdit->setSizePolicy(sizePolicy5);
        lengthLineEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);

        horizontalLayout_7->addWidget(lengthLineEdit);

        widthLineEdit = new QLineEdit(centralwidget);
        widthLineEdit->setObjectName("widthLineEdit");
        sizePolicy5.setHeightForWidth(widthLineEdit->sizePolicy().hasHeightForWidth());
        widthLineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(widthLineEdit);

        radiusLineEdit = new QLineEdit(centralwidget);
        radiusLineEdit->setObjectName("radiusLineEdit");
        sizePolicy5.setHeightForWidth(radiusLineEdit->sizePolicy().hasHeightForWidth());
        radiusLineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(radiusLineEdit);

        semimajorLineEdit = new QLineEdit(centralwidget);
        semimajorLineEdit->setObjectName("semimajorLineEdit");
        sizePolicy5.setHeightForWidth(semimajorLineEdit->sizePolicy().hasHeightForWidth());
        semimajorLineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(semimajorLineEdit);

        semiminorLineEdit = new QLineEdit(centralwidget);
        semiminorLineEdit->setObjectName("semiminorLineEdit");
        sizePolicy5.setHeightForWidth(semiminorLineEdit->sizePolicy().hasHeightForWidth());
        semiminorLineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(semiminorLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_19->addLayout(verticalLayout_4);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName("verticalLayout_23");
        addPushButton = new QPushButton(centralwidget);
        addPushButton->setObjectName("addPushButton");
        sizePolicy1.setHeightForWidth(addPushButton->sizePolicy().hasHeightForWidth());
        addPushButton->setSizePolicy(sizePolicy1);
        addPushButton->setMaximumSize(QSize(500, 50));
        addPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 95, 95);\n"
"color: white;\n"
"font: 900 9pt \"Segoe UI Black\";"));

        verticalLayout_23->addWidget(addPushButton);


        verticalLayout_19->addLayout(verticalLayout_23);


        horizontalLayout_6->addLayout(verticalLayout_19);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        canvasWidget = new Canvas(centralwidget);
        canvasWidget->setObjectName("canvasWidget");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(canvasWidget->sizePolicy().hasHeightForWidth());
        canvasWidget->setSizePolicy(sizePolicy6);
        canvasWidget->setMinimumSize(QSize(1000, 500));
        canvasWidget->setMaximumSize(QSize(3000, 2000));
        canvasWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_5->addWidget(canvasWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        toggleLine = new QPushButton(centralwidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(toggleLine);
        toggleLine->setObjectName("toggleLine");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(toggleLine->sizePolicy().hasHeightForWidth());
        toggleLine->setSizePolicy(sizePolicy7);
        toggleLine->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 124, 124);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/line.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleLine->setIcon(icon);
        toggleLine->setIconSize(QSize(30, 50));
        toggleLine->setCheckable(true);
        toggleLine->setAutoExclusive(true);

        horizontalLayout_2->addWidget(toggleLine);

        togglePolyline = new QPushButton(centralwidget);
        buttonGroup->addButton(togglePolyline);
        togglePolyline->setObjectName("togglePolyline");
        sizePolicy7.setHeightForWidth(togglePolyline->sizePolicy().hasHeightForWidth());
        togglePolyline->setSizePolicy(sizePolicy7);
        togglePolyline->setStyleSheet(QString::fromUtf8("background-color: rgb(165, 165, 165);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/polyline.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        togglePolyline->setIcon(icon1);
        togglePolyline->setIconSize(QSize(50, 50));
        togglePolyline->setCheckable(true);
        togglePolyline->setAutoExclusive(true);

        horizontalLayout_2->addWidget(togglePolyline);

        togglePolygon = new QPushButton(centralwidget);
        buttonGroup->addButton(togglePolygon);
        togglePolygon->setObjectName("togglePolygon");
        sizePolicy7.setHeightForWidth(togglePolygon->sizePolicy().hasHeightForWidth());
        togglePolygon->setSizePolicy(sizePolicy7);
        togglePolygon->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/polygon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        togglePolygon->setIcon(icon2);
        togglePolygon->setIconSize(QSize(30, 50));
        togglePolygon->setCheckable(true);
        togglePolygon->setAutoExclusive(true);

        horizontalLayout_2->addWidget(togglePolygon);

        toggleSquare = new QPushButton(centralwidget);
        buttonGroup->addButton(toggleSquare);
        toggleSquare->setObjectName("toggleSquare");
        sizePolicy7.setHeightForWidth(toggleSquare->sizePolicy().hasHeightForWidth());
        toggleSquare->setSizePolicy(sizePolicy7);
        toggleSquare->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/square.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleSquare->setIcon(icon3);
        toggleSquare->setIconSize(QSize(30, 50));
        toggleSquare->setCheckable(true);
        toggleSquare->setAutoExclusive(true);

        horizontalLayout_2->addWidget(toggleSquare);

        toggleRectangle = new QPushButton(centralwidget);
        buttonGroup->addButton(toggleRectangle);
        toggleRectangle->setObjectName("toggleRectangle");
        sizePolicy7.setHeightForWidth(toggleRectangle->sizePolicy().hasHeightForWidth());
        toggleRectangle->setSizePolicy(sizePolicy7);
        toggleRectangle->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 229, 229);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/rectangle.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleRectangle->setIcon(icon4);
        toggleRectangle->setIconSize(QSize(30, 50));
        toggleRectangle->setCheckable(true);
        toggleRectangle->setAutoExclusive(true);

        horizontalLayout_2->addWidget(toggleRectangle);

        toggleCircle = new QPushButton(centralwidget);
        buttonGroup->addButton(toggleCircle);
        toggleCircle->setObjectName("toggleCircle");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(toggleCircle->sizePolicy().hasHeightForWidth());
        toggleCircle->setSizePolicy(sizePolicy8);
        toggleCircle->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 236, 236);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/circle.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleCircle->setIcon(icon5);
        toggleCircle->setIconSize(QSize(30, 50));
        toggleCircle->setCheckable(true);
        toggleCircle->setAutoExclusive(true);

        horizontalLayout_2->addWidget(toggleCircle);

        toggleEllipse = new QPushButton(centralwidget);
        buttonGroup->addButton(toggleEllipse);
        toggleEllipse->setObjectName("toggleEllipse");
        sizePolicy7.setHeightForWidth(toggleEllipse->sizePolicy().hasHeightForWidth());
        toggleEllipse->setSizePolicy(sizePolicy7);
        toggleEllipse->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/ellipse.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleEllipse->setIcon(icon6);
        toggleEllipse->setIconSize(QSize(30, 50));
        toggleEllipse->setCheckable(true);
        toggleEllipse->setAutoExclusive(true);

        horizontalLayout_2->addWidget(toggleEllipse);

        toggleText = new QPushButton(centralwidget);
        buttonGroup->addButton(toggleText);
        toggleText->setObjectName("toggleText");
        sizePolicy8.setHeightForWidth(toggleText->sizePolicy().hasHeightForWidth());
        toggleText->setSizePolicy(sizePolicy8);
        QPalette palette2;
        QBrush brush1(QColor(123, 169, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(123, 169, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        toggleText->setPalette(palette2);
        toggleText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/text.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toggleText->setIcon(icon7);
        toggleText->setIconSize(QSize(50, 80));
        toggleText->setCheckable(true);
        toggleText->setAutoExclusive(true);

        horizontalLayout_2->addWidget(toggleText);


        verticalLayout_5->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        contactUsButton->setText(QCoreApplication::translate("MainWindow", "Contact Us", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Testimonials", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "2D Graphics Modeler", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pen", nullptr));
        colorDropDown->setItemText(0, QCoreApplication::translate("MainWindow", "Red", nullptr));
        colorDropDown->setItemText(1, QCoreApplication::translate("MainWindow", "White", nullptr));
        colorDropDown->setItemText(2, QCoreApplication::translate("MainWindow", "Black", nullptr));
        colorDropDown->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        colorDropDown->setItemText(4, QCoreApplication::translate("MainWindow", "Cyan", nullptr));
        colorDropDown->setItemText(5, QCoreApplication::translate("MainWindow", "Magenta", nullptr));
        colorDropDown->setItemText(6, QCoreApplication::translate("MainWindow", "Yellow", nullptr));
        colorDropDown->setItemText(7, QCoreApplication::translate("MainWindow", "Gray", nullptr));
        colorDropDown->setItemText(8, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        colorDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        widthDropDown->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        widthDropDown->setItemText(1, QCoreApplication::translate("MainWindow", "10", nullptr));
        widthDropDown->setItemText(2, QCoreApplication::translate("MainWindow", "100", nullptr));

        widthDropDown->setCurrentText(QString());
        widthDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        styleDropDown->setItemText(0, QCoreApplication::translate("MainWindow", "No Pen", nullptr));
        styleDropDown->setItemText(1, QCoreApplication::translate("MainWindow", "Solid Line", nullptr));
        styleDropDown->setItemText(2, QCoreApplication::translate("MainWindow", "Dash Line", nullptr));
        styleDropDown->setItemText(3, QCoreApplication::translate("MainWindow", "Dash Dot Line", nullptr));
        styleDropDown->setItemText(4, QCoreApplication::translate("MainWindow", "Dash Dot Dot Line", nullptr));

        styleDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "Style", nullptr));
        capDropDown->setItemText(0, QCoreApplication::translate("MainWindow", "Square Cap", nullptr));
        capDropDown->setItemText(1, QCoreApplication::translate("MainWindow", "Flat Cap", nullptr));
        capDropDown->setItemText(2, QCoreApplication::translate("MainWindow", "Round Cap", nullptr));

        capDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "CapStyle", nullptr));
        joinStyleDropDown->setItemText(0, QCoreApplication::translate("MainWindow", "Bevel Join", nullptr));
        joinStyleDropDown->setItemText(1, QCoreApplication::translate("MainWindow", "Miter Join", nullptr));
        joinStyleDropDown->setItemText(2, QCoreApplication::translate("MainWindow", "Round Join", nullptr));

        joinStyleDropDown->setPlaceholderText(QCoreApplication::translate("MainWindow", "JoinStyle", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", " Move Shape", nullptr));
        shapeIdLineEdit->setText(QCoreApplication::translate("MainWindow", "Enter ID:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Toggle Arrow Movement", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Num. of Points", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Brush", nullptr));
        brushColorDrop->setItemText(0, QCoreApplication::translate("MainWindow", "White", nullptr));
        brushColorDrop->setItemText(1, QCoreApplication::translate("MainWindow", "Black", nullptr));
        brushColorDrop->setItemText(2, QCoreApplication::translate("MainWindow", "Red", nullptr));
        brushColorDrop->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        brushColorDrop->setItemText(4, QCoreApplication::translate("MainWindow", "Blue", nullptr));
        brushColorDrop->setItemText(5, QCoreApplication::translate("MainWindow", "Cyan", nullptr));
        brushColorDrop->setItemText(6, QCoreApplication::translate("MainWindow", "Magenta", nullptr));
        brushColorDrop->setItemText(7, QCoreApplication::translate("MainWindow", "Yellow", nullptr));
        brushColorDrop->setItemText(8, QCoreApplication::translate("MainWindow", "Gray", nullptr));

        brushColorDrop->setPlaceholderText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        brushStyleDrop->setItemText(0, QCoreApplication::translate("MainWindow", "No Brush", nullptr));
        brushStyleDrop->setItemText(1, QCoreApplication::translate("MainWindow", "Solid Pattern", nullptr));
        brushStyleDrop->setItemText(2, QCoreApplication::translate("MainWindow", "Hor Pattern", nullptr));
        brushStyleDrop->setItemText(3, QCoreApplication::translate("MainWindow", "Ver Pattern", nullptr));

        brushStyleDrop->setPlaceholderText(QCoreApplication::translate("MainWindow", "Style", nullptr));
        removeShapeLabel->setText(QCoreApplication::translate("MainWindow", "Remove Shape", nullptr));
        removeShapeLineEdit->setText(QCoreApplication::translate("MainWindow", "Enter ID:", nullptr));
        removeShapeButton->setText(QCoreApplication::translate("MainWindow", "Remove Shape", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Font and Content", nullptr));
        textEdit->setDocumentTitle(QString());
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type contexts of text here.", nullptr));
        comboBox_41->setItemText(0, QCoreApplication::translate("MainWindow", "Red", nullptr));
        comboBox_41->setItemText(1, QCoreApplication::translate("MainWindow", "White", nullptr));
        comboBox_41->setItemText(2, QCoreApplication::translate("MainWindow", "Black", nullptr));
        comboBox_41->setItemText(3, QCoreApplication::translate("MainWindow", "Green", nullptr));
        comboBox_41->setItemText(4, QCoreApplication::translate("MainWindow", "Cyan", nullptr));
        comboBox_41->setItemText(5, QCoreApplication::translate("MainWindow", "Magenta", nullptr));
        comboBox_41->setItemText(6, QCoreApplication::translate("MainWindow", "Yellow", nullptr));
        comboBox_41->setItemText(7, QCoreApplication::translate("MainWindow", "Gray", nullptr));
        comboBox_41->setItemText(8, QCoreApplication::translate("MainWindow", "Blue", nullptr));

        comboBox_41->setPlaceholderText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        comboBox_42->setItemText(0, QCoreApplication::translate("MainWindow", "AlignLeft", nullptr));
        comboBox_42->setItemText(1, QCoreApplication::translate("MainWindow", "AlignRight", nullptr));
        comboBox_42->setItemText(2, QCoreApplication::translate("MainWindow", "AlignHCenter", nullptr));
        comboBox_42->setItemText(3, QCoreApplication::translate("MainWindow", "AlignTop", nullptr));
        comboBox_42->setItemText(4, QCoreApplication::translate("MainWindow", "AlignBottom", nullptr));
        comboBox_42->setItemText(5, QCoreApplication::translate("MainWindow", "AlignVCenter", nullptr));
        comboBox_42->setItemText(6, QCoreApplication::translate("MainWindow", "AlignBaseline", nullptr));

        comboBox_42->setPlaceholderText(QCoreApplication::translate("MainWindow", "Allignment", nullptr));
        comboBox_43->setPlaceholderText(QCoreApplication::translate("MainWindow", "PointSize", nullptr));
        comboBox_44->setPlaceholderText(QCoreApplication::translate("MainWindow", "FontFamily", nullptr));
        comboBox_45->setItemText(0, QCoreApplication::translate("MainWindow", "StyleNormal", nullptr));
        comboBox_45->setItemText(1, QCoreApplication::translate("MainWindow", "StyleItalic", nullptr));
        comboBox_45->setItemText(2, QCoreApplication::translate("MainWindow", "StyleOblique", nullptr));

        comboBox_45->setPlaceholderText(QCoreApplication::translate("MainWindow", "FontStyle", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Thin", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "ExtraLight", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Light", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "Medium", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "DemiBold", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("MainWindow", "Bold", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("MainWindow", "ExtraBold", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("MainWindow", "Black", nullptr));

        comboBox_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "FontWeight", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "SemiMajor", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "SemiMinor", nullptr));
        lengthLineEdit->setText(QString());
        lengthLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        widthLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        radiusLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        semimajorLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        semiminorLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        addPushButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        toggleLine->setText(QString());
        togglePolyline->setText(QString());
        togglePolygon->setText(QString());
        toggleSquare->setText(QString());
        toggleRectangle->setText(QString());
        toggleCircle->setText(QString());
        toggleEllipse->setText(QString());
        toggleText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
