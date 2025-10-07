QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ShapeParser.cpp \
    TestimonialsManager.cpp \
    canvas.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    reportsdialog.cpp \
    serializer.cpp

HEADERS += \
    Circle.h \
    Ellipse.h \
    Line.h \
    Polygon.h \
    Polyline.h \
    Rectangle.h \
    Shape.h \
    ShapeParser.h \
    Square.h \
    TestimonialsManager.h \
    Text.h \
    canvas.h \
    login.h \
    mainwindow.h \
    reportsdialog.h \
    serializer.h \
    vector.h

FORMS += \
    login.ui \
    mainwindow.ui \
    reports.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    img.qrc
