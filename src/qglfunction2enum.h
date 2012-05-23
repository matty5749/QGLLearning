/**
 *\file qglfunction2enum.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLFUNCTION2ENUM_H
#define QGLFUNCTION2ENUM_H

#include "qglfunction.h"

class QComboBox;

/**
 * \class QGLFunction2Enum
 * \brief Permet la gestion de fonction openGL prenant comme parametre 2 enum
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLFunction2Enum : public QGLFunction
{
protected:
    QComboBox* m_src;
    QComboBox* m_dst;
    QLabel* m_comma1;
    QLabel* m_bracketRight;
public:
    QGLFunction2Enum(QWidget* parent = 0);
};

#endif // QGLFUNCTION2ENUM_H
