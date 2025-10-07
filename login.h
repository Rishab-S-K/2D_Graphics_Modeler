#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

/**
 * @class login
 * @brief Provides the login dialog interface for the application
 *
 * This class manages the user authentication process through a dialog window.
 * It handles username/password validation and provides feedback to the user.
 *
 * @author Omar Farag, Cem Yildiz, Kiefer Kokhavi
 * @date November 2024
 */
class login : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the login dialog
     * @param parent Optional parent widget
     */
    explicit login(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     * 
     * Cleans up the UI resources
     */
    ~login();

private slots:
    /**
     * @brief Handles the login button click event
     * 
     * Validates the entered credentials and provides appropriate feedback
     */
    void on_loginButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::login *ui;    ///< Pointer to the UI elements
};

#endif // LOGIN_H
