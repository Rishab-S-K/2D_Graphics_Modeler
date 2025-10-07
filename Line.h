#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include <QColor>
#include <QPoint>

/**
 * @class Line
 * @brief Represents a line segment in the 2D graphics modeler
 *
 * The Line class provides functionality for rendering and manipulating
 * line segments defined by two endpoints. Lines can have various pen
 * styles and colors but no fill properties.
 *
 * @author Rishab Senthil Kumar, Omar Farag, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Line : public Shape {
private:
    QPoint start, end; ///< Start and end points of the line

public:
    /**
     * @brief Constructs a new line with specified properties
     * @param id Unique identifier for the line
     * @param pen Pen settings for drawing the line
     * @param brush Brush settings (unused for lines)
     * @param start Starting point of the line
     * @param end Ending point of the line
     */
    Line(int id, const QPen& pen, const QBrush& brush, QPoint start, QPoint end)
        : Shape(id, pen, brush), start(start), end(end){}

    /**
     * @brief Renders the line on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.drawLine(start, end);
    }

    /**
     * @brief Moves the line by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override {
        start += QPoint(dx, dy);
        end += QPoint(dx, dy);
    }

    /**
     * @brief Calculates the length of the line
     * @return The length of the line segment
     */
    double perimeter() const override {
        return QLineF(start, end).length();
    }

    /**
     * @brief Returns the area of the line (always 0)
     * @return 0 as a line has no area
     */
    double area() const override {
        return 0.0;
    }

    std::string getType() const override {
        return "Line";
    }

    bool isFill() const override {
        return false;
    }

    QPoint getStart() const
    {
        return start;
    }

    QPoint getEnd() const
    {
        return end;
    }
};

#endif // LINE_H
