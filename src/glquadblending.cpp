/**
 *\file glquadblending.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "glquadblending.h"
#include "vertex.h"

/**
 * \fn GLQuadBlending::GLQuadBlending(QWidget* parent): GLWidget(parent)
 * \brief Le constructeur creer tout les objets dont la scene à besoin
 */
GLQuadBlending::GLQuadBlending(QWidget* parent): GLWidget(parent)
{
    Vertex* one=new Vertex(0,0,0);
    Vertex* two=new Vertex(1,0,0);
    Vertex* three=new Vertex(1,1,0);
    Vertex* four=new Vertex(0,1,0);


    m_quad1=new Quad(1.0,0.0,0.0,0.5,one,two,three,four);
}

void GLQuadBlending::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);

    //MODELISATION
    m_quad1->drawFigure();
}

