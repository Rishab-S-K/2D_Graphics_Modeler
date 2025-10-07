#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "vector.h"
#include "Shape.h"
#include "line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Text.h"
#include "fstream"

/**
 * @brief Converts a QColor to its string representation
 * @param type The QColor to convert
 * @return String representation of the color
 * @throws invalid_argument If the color is not recognized
 */
string getColor(QColor type);

/**
 * @brief Converts a Qt::PenStyle to its string representation
 * @param type The pen style to convert
 * @return String representation of the pen style
 * @throws invalid_argument If the style is not recognized
 */
string getPenStyle(Qt::PenStyle type);

/**
 * @brief Converts a Qt::PenCapStyle to its string representation
 * @param type The pen cap style to convert
 * @return String representation of the cap style
 * @throws invalid_argument If the cap style is not recognized
 */
string getPenCap(Qt::PenCapStyle type);

/**
 * @brief Converts a Qt::PenJoinStyle to its string representation
 * @param type The pen join style to convert
 * @return String representation of the join style
 * @throws invalid_argument If the join style is not recognized
 */
string getPenJoin(Qt::PenJoinStyle type);

/**
 * @brief Converts a Qt::BrushStyle to its string representation
 * @param type The brush style to convert
 * @return String representation of the brush style
 * @throws invalid_argument If the brush style is not recognized
 */
string getBrushStyle(Qt::BrushStyle type);

/**
 * @brief Converts a QFont::Style to its string representation
 * @param type The font style to convert
 * @return String representation of the font style
 * @throws invalid_argument If the font style is not recognized
 */
string getTextStyle(QFont::Style type);

/**
 * @brief Converts a QFont::Weight to its string representation
 * @param type The font weight to convert
 * @return String representation of the font weight
 * @throws invalid_argument If the font weight is not recognized
 */
string getTextWeight(QFont::Weight type);

/**
 * @brief Converts a Qt::Alignment to its string representation
 * @param type The alignment to convert
 * @return String representation of the alignment
 * @throws invalid_argument If the alignment is not recognized
 */
string getAlign(Qt::Alignment type);

/**
 * @brief Stream operator for serializing a vector of shapes
 * @param out Output stream to write to
 * @param shapes Vector of shape pointers to serialize
 * @return Reference to the output stream
 * 
 * Writes all shape properties in a formatted text representation
 * that can be later parsed to reconstruct the shapes.
 */
ostream& operator<<(ostream& out, const custom::vector<Shape*>& shapes);

#endif // SERIALIZER_H
