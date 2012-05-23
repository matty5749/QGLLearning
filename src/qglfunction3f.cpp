/**
 *\file qglfunction3f.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglfunction3f.h"

#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>

QGLFunction3f::QGLFunction3f(QWidget* parent)
{
    m_hbox->setParent(this);

    m_coma1=new QLabel(this);
    m_coma2=new QLabel(this);
    m_bracketRight=new QLabel(this);

    m_coma1->setText(" , ");
    m_coma2->setText(" , ");
    m_bracketRight->setText(" );");

    m_spin1=new QDoubleSpinBox(this);
    m_spin2=new QDoubleSpinBox(this);
    m_spin3=new QDoubleSpinBox(this);

    m_spin1->setRange(-100,100);
    m_spin2->setRange(-100,100);
    m_spin3->setRange(-100,100);

    m_spin1->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    m_spin2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
    m_spin3->setButtonSymbols(QAbstractSpinBox::PlusMinus);

    m_hbox->addWidget(m_spin1);
    m_hbox->addWidget(m_coma1);
    m_hbox->addWidget(m_spin2);
    m_hbox->addWidget(m_coma2);
    m_hbox->addWidget(m_spin3);
    m_hbox->addWidget(m_bracketRight);
}
