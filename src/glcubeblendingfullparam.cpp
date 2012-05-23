/**
 *\file glcubeblendingfullparam.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "glcubeblendingfullparam.h"
#include "vertex.h"

/**
 * \fn GLCubeBlendingFullParam::GLCubeBlendingFullParam(QWidget* parent): GLWidget(parent)
 * \brief Le constructeur creer tout les objets dont la scene à besoin
 */
GLCubeBlendingFullParam::GLCubeBlendingFullParam(QWidget* parent): GLWidget(parent)
{
    Vertex* base = new Vertex(-1, -1, 1);

    
    m_cube = new Cube(base, 2.0, false);
}

void GLCubeBlendingFullParam::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);

    //MODELISATION
    m_cube->drawFigure();
    depthMask();
}

