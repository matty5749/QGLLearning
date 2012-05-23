/**
 *\file qglfunctionenum.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLFUNCTIONENUM_H
#define QGLFUNCTIONENUM_H

#include "qglfunction.h"

class QComboBox;

/**
 * \class QGLFunctionEnum
 * \brief Permet la gestion de fonction openGL prenant comme parametre 1 GLEnum
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLFunctionEnum : public QGLFunction
{
protected:
    QComboBox* m_equation;
    QLabel* m_bracketRight;
public:
    QGLFunctionEnum(QWidget* parent = 0);
};

#endif // QGLFUNCTIONENUM_H
