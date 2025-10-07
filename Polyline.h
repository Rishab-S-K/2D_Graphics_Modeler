#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"
#include "vector.h"
#include <QPoint>
#include <cmath>

/**
 * @class Polyline
 * @brief Represents a sequence of connected line segments
 *
 * The Polyline class manages a sequence of points connected by straight lines.
 * Unlike a polygon, a polyline is not closed and does not have a fill property.
 * It provides functionality for rendering and manipulating multi-segment lines.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Polyline : public Shape {
private:
    custom::vector<QPoint> points; ///< Collection of points defining the line segments

public:
    /**
     * @brief Constructs a new polyline with specified properties
     * @param id Unique identifier for the polyline
     * @param pen Pen settings for drawing the line segments
     * @param brush Brush settings (unused for polylines)
     * @param points Vector of points defining the line segments
     */
    Polyline(int id, const QPen& pen, const QBrush& brush, const custom::vector<QPoint>& points)
        : Shape(id, pen, brush), points(points) {}

    /**
     * @brief Renders the polyline on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override
    {
        QPolygon polyline;
        painter.setPen(pen);

        for(const QPoint& point : points)
        {
            polyline << point;
        }

        painter.drawPolyline(polyline);
    }

    /**
     * @brief Moves the polyline by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override
    {
        for(QPoint& point : points)
        {
            point.setX(point.x()+dx);
            point.setY(point.y()+dy);
        }
    }

    /**
     * @brief Calculates the total length of all line segments
     * @return The sum of all segment lengths
     */
    double perimeter() const override
    {
        double perimValue = 0;

        for(int i = 0; i < points.size() - 1; i++)
        {
            double dx = points[i+1].x() - points[i].x();
            double dy = points[i+1].y() - points[i].y();

            perimValue += sqrt(pow(dx,2) + pow(dy,2));
        }

        return perimValue;
    }

    /**
     * @brief Returns the area of the polyline (always 0)
     * @return 0 as a polyline has no area
     */
    double area() const override
    {
        return 0.0;
    }

    std::string getType() const override {
        return "Polyline";
    }

    bool isFill() const override {
        return false;
    }

    custom::vector<QPoint> getPoints() const
    {
        return points;
    }
};

#endif // POLYLINE_H
