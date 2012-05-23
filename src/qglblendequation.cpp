/**
 *\file qglblendequation.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglblendequation.h"

#include <GL/gl.h>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>

QGLBlendEquation::QGLBlendEquation( QWidget* parent):QGLFunctionEnum(parent)
{

    m_nameFunction->setText( "glBlendEquation (" );

    m_equation->addItem ( "GL_FUNC_ADD" );
    m_equation->addItem ( "GL_FUNC_SUBTRACT" );
    m_equation->addItem ( "GL_FUNC_REVERSE_SUBTRACT" );
    m_equation->addItem ( "GL_MIN" );
    m_equation->addItem ( "GL_MAX" );

    m_equation->setCurrentIndex(0);

    connect(m_equation,SIGNAL(currentIndexChanged(int)),this,SLOT(changeEqu(int)));
}

/**
 * \fn int QGLBlendEquation::convertEquToGLEnum ( int var)
 * \brief Permet de convertir l'index d'un label de comboBox en son GLEnum correspondant
 * \param var index du label de la comboBox
 */
int QGLBlendEquation::convertEquToGLEnum ( int var)
{
    switch (var)
    {
    case 0:
        return GL_FUNC_ADD;
        break;
    case 1:
        return GL_FUNC_SUBTRACT;
        break;
    case 2:
        return GL_FUNC_REVERSE_SUBTRACT;
        break;
    case 3:
        return GL_MIN;
        break;
    case 4:
        return GL_MAX;
        break;
    default:
        return 0;
        break;
    }
}

void QGLBlendEquation::changeEqu ( int src)
{
    emit blendEquationChanged(convertEquToGLEnum(src));
}

