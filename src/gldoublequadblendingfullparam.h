/**
 *\file gldoublequadblendingfullparam.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef GLDOUBLEQUADBLENDINGFULLPARAM_H
#define GLDOUBLEQUADBLENDINGFULLPARAM_H

#include "glwidget.h"
#include "quad.h"

class LearningDoubleQuadBlendingFullParam;
/**
 * \class GLDoubleQuadBlendingFullParam
 * \brief Gere la modelisation de la scene DoubleQuadBlendingFullParam.Est manipulé par les widgets present dans LearningDoubleQuadBlendingFullParam.
 * \warning Ne doit etre instancier que une seule fois.Le contraire n'aurait pas d'interet puisque chaque theme de scene doit etre unique.
 */
class GLDoubleQuadBlendingFullParam : public GLWidget
{
private:
    Quad* m_quad1;
    Quad* m_quad2;
public:
    GLDoubleQuadBlendingFullParam(QWidget* parent = 0);
    ~GLDoubleQuadBlendingFullParam();
private:
    virtual void draw();
    friend class LearningDoubleQuadBlendingFullParam;
};

#endif // GLDOUBLEQUADBLENDINGFULLPARAM_H
