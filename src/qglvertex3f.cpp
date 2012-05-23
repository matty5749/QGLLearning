/**
 *\file qglvertex3f.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglvertex3f.h"

#include <QLabel>
#include <QDoubleSpinBox>
#include "vertex.h"

QGLVertex3f::QGLVertex3f( Vertex* vertex , QWidget* parent): QGLFunction3f(parent),m_vertex(vertex)
{
    m_nameFunction->setText("glVertex3f(");
    m_spin1->setValue(m_vertex->getX());
    m_spin2->setValue(m_vertex->getY());
    m_spin3->setValue(m_vertex->getZ());

    connect(m_spin1,SIGNAL(valueChanged(double)),m_vertex,SLOT(changeX(double)));
    connect(m_spin2,SIGNAL(valueChanged(double)),m_vertex,SLOT(changeY(double)));
    connect(m_spin3,SIGNAL(valueChanged(double)),m_vertex,SLOT(changeZ(double)));
}
