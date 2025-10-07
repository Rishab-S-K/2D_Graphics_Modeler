#include "TestimonialsManager.h"
#include <QInputDialog>

TestimonialsManager::TestimonialsManager(QObject *parent)
    : QObject(parent)
{
    loadTestimonials();
}

TestimonialsManager::~TestimonialsManager()
{
    saveTestimonials();
}

void TestimonialsManager::showTestimonials()
{
    QString allTestimonials;
    
    if (testimonials.isEmpty()) {
        allTestimonials = "No testimonials yet. Be the first to add one!";
    } else {
        for (const QString& testimonial : testimonials) {
            if (!testimonial.trimmed().isEmpty()) {
                allTestimonials += "• " + testimonial + "\n\n";
            }
        }
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("Customer Testimonials");
    msgBox.setText(allTestimonials);
    
    QPushButton *addButton = msgBox.addButton("Add Testimonial", QMessageBox::ActionRole);
    QPushButton *closeButton = msgBox.addButton(QMessageBox::Close);
    msgBox.setDefaultButton(closeButton);
    
    msgBox.exec();
    
    if (msgBox.clickedButton() == addButton) {
        addTestimonial();
    }
}

void TestimonialsManager::addTestimonial()
{
    bool ok;
    QString testimonial = QInputDialog::getMultiLineText(nullptr,
        "Add Testimonial",
        "Please share your experience:",
        "", &ok);

    if (ok && !testimonial.isEmpty()) {
        testimonials.append(testimonial);
        saveTestimonials();
        showTestimonials();
    }
}

    void TestimonialsManager::loadTestimonials()
{
    QFile file(TESTIMONIALS_FILE);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                testimonials.append(line);
            }
        }
        file.close();
    }
}

void TestimonialsManager::saveTestimonials()
{
    QFile file(TESTIMONIALS_FILE);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString& testimonial : testimonials) {
            out << testimonial << "\n";
        }
        file.close();
    }
}