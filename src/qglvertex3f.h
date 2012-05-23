/**
 *\file qglvertex3f.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLVERTEX3F_H
#define QGLVERTEX3F_H

#include "qglfunction3f.h"

class Vertex;
/**
 * \class QGLVertex3f
 * \brief Permet la gestion de la fonction glVertex3f
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLVertex3f : public QGLFunction3f
{
private:
    Vertex* m_vertex;
public:
    QGLVertex3f( Vertex* vertex=0 , QWidget* parent = 0);

    friend class Figure;
};

#endif // QGLVERTEX3F_H
