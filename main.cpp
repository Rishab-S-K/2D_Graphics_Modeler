#include "mainwindow.h"
#include "ShapeParser.h"
#include "Shape.h"
#include "login.h"
#include "ui_login.h"
#include "canvas.h"

#include <QApplication>

/**
 * @brief Application entry point
 * 
 * Initializes the Qt application, displays the login dialog,
 * and launches the main window if authentication succeeds.
 * 
 * @note Currently configured for testing with authentication disabled
 * 
 * @param argc Command line argument count
 * @param argv Command line arguments
 * @return Application exit code
 * 
 * @author Rishab Senthil Kumar
 * @date December 2024
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}