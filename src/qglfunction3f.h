/**
 *\file qglfunction3f.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLFUNCTION3F_H
#define QGLFUNCTION3F_H

#include "qglfunction.h"

class QDoubleSpinBox;
/**
 * \class QGLFunction3f
 * \brief Permet la gestion de fonction openGL prenant comme parametre 3 GLfloat
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLFunction3f : public QGLFunction
{
protected:
    QLabel* m_coma1;
    QLabel* m_coma2;
    QLabel* m_bracketRight;

    QDoubleSpinBox* m_spin1;
    QDoubleSpinBox* m_spin2;
    QDoubleSpinBox* m_spin3;
public:
    QGLFunction3f(QWidget* parent = 0);

};

#endif // QGLFUNCTION3F_H
