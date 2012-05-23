#ifndef GLTRIPLEQUADBLENDINGLESSPARAM_H
#define GLTRIPLEQUADBLENDINGLESSPARAM_H

#include "glwidget.h"
#include "quad.h"

class LearningTripleQuadBlendingLessParam;

class GLTripleQuadBlendingLessParam : public GLWidget
{
private:
    Quad* m_quad1;
    Quad* m_quad2;
    Quad* m_quad3;
public:
    GLTripleQuadBlendingLessParam ( QWidget* parent = 0 );

private:
    virtual void draw();
    friend class LearningTripleQuadBlendingLessParam;
};

#endif // GLTRIPLEQUADBLENDINGLESSPARAM_H
