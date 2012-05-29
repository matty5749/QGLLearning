/**
 *\file glquadblending.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef GLQUADBLENDING_H
#define GLQUADBLENDING_H

#include "glwidget.h"
#include "quad.h"

class LearningQuadBlending;
/**
 * \class GLQuadBlending
 * \brief Gere la modelisation de la scene QuadBlending.Est manipulé par les widgets present dans LearningQuadBlending.
 * \warning Ne doit etre instancier que une seule fois.Le contraire n'aurait pas d'interet puisque chaque theme de scene doit etre unique.
 */
class GLQuadBlending : public GLWidget
{
private:
    Quad* m_quad1;

public:
    GLQuadBlending ( QWidget* parent = 0 );

private:
    virtual void draw();
    friend class LearningQuadBlending;
};

#endif // GLQUADBLENDING_H
