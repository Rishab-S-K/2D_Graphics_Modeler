#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

/**
 * @brief Constructs the login dialog and sets up the UI
 * @param parent Parent widget, if any
 */
login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor that cleans up UI resources
 */
login::~login()
{
    delete ui;
}

/**
 * @brief Handles validation and authorization when the login button is clicked
 * 
 * This function validates the entered username and password against hardcoded
 * credentials. On successful login, it accepts the dialog. On failure, it 
 * displays a warning message.
 * 
 * Credentials:
 * - Username: heapgobbler
 * - Password: gobble
 */
void login::on_loginButton_clicked()
{
    auto username = ui->usernameLineEdit->text();
    auto password = ui->passwordLineEdit->text();

    if (username == "heapgobbler" && password == "gobble")
    {
        QMessageBox::information(this, "Login", "Correct");
        accept();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Incorrect");
    }
}

/**
 * @brief Handles the exit button click event
 * 
 * Closes the login dialog by rejecting it, which will trigger
 * application termination in the main window.
 */
void login::on_exitButton_clicked()
{
    reject();
}

