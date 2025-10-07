#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <QColor>

/**
 * @class Square
 * @brief Represents a square shape in the 2D graphics modeler
 *
 * The Square class provides functionality for rendering and manipulating
 * squares, which are special cases of rectangles where all sides are equal.
 * The shape is defined by its top-left corner and side length.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Square : public Shape {
private:
    QPointF topLeft; ///< Top-left corner of the square
    float side;      ///< Length of each side of the square

public:
    /**
     * @brief Constructs a new square with specified properties
     * @param id Unique identifier for the square
     * @param pen Pen settings for drawing the square's outline
     * @param brush Brush settings for filling the square
     * @param x X-coordinate of the top-left corner
     * @param y Y-coordinate of the top-left corner
     * @param side Length of each side of the square
     */
    Square(int id, const QPen& pen, const QBrush& brush, float x, float y, float side)
        : Shape(id, pen, brush), topLeft(x, y), side(side) {}

    /**
     * @brief Renders the square on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(QRectF(topLeft, QSizeF(side, side)));
    }

    /**
     * @brief Moves the square by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override {
        topLeft += QPointF(dx, dy);
    }

    /**
     * @brief Calculates the perimeter of the square
     * @return The perimeter (4 * side)
     */
    double perimeter() const override {
        return 4 * side;
    }

    /**
     * @brief Calculates the area of the square
     * @return The area (side * side)
     */
    double area() const override {
        return side * side;
    }

    std::string getType() const override {
        return "Square";
    }

    bool isFill() const override {
        return true;
    }

    QPointF getTopLeft() const
    {
        return topLeft;
    }

    float getSide() const
    {
        return side;
    }
};

#endif // SQUARE_H
