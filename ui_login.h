/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(605, 437);
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 120, 71, 16));
        label_2 = new QLabel(login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 170, 71, 16));
        loginButton = new QPushButton(login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(210, 290, 80, 24));
        exitButton = new QPushButton(login);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(300, 290, 80, 24));
        usernameLineEdit = new QLineEdit(login);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(210, 140, 161, 24));
        usernameLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        passwordLineEdit = new QLineEdit(login);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(210, 200, 161, 24));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_3 = new QLabel(login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 40, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../heap_gobblers_mascot_2.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 10, 131, 16));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("login", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("login", "Login", nullptr));
        exitButton->setText(QCoreApplication::translate("login", "Exit", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("login", "Heap Gobblers Inc.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
