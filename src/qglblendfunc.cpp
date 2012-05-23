/**
 *\file qglblendfunc.cpp
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "qglblendfunc.h"

#include <GL/gl.h>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>

QGLBlendFunc::QGLBlendFunc( QWidget* parent):QGLFunction2Enum(parent)
{

    m_nameFunction->setText( "glBlendFunc (" );

    m_src->addItem ( "GL_ZERO" );
    m_src->addItem ( "GL_ONE" );
    m_src->addItem ( "GL_DST_COLOR" );
    m_src->addItem ( "GL_ONE_MINUS_DST_COLOR" );
    m_src->addItem ( "GL_SRC_ALPHA" );
    m_src->addItem ( "GL_ONE_MINUS_SRC_ALPHA" );
    m_src->addItem ( "GL_DST_ALPHA" );
    m_src->addItem ( "GL_ONE_MINUS_DST_ALPHA" );
    m_src->addItem ( "GL_SRC_ALPHA_SATURATE" );

    m_dst->addItem ( "GL_ZERO" );
    m_dst->addItem ( "GL_ONE" );
    m_dst->addItem ( "GL_SRC_COLOR" );
    m_dst->addItem ( "GL_ONE_MINUS_SRC_COLOR" );
    m_dst->addItem ( "GL_SRC_ALPHA" );
    m_dst->addItem ( "GL_ONE_MINUS_SRC_ALPHA" );
    m_dst->addItem ( "GL_DST_ALPHA" );
    m_dst->addItem ( "GL_ONE_MINUS_DST_ALPHA" );

    m_src->setCurrentIndex(4);
    m_dst->setCurrentIndex(5);

    connect(m_src,SIGNAL(currentIndexChanged(int)),this,SLOT(changeSrc(int)));
    connect(m_dst,SIGNAL(currentIndexChanged(int)),this,SLOT(changeDst(int)));
}
/**
 * \fn int QGLBlendFunc::convertSrcToGLEnum ( int var)
 * \brief Permet de convertir l'index d'un label de comboBox en son GLEnum correspondant
 * \param var index du label source de la comboBox
 */
int QGLBlendFunc::convertSrcToGLEnum ( int var)
{
    switch (var)
    {
    case 0:
        return GL_ZERO;
        break;
    case 1:
        return GL_ONE;
        break;
    case 2:
        return GL_DST_COLOR;
        break;
    case 3:
        return GL_ONE_MINUS_DST_COLOR;
        break;
    case 4:
        return GL_SRC_ALPHA;
        break;
    case 5:
        return GL_ONE_MINUS_SRC_ALPHA;
        break;
    case 6:
        return GL_DST_ALPHA;
        break;
    case 7:
        return GL_ONE_MINUS_DST_ALPHA;
        break;
    case 8:
        return GL_SRC_ALPHA_SATURATE;
        break;
    default:
        return 0;
        break;
    }
}

/**
 * \fn int QGLBlendFunc::convertDstToGLEnum ( int var )
 * \brief Permet de convertir l'index d'un label de comboBox en son GLEnum correspondant
 * \param var index du label destination de la comboBox
 */
int QGLBlendFunc::convertDstToGLEnum ( int var )
{
    switch (var)
    {
    case 0:
        return GL_ZERO;
        break;
    case 1:
        return GL_ONE;
        break;
    case 2:
        return GL_SRC_COLOR;
        break;
    case 3:
        return GL_ONE_MINUS_SRC_COLOR;
        break;
    case 4:
        return GL_SRC_ALPHA;
        break;
    case 5:
        return GL_ONE_MINUS_SRC_ALPHA;
        break;
    case 6:
        return GL_DST_ALPHA;
        break;
    case 7:
        return GL_ONE_MINUS_DST_ALPHA;
        break;
    default:
        return 0;
        break;
    }
}

/**
 * \fn void QGLBlendFunc::changeSrc ( int src)
 * \brief Lors de l'interraction dans la comboBox source , on envoie le signal blendFuncChanged avec les parametre glEnum correspondant
 */
void QGLBlendFunc::changeSrc ( int src)
{
    emit blendFuncChanged(convertSrcToGLEnum(src),convertDstToGLEnum(m_dst->currentIndex()));
}

/**
 * \fn void QGLBlendFunc::changeSrc ( int src)
 * \brief Lors de l'interraction dans la comboBox destination , on envoie le signal blendFuncChanged avec les parametre glEnum correspondant
 */
void QGLBlendFunc::changeDst ( int dst)
{
    emit blendFuncChanged(convertSrcToGLEnum(m_src->currentIndex()),convertDstToGLEnum(dst));
}

