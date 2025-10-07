#ifndef TESTIMONIALSMANAGER_H
#define TESTIMONIALSMANAGER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPushButton>

/**
 * @class TestimonialsManager
 * @brief Manages customer testimonials for the 2D Graphics Modeler
 *
 * The TestimonialsManager class provides functionality to display, add, save,
 * and load customer testimonials. It maintains testimonials between program
 * executions by saving them to a text file.
 *
 * @author Cem Yildiz
 * @date December 2024
 */
class TestimonialsManager : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a TestimonialsManager
     * @param parent Optional parent QObject for memory management
     * 
     * Loads existing testimonials from file during construction
     */
    explicit TestimonialsManager(QObject *parent = nullptr);

    /**
     * @brief Destructor
     * 
     * Saves testimonials to file before destruction
     */
    ~TestimonialsManager();

    /**
     * @brief Shows the testimonials dialog
     * 
     * Displays all existing testimonials in a message box with options
     * to close or add a new testimonial
     */
    void showTestimonials();

    /**
     * @brief Prompts user to add a new testimonial
     * 
     * Opens an input dialog for entering a new testimonial. If confirmed,
     * the testimonial is added to the collection and saved to file
     */
    void addTestimonial();

    /**
     * @brief Loads testimonials from file
     * 
     * Reads all testimonials from the testimonials.txt file and stores
     * them in memory for display
     */
    void loadTestimonials();

    /**
     * @brief Saves testimonials to file
     * 
     * Writes all testimonials from memory to the testimonials.txt file
     * for persistence between program executions
     */
    void saveTestimonials();

private:
    QVector<QString> testimonials;  ///< Collection of testimonials in memory
    const QString TESTIMONIALS_FILE = "testimonials.txt";  ///< File for storing testimonials
};

#endif // TESTIMONIALSMANAGER_H