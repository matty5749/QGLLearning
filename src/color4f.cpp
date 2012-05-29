/**
 *\file color4f.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "color4f.h"
#include <QPalette>

Color4f::Color4f ( GLfloat r, GLfloat g, GLfloat b, GLfloat a ) :m_r ( r ),m_g ( g ),m_b ( b ),m_a ( a )
{

}

Color4f::~Color4f()
{

}


/**
 * \return Proportion de rouge.
 */
GLfloat Color4f::getR() const
{
    return m_r;
}
/**
 * \return Proportion de vert.
 */
GLfloat Color4f::getG() const
{
    return m_g;
}
/**
 * \return Proportion de bleu.
 */
GLfloat Color4f::getB() const
{
    return m_b;
}
/**
 * \return Composante alpha.
 */
GLfloat Color4f::getA() const
{
    return m_a;
}
/**
 * \fn QPalette Color4f::getQPalette() const
 * \return Une QPalette correspondant à la couleur , utile pour la coloration (background) des widgets.
 */
QPalette Color4f::getQPalette() const
{
  QColor color(m_r*255,m_g*255,m_b*255,m_a*255);
  return QPalette(color);
}


/**
 * \fn void Color4f::drawColor() const
 * \brief Utilise la fonction glColor4f(r,g,b,a) avec les r,g,b,a de l'instance de la classe.
 */
void Color4f::drawColor() const
{
    glColor4f ( m_r,m_g,m_b,m_a );
}

/**
 *\brief Change le membre m_r . Envoie le signal colorChanged.
 */
void Color4f::changeR ( int r )
{
    m_r=r/ ( float ) 100;
    emit colorChanged();
}

/**
  *\brief Change le membre m_g . Envoie le signal colorChanged.
  */
void Color4f::changeG ( int g )
{
    m_g=g/ ( float ) 100;
    emit colorChanged();
}

/**
 *\brief Change le membre m_b . Envoie le signal colorChanged.
 */
void Color4f::changeB ( int b )
{
    m_b=b/ ( float ) 100;
    emit colorChanged();
}

/**
 *\brief Change le membre m_a . Envoie le signal colorChanged.
 */
void Color4f::changeA ( int a )
{
    m_a=a/ ( float ) 100;
    emit colorChanged();
}
