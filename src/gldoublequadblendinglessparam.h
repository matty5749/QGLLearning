/**
 *\file gldoublequadblendinglessparam.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef GLDOUBLEQUADBLENDINGLESSPARAM_H
#define GLDOUBLEQUADBLENDINGLESSPARAM_H

#include "glwidget.h"
#include "quad.h"

class LearningDoubleQuadBlendingLessParam;
/**
 * \class GLDoubleQuadBlendingLessParam
 * \brief Gere la modelisation de la scene DoubleQuadBlendingLessParam.Est manipulé par les widgets present dans LearningDoubleQuadBlendingLessParam.
 * \warning Ne doit etre instancier que une seule fois.Le contraire n'aurait pas d'interet puisque chaque theme de scene doit etre unique.
 */
class GLDoubleQuadBlendingLessParam : public GLWidget
{
private:
    Quad* m_quad1;
    Quad* m_quad2;
public:
    GLDoubleQuadBlendingLessParam ( QWidget* parent = 0 );
    ~GLDoubleQuadBlendingLessParam();

private:
    virtual void draw();
    friend class LearningDoubleQuadBlendingLessParam;
};

#endif // GLDOUBLEQUADBLENDINGLESSPARAM_H
