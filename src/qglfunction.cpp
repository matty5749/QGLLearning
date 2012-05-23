/**
 *\file qglfunction.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglfunction.h"
#include <QHBoxLayout>
#include <QLabel>

/**
 * \fn QGLFunction::QGLFunction(QWidget* parent, Qt::WindowFlags f): QDialog(parent, f)
 * \brief Creation du label qui contiendra le nom de la fonction dans les classes filles par un appel à setName et creation du gestionnaire de disposition des widget qui seront
 * créé dans les classes filles.
 */
QGLFunction::QGLFunction(QWidget* parent): QDialog(parent)
{
    m_hbox=new QHBoxLayout(this);
    m_nameFunction=new QLabel;

    m_hbox->addWidget(m_nameFunction);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
}
