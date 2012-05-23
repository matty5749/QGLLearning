/**
 *\file learningdoublequadblendingfullparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGCUBEBLENDINGFULLPARAM_H
#define LEARNINGCUBEBLENDINGFULLPARAM_H

#include "learning.h"

class GLCubeBlendingFullParam;
class QGLDepthMask;

/**
 * \class LearningCubeBlendingFullParam
 * \brief Construit la modelisation GLCubeBlendingFullParam et gere l'affichage des controlleurs de celle-ci.
 */
class LearningCubeBlendingFullParam : public Learning
{
private:
    GLCubeBlendingFullParam* m_glCubeBlendingFullParam;
    QGLDepthMask* m_qGLDepthMask;

public:
    LearningCubeBlendingFullParam(GLCubeBlendingFullParam* modelisation = 0 , QWidget* parent = 0);
    virtual QString getName() const;
};

#endif // LEARNINGCUBEBLENDINGFULLPARAM_H
