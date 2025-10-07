#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <string>
#include <sstream>
#include "vector.h"
#include <map>
#include <QFile>
#include <QTextStream>
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Ellipse.h"
#include "Text.h"
#include "Square.h"

using namespace std;

/**
 * @class ShapeParser
 * @brief Parses shape definitions from text files and creates corresponding shape objects
 *
 * The ShapeParser class is responsible for reading shape definitions from a file,
 * parsing their properties, and creating the appropriate shape objects. It supports
 * multiple shape types including lines, rectangles, circles, polygons, and text,
 * parsing their various attributes such as position, size, color, and style settings.
 *
 * @author Rishab Senthil Kumar, Cem Yildiz, Reise Young, Anthony Dimitriov 
 * @date November 2024
 */
class ShapeParser {
public:
    /**
     * @brief Loads and parses shapes from a specified file
     * @param filePath Path to the file containing shape definitions
     * @return Vector of pointers to the created Shape objects
     * 
     * The file should contain shape definitions in a specific format:
     * @code
     * ShapeId: 1
     * ShapeType: Rectangle
     * ShapeDimensions: 20, 200, 170, 100
     * PenColor: blue
     * PenWidth: 0
     * PenStyle: DashLine
     * ...
     * @endcode
     *
     * @throws runtime_error If the file cannot be opened or contains invalid data
     * @throws invalid_argument If shape properties are invalid
     */
    custom::vector<Shape*> loadShapesFromFile(const string& filePath);

private:
    /**
     * @brief Parses a single line from the file
     * @param line The line to parse
     * @return Pointer to the created Shape object, or nullptr if parsing failed
     * 
     * @note This function is used internally by loadShapesFromFile
     */
    Shape* parseLine(const string& line);

    /**
     * @brief Creates a shape object based on parsed properties
     * @param shapeType The type of shape to create (e.g., "Rectangle", "Circle")
     * @param properties Map of property names to values
     * @return Pointer to the created Shape object
     * 
     * @throws invalid_argument If the shape type is unknown or properties are invalid
     */
    Shape* createShape(const string& shapeType, const map<string, string>& properties);

    /**
     * @brief Extracts key-value property pairs from shape definition lines
     * @param startLine The first line of the shape definition
     * @param stream Input string stream containing property lines
     * @return Map of property names to their values
     */
    map<string, string> extractProperties(const string& startLine, stringstream& stream);
};

#endif // SHAPEPARSER_H