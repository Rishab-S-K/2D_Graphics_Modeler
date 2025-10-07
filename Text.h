#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"
#include <QString>
#include <QColor>

/**
 * @class Text
 * @brief Represents text as a drawable shape in the 2D graphics modeler
 *
 * The Text class provides functionality for rendering text with various font
 * properties. While it inherits from Shape, text has special properties
 * and behaves differently from geometric shapes (e.g., no area or perimeter).
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitrov
 * @date November 2024
 */
class Text : public Shape {
private:
    QRect rect;
    int align;
    QString content;  ///< Text content to be displayed
    QColor color;     ///< Color of the text

public:
    /**
     * @brief Constructs a new text object with specified properties
     * @param id Unique identifier for the text object
     * @param x X-coordinate of the text position
     * @param y Y-coordinate of the text position
     * @param content The actual text to be displayed
     * @param font Font settings (family, size, style, etc.)
     * @param color Color of the text
     */
    Text(int id, QRect rect, int align, const QString& content, const QFont& font, const QColor& color)
        : Shape(id, font), rect(rect), align(align), content(content), color(color) {}

    /**
     * @brief Renders the text on the provided painter
     * @param painter QPainter object used for drawing
     */
    void draw(QPainter& painter) override {
        painter.setFont(font);
        //neccesary to set the color
        painter.setPen(QPen(color));
        painter.drawText(rect, align, content);
    }

    /**
     * @brief Moves the text by the specified offset
     * @param dx Horizontal displacement in pixels
     * @param dy Vertical displacement in pixels
     */
    void move(int dx, int dy) override {
        rect.adjust(dx, dy, dx, dy);
    }

    /**
     * @brief Returns the perimeter of the text (always 0)
     * @return perimeter of enclosing rectangle
     */
    double perimeter() const override {
        return (2*rect.width()+2*rect.height());
    }

    /**
     * @brief Returns the area of the text (always 0)
     * @return area of enclosing rectangle
     */
    double area() const override {
        return rect.width()*rect.height();
    }

    std::string getType() const override {
        return "Text";
    }

    bool isFill() const override {
        return false;
    }

    std::string getAlign() const{
        if(align == Qt::AlignLeft) return "AlignLeft";
        if(align == Qt::AlignRight) return "AlignRight";
        if(align == Qt::AlignHCenter) return "AlignHCenter";
        if(align == Qt::AlignTop) return "AlignTop";
        if(align == Qt::AlignBottom) return "AlignBottom";
        if(align == Qt::AlignVCenter) return "AlignVCenter";
        if(align == Qt::AlignCenter) return "AlignCenter";
        return "INVALID";
    }

    std::string getContent() const{
        return content.toStdString();
    }

    QRect getRect() const
    {
        return rect;
    }

    QColor getColor() const
    {
        return color;
    }



};

#endif // TEXT_H
