/**
 *\file mainwindow.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class LearningManager;
/**
 * \class MainWindow
 * \brief Gere la fenetre principale du programme.Herite de QMainWindow
 */
class MainWindow : public QMainWindow
{
private:
    LearningManager* m_learningManager;
public:
    MainWindow();
};

#endif
