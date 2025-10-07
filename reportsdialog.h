#ifndef REPORTSDIALOG_H
#define REPORTSDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include "canvas.h"
#include "Shape.h"

namespace Ui {
class reports;
}

/**
 * @class ReportsDialog
 * @brief Dialog for displaying various shape reports and analytics
 *
 * The ReportsDialog class provides a tabbed interface for viewing different
 * sorted representations of shapes in the canvas. It offers three main views:
 * - Shapes sorted by ID, showing complete shape properties
 * - Shapes sorted by area, focused on geometric measurements
 * - Shapes sorted by perimeter, displaying boundary measurements
 *
 * Each tab presents data in a table format.
 *
 * @author Cem Yildiz
 * @date December 2024
 */
class ReportsDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Constructs a reports dialog
     * @param canvas Pointer to the canvas containing shapes to analyze
     * @param parent Optional parent widget for Qt's parent-child system
     * 
     * Initializes the dialog and populates all three report tabs with data.
     * The dialog takes ownership of managing the UI elements but not the canvas pointer.
     */
    explicit ReportsDialog(Canvas* canvas, QWidget* parent = nullptr);

    /**
     * @brief Destructor
     * 
     * Cleans up the UI resources. The canvas pointer is not deleted
     * as ownership remains with the parent window.
     */
    ~ReportsDialog();

private:
    Ui::reports* ui;     ///< Pointer to the UI elements
    Canvas* canvas;      ///< Pointer to the canvas containing shapes

    /**
     * @brief Initializes the ID-sorted tab
     * 
     * Populates the first tab with shapes sorted by ID in ascending order.
     * Shows all shape properties including:
     * - Shape ID
     * - Shape type
     * - Pen properties (color, width, style)
     * - Brush properties (for filled shapes)
     */
    void initializeById();

    /**
     * @brief Initializes the area-sorted tab
     * 
     * Populates the second tab with shapes sorted by area in ascending order.
     * Shows:
     * - Shape ID
     * - Shape type
     * - Area value with 2 decimal precision
     * 
     * Note: Lines, polylines, and text shapes show 0 area.
     */
    void initializeByArea();

    /**
     * @brief Initializes the perimeter-sorted tab
     * 
     * Populates the third tab with shapes sorted by perimeter in ascending order.
     * Shows:
     * - Shape ID
     * - Shape type
     * - Perimeter value with 2 decimal precision
     */
    void initializeByPerimeter();

    /**
     * @brief Converts a QColor to its string name
     * @param color The QColor to convert
     * @return QString containing the color name
     * 
     * Supported colors: White, Black, Red, Green, Blue, Cyan, Magenta, Yellow, Gray
     * Returns "Unknown" for any other color values.
     */
    QString getColorName(const QColor& color);
};

#endif // REPORTSDIALOG_H