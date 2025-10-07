#include <canvas.h>
#include <QtGui>
#include <fstream>

/**
 * @brief Constructor for the Canvas widget
 * @param parent Parent widget, typically the main window
 * 
 * Initializes an empty canvas as a QWidget with no shapes.
 */
Canvas::Canvas(QWidget* parent): QWidget(parent)
{}

/**
 * @brief Handles paint events for the canvas
 * @param event The paint event triggering the redraw
 * 
 * This function is automatically called by Qt's event system whenever
 * the canvas needs to be redrawn. It iterates through all shapes
 * and calls their respective draw methods.
 */
void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QSize size = this->size();

    for (Shape* shape : shapes) {
        shape->draw(painter);
    }
}

/**
 * @brief Static counter for assigning unique IDs to shapes
 *
 * This counter is incremented each time a new shape is added,
 * ensuring each shape gets a unique identifier.
 */
int Canvas::currentId = 1;

/**
 * @brief Adds a new shape to the canvas
 * @param shape Pointer to the shape to be added
 * 
 * Takes ownership of the shape pointer and triggers a canvas update
 * to display the new shape immediately.
 */
void Canvas::storeShape(Shape* shape)
{
    shapes.push_back(shape);
    update();

    currentId++;

    ofstream testFile("shapes.txt");

    testFile << shapes;

    testFile.close();

}

/**
 * @brief removeShape
 * @param id
 *
 * This method removes the shape that has int id
 */

void Canvas::removeShape(int id)
{
    for (auto i = shapes.begin(); i != shapes.end(); i++)
    {
        // tracks shapes index
        if ((*i)->getId() == id)
        {
            // erase the shape when the id is found
            shapes.erase(i);
            return;
        }
    }
}
