#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include "reportsdialog.h"
#include <iostream>
#include "login.h"
#include <QMessageBox>
#include <QFontDatabase>

/**
 * @brief Constructs and initializes the main window
 * @param parent Optional parent widget
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::on_spinBox_change);

    // god this is so hacky but I swear I can't get QT to render the button widget when I add it from the designer view so please bare with me
    // if you need to make any changes to this at any point just re-create it in the actual QT designer instead of dealing with this if you want
    QPushButton* reportBtn = new QPushButton("Reports", this);
    reportBtn->setObjectName("reportButton");
    reportBtn->setStyleSheet("background-color: #005500; color: white;");
    if(auto layout = ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_3")) {
        int contactButtonIndex = -1;
        for(int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            if(widget && widget->objectName() == "contactUsButton") {
                contactButtonIndex = i;
                break;
            }
        }
        
        if(contactButtonIndex != -1) {
            layout->insertWidget(contactButtonIndex, reportBtn);
        } else {
            // Fallback: just add to layout if we can't find contact button for whatever reason
            layout->addWidget(reportBtn);
        }
        
        connect(reportBtn, &QPushButton::clicked, this, &MainWindow::on_reportButton_clicked);
    }

    testimonialsManager = new TestimonialsManager(this);

    // Initially disable all shape controls until login
    setControlsEnabled(false);

    canvas = ui->canvasWidget;
    //if the canvas != null
    if (canvas) {
        parsed = parser.loadShapesFromFile("shapes.txt");

        // Store a vector of shapes and update the canvas
        for (Shape* shape : parsed) {
            canvas->storeShape(shape);
        }
    }

    //populate font family combo bos
    ui->comboBox_44->addItems(QFontDatabase::families());

    //populate pointsize combo box
    QStringList pnts;
    for(int i = 0; i<100; ++i)
    {
        pnts << QString::number(i);
    }
    ui->comboBox_43->addItems(pnts);

    ui->spinBox->setReadOnly(true);
    emit ui->spinBox->valueChanged(true);
}

/**
 * @brief Destructor
 * 
 * Releases UI resources and any remaining shapes
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Handler for generic button clicks
 * 
 * Currently empty, reserved for future functionality
 */

void MainWindow::on_spinBox_change()
{

    if (pointsLayout)
    {
        qDebug() << "pointsLayout item count: " << pointsLayout->count();


        for (int i = pointsLayout->count() - 1; i >= 0; --i) {
            // Get the item at index i
            QLayoutItem* extItem = pointsLayout->itemAt(i);
            QLayout* layout = extItem->layout();
            qDebug() << "Processing pointsLayout item at index: " << i;

            qDebug() << "Layout item count at index " << i << ": " << layout->count();
            for(int j = layout->count() - 1 ; j >= 0; j--)
            {
                qDebug() << "Processing widget at index " << j << " in layout " << i;
                QLayoutItem* intItem = layout->itemAt(j);
                QWidget* line= intItem->widget();
                layout->removeWidget(line);
                line->deleteLater(); // Delete widget

                qDebug() << "Widget deleted: " << line;


            }

            pointsLayout->removeItem(layout);
            layout->deleteLater();

        }

        ui->verticalLayout_20->removeItem(pointsLayout);
        pointsLayout->deleteLater();
        pointsLayout = nullptr;


    }

    pointsLayout = new QVBoxLayout();
    ui->verticalLayout_20->addLayout(pointsLayout);

    for(int i = 0; i < ui->spinBox->value(); i++)
    {
        QHBoxLayout* hRow = new QHBoxLayout();
        QLineEdit* xIn = new QLineEdit();
        QLineEdit* yIn = new QLineEdit();

        hRow->addWidget(xIn);
        hRow->addWidget(yIn);
        pointsLayout->addLayout(hRow);
    }

}

void MainWindow::showWidgets(bool pen, bool brush, bool text, bool l, bool w, bool radius, bool semiMajor, bool semiMinor)
{
#define CHECK_HIDE(widget, showIfTrue)  \
    if (showIfTrue) {           \
            widget->show();     \
    } else {                    \
            widget->hide();     \
    }


    CHECK_HIDE(ui->label_2, pen);
    CHECK_HIDE(ui->label_3, brush);
    CHECK_HIDE(ui->label_4, text);

    CHECK_HIDE(ui->capDropDown, pen);
    CHECK_HIDE(ui->colorDropDown, pen);
    CHECK_HIDE(ui->joinStyleDropDown, pen);
    CHECK_HIDE(ui->styleDropDown, pen);
    CHECK_HIDE(ui->widthDropDown, pen);


    CHECK_HIDE(ui->brushColorDrop, brush);
    CHECK_HIDE(ui->brushStyleDrop, brush);

    CHECK_HIDE(ui->textEdit, text);
    CHECK_HIDE(ui->comboBox_2, text);
    CHECK_HIDE(ui->comboBox_41, text);
    CHECK_HIDE(ui->comboBox_42, text);
    CHECK_HIDE(ui->comboBox_43, text);
    CHECK_HIDE(ui->comboBox_44, text);
    CHECK_HIDE(ui->comboBox_45, text);


    CHECK_HIDE(ui->lengthLineEdit, l);
    CHECK_HIDE(ui->widthLineEdit, w);
    CHECK_HIDE(ui->radiusLineEdit, radius);
    CHECK_HIDE(ui->semimajorLineEdit, semiMajor);
    CHECK_HIDE(ui->semiminorLineEdit, semiMinor);

    CHECK_HIDE(ui->label_9, l);
    CHECK_HIDE(ui->label_8, w);
    CHECK_HIDE(ui->label_7, radius);
    CHECK_HIDE(ui->label_6, semiMajor);
    CHECK_HIDE(ui->label_5, semiMinor);

#undef CHECK_HIDE
}

custom::vector<QPoint> MainWindow::getPoints(bool &ok)
{
    custom::vector<QPoint> points;
    QPoint point;

    for (int i = pointsLayout->count() - 1; i >= 0; --i) {
        // Get the item at index i
        QLayoutItem* extItem = pointsLayout->itemAt(i);
        QLayout* layout = extItem->layout();



        QLayoutItem* intItem = layout->itemAt(0);
        QLineEdit* line = qobject_cast<QLineEdit*>(intItem->widget());

        point.setX(line->text().toInt(&ok));

        intItem = layout->itemAt(1);
        line = qobject_cast<QLineEdit*>(intItem->widget());

        point.setY(line->text().toInt(&ok));

        points.push_back(point);

    }

    return points;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_toggleText_clicked() {

    if(ui->toggleText->isChecked())
    {
        showWidgets(0,0,1,1,1,0,0,0);

        ui->spinBox->setValue(1);
        ui->spinBox->setReadOnly(true);
    }
}

void MainWindow::on_toggleEllipse_clicked() {

    if(ui->toggleEllipse->isChecked())
    {
        showWidgets(1,1,0,0,0,0,1,1);

        ui->spinBox->setValue(1);
        ui->spinBox->setReadOnly(true);

    }
}

void MainWindow::on_toggleCircle_clicked() {

    if(ui->toggleCircle->isChecked())
    {
        showWidgets(1,1,0,0,0,1,0,0);

        ui->spinBox->setValue(1);
        ui->spinBox->setReadOnly(true);

    }
}

void MainWindow::on_toggleRectangle_clicked() {

    if(ui->toggleRectangle->isChecked())
    {
        showWidgets(1,1,0,1,1,0,0,0);

        //topleft
        ui->spinBox->setValue(1);
        ui->spinBox->setReadOnly(true);

    }
}

void MainWindow::on_toggleSquare_clicked() {

    if(ui->toggleSquare->isChecked())
    {
        showWidgets(1,1,0,1,0,0,0,0);


        //topleft
        ui->spinBox->setValue(1);
        ui->spinBox->setReadOnly(true);


    }
}

void MainWindow::on_togglePolygon_clicked() {

    if (ui->togglePolygon->isChecked())
    {
        showWidgets(1,1,0,0,0,0,0,0);

        ui->spinBox->setReadOnly(false);


    }
}

void MainWindow::on_togglePolyline_clicked() {

    if (ui->togglePolyline->isChecked())
    {
        showWidgets(1,0,0,0,0,0,0,0);

        ui->spinBox->setReadOnly(false);


    }
}

void MainWindow::on_toggleLine_clicked() {
    if (ui->toggleLine->isChecked())
    {
        showWidgets(1,0,0,0,0,0,0,0);

        //a line requires only 2 points
        ui->spinBox->setValue(2);
        ui->spinBox->setReadOnly(true);


    }
}


/**
 * @brief Handles the "Add" button click to create new shapes
 * 
 * This method:
 * 1. Collects shape properties from the UI (pen, brush, dimensions)
 * 2. Validates the input parameters
 * 3. Creates the appropriate shape based on user selection
 * 4. Adds the new shape to the canvas
 * 
 * Provides error messages if any parameters are invalid.
 */
void MainWindow::on_addPushButton_clicked()
{
    if (!isLoggedIn) {
        QMessageBox::warning(this, "Access Denied", "Please log in to add shapes.");
        return;
    }

    int id = canvas->getCurrentId(); // Use canvas's shape count as the unique ID
    QPen pen;
    QBrush brush;

    // Configure Pen
    pen.setColor(QColor(ui->colorDropDown->currentText()));
    pen.setWidth(ui->widthDropDown->currentText().toInt());
    QString penStyle = ui->styleDropDown->currentText();
    // get from ui the type of line
    if (penStyle == "Solid Line")
        pen.setStyle(Qt::SolidLine);
    else if (penStyle == "Dash Line")
        pen.setStyle(Qt::DashLine);
    else if (penStyle == "Dash Dot Line")
        pen.setStyle(Qt::DashDotLine);
    else if (penStyle == "Dash Dot Dot Line")
        pen.setStyle(Qt::DashDotDotLine);

    // cap style from ui
    QString capStyle = ui->capDropDown->currentText();
    if (capStyle == "Flat Cap")
        pen.setCapStyle(Qt::FlatCap);
    else if (capStyle == "Square Cap")
        pen.setCapStyle(Qt::SquareCap);
    else if (capStyle == "Round Cap")
        pen.setCapStyle(Qt::RoundCap);

    // join style from the ui selection
    QString joinStyle = ui->joinStyleDropDown->currentText();
    if (joinStyle == "Bevel Join")
        pen.setJoinStyle(Qt::BevelJoin);
    else if (joinStyle == "Miter Join")
        pen.setJoinStyle(Qt::MiterJoin);
    else if (joinStyle == "Round Join")
        pen.setJoinStyle(Qt::RoundJoin);

    // Configure Brush
    brush.setColor(QColor(ui->brushColorDrop->currentText())); // Brush color
    QString brushStyle = ui->brushStyleDrop->currentText();
    if (brushStyle == "Solid Pattern")
        brush.setStyle(Qt::SolidPattern);
    else if (brushStyle == "Hor Pattern")
        brush.setStyle(Qt::HorPattern);
    else if (brushStyle == "Ver Pattern")
        brush.setStyle(Qt::VerPattern);
    else if (brushStyle == "No Brush")
        brush.setStyle(Qt::NoBrush);

    bool ok;

    // Shape Handling
    Shape* newShape = nullptr;

    // Circle Toggle
    if (ui->toggleCircle->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);
        int x = points[0].x();
        int y = points[0].y();

        // checks to make sure radius isnt 0 (crazy)
        int radius = ui->radiusLineEdit->text().toInt(&ok);
        if (!ok || radius <= 0)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter a positive integer for the radius.");
            return;
        }
        QPoint center(x,y);
        newShape = new Circle(id, pen, brush, center, radius);
    }
    // Ellipse Toggle
    else if (ui->toggleEllipse->isChecked())
    {
        // input most of the integers for the ellipse
        custom::vector<QPoint> points = getPoints(ok);
        int x = points[0].x();
        int y = points[0].y();

        int semiMajor = ui->semimajorLineEdit->text().toInt(&ok);
        int semiMinor = ui->semiminorLineEdit->text().toInt(&ok);
        if (!ok || semiMajor <= 0 || semiMinor <= 0)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter positive integers for the ellipse dimensions.");
            return;
        }
        QRect boundingRect(x, y, semiMajor * 2, semiMinor * 2);
        newShape = new Ellipse(id, pen, brush, boundingRect);
    }
    // Line toggle
    else if (ui->toggleLine->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);

        QPoint start = points[0];
        QPoint end = points[1];

        if (!ok || start.x() < 0 || start.y() < 0 || end.x() < 0 || end.y() < 0)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter valid positive integers for the line endpoints.");
            return;
        }
        newShape = new Line(id, pen, brush, start, end);
    }
    else if (ui->togglePolyline->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);

        if (!ok)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter valid integers for the polyline endpoints.");
            return;
        }
        newShape = new Polyline(id, pen, brush, points);
    }
    else if (ui->togglePolygon->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);


        if (!ok)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter valid integers for the polygon endpoints.");
           return;
        }
        newShape = new Polygon(id, pen, brush, points);
    }
    else if (ui->toggleRectangle->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);
        int x = points[0].x();
        int y = points[0].y();

        int length = ui->lengthLineEdit->text().toInt(&ok);
        int width = ui->widthLineEdit->text().toInt(&ok);
        if (!ok || length <= 0 || width <= 0)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter positive integers for the rectangle dimensions.");
            return;
        }
        QRect rect(x, y, length, width);
        newShape = new Rectangle(id, pen, brush, rect);
    }
    else if (ui->toggleSquare->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);
        int x = points[0].x();
        int y = points[0].y();

        float side = ui->lengthLineEdit->text().toFloat(&ok);
        if (!ok || side <= 0)
        {
            QMessageBox::warning(this, "Invalid Input", "Please enter a positive number for the square side length.");
            return;
        }
        newShape = new Square(id, pen, brush, x, y, side);
    }
    else if (ui->toggleText->isChecked())
    {
        custom::vector<QPoint> points = getPoints(ok);
        int x = points[0].x();
        int y = points[0].y();

        float length = ui->lengthLineEdit->text().toInt(&ok);
        float width = ui->widthLineEdit->text().toInt(&ok);
        //this is probably wrong, i was just trying to follow the format
        int align;
        if(ui->comboBox_42->currentText() == "AlignLeft") align = Qt::AlignLeft;
        if(ui->comboBox_42->currentText() == "AlignRight") align = Qt::AlignRight;
        if(ui->comboBox_42->currentText() == "AlignHCenter") align = Qt::AlignHCenter;
        if(ui->comboBox_42->currentText() == "AlignTop") align = Qt::AlignTop;
        if(ui->comboBox_42->currentText() == "AlignBottom") align = Qt::AlignBottom;
        if(ui->comboBox_42->currentText() == "AlignVCenter") align = Qt::AlignVCenter;
        if(ui->comboBox_42->currentText() == "AlignCenter") align = Qt::AlignCenter;
        QString content = ui->textEdit->toPlainText();
        QFont font;
        font.setFamily(ui->comboBox_44->currentText());
        font.setPointSize(ui->comboBox_43->currentText().toInt(&ok));
        QColor color(QColor(ui->comboBox_41->currentText()));
        newShape = new Text(id, QRect(x, y, width, length), align, content, font, color);
    }
    else
    {
        QMessageBox::warning(this, "No Shape Selected", "Please select a shape to add.");
        return;
    }

    // Add the new shape to the canvas
    if (newShape)
    {
        canvas->storeShape(newShape);
    }

    canvas->update(); // Redraw the canvas
}


/**
 * @brief MainWindow::on_pushButton_toggled
 * @param checks that the movement toggle button is enabled
 *
 */
void MainWindow::on_pushButton_toggled(bool checked)
{
    movementEnabled = checked;
}


/**
 * @brief MainWindow::keyPressEvent
 * @param event
 *
 * event listener that activates when user toggles shape movement button and moves
 * a specified shape with an ID with W A S D keys for Left, Right, Down, Up movement respectivly.
 */

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!isLoggedIn) {
        QMessageBox::warning(this, "Access Denied", "Please log in to modify shapes.");
        return;
    }

    if (!movementEnabled)
    {
        // If movement is not enabled, skip key handling
        qDebug() << "Movement is disabled. Toggle the button to enable.";
        return;
    }
    // list to find the vector whose id is inputted
    custom::vector<Shape*> shapesList = canvas->getShapes();
    bool ok;
    int shapeId = ui->shapeIdLineEdit->text().toInt(&ok);

    for (Shape* shape : shapesList) {
        if (shape && shape->getId() == shapeId) { // Find the shape to move
            switch (event->key()) {
            case Qt::Key_W:
                shape->move(0, -10); // Move shape up
                break;
            case Qt::Key_S:
                shape->move(0, 10);  // Move shape down
                break;
            case Qt::Key_A:
                shape->move(-10, 0); // Move shape left
                break;
            case Qt::Key_D:
                shape->move(10, 0);  // Move shape right
                break;
            default:
                QMainWindow::keyPressEvent(event); // Pass other keys to default handler
                return;
            }
            canvas->update(); // Redraw canvas with updated position
            return;
        }
    }
}

/**
 * @brief MainWindow::on_contactUsButton_clicked
 *
 * This function shows the Heap Gobbler LLC Inc phone number
 *
 */

void MainWindow::on_contactUsButton_clicked()
{
    QMessageBox msgBox(this);
    // title of the window
    msgBox.setWindowTitle("Contact Us");
    // the information of our group or so they say
    msgBox.setText("Heap Gobbler LLC Inc.\nPhone: (123) 456-7890\nEmail: support@heapgobbler.com");
    msgBox.setIconPixmap(QPixmap(":/images/logo.png"));

    // path to the logo
    QPixmap logo(":/images/logo.png");
    // set the heap gobbler logo instead of the default i logo
    msgBox.setIconPixmap(logo.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // ok button to exit
    msgBox.addButton(QMessageBox::Ok);

    msgBox.exec();
}


/**
 * @brief MainWindow::on_loginButton_clicked
 * 
 * This function creates a login window and handles the application state based on the login result.
 */
void MainWindow::on_loginButton_clicked()
{
    if (alreadyLoggedIn || isLoggedIn) {
        return;
    }

    login loginWindow;
    loginWindow.setWindowFlags(Qt::Window);

    this->hide();

    int result = loginWindow.exec();
    if (result == QDialog::Accepted) {
        isLoggedIn = true;
        alreadyLoggedIn = true;
        ui->loginButton->hide();
        setControlsEnabled(true);
        this->show();
    } else {
        QApplication::quit();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    testimonialsManager->showTestimonials();
}

void MainWindow::setControlsEnabled(bool enabled)
{
    // Disable/enable all shape manipulation controls
    ui->addPushButton->setEnabled(enabled);
    ui->pushButton->setEnabled(enabled);  // Movement toggle
    ui->shapeIdLineEdit->setEnabled(enabled);
    ui->spinBox->setEnabled(enabled);
    ui->removeShapeButton->setEnabled(enabled);

    // Disable/enable all shape type toggles
    ui->toggleLine->setEnabled(enabled);
    ui->togglePolyline->setEnabled(enabled);
    ui->togglePolygon->setEnabled(enabled);
    ui->toggleSquare->setEnabled(enabled);
    ui->toggleRectangle->setEnabled(enabled);
    ui->toggleCircle->setEnabled(enabled);
    ui->toggleEllipse->setEnabled(enabled);
    ui->toggleText->setEnabled(enabled);

    // Disable/enable all property controls
    ui->colorDropDown->setEnabled(enabled);
    ui->widthDropDown->setEnabled(enabled);
    ui->styleDropDown->setEnabled(enabled);
    ui->capDropDown->setEnabled(enabled);
    ui->joinStyleDropDown->setEnabled(enabled);
    ui->brushColorDrop->setEnabled(enabled);
    ui->brushStyleDrop->setEnabled(enabled);

    // Disable/enable dimension inputs
    ui->lengthLineEdit->setEnabled(enabled);
    ui->widthLineEdit->setEnabled(enabled);
    ui->radiusLineEdit->setEnabled(enabled);
    ui->semimajorLineEdit->setEnabled(enabled);
    ui->semiminorLineEdit->setEnabled(enabled);
}

void MainWindow::on_removeShapeButton_clicked()
{
    bool ok;
    int removeShapeWithId = ui->removeShapeLineEdit->text().toInt(&ok);
    canvas->removeShape(removeShapeWithId);
    update();
}

void MainWindow::on_reportButton_clicked()
{
    ReportsDialog* reportsDialog = new ReportsDialog(canvas, this);
    reportsDialog->setAttribute(Qt::WA_DeleteOnClose);
    reportsDialog->exec();
}
