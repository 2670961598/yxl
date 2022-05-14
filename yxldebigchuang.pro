QT       += core gui
QT       += androidextras
QT       += multimedia multimediawidgets
QT       += positioning
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    friends.cpp \
    gcarouselfigurewidget.cpp \
    gpsinfo.cpp \
    http.cpp \
    image.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    set.cpp \
    setFind.cpp \
    widget.cpp

HEADERS += \
    friends.h \
    gcarouselfigurewidget.h \
    gpsinfo.h \
    http.h \
    image.h \
    login.h \
    mainwindow.h \
    set.h \
    setFind.h \
    widget.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc


android{
    date.files += sets
    date.files += information
    date.path = /assets/user
    INSTALLS += date
}
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android_sources




DISTFILES += \
    Camera.py \
    android_sources/AndroidManifest.xml \
    android_sources/AndroidManifest.xml \
    android_sources/build.gradle \
    android_sources/gradle/wrapper/gradle-wrapper.jar \
    android_sources/gradle/wrapper/gradle-wrapper.properties \
    android_sources/gradlew \
    android_sources/gradlew.bat \
    android_sources/res/values/libs.xml



