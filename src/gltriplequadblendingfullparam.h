#ifndef GLTRIPLEQUADBLENDINGFULLPARAM_H
#define GLTRIPLEQUADBLENDINGFULLPARAM_H

#include "glwidget.h"
#include "quad.h"

class LearningTripleQuadBlendingFullParam;

class GLTripleQuadBlendingFullParam : public GLWidget
{
private:
    Quad* m_quad1;
    Quad* m_quad2;
    Quad* m_quad3;
public:
    GLTripleQuadBlendingFullParam ( QWidget* parent = 0 );

private:
    virtual void draw();
    friend class LearningTripleQuadBlendingFullParam;
};

#endif // GLTRIPLEQUADBLENDINGFULLPARAM_H
