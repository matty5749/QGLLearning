/**
 *\file quad.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QUAD_H
#define QUAD_H
#include "figure.h"

class QVBoxLayout;
class Vertex;
class QGLColor4f;
class QLabel;
class QDialog;
class QLabel;
class QGLVertex3f;
class Cube;
class LearningDoubleQuadBlendingLessParam;

/**
 * \class Quad
 * \brief Créer des quadrilateres
 */
class Quad : public Figure
{
    Q_OBJECT
private:
    Vertex* m_one;
    Vertex* m_two;
    Vertex* m_three;
    Vertex* m_four;

    QLabel* m_glBegin;
    QLabel* m_glEnd;

    QGLColor4f* m_qGLColor4f;

    QGLVertex3f* m_qGLVertex3fOne;
    QGLVertex3f* m_qGLVertex3fTwo;
    QGLVertex3f* m_qGLVertex3fThree;
    QGLVertex3f* m_qGLVertex3fFour;

public:
    Quad ( GLfloat r, GLfloat g, GLfloat b, GLfloat a, Vertex* one, Vertex* two, Vertex* three, Vertex* four, bool depthMaskWidget = false, bool cullFaceWidget = true, bool depthTestWidget = true, bool blendWidget = true );
    ~Quad();
    virtual void drawFigure();

private:
    virtual QDialog* getDialogCode();

protected slots:
    void change();

signals:
    void quadChanged();

    friend class Cube;
    friend class LearningQuadBlending;
    friend class LearningDoubleQuadBlendingLessParam;
    friend class LearningDoubleQuadBlendingFullParam;
    friend class LearningTripleQuadBlendingLessParam;
    friend class LearningTripleQuadBlendingFullParam;
    friend class LearningCubeBlendingLessParam;
    friend class LearningCubeBlendingFullParam;
};

#endif // QUAD_H
