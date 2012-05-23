/**
 *\file glcubeblendinglessparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef GLCUBEBLENDINGFULLPARAM_H
#define GLCUBEBLENDINGFULLPARAM_H

#include "glwidget.h"
#include "cube.h"

class LearningCubeBlendingFullParam;
/**
 * \class GLCubeBlendingFullParam
 * \brief Gere la modelisation de la scene CubeBlendingFullParam.Est manipulé par les widgets present dans LearningCubeBlendingFullParam.
 * \warning Ne doit etre instancier que une seule fois.Le contraire n'aurait pas d'interet puisque chaque theme de scene doit etre unique.
 */
class GLCubeBlendingFullParam : public GLWidget
{
private:
    Cube *m_cube;
public:
    GLCubeBlendingFullParam ( QWidget* parent = 0 );

private:
    virtual void draw();
    friend class LearningCubeBlendingFullParam;
};

#endif // GLCUBEBLENDINGFULLPARAM_H
