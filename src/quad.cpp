/**
 *\file quad.cpp
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */


#include "quad.h"
#include "cube.h"
#include <iostream>

#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include "qglcolor4f.h"
#include "qglvertex3f.h"
#include "vertex.h"
#include <math.h>


Quad::Quad(GLfloat r, GLfloat g, GLfloat b, GLfloat a, Vertex* one, Vertex* two, Vertex* three, Vertex* four,bool depthMaskWidget, bool cullFaceWidget, bool depthTestWidget, bool blendWidget):
        Figure(r, g, b, a, depthMaskWidget, cullFaceWidget, depthTestWidget, blendWidget),m_one(one),m_two(two),m_three(three),m_four(four)
{
    m_glBegin=new QLabel();
    m_qGLColor4f=new QGLColor4f(m_color);

    m_qGLVertex3fOne=new QGLVertex3f(m_one);
    m_qGLVertex3fTwo=new QGLVertex3f(m_two);
    m_qGLVertex3fThree=new QGLVertex3f(m_three);
    m_qGLVertex3fFour=new QGLVertex3f(m_four);

    m_glEnd=new QLabel();

    m_glBegin->setText("glBegin(GL_QUADS);");
    m_glEnd->setText("glEnd ();");
    m_glBegin->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    m_glEnd->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);


    m_vbox->addWidget(m_glBegin);
    m_vbox->addWidget(m_qGLColor4f);
    m_vbox->addWidget(m_qGLVertex3fOne);
    m_vbox->addWidget(m_qGLVertex3fTwo);
    m_vbox->addWidget(m_qGLVertex3fThree);
    m_vbox->addWidget(m_qGLVertex3fFour);
    m_vbox->addWidget(m_glEnd);


    connect(this,SIGNAL(figureChanged()),this,SLOT(change()));
    connect(m_color,SIGNAL(colorChanged()),this,SLOT(change()));
    connect(m_one,SIGNAL(vertexChanged()),this,SLOT(change()));
    connect(m_two,SIGNAL(vertexChanged()),this,SLOT(change()));
    connect(m_three,SIGNAL(vertexChanged()),this,SLOT(change()));
    connect(m_four,SIGNAL(vertexChanged()),this,SLOT(change()));
}

void Quad::drawFigure()
{
    if (!m_noCullFace) cullFace();
    if (!m_noDepthTest) 
    {
	depthTest();
	depthMask();
    }

    
    if (!m_noBlend)
    {
        blend();
        blendFunc();
        blendEquation();
    }
    
    glBegin(GL_QUADS);
    m_color->drawColor();
    m_one->drawVertex();
    m_two->drawVertex();
    m_three->drawVertex();
    m_four->drawVertex();
    glEnd();
}
/**
 * \fn QDialog* Quad::getDialogCode()
 * \return Un pointeur de QDialog qui permet l'interraction avec le quadrilatere
 */
QDialog* Quad::getDialogCode()
{
    return m_dialogCodeVertex;
}

/**
 * \fn void Quad::change()
 * \brief Envoie le signal quadChanged lors du changement de n'importe lequel de ses membres
 */
void Quad::change()
{
    emit quadChanged();
}
