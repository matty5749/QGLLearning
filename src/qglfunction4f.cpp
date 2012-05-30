/**
 *\file qglfunction4f.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglfunction4f.h"

#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <qt4/Qt/qcolor.h>

QGLFunction4f::QGLFunction4f(QWidget* parent): QGLFunction(parent)
{
    m_hbox->setParent(this);

    m_comma1=new QLabel(this);
    m_comma1->setText(" , ");
    m_comma2=new QLabel(this);
    m_comma2->setText(" , ");
    m_comma3=new QLabel(this);
    m_comma3->setText(" , ");
    m_bracketRight=new QLabel(this);
    m_bracketRight->setText(" );");

    m_spin1=new QSpinBox(this);
    m_spin2=new QSpinBox(this);
    m_spin3=new QSpinBox(this);
    m_spin4=new QSpinBox(this);
    
    m_spin1->setPalette(QPalette(Qt::white));
    m_spin2->setPalette(QPalette(Qt::white));
    m_spin3->setPalette(QPalette(Qt::white));
    m_spin4->setPalette(QPalette(Qt::white));

    m_spin1->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    m_spin2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    m_spin3->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    m_spin4->setButtonSymbols(QAbstractSpinBox::PlusMinus);

    m_hbox->addWidget(m_spin1);
    m_hbox->addWidget(m_comma1);
    m_hbox->addWidget(m_spin2);
    m_hbox->addWidget(m_comma2);
    m_hbox->addWidget(m_spin3);
    m_hbox->addWidget(m_comma3);
    m_hbox->addWidget(m_spin4);
    m_hbox->addWidget(m_bracketRight);
}

