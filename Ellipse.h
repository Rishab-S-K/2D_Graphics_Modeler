#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <QColor>

/**
 * @class Ellipse
 * @brief Represents an elliptical shape in the 2D graphics modeler
 *
 * The Ellipse class provides functionality for rendering and manipulating
 * elliptical shapes, defined by their bounding rectangle and drawing properties.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Ellipse : public Shape {
private:
    QRect boundingRect; ///< Major and minor axes of the ellipse

public:
    /**
     * @brief Constructs a new ellipse with specified properties
     * @param id Unique identifier for the ellipse
     * @param pen Pen settings for drawing the ellipse's outline
     * @param brush Brush settings for filling the ellipse
     * @param boundingRect Rectangle that defines the ellipse's bounds
     */
    Ellipse(int id, const QPen& pen, const QBrush& brush, QRect boundingRect)
        : Shape(id, pen, brush), boundingRect(boundingRect) {}

    /**
     * @brief Renders the ellipse on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse(boundingRect);
    }

    /**
     * @brief Moves the ellipse by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override {
        boundingRect.moveTo(boundingRect.x() +dx, boundingRect.y() +dy);
    }

    /**
     * @brief Calculates the perimeter of the ellipse
     * @return The perimeter value using Ramanujan's approximation formula
     */
    double perimeter() const override {
        double majorAxis = boundingRect.height();
        double minorAxis = boundingRect.width();

        if(boundingRect.width() > boundingRect.height())
        {
            majorAxis = boundingRect.width();
            minorAxis = boundingRect.height();
        }

        double h = qPow((majorAxis - minorAxis), 2) / qPow((majorAxis + minorAxis), 2);
        return M_PI * (majorAxis + minorAxis) * (1 + (3 * h) / (10 + qSqrt(4 - 3 * h)));
    }

    /**
     * @brief Calculates the area of the ellipse
     * @return The area value
     */
    double area() const override {
        double majorAxis = boundingRect.height();
        double minorAxis = boundingRect.width();

        if(boundingRect.width() > boundingRect.height())
        {
            majorAxis = boundingRect.width();
            minorAxis = boundingRect.height();
        }

        return M_PI * majorAxis * minorAxis;
    }

    std::string getType() const override {
        return "Ellipse";
    }

    bool isFill() const override {
        return true;
    }

    QRect getRect() const
    {
        return boundingRect;
    }

};

#endif // ELLIPSE_H
