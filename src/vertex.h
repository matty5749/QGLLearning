/**
 *\file vertex.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef VERTEX_H
#define VERTEX_H

#include <GL/gl.h>
#include <qobject.h>

/**
 * \class Vertex
 * \brief Structure un sommet en typage openGL (GLfloat) .Prevu pour des espaces en 3 dimensions (x,y,z)
 */
class Vertex : public QObject
{
    Q_OBJECT
private:
    GLfloat m_x;
    GLfloat m_y;
    GLfloat m_z;
public:
    Vertex ( GLfloat x, GLfloat y, GLfloat z );
    GLfloat getX() const;
    GLfloat getY() const;
    GLfloat getZ() const;
    void drawVertex() const;
protected slots:
    void changeX ( double );
    void changeY ( double );
    void changeZ ( double );

signals:
    /**
     * \fn void vertexChanged();
     * \brief Est envoyé lorsque l'un des membres a changé.
     */
    void vertexChanged();
};

#endif // VERTEX_H
