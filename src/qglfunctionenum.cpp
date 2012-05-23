/**
 *\file qglfunctionenum.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglfunctionenum.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>

QGLFunctionEnum::QGLFunctionEnum(QWidget* parent): QGLFunction(parent)
{
    m_hbox->setParent(this);

    m_bracketRight=new QLabel(this);
    m_bracketRight->setText(" );");

    m_equation=new QComboBox(this);

    m_hbox->addWidget ( m_equation );
    m_hbox->addWidget(m_bracketRight);
}
