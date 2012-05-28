/**
 *\file gldoublequadblendinglessparam.cpp
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "gldoublequadblendinglessparam.h"
#include "vertex.h"

/**
 * \fn GLDoubleQuadBlendingLessParam::GLDoubleQuadBlendingLessParam(QWidget* parent): GLWidget(parent)
 * \brief Le constructeur creer tout les objets dont la scene à besoin
 */
GLDoubleQuadBlendingLessParam::GLDoubleQuadBlendingLessParam(QWidget* parent): GLWidget(parent)
{
    Vertex* one=new Vertex(0,0,0);
    Vertex* two=new Vertex(1,0,0);
    Vertex* three=new Vertex(1,1,0);
    Vertex* four=new Vertex(0,1,0);

    Vertex* five=new Vertex(1,1,1);
    Vertex* six=new Vertex(2,1,1);
    Vertex* seven=new Vertex(2,2,1);
    Vertex* eight=new Vertex(1,2,1);

    m_quad1=new Quad(1.0,0.0,0.0,0.5,one,two,three,four);
    m_quad2=new Quad(0.0,1.0,0.0,0.5,five,six,seven,eight,false,false,false,false);
}

GLDoubleQuadBlendingLessParam::~GLDoubleQuadBlendingLessParam()
{
 delete m_quad1;
 delete m_quad2;
}


void GLDoubleQuadBlendingLessParam::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);

    //glDepthMask(GL_FALSE);//Tampon de profondeur activé en lecture seule, a pour effet de fusionner les couleurs des quads au lieu de remplacer les valeurs dans le tampon
    //MODELISATION
    m_quad1->drawFigure();
    m_quad2->drawFigure();
}

