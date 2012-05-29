/**
 *\file learningdoublequadblendingfullparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGDOUBLEQUADBLENDINGFULLPARAM_H
#define LEARNINGDOUBLEQUADBLENDINGFULLPARAM_H

#include "learning.h"

class GLDoubleQuadBlendingFullParam;
class LearningDoubleQuadBlendingFullParam;
class QGLClearColor;

/**
 * \class LearningDoubleQuadBlendingFullParam
 * \brief Construit la modelisation GLDoubleQuadBlendingFullParam et gere l'affichage des controlleurs de celle-ci.
 */
class LearningDoubleQuadBlendingFullParam : public Learning
{
private:
    GLDoubleQuadBlendingFullParam* m_glDoubleQuadBlendingFullParam;
    QGLClearColor* m_qGLClearColor;

public:
    LearningDoubleQuadBlendingFullParam(GLDoubleQuadBlendingFullParam* modelisation = 0 , QWidget* parent = 0);
    ~LearningDoubleQuadBlendingFullParam();
    virtual QString getName() const;
};

#endif // LEARNINGDOUBLEQUADBLENDINGFULLPARAM_H
