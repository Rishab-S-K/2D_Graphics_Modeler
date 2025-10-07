#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <string>

/**
 * @class Shape
 * @brief Abstract base class for all shapes in the 2D graphics modeler
 *
 * The Shape class provides a common interface for all drawable shapes in the application.
 * It defines pure virtual functions that all derived shape classes must implement for
 * drawing, movement, and geometric calculations. The class maintains basic properties
 * common to all shapes such as identifier, pen style, brush style, and font settings.
 *
 * @author Omar Farag, Rishab Senthil Kumar, Cem Yildiz, Kiefer Kokhavi, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Shape {
protected:
    int id;         ///< Unique identifier for the shape
    QPen pen;       ///< Pen settings for drawing the shape's outline
    QBrush brush;   ///< Brush settings for filling the shape
    QFont font;     ///< Font settings (used primarily by Text shapes)

public:
    /**
     * @brief Constructor for shapes with pen and brush properties
     * @param id Unique identifier for the shape
     * @param pen QPen object defining the shape's outline properties
     * @param brush QBrush object defining the shape's fill properties
     */
    Shape(int id, const QPen& pen, const QBrush& brush)
        : id(id), pen(pen), brush(brush) {}

    /**
     * @brief Constructor for text-based shapes
     * @param id Unique identifier for the shape
     * @param font QFont object defining the text properties
     */
    Shape(int id, const QFont& font)
        : id(id), font(font) {}

    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Shape() = default;

    /**
     * @brief Pure virtual function to draw the shape
     * @param painter QPainter object used to render the shape
     * 
     * Each derived class must implement this function to define how the shape
     * is rendered on the canvas.
     */
    virtual void draw(QPainter& painter) = 0;

    /**
     * @brief Pure virtual function to move the shape
     * @param dx Horizontal displacement in pixels (positive moves right)
     * @param dy Vertical displacement in pixels (positive moves down)
     * 
     * Each derived class must implement this function to define how the shape
     * is moved on the canvas.
     */
    virtual void move(int dx, int dy) = 0;

    /**
     * @brief Pure virtual function to calculate the shape's perimeter
     * @return The perimeter value as a double
     * 
     * Each derived class must implement this function to calculate its specific
     * perimeter formula.
     */
    virtual double perimeter() const = 0;

    /**
     * @brief Pure virtual function to calculate the shape's area
     * @return The area value as a double
     * 
     * Each derived class must implement this function to calculate its specific
     * area formula.
     */
    virtual double area() const = 0;

    /**
     * @brief Equality comparison operator
     * @param other The shape to compare with
     * @return true if the shapes have the same ID, false otherwise
     */

    /**
     * @brief Get the type identifier of the shape
     * @return String representation of the shape type
     * 
     * Each derived class must implement this to return its specific type identifier.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Check if the shape supports fill properties
     * @return true if the shape can be filled, false otherwise
     * 
     * Indicates whether the shape uses brush properties for filling.
     * For example, lines return false while rectangles return true.
     */
    virtual bool isFill() const = 0;

    /**
     * @brief Get the shape's pen settings
     * @return Current QPen object defining the shape's outline properties
     */
    QPen getPen() const {
        return pen;
    }

    /**
     * @brief Get the shape's brush settings
     * @return Current QBrush object defining the shape's fill properties
     */
    QBrush getBrush() const {
        return brush;
    }

    /**
     * @brief Get the shape's font settings
     * @return Current QFont object defining text properties
     */
    QFont getFont() const {
        return font;
    }

    bool operator==(const Shape& other) const { return id == other.id; }

    /**
     * @brief Less than comparison operator
     * @param other The shape to compare with
     * @return true if this shape's ID is less than the other's ID
     */
    bool operator<(const Shape& other) const { return id < other.id; }

    /**
     * @brief Get the shape's unique identifier
     * @return Integer ID of the shape
     */
    int getId()
    {
        return id;
    }

    /**
     * @brief setId
     * @param newId
     *
     * Set a new id to the shape
     */

    void setId(int newId)
    {
        id = newId;
    }

    // Prevent copying of shapes
    Shape(const Shape&) = delete;            ///< Deleted copy constructor
    Shape& operator=(const Shape&) = delete; ///< Deleted copy assignment operator
};

#endif // SHAPE_H
