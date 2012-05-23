/**
 *\file main.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include <Qt/QtGui>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    MainWindow window;
    window.showMaximized();
    return app.exec();
}
