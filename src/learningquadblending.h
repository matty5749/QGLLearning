/**
 *\file learningquadblending.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGQUADBLENDING_H
#define LEARNINGQUADBLENDING_H

#include "learning.h"

class GLQuadBlending;
class QGLClearColor;
/**
 * \class LearningQuadBlending
 * \brief Construit la modelisation GLQuadBlending et gere l'affichage des controlleurs de celle-ci.
 */
class LearningQuadBlending : public Learning
{
private:
    GLQuadBlending* m_glQuadBlending;
    QGLClearColor* m_qGLClearColor;

public:
    LearningQuadBlending(GLQuadBlending* modelisation = 0 , QWidget* parent = 0);
    virtual QString getName() const;
};

#endif // LEARNINGQUADBLENDING_H
