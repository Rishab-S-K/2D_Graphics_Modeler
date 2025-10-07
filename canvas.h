#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <serializer.h>

class QPaintEvent;

/**
 * @class Canvas
 * @brief Custom widget for rendering and managing shapes
 *
 * The Canvas class provides a drawing surface for all shapes in the 2D graphics modeler.
 * It manages a collection of shapes and handles their rendering through Qt's painting system.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz
 * @date November 2024
 */
class Canvas : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a Canvas widget
     * @param parent Optional parent widget
     */
    explicit Canvas(QWidget *parent = nullptr);

    /**
     * @brief Virtual destructor
     */
    ~Canvas() {};

    /**
     * @brief Adds a new shape to the canvas
     * @param shape Pointer to the shape to add
     * 
     * Takes ownership of the shape pointer and will handle its deletion
     */
    void storeShape(Shape* shape);

    /**
     * @brief Handles the painting of all shapes
     * @param event The paint event containing information about the area to be updated
     */
    virtual void paintEvent(QPaintEvent* event);

    /**
     * @brief Returns a reference to the stored shapes
     * @return Reference to the vector of shapes
     */
    const custom::vector<Shape*>& getShapes() const {
        return shapes;
    }

    /**
     * @brief getCurrentId
     * @return current shape id
     */

    int getCurrentId() const {
        return currentId;
    }

    /**
     * @brief removeShape
     * @param id
     *
     * This method removes the shape that has int id
     */

    void removeShape(int id);

    /**
     * @brief Gets a vector of shapes sorted by area
     * @return Vector of shape pointers sorted by ascending area
     */
    custom::vector<Shape*> getShapesSortedByArea() const {
        return sortShapesByArea();
    }

    /**
     * @brief Gets a vector of shapes sorted by perimeter
     * @return Vector of shape pointers sorted by ascending perimeter
     */
    custom::vector<Shape*> getShapesSortedByPerimeter() const {
        return sortShapesByPerimeter();
    }

private:
    custom::vector<Shape*> shapes;  ///< Collection of shapes to be rendered
    static int currentId;

    /**
     * @brief Helper method that sorts shapes by area in ascending order
     * @return A new vector containing shapes sorted by area
     * 
     * Creates a copy of the internal shapes vector and sorts it using each shape's
     * implemented area() function. The original order of shapes in the canvas is preserved.
     * 
     * @see Shape::area()
     */
    custom::vector<Shape*> sortShapesByArea() const {
        custom::vector<Shape*> sortedShapes = shapes;
        
        for (int i = 0; i < sortedShapes.size() - 1; i++) {
            int minIndex = i;
            
            for (int j = i + 1; j < sortedShapes.size(); j++) {
                if (sortedShapes[j]->area() < sortedShapes[minIndex]->area()) {
                    minIndex = j;
                }
            }
            
            if (minIndex != i) {
                Shape* temp = sortedShapes[i];
                sortedShapes[i] = sortedShapes[minIndex];
                sortedShapes[minIndex] = temp;
            }
        }
        
        return sortedShapes;
    }

    /**
     * @brief Helper method that sorts shapes by perimeter in ascending order
     * @return A new vector containing shapes sorted by perimeter
     * 
     * Creates a copy of the internal shapes vector and sorts it using each shape's
     * implemented perimeter() function. The original order of shapes in the canvas is preserved.
     * 
     * @see Shape::perimeter()
     */
    custom::vector<Shape*> sortShapesByPerimeter() const {
        custom::vector<Shape*> sortedShapes = shapes;
        
        for (int i = 0; i < sortedShapes.size() - 1; i++) {
            int minIndex = i;
            
            for (int j = i + 1; j < sortedShapes.size(); j++) {
                if (sortedShapes[j]->perimeter() < sortedShapes[minIndex]->perimeter()) {
                    minIndex = j;
                }
            }
            
            if (minIndex != i) {
                Shape* temp = sortedShapes[i];
                sortedShapes[i] = sortedShapes[minIndex];
                sortedShapes[minIndex] = temp;
            }
        }
        
        return sortedShapes;
    }
};

#endif // CANVAS_H
