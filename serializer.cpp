#include "serializer.h"

string getColor(QColor type) {
    if (type == Qt::white) return "white";
    if (type == Qt::black) return "black";
    if (type == Qt::red) return "red";
    if (type == Qt::green) return "green";
    if (type == Qt::blue) return "blue";
    if (type == Qt::cyan) return "cyan";
    if (type == Qt::magenta) return "magenta";
    if (type == Qt::yellow) return "yellow";
    if (type == Qt::gray) return "gray";
    return "INVALID";
}


string getPenStyle(Qt::PenStyle type) {
    if (type == Qt::NoPen) return "NoPen";
    if (type == Qt::SolidLine) return "SolidLine";
    if (type == Qt::DashLine) return "DashLine";
    if (type == Qt::DotLine) return "DotLine";
    if (type == Qt::DashDotLine) return "DashDotLine";
    if (type == Qt::DashDotDotLine) return "DashDotDotLine";
    return "INVALID";
}



string getPenCap(Qt::PenCapStyle type) {
    if(type == Qt::SquareCap) return "SquareCap";
    if(type == Qt::FlatCap) return "FlatCap";
    if(type == Qt::RoundCap) return "RoundCap";
    return "INVALID";
}


string getPenJoin(Qt::PenJoinStyle type) {
    if(type == Qt::BevelJoin) return "BevelJoin";
    if(type == Qt::MiterJoin) return "MiterJoin";
    if(type == Qt::RoundJoin) return "RoundJoin";
    return "INVALID";
}

string getBrushStyle(Qt::BrushStyle type) {
    if (type == Qt::NoBrush) return "NoBrush";
    if (type == Qt::SolidPattern) return "SolidPattern";
    if (type == Qt::HorPattern) return "HorPattern";
    if (type == Qt::VerPattern) return "VerPattern";
    return "INVALID";
}

string getTextStyle(QFont::Style type) {
    if(type == QFont::StyleNormal) return "StyleNormal";
    if(type == QFont::StyleItalic) return "StyleItalic";
    if(type == QFont::StyleOblique) return "StyleOblique";
    return "INVALID";
}

string  getTextWeight(QFont::Weight type) {
    if(type == QFont::Thin) return "Thin";
    if(type == QFont::ExtraLight) return "ExtraLight";
    if(type == QFont::Light) return "Light";
    if(type == QFont::Normal) return "Normal";
    if(type == QFont::Medium) return "Medium";
    if(type == QFont::DemiBold) return "DemiBold";
    if(type == QFont::Bold) return "Bold";
    if(type == QFont::ExtraBold) return "ExtraBold";
    if(type == QFont::Black) return "Black";
    return "INVALID";
}

string getAlign(Qt::Alignment type) {
    if(type == Qt::AlignLeft) return "AlignLeft";
    if(type == Qt::AlignRight) return "AlignRight";
    if(type == Qt::AlignHCenter) return "AlignHCenter";
    if(type == Qt::AlignJustify) return "AlignJustify";
    if(type == Qt::AlignTop) return "AlignTop";
    if(type == Qt::AlignBottom) return "AlignBottom";
    if(type == Qt::AlignVCenter) return "AlignVCenter";
    if(type == Qt::AlignCenter) return "AlignCenter";
    return "INVALID";
}

ostream& operator<<(ostream& out, const custom::vector<Shape*>& shapes)
{

    for(Shape * shape : shapes) {
        out << "ShapeId: " << shape->getId() << '\n';
        out << "ShapeType: " << shape->getType() << '\n';
        out << "ShapeDimensions: ";


#define TRY_CAST(type) type* cast = dynamic_cast<type*>(shape)

        //insert dimension code
        if(TRY_CAST(Line))
        {
            QPoint A = cast->getStart();
            QPoint B = cast->getEnd();

            out << A.x() << ", " << A.y() << ", " << B.x() << ", " << B.y() << '\n';
        }

        else if(TRY_CAST(Polyline))
        {
            QPoint A;
            bool first = true;
            custom::vector<QPoint> points = cast->getPoints();
            for(QPoint point : points)
            {
                if(!first)
                    out << ", ";
                first = false;
                A = point;
                out << A.x() << ", " << A.y();
            }

            out << '\n';
        }

        else if(TRY_CAST(Polygon))
        {
            QPoint A;
            bool first = true;
            custom::vector<QPoint> points = cast->getVertices();
            for(QPoint point : points)
            {
                if(!first)
                    out << ", ";
                first = false;
                A = point;
                out << A.x() << ", " << A.y();
            }

            out << '\n';
        }

        else if(TRY_CAST(Rectangle))
        {
            QRect rect = cast->getRect();

            out << rect.topLeft().x() << ", " << rect.topLeft().y() << ", " << rect.width() << ", " << rect.height() << '\n';
        }

        else if(TRY_CAST(Square))
        {
            QPointF topLeft= cast->getTopLeft();

            out << topLeft.x() << ", " << topLeft.y() << ", " << cast->getSide() << '\n';
        }

        else if(TRY_CAST(Ellipse))
        {
            QRect rect = cast->getRect();

            out << rect.topLeft().x() << ", " << rect.topLeft().y() << ", ";
            if(rect.width() > rect.height())
                out << rect.width() << ", " << rect.height() << '\n';
            else
                out << rect.height() << ", " << rect.width() << '\n';
        }

        else if(TRY_CAST(Circle))
        {
            QPoint A = cast->getCenter();

            out << A.x() << ", " << A.y() << ", " << cast->getRadius() << '\n';
        }

        else if(TRY_CAST(Text))
        {
            QRect rect = cast->getRect();

            out << rect.topLeft().x() << ", " << rect.topLeft().y() << ", " << rect.width() << ", " << rect.height() << '\n';
        }

        if(shape->getType() != "Text")
        {
            out << "PenColor: " << getColor(shape->getPen().color()) << '\n';
            out << "PenWidth: " << to_string((shape->getPen().width())) << '\n';
            out << "PenStyle: " << getPenStyle(shape->getPen().style()) << '\n';;
            out << "PenCapStyle: " << getPenCap(shape->getPen().capStyle()) << '\n';
            out << "PenJoinStyle: " << getPenJoin(shape->getPen().joinStyle()) << '\n';
        }

        if(shape->isFill())
        {
            out << "BrushColor: " << getColor(shape->getBrush().color()) << '\n';
            out << "BrushStyle: " << getBrushStyle(shape->getBrush().style()) << '\n';
        }

        if(TRY_CAST(Text))
        {
            out << "TextString: " << cast->getContent() << '\n';
            out << "TextColor: " << getColor(cast->getColor()) << '\n';
            out << "TextAlignment: " << cast->getAlign() << '\n';
            out << "TextPointSize: " << to_string(cast->getFont().pointSize()) << '\n';
            out << "TextFontFamily: " << cast->getFont().family().toStdString() << '\n';
            out << "TextFontStyle: " << getTextStyle(cast->getFont().style()) << '\n';
            out << "TextFontWeight: " << getTextWeight(cast->getFont().weight()) << '\n';
        }

        out << "\n";
    }

#undef TRY_CAST
    return out;
}
