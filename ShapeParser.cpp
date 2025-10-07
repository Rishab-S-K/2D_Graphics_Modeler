#include "ShapeParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "Text.h"

using namespace std;

/**
 * @brief Converts a string color name to Qt color enum
 * @param color The color name as a string
 * @return The corresponding Qt::GlobalColor value
 * @throws invalid_argument If the color name is not recognized
 */
Qt::GlobalColor getColorFromString(const string& color) {
    if (color == "white") return Qt::white;
    if (color == "black") return Qt::black;
    if (color == "red") return Qt::red;
    if (color == "green") return Qt::green;
    if (color == "blue") return Qt::blue;
    if (color == "cyan") return Qt::cyan;
    if (color == "magenta") return Qt::magenta;
    if (color == "yellow") return Qt::yellow;
    if (color == "gray") return Qt::gray;
    throw invalid_argument("Invalid color: " + color);
}

/**
 * @brief Converts a string pen style name to Qt pen style enum
 * @param style The pen style name as a string
 * @return The corresponding Qt::PenStyle value
 * @throws invalid_argument If the pen style is not recognized
 */
Qt::PenStyle getPenStyleFromString(const string& style) {
    if (style == "NoPen") return Qt::NoPen;
    if (style == "SolidLine") return Qt::SolidLine;
    if (style == "DashLine") return Qt::DashLine;
    if (style == "DotLine") return Qt::DotLine;
    if (style == "DashDotLine") return Qt::DashDotLine;
    if (style == "DashDotDotLine") return Qt::DashDotDotLine;
    throw invalid_argument("Invalid pen style: " + style);
}

/**
 * @brief Converts a string cap style name to Qt pen cap style enum
 * @param cap The cap style name as a string
 * @return The corresponding Qt::PenCapStyle value
 * @throws invalid_argument If the cap style is not recognized
 */
Qt::PenCapStyle getPenCapFromString(const string& cap) {
    if(cap == "SquareCap") return Qt::SquareCap;
    if(cap == "FlatCap") return Qt::FlatCap;
    if(cap == "RoundCap") return Qt::RoundCap;
    throw invalid_argument("Invalid cap style: "+ cap);
}

/**
 * @brief Converts a string join style name to Qt pen join style enum
 * @param join The join style name as a string
 * @return The corresponding Qt::PenJoinStyle value
 * @throws invalid_argument If the join style is not recognized
 */
Qt::PenJoinStyle getPenJoinFromString(const string& join) {
    if(join == "BevelJoin") return Qt::BevelJoin;
    if(join == "MiterJoin") return Qt::MiterJoin;
    if(join == "RoundJoin") return Qt::RoundJoin;
    throw invalid_argument("Invalid join style: "+ join);
}

/**
 * @brief Converts a string brush style name to Qt brush style enum
 * @param style The brush style name as a string
 * @return The corresponding Qt::BrushStyle value
 * @throws invalid_argument If the brush style is not recognized
 */
Qt::BrushStyle getBrushStyleFromString(const string& style) {
    if (style == "NoBrush") return Qt::NoBrush;
    if (style == "SolidPattern") return Qt::SolidPattern;
    if (style == "HorPattern") return Qt::HorPattern;
    if (style == "VerPattern") return Qt::VerPattern;
    throw invalid_argument("Invalid brush style: " + style);
}

/**
 * @brief Converts a string font style name to Qt font style enum
 * @param style The font style name as a string
 * @return The corresponding QFont::Style value
 * @throws invalid_argument If the font style is not recognized
 */
QFont::Style getTextStyleFromString(const string& style) {
    if(style == "StyleNormal") return QFont::StyleNormal;
    if(style == "StyleItalic") return QFont::StyleItalic;
    if(style == "StyleOblique") return QFont::StyleOblique;
    throw invalid_argument("Invalid text style: "+ style);
}

/**
 * @brief Converts a string font weight name to Qt font weight enum
 * @param weight The font weight name as a string
 * @return The corresponding QFont::Weight value
 * @throws invalid_argument If the font weight is not recognized
 */
QFont::Weight getTextWeightFromString(const string& weight) {
    if(weight == "Thin") return QFont::Thin;
    if(weight == "ExtraLight") return QFont::ExtraLight;
    if(weight == "Light") return QFont::Light;
    if(weight == "Normal") return QFont::Normal;
    if(weight == "Medium") return QFont::Medium;
    if(weight == "DemiBold") return QFont::DemiBold;
    if(weight == "Bold") return QFont::Bold;
    if(weight == "ExtraBold") return QFont::ExtraBold;
    if(weight == "Black") return QFont::Black;
    throw invalid_argument("Invalid text weight: "+ weight);
}

Qt::Alignment getAlignFromString(const string& align) {
    if(align == "AlignLeft") return Qt::AlignLeft;
    if(align == "AlignRight") return Qt::AlignRight;
    if(align == "AlignHCenter") return Qt::AlignHCenter;
    if(align == "AlignJustify") return Qt::AlignJustify;
    if(align == "AlignTop") return Qt::AlignTop;
    if(align == "AlignBottom") return Qt::AlignBottom;
    if(align == "AlignVCenter") return Qt::AlignVCenter;
    if(align == "AlignCenter") return Qt::AlignCenter;
    throw invalid_argument("Invalid text allign: "+ align);
}

/**
 * @brief Parses a string of comma-separated integers into a vector
 * @param dims The string containing comma-separated integers
 * @return Vector of parsed integer values
 */
custom::vector<int> parseDimensions(const string& dims) {
    custom::vector<int> result;
    stringstream ss(dims);
    string value;
    while (getline(ss, value, ',')) {
        result.push_back(stoi(value));
    }
    return result;
}

custom::vector<Shape*> ShapeParser::loadShapesFromFile(const string& filePath) {
    custom::vector<Shape*> shapes;
    
    QString resourcePath = QString(":/txt/") + QString::fromStdString(filePath);
    QFile file(resourcePath);
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cerr << "Error: Could not open file " << resourcePath.toStdString() << endl;
        return shapes;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains("ShapeId:")) {
            stringstream ss;
            ss << line.toStdString() << endl;
            
            QString nextLine;
            while (!in.atEnd()) {
                nextLine = in.readLine();
                if (nextLine.isEmpty() || nextLine.contains("ShapeId:")) {
                    break;
                }
                ss << nextLine.toStdString() << endl;
            }

            map<string, string> properties = extractProperties(line.toStdString(), ss);
            try {
                string shapeType = properties.at("ShapeType");
                Shape* shape = createShape(shapeType, properties);
                if (shape) {
                    shapes.push_back(shape);
                }
            } catch (const exception& e) {
                cerr << "Error parsing shape: " << e.what() << endl;
            }

            if (nextLine.contains("ShapeId:")) {
                line = nextLine;
            }
        }
    }

    file.close();
    return shapes;
}

map<string, string> ShapeParser::extractProperties(const string& startLine, stringstream& stream) {
    map<string, string> properties;
    string line = startLine;

    do {
        size_t delimiter = line.find(":");
        if (delimiter != string::npos) {
            string key = line.substr(0, delimiter);
            string value = line.substr(delimiter + 1);
            // Trim whitespace
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            properties[key] = value;
        }
    } while (getline(stream, line) && !line.empty());

    return properties;
}

Shape* ShapeParser::createShape(const string& shapeType, const map<string, string>& properties) {
    try {
        int id = stoi(properties.at("ShapeId"));
        QPen pen;
        QBrush brush;
        QFont font;

        //if it was text, it would not have a pen or brush, which could crash the program
        if (shapeType != "Text") {
            pen.setColor(getColorFromString(properties.at("PenColor")));
            pen.setWidth(stoi(properties.at("PenWidth")));
            pen.setStyle(getPenStyleFromString(properties.at("PenStyle")));
            pen.setCapStyle(getPenCapFromString(properties.at("PenCapStyle")));
            pen.setJoinStyle(getPenJoinFromString(properties.at("PenJoinStyle")));

            if (properties.count("BrushColor") && properties.count("BrushStyle")) {
                brush.setColor(getColorFromString(properties.at("BrushColor")));
                brush.setStyle(getBrushStyleFromString(properties.at("BrushStyle")));
            }
        }

        custom::vector<int> dims = parseDimensions(properties.at("ShapeDimensions"));
        
        if (shapeType == "Line") {
            return new Line(id, pen, brush, QPoint(dims[0], dims[1]), QPoint(dims[2], dims[3]));
        } else if (shapeType == "Rectangle") {
            return new Rectangle(id, pen, brush, QRect(dims[0], dims[1], dims[2], dims[3]));
        } else if (shapeType == "Circle") {
            return new Circle(id, pen, brush, QPoint(dims[0], dims[1]), dims[2]);
        } else if (shapeType == "Ellipse") {
            return new Ellipse(id, pen, brush, QRect(dims[0], dims[1], dims[2], dims[3]));
        } else if (shapeType == "Polyline" || shapeType == "Polygon") {
            custom::vector<QPoint> points;
            for (size_t i = 0; i < dims.size(); i += 2) {
                //changed from emplace to push_back
                QPoint pair(dims[i], dims[i + 1]);
                points.push_back(pair);
            }
            return (shapeType == "Polyline") ?
                static_cast<Shape*>(new Polyline(id, pen, brush, points)) :
                static_cast<Shape*>(new Polygon(id, pen, brush, points));
        } else if (shapeType == "Square") {
            return new Square(id, pen, brush, dims[0], dims[1], dims[2]);
        } else if (shapeType == "Text") {
            QString content = QString::fromStdString(properties.at("TextString"));
            font.setPointSize(stoi(properties.at("TextPointSize")));
            font.setFamily(QString::fromStdString(properties.at("TextFontFamily")));
            font.setStyle(getTextStyleFromString(properties.at("TextFontStyle")));
            font.setWeight(getTextWeightFromString(properties.at("TextFontWeight")));
            QColor color = getColorFromString(properties.at("TextColor"));
            return new Text(id, QRect(dims[0], dims[1], dims[2], dims[3]), getAlignFromString(properties.at("TextAlignment")),content, font, color);
        }
    } catch (const exception& e) {
        cerr << "Error creating shape: " << e.what() << endl;
    }

    cerr << "Unknown shape type: " << shapeType << endl;
    return nullptr;
}
