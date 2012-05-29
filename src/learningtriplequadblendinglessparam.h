/**
 *\file learningtriplequadblendinglessparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGTRIPLEQUADBLENDINGLESSPARAM_H
#define LEARNINGTRIPLEQUADBLENDINGLESSPARAM_H

#include "learning.h"
class QGLClearColor;

class GLTripleQuadBlendingLessParam;

/**
 * \class LearningTripleQuadBlendingLessParam
 * \brief Gere l'interaction entre la modelisation GLTripleQuadBlendingLessParam et l'utilisateur
 */
class LearningTripleQuadBlendingLessParam : public Learning
{
private:
    GLTripleQuadBlendingLessParam* m_glTripleQuadBlendingLessParam;
    QGLClearColor* m_qGLClearColor;

public:
    LearningTripleQuadBlendingLessParam(QWidget* parent = 0);
    virtual QString getName() const;
};

#endif // LEARNINGTRIPLEQUADBLENDINGLESSPARAM_H
