/**
 *\file qglcolor4f.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglcolor4f.h"

#include "color4f.h"
#include <QLabel>
#include <QSpinBox>

QGLColor4f::QGLColor4f(Color4f* color , QWidget* parent): QGLFunction4f(parent), m_color(color)
{
    m_nameFunction->setText("glColor4f(");

    m_spin1->setRange(0,99);
    m_spin2->setRange(0,99);
    m_spin3->setRange(0,99);
    m_spin4->setRange(0,99);

    m_spin1->setPrefix("0.");
    m_spin2->setPrefix("0.");
    m_spin3->setPrefix("0.");
    m_spin4->setPrefix("0.");

    m_spin1->setValue(m_color->getR()*100);
    m_spin2->setValue(m_color->getG()*100);
    m_spin3->setValue(m_color->getB()*100);
    m_spin4->setValue(m_color->getA()*100);

    connect(m_spin1,SIGNAL(valueChanged(int)),m_color,SLOT(changeR(int)));
    connect(m_spin2,SIGNAL(valueChanged(int)),m_color,SLOT(changeG(int)));
    connect(m_spin3,SIGNAL(valueChanged(int)),m_color,SLOT(changeB(int)));
    connect(m_spin4,SIGNAL(valueChanged(int)),m_color,SLOT(changeA(int)));
}

QGLColor4f::~QGLColor4f()
{
  /*
  delete m_color;
  m_color=NULL;
  */
}
