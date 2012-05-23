/**
 *\file qglcolor4f.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLCOLOR4F_H
#define QGLCOLOR4F_H

#include "qglfunction4f.h"

class Color4f;
/**
 * \class QGLColor4f
 * \brief Creer un widget permettant la gestion de la fonction glColor4f
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLColor4f : public QGLFunction4f
{
private:
    Color4f* m_color;
public:
    QGLColor4f(Color4f* color=0 , QWidget* parent = 0);
};

#endif // QGLCOLOR4F_H
