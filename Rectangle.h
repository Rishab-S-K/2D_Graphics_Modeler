#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <QColor>
#pragma once

/**
 * @class Rectangle
 * @brief Represents a rectangle in the 2D graphics modeler
 *
 * The Rectangle class provides functionality for rendering and manipulating
 * rectangular shapes. Rectangles are defined by their position and dimensions
 * and can have both outline and fill properties.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Rectangle : public Shape {
private:
    QRect rect; ///< Position and dimensions of the rectangle

public:
    /**
     * @brief Constructs a new rectangle with specified properties
     * @param id Unique identifier for the rectangle
     * @param pen Pen settings for drawing the rectangle's outline
     * @param brush Brush settings for filling the rectangle
     * @param rect QRect defining the position and dimensions
     */
    Rectangle(int id, const QPen& pen, const QBrush& brush, QRect rect)
        : Shape(id, pen, brush), rect(rect)  {}

    /**
     * @brief Renders the rectangle on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(rect);
    }

    /**
     * @brief Moves the rectangle by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override {
        rect.adjust(dx, dy, dx, dy);
    }

    /**
     * @brief Calculates the perimeter of the rectangle
     * @return The sum of all sides (2 * width + 2 * height)
     */
    double perimeter() const override {
        return 2 * (rect.height() + rect.width());
    }

    /**
     * @brief Calculates the area of the rectangle
     * @return The area (width * height)
     */
    double area() const override {
        return rect.height() * rect.width();
    }

    std::string getType() const override {
        return "Rectangle";
    }

    bool isFill() const override {
        return true;
    }

    QRect getRect() const
    {
        return rect;
    }
};

#endif // RECTANGLE_H
