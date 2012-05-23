/**
 *\file vertex.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "vertex.h"

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z):m_x(x),m_y(y),m_z(z)
{

}

GLfloat Vertex::getX() const
{
    return m_x;
}

GLfloat Vertex::getY() const
{
    return m_y;
}

GLfloat Vertex::getZ() const
{
    return m_z;
}

void Vertex::drawVertex() const
{
    glVertex3f(m_x,m_y,m_z);
}

void Vertex::changeX(double x)
{
    m_x=x;
    emit vertexChanged();
}

void Vertex::changeY(double y)
{
    m_y=y;
    emit vertexChanged();
}

void Vertex::changeZ(double z)
{
    m_z=z;
    emit vertexChanged();
}
