/**
 *\file learningtriplequadblendingfullparam.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGTRIPLEQUADBLENDINGFULLPARAM_H
#define LEARNINGTRIPLEQUADBLENDINGFULLPARAM_H

#include "learning.h"


class GLTripleQuadBlendingFullParam;
class QGLClearColor;

/**
 * \class LearningTripleQuadBlendingFullParam
 * \brief Gere l'interaction entre la modelisation GLTripleQuadBlendingFullParam et l'utilisateur
 */
class LearningTripleQuadBlendingFullParam : public Learning
{
private:
    GLTripleQuadBlendingFullParam* m_glTripleQuadBlendingFullParam;
    QGLClearColor* m_qGLClearColor;

public:
    LearningTripleQuadBlendingFullParam(QWidget* parent = 0);
    ~LearningTripleQuadBlendingFullParam();
    virtual QString getName() const;
};

#endif // LEARNINGTRIPLEQUADBLENDINGFULLPARAM_H
