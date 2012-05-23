/**
 *\file qglfunction2enum.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglfunction2enum.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>

QGLFunction2Enum::QGLFunction2Enum(QWidget* parent): QGLFunction(parent)
{
    m_hbox->setParent(this);

    m_comma1=new QLabel;
    m_bracketRight=new QLabel;
    m_comma1->setText(" , ");
    m_bracketRight->setText(" );");

    m_src=new QComboBox;
    m_dst=new QComboBox;

    m_hbox->addWidget ( m_src );
    m_hbox->addWidget(m_comma1);
    m_hbox->addWidget ( m_dst );
    m_hbox->addWidget(m_bracketRight);
}
