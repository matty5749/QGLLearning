/**
 *\file glcubeblendinglessparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef GLCUBEBLENDINGLESSPARAM_H
#define GLCUBEBLENDINGLESSPARAM_H

#include "glwidget.h"
#include "cube.h"

class LearningCubeBlendingLessParam;
/**
 * \class GLCubeBlendingLessParam
 * \brief Gere la modelisation de la scene CubeBlendingLessParam.Est manipulé par les widgets present dans LearningCubeBlendingLessParam.
 * \warning Ne doit etre instancier que une seule fois.Le contraire n'aurait pas d'interet puisque chaque theme de scene doit etre unique.
 */
class GLCubeBlendingLessParam : public GLWidget
{
private:
    Cube *m_cube;
public:
    GLCubeBlendingLessParam ( QWidget* parent = 0 );

private:
    virtual void draw();
    friend class LearningCubeBlendingLessParam;
};

#endif // GLCUBEBLENDINGLESSPARAM_H
