/**
 *\file learningdoublequadblendinglessparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGCUBEBLENDINGLESSPARAM_H
#define LEARNINGCUBEBLENDINGLESSPARAM_H

#include "learning.h"

class GLCubeBlendingLessParam;
class QGLClearColor;

/**
 * \class LearningCubeBlendingLessParam
 * \brief Construit la modelisation GLCubeBlendingLessParam et gere l'affichage des controlleurs de celle-ci.
 */
class LearningCubeBlendingLessParam : public Learning
{
private:
    GLCubeBlendingLessParam* m_glCubeBlendingLessParam;
    QGLClearColor* m_qGLClearColor;

public:
    LearningCubeBlendingLessParam(GLCubeBlendingLessParam* modelisation = 0 , QWidget* parent = 0);
    ~LearningCubeBlendingLessParam();
    virtual QString getName() const;
};

#endif // LEARNINGCUBEBLENDINGLESSPARAM_H
