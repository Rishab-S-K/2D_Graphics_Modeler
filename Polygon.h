#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include "vector.h"
#include <QPoint>

/**
 * @class Polygon
 * @brief Represents a polygon shape in the 2D graphics modeler
 *
 * The Polygon class manages a sequence of connected points forming a closed shape.
 * It provides functionality for rendering, moving, and calculating geometric properties
 * of polygons with any number of vertices.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Polygon : public Shape {
private:
    custom::vector<QPoint> vertices; ///< Collection of polygon vertices

public:
    /**
     * @brief Constructs a new polygon with specified properties
     * @param id Unique identifier for the polygon
     * @param pen Pen settings for drawing the polygon's outline
     * @param brush Brush settings for filling the polygon
     * @param vertices Vector of points defining the polygon's vertices
     */
    Polygon(int id, const QPen& pen, const QBrush& brush, const custom::vector<QPoint>& vertices)
        : Shape(id, pen, brush), vertices(vertices) {}

    /**
     * @brief Renders the polygon on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override
    {
        painter.setPen(pen);
        painter.setBrush(brush);
        QPolygon polygon;

        //range based loop that sets each point in the polgon
        for(const QPoint& vertice : vertices)
        {
            polygon << vertice;
        }

        painter.drawPolygon(polygon);
    }

    /**
     * @brief Moves the polygon by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override
    {
        //another range based loop, will add dx and dy to the x,y coords
        for(QPoint& vertice : vertices)
        {
            vertice.setX(vertice.x()+dx);
            vertice.setY(vertice.y()+dy);
        }
    }

    /**
     * @brief Calculates the perimeter of the polygon
     * @return The sum of all side lengths
     */
    double perimeter() const override
    {
        double perimValue = 0;
        
        for(int i = 0; i < vertices.size() - 1; i++)
        {
            double dx = vertices[i+1].x() - vertices[i].x();
            double dy = vertices[i+1].y() - vertices[i].y();

            perimValue += sqrt(pow(dx,2) + pow(dy,2));
        }

        if(vertices.size() > 0)
        {
            double dx = vertices[0].x() - vertices[vertices.size()-1].x();
            double dy = vertices[0].y() - vertices[vertices.size()-1].y();
            perimValue += sqrt(pow(dx,2) + pow(dy,2));
        }

        return perimValue;
    }

    /**
     * @brief Calculates the area of the polygon
     * @return The area value using the Shoelace formula
     */
    double area() const override
    {
        int n = vertices.size();
        int x1, x2, y1, y2;
        double area = 0;

        //uses shoelace formula to find area of simple polygons

        //area is initially |x1 x2 x3 ...| (1/2)
        //                  |y1 y2 y3 ...|
        for(int i = 0; i < n; i++)
        {
            //added "wrap-around" behavior so it can be closed
            x1 = vertices[i].x();
            x2 = vertices[(i+1)%n].x();
            y1 = vertices[i].y();
            y2 = vertices[(i+1)%n].y();

            area += (x1*y2) - (x2*y1);
        }

        area = area/2;

        //return the positive area
        if(area < 0)
        {
            return -area;
        }

        return area;
    }

    std::string getType() const override {
        return "Polygon";
    }

    bool isFill() const override {
        return true;
    }

    custom::vector<QPoint> getVertices() const
    {
        return vertices;
    }
};

#endif // POLYGON_H
