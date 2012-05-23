/**
 *\file mainwindow.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "mainwindow.h"
#include <iostream>
#include "learningmanager.h"
#include <QDockWidget>

/**
 * \fn MainWindow::MainWindow()
 * \brief Instancie un gestionnaire de themes LearningManager qui devient le widget central.Un QDockWidget est passé en parametre de ce gestionnaire afin que celui gere la navigabilite entre les themes.
 */
MainWindow::MainWindow()
{
    QDockWidget* m_learningChoice=new QDockWidget(tr("Learning choice"));
    m_learningManager=new LearningManager(m_learningChoice);
    addDockWidget(Qt::LeftDockWidgetArea,m_learningChoice);
    this->setCentralWidget(m_learningManager);
}

