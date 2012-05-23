/**
 *\file qglfunction4f.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLFUNCTION4F_H
#define QGLFUNCTION4F_H

#include "qglfunction.h"

class QLabel;
class QSpinBox;
/**
 * \class QGLFunction4f
 * \brief Permet la gestion de fonction openGL prenant comme parametre 4 GLfloat
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLFunction4f : public QGLFunction
{
protected:
    QSpinBox* m_spin1;
    QSpinBox* m_spin2;
    QSpinBox* m_spin3;
    QSpinBox* m_spin4;
    QLabel* m_comma1;
    QLabel* m_comma2;
    QLabel* m_comma3;
    QLabel* m_bracketRight;
public:
    QGLFunction4f(QWidget* parent = 0);

};

#endif // QGLFUNCTION4F_H
