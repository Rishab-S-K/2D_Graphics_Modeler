#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"
#include "vector.h"
#include "ShapeParser.h"
#include "TestimonialsManager.h"
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Main application window for the 2D graphics modeler
 *
 * This class manages the main UI interface, including the shape creation tools,
 * canvas display, and all shape manipulation controls. It coordinates between
 * the UI components, shape parser, and canvas to provide the complete
 * graphics modeling functionality.
 *
 * @author Rishab Senthil Kumar, Omar Farag, Cem Yildiz, Kiefer Kokhavi
 * @date November 2024
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window
     * @param parent Optional parent widget
     * 
     * Initializes the UI, sets up the canvas, and loads any existing shapes
     * from the shapes.txt file.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     * 
     * Cleans up UI resources and any allocated shapes
     */
    ~MainWindow();

    /**
     * @brief Retrieves points input by the user from the UI
     * @param ok Reference to a boolean that will be set to true if points were successfully retrieved
     * @return Vector of QPoints containing the user-input coordinates
     * 
     * Collects points from the dynamic point input layout and converts them to QPoint objects.
     * The ok parameter will be set to false if any conversion fails.
     */
    custom::vector<QPoint> getPoints(bool &ok);

    /**
     * @brief Shows or hides widget groups based on the selected shape type
     * @param pen Whether to show pen-related widgets
     * @param brush Whether to show brush-related widgets
     * @param text Whether to show text-related widgets
     * @param l Whether to show length input
     * @param w Whether to show width input
     * @param radius Whether to show radius input
     * @param semiMajor Whether to show semi-major axis input
     * @param semiMinor Whether to show semi-minor axis input
     * 
     * Controls visibility of widget groups to show only relevant inputs for the currently
     * selected shape type.
     */
    void showWidgets(bool pen, bool brush, bool text, bool l, bool w, bool radius, bool semiMajor, bool semiMinor);


protected:
    /**
     * @brief Handles keyboard events for shape movement
     * @param event The key event containing information about the pressed key
     * 
     * Implements WASD key controls for moving shapes when movement is enabled.
     * Only active when a valid shape ID is entered and movement is toggled on.
     */
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    /**
     * @brief Handles generic button clicks
     */
    void on_pushButton_clicked();

    /**
     * @brief Handles text shape toggle button click
     * 
     * Shows text-specific input fields and hides irrelevant controls.
     */
    void on_toggleText_clicked();

    /**
     * @brief Handles ellipse shape toggle button click
     * 
     * Shows ellipse-specific input fields and hides irrelevant controls.
     */
    void on_toggleEllipse_clicked();

    /**
     * @brief Handles circle shape toggle button click
     * 
     * Shows circle-specific input fields and hides irrelevant controls.
     */
    void on_toggleCircle_clicked();

    /**
     * @brief Handles rectangle shape toggle button click
     * 
     * Shows rectangle-specific input fields and hides irrelevant controls.
     */
    void on_toggleRectangle_clicked();

    /**
     * @brief Handles square shape toggle button click
     * 
     * Shows square-specific input fields and hides irrelevant controls.
     */
    void on_toggleSquare_clicked();

    /**
     * @brief Handles polygon shape toggle button click
     * 
     * Shows polygon-specific input fields and enables point input.
     */
    void on_togglePolygon_clicked();

    /**
     * @brief Handles polyline shape toggle button click
     * 
     * Shows polyline-specific input fields and enables point input.
     */
    void on_togglePolyline_clicked();

    /**
     * @brief Handles line shape toggle button click
     * 
     * Shows line-specific input fields and restricts point input to exactly two points.
     */
    void on_toggleLine_clicked();

    /**
     * @brief Handles changes to the number of points spinbox
     * 
     * Dynamically updates the point input layout to match the selected number of points,
     * creating or removing coordinate input fields as needed.
     */
    void on_spinBox_change();

    /**
     * @brief Handles the "Add" button click
     * 
     * Creates a new shape based on the current UI settings and adds it
     * to the canvas. Validates all input parameters before shape creation.
     */
    void on_addPushButton_clicked();

    /**
     * @brief Toggles shape movement functionality
     * @param checked Whether movement is being enabled or disabled
     */
    void on_pushButton_toggled(bool checked);

    /**
     * @brief Displays contact information in a message box
     */
    void on_contactUsButton_clicked();

    /**
     * @brief Creates a login window and handles application state based on login result
     */
    void on_loginButton_clicked();

    /**
     * @brief Handles clicks on the testimonials button to display customer reviews
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Handles clicks on the remove button to remove objects from the canvas
     */
    void on_removeShapeButton_clicked();

    /**
     * @brief Handles clicks on the report button to generate a report of the shapes on the canvas
     */
    void on_reportButton_clicked();
private:
    Ui::MainWindow *ui;     ///< Pointer to the UI elements
    Canvas *canvas;         ///< Pointer to the drawing canvas
    ShapeParser parser;     ///< Parser for loading shapes from file
    custom::vector<Shape*> parsed;  ///< Collection of loaded shapes
    bool movementEnabled = false; ///< Tracks if the movement button is toggled
    TestimonialsManager* testimonialsManager; ///< Manager for customer testimonials
    QVBoxLayout* pointsLayout = nullptr; // for multiple points
    bool alreadyLoggedIn = false; ///< Checks if the user has already logged in from the login button in the main window
    bool isLoggedIn = false;  ///< Track login status

    /**
     * @brief Enables or disables all shape manipulation controls
     * @param enabled true to enable controls, false to disable
     */
    void setControlsEnabled(bool enabled);

};

#endif // MAINWINDOW_H
