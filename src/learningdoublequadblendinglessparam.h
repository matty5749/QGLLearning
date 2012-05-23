/**
 *\file learningdoublequadblendinglessparam.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGDOUBLEQUADBLENDINGLESSPARAM_H
#define LEARNINGDOUBLEQUADBLENDINGLESSPARAM_H

#include "learning.h"

class GLDoubleQuadBlendingLessParam;

/**
 * \class LearningDoubleQuadBlendingLessParam
 * \brief Construit la modelisation GLDoubleQuadBlendingLessParam et gere l'affichage des controlleurs de celle-ci.
 */
class LearningDoubleQuadBlendingLessParam : public Learning
{
private:
    GLDoubleQuadBlendingLessParam* m_glDoubleQuadBlendingLessParam;

public:
    LearningDoubleQuadBlendingLessParam(GLDoubleQuadBlendingLessParam* modelisation = 0 , QWidget* parent = 0);
    virtual QString getName() const;
};

#endif // LEARNINGDOUBLEQUADBLENDINGLESSPARAM_H
