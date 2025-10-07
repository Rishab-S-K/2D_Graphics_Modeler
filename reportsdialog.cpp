#include "reportsdialog.h"
#include "ui_reports.h"
#include <iomanip>
#include <sstream>

ReportsDialog::ReportsDialog(Canvas* canvas, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::reports)
    , canvas(canvas)
{
    ui->setupUi(this);
    
    initializeById();
    initializeByArea();
    initializeByPerimeter();

    ui->tableById->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableByArea->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableByPerimeter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

ReportsDialog::~ReportsDialog()
{
    delete ui;
}

void ReportsDialog::initializeById()
{
    const custom::vector<Shape*>& shapes = canvas->getShapes();
    ui->tableById->setRowCount(shapes.size());
    
    for(int i = 0; i < shapes.size(); ++i) {
        Shape* shape = shapes[i];
        
        auto idItem = new QTableWidgetItem(QString::number(shape->getId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tableById->setItem(i, 0, idItem);
        
        auto typeItem = new QTableWidgetItem(QString::fromStdString(shape->getType()));
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableById->setItem(i, 1, typeItem);
        
        QString properties;
        if(shape->isFill()) {
            properties += QString("Pen Color: %1, Brush Color: %2")
                .arg(getColorName(shape->getPen().color()))
                .arg(getColorName(shape->getBrush().color()));
        } else {
            properties += QString("Pen Color: %1")
                .arg(getColorName(shape->getPen().color()));
        }
        auto propsItem = new QTableWidgetItem(properties);
        propsItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->tableById->setItem(i, 2, propsItem);
    }
}

void ReportsDialog::initializeByArea()
{
    custom::vector<Shape*> sortedShapes = canvas->getShapesSortedByArea();
    ui->tableByArea->setRowCount(sortedShapes.size());
    
    for(int i = 0; i < sortedShapes.size(); ++i) {
        Shape* shape = sortedShapes[i];
        
        auto idItem = new QTableWidgetItem(QString::number(shape->getId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tableByArea->setItem(i, 0, idItem);
        
        auto typeItem = new QTableWidgetItem(QString::fromStdString(shape->getType()));
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableByArea->setItem(i, 1, typeItem);
        
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << shape->area();
        auto areaItem = new QTableWidgetItem(QString::fromStdString(ss.str()));
        areaItem->setTextAlignment(Qt::AlignCenter);
        ui->tableByArea->setItem(i, 2, areaItem);
    }
}

void ReportsDialog::initializeByPerimeter()
{
    custom::vector<Shape*> shapes = canvas->getShapesSortedByPerimeter();
    ui->tableByPerimeter->setRowCount(shapes.size());
    
    for(int i = 0; i < shapes.size(); ++i) {
        Shape* shape = shapes[i];
        
        auto idItem = new QTableWidgetItem(QString::number(shape->getId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tableByPerimeter->setItem(i, 0, idItem);
        
        auto typeItem = new QTableWidgetItem(QString::fromStdString(shape->getType()));
        typeItem->setTextAlignment(Qt::AlignCenter);
        ui->tableByPerimeter->setItem(i, 1, typeItem);
        
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << shape->perimeter();
        auto perimeterItem = new QTableWidgetItem(QString::fromStdString(ss.str()));
        perimeterItem->setTextAlignment(Qt::AlignCenter);
        ui->tableByPerimeter->setItem(i, 2, perimeterItem);
    }
}

QString ReportsDialog::getColorName(const QColor& color)
{
    if(color == Qt::white) return "White";
    if(color == Qt::black) return "Black";
    if(color == Qt::red) return "Red";
    if(color == Qt::green) return "Green";
    if(color == Qt::blue) return "Blue";
    if(color == Qt::cyan) return "Cyan";
    if(color == Qt::magenta) return "Magenta";
    if(color == Qt::yellow) return "Yellow";
    if(color == Qt::gray) return "Gray";
    return "Unknown";
}
