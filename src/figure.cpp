/**
 *\file figure.cpp
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "figure.h"
#include "qglcullface.h"
#include "qglblend.h"
#include "qgldepthtest.h"
#include "qgldepthmask.h"
#include "qglblendequation.h"
#include "qglblendfunc.h"
#include <QVBoxLayout>

#include <iostream>
/**
 * \fn Figure::Figure(GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool cullFaceWidget, bool depthTestWidget, bool blendWidget)
 * \brief Constructeur de figure.
 * \details Le widget QDialog contient les eventuelles widgets de controles de culling , buffering , blending , dépend de l'instanciation.
 * \param r composante de rouge
 * \param g composante de vert
 * \param b composante de bleu
 * \param a composante alpha (transparence)
 * \param depthMaskWidget (=false par defaut) indique si l'on veut avoir la main sur le depthMask --> creation d'un QGLDepthMask si true
 * \param cullFaceWidget (=true par defaut) indique si l'on veut avoir la main sur le culling --> creation d'un QGLCullFace
 * \param depthTestWidget (=true par defaut) indique si l'on veut avoir la main sur le buffer de profondeur --> creation d'un QGLDepthTest
 * \param blendWidget (=true par defaut) indique si l'on veut avoir la main sur le blending --> creation d'un QGLBlend ET QGLBlendFunc ET QGLBlendEquation
 */
Figure::Figure(GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool depthMaskWidget, bool cullFaceWidget, bool depthTestWidget, bool blendWidget):m_color(new Color4f(r,g,b,a))
        , m_depthMaskWidget(depthMaskWidget), m_cullFaceWidget(cullFaceWidget), m_depthTestWidget(depthTestWidget), m_blendWidget(blendWidget), m_depthMask(true), m_cullFace(false), m_depthTest(true)
        , m_blend(true), m_noCullFace(false), m_noDepthTest(false), m_noBlend(false),m_srcBlendFunc(GL_SRC_ALPHA),m_dstBlendFunc(GL_ONE_MINUS_SRC_ALPHA)
        ,m_blendEquation(GL_FUNC_ADD)
{
    m_dialogCodeVertex=new QDialog;
    m_dialogCodeVertex->setAutoFillBackground(true);
    m_dialogCodeVertex->setPalette(m_color->getQPalette());
    
    m_vbox = new QVBoxLayout(m_dialogCodeVertex);

    if (m_cullFaceWidget) 
    {
      m_qGLCullFace=new QGLCullFace;
    }
    else m_noCullFace=true;
    
    if (m_depthTestWidget) 
    {
      m_qGLDepthTest=new QGLDepthTest;
      if(m_depthMaskWidget)
	m_qGLDepthMask = new QGLDepthMask;
    }
    else m_noDepthTest=true;
    
    if (m_blendWidget) m_qGLBlend=new QGLBlend;
    else m_noBlend=true;

    if (m_cullFaceWidget) m_vbox->addWidget(m_qGLCullFace);
    
    if (m_depthTestWidget) 
    {  
      m_vbox->addWidget(m_qGLDepthTest);
       if(m_depthMaskWidget) m_vbox->addWidget(m_qGLDepthMask); 
    }
    
    if (m_blendWidget) m_vbox->addWidget(m_qGLBlend);
    if(m_depthMaskWidget) m_vbox->addWidget(m_qGLDepthMask);
    
    if (m_blendWidget ==  true)
    {
        m_qGLBlendFunc=new QGLBlendFunc;
        m_qGLBlendEquation=new QGLBlendEquation;

        m_vbox->addWidget(m_qGLBlendFunc);
        m_vbox->addWidget(m_qGLBlendEquation);
    }

    if (m_cullFaceWidget) connect(m_qGLCullFace,SIGNAL(switchChanged(bool)),this,SLOT(switchCullFace(bool)));
    if (m_depthTestWidget) 
    {
      connect(m_qGLDepthTest,SIGNAL(switchChanged(bool)),this,SLOT(switchDepthTest(bool)));
      if(m_depthMaskWidget)
	connect(m_qGLDepthMask,SIGNAL(switchChanged(bool)),this,SLOT(switchDepthMask(bool)));
    }
    if (m_blendWidget)
    {
        connect(m_qGLBlend,SIGNAL(switchChanged(bool)),this,SLOT(switchBlend(bool)));
        connect(m_qGLBlendEquation,SIGNAL(blendEquationChanged(int)),this,SLOT(switchBlendEquation(int)));
        connect(m_qGLBlendFunc,SIGNAL(blendFuncChanged(int,int)),this,SLOT(switchBlendFunc(int,int)));
    }
    connect(m_color,SIGNAL(colorChanged()),this,SLOT(changeColor()));
}

Figure::~Figure()
{
  delete m_color;
  m_color=NULL;
}


/**
 * \fn void Figure::cullFace()
 * \brief Appel de la fonction glEnable ou glDisable en fonction de m_cullFace.
 */
void Figure::cullFace()
{
    Q_ASSERT(!m_noCullFace);//Verifie que le widget qglcullface est activé/instancié
    if ( m_cullFace ) glEnable ( GL_CULL_FACE );
    else glDisable ( GL_CULL_FACE );
}

/**
 * \fn void Figure::depthTest()
 * \brief Appel de la fonction glEnable ou glDisable en fonction de m_depthTest.
 */
void Figure::depthTest()
{
    Q_ASSERT(!m_noDepthTest);//Verifie que le widget qgldepthtest est activé/instancié
    if ( m_depthTest ) glEnable ( GL_DEPTH_TEST );
    else glDisable ( GL_DEPTH_TEST );
}

/**
 * \fn void Figure::depthMask()
 * \brief Appel de la fonction glEnable ou glDisable en fonction de m_depthMask.
 */
void Figure::depthMask()
{
    Q_ASSERT(!m_noDepthTest);//Verifie que le widget qgldepthtest est activé/instancié
    if ( m_depthMask ) glDepthMask(GL_TRUE);
    else glDepthMask(GL_FALSE);
}


/**
 * \fn void Figure::blend()
 * \brief Appel de la fonction glEnable ou glDisable en fonction de m_blend.
 */
void Figure::blend()
{
    Q_ASSERT(!m_noBlend);//Verifie que le widget qglblend est activé/instancié
    if ( m_blend ) glEnable ( GL_BLEND );
    else glDisable ( GL_BLEND );
}

/**
 * \fn void Figure::blendFunc ( )
 * \brief Permet de distinguer toute les possibilites de glBlendFunc. Cette fonction appel nécéssairement switchDst
 */
void Figure::blendFunc ( )
{
    Q_ASSERT(!m_noBlend);//Verifie que le widget qglblend est activé/instancié
    switch ( m_srcBlendFunc )
    {
    case GL_ZERO:
        switchDst ( GL_ZERO, m_dstBlendFunc );
        break;

    case GL_ONE:
        switchDst ( GL_ONE, m_dstBlendFunc );
        break;

    case GL_DST_COLOR:
        switchDst ( GL_DST_COLOR, m_dstBlendFunc );
        break;

    case GL_ONE_MINUS_DST_COLOR:
        switchDst ( GL_ONE_MINUS_DST_COLOR, m_dstBlendFunc );
        break;

    case GL_SRC_ALPHA:
        switchDst ( GL_SRC_ALPHA, m_dstBlendFunc );
        break;

    case GL_ONE_MINUS_SRC_ALPHA:
        switchDst ( GL_ONE_MINUS_SRC_ALPHA, m_dstBlendFunc );
        break;

    case GL_DST_ALPHA:
        switchDst ( GL_DST_ALPHA, m_dstBlendFunc );
        break;

    case GL_ONE_MINUS_DST_ALPHA:
        switchDst ( GL_ONE_MINUS_DST_ALPHA, m_dstBlendFunc );
        break;

    case GL_SRC_ALPHA_SATURATE:
        switchDst ( GL_SRC_ALPHA_SATURATE, m_dstBlendFunc );
        break;
    }
}

/**
 * \fn void Figure::switchDst ( int src, int dst )
 * \brief Appel de la fonction glBlendFunc en  fonction des parametres
 * \param src Facteur de source.
 * \param dst Facteur de destination.
 */
void Figure::switchDst ( int src, int dst )
{
    switch ( dst )
    {
    case GL_ZERO:
        glBlendFunc ( src, GL_ZERO );
        break;

    case GL_ONE:
        glBlendFunc ( src, GL_ONE );
        break;

    case GL_SRC_COLOR:
        glBlendFunc ( src, GL_SRC_COLOR );
        break;

    case GL_ONE_MINUS_SRC_COLOR:
        glBlendFunc ( src, GL_ONE_MINUS_SRC_COLOR );
        break;

    case GL_SRC_ALPHA:
        glBlendFunc ( src, GL_SRC_ALPHA );
        break;
    case GL_ONE_MINUS_SRC_ALPHA:
        glBlendFunc ( src, GL_ONE_MINUS_SRC_ALPHA );
        break;
    case GL_DST_ALPHA:
        glBlendFunc ( src, GL_DST_ALPHA );
        break;

    case GL_ONE_MINUS_DST_ALPHA:
        glBlendFunc ( src, GL_ONE_MINUS_DST_ALPHA );
        break;
    }
}

/**
 * \fn void Figure::blendEquation ( )
 * \brief Appel la fonction glBlendEquation avec la valeur adequate (definit en tant que membre m_blendEquation).
 */
void Figure::blendEquation ( )
{
    Q_ASSERT(!m_noBlend);//Verifie que le widget qglblend est activé/instancié
    switch ( m_blendEquation )
    {
    case GL_FUNC_ADD:
        glBlendEquation ( GL_FUNC_ADD );
        break;

    case GL_FUNC_SUBTRACT:
        glBlendEquation ( GL_FUNC_SUBTRACT );
        break;

    case GL_FUNC_REVERSE_SUBTRACT:
        glBlendEquation ( GL_FUNC_REVERSE_SUBTRACT );
        break;

    case GL_MIN:
        glBlendEquation ( GL_MIN );
        break;

    case GL_MAX:
        glBlendEquation ( GL_MAX );
        break;

    }
}

/**
 * \fn void Figure::switchCullFace ( bool flag )
 * \brief Prend en compte l'activation/desactivation du culling.
 * \param flag vrai/faux.
 */
void Figure::switchCullFace ( bool flag )
{
    m_cullFace=flag;
    emit figureChanged();
}

/**
 * \fn void Figure::switchDepthTest ( bool flag )
 * \brief Prend en compte l'activation/desactivation du buffer de profondeur.
 * \param flag vrai/faux.
 */
void Figure::switchDepthTest ( bool flag )
{
    m_depthTest=flag;
    emit figureChanged();
}

/**
 * \fn void Figure::switchDepthMask ( bool flag )
 * \brief Prend en compte le fonctionnement normal(lecture/ecriture) ou la lecture seul du buffer de profondeur.
 * \param flag vrai/faux.
 */
void Figure::switchDepthMask ( bool flag )
{
    m_depthMask=flag;
    emit figureChanged();
}

/**
 * \fn void Figure::switchBlend ( bool flag )
 * \brief Prend en compte l'activation/desactivation du blending.
 * \param flag vrai/faux.
 */
void Figure::switchBlend ( bool flag )
{
    m_blend=flag;
    emit figureChanged();
}

/**
 * \fn void Figure::switchBlendFunc ( int src , int dst )
 * \brief Prend en compte les nouveaux facteurs pour le rendu du blending.
 * \param src Facteur de source.
 * \param dst Facteur de destination.
 */
void Figure::switchBlendFunc ( int src , int dst )
{
    m_srcBlendFunc=src;
    m_dstBlendFunc=dst;
    emit figureChanged();
}

/**
 * \fn void Figure::switchBlendEquation ( int equ )
 * \brief Prend en compte le nouveau facteur d'equation.
 * \param equ Facteur d'equation.
 */
void Figure::switchBlendEquation ( int equ )
{
    m_blendEquation=equ;
    emit figureChanged();
}

void Figure::changeColor()
{
  m_dialogCodeVertex->setPalette(m_color->getQPalette());
}