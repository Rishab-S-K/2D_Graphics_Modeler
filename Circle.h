#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <QColor>

/**
 * @class Circle
 * @brief Represents a circular shape in the 2D graphics modeler
 *
 * The Circle class provides functionality for rendering and manipulating
 * circular shapes, including position, radius, color, and geometric calculations.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Circle : public Shape {
private:
    QPoint center; ///< Center of the circle
    int radius;    ///< Radius of the circle
    QColor color;  ///< Color of the circle

public:
    /**
     * @brief Constructs a new circle with specified properties
     * @param id Unique identifier for the circle
     * @param pen Pen settings for drawing the circle's outline
     * @param brush Brush settings for filling the circle
     * @param center Center point of the circle
     * @param radius Radius of the circle in pixels
     */
    Circle(int id, const QPen& pen, const QBrush& brush, QPoint center, int radius)
        : Shape(id, pen, brush), center(center), radius(radius) {}

    /**
     * @brief Renders the circle on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse(center, radius, radius);
    }

    /**
     * @brief Moves the circle by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override {
        center += QPoint(dx, dy);
    }

    /**
     * @brief Calculates the circumference of the circle
     * @return The circumference value
     */
    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    /**
     * @brief Calculates the area of the circle
     * @return The area value
     */
    double area() const override {
        return M_PI * qPow(radius, 2);
    }

    std::string getType() const override {
        return "Circle";
    }

    bool isFill() const override {
        return true;
    }

    QPoint getCenter() const
    {
        return center;
    }

    int getRadius() const
    {
        return radius;
    }
};

#endif // CIRCLE_H
