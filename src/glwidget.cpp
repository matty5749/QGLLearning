/**
 *\file glwidget.cpp
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "glwidget.h"
#include "color4f.h"
/**
 * \fn GLWidget::GLWidget ( QWidget *parent )
 * \brief Construit la base des modelisations à venir en sous classes
 */
GLWidget::GLWidget ( QWidget *parent ) : QGLWidget ( parent ),rotationX ( 0 ),rotationY ( 0 ),rotationZ ( 0 ),m_depthMask(true)
{
    m_backgroundColor=new Color4f(0,0,0,0);
    setSizePolicy ( QSizePolicy::Minimum,QSizePolicy::Minimum );
    setMinimumSize ( topLevelWidget()->width(),topLevelWidget()->height() );
    setFormat ( QGLFormat ( QGL::DoubleBuffer | QGL::DepthBuffer ) );
}

/**
 * \fn void GLWidget::initializeGL()
 * \brief Initialisation de la scene
 */
void GLWidget::initializeGL()
{
    glShadeModel ( GL_FLAT );
    glEnable ( GL_DEPTH_TEST );
}

/**
 * \fn void GLWidget::resizeGL
 * \brief Cette fonction est appelé lors d'un redimensionnement du widget.Elle recalcule les rapports en fonction des parametres width et height.Equivalent de resize (Qt).
 */
void GLWidget::resizeGL ( int width, int height )
{
    glViewport ( 0, 0, width, height );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity();
    GLfloat x = GLfloat ( width ) / height;
    glFrustum ( -x, x, -1.0, 1.0, 4.0, 15.0 );
    glMatrixMode ( GL_MODELVIEW );
}

/**
 * \fn void GLWidget::paintGL()
 * \brief Dessine la scene.Equivalent de paint (Qt).
 */
void GLWidget::paintGL()
{
    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    clearColor();
    draw();
}

/**
 * \fn void GLWidget::mousePressEvent ( QMouseEvent *event )
 * \brief Gestion du clic de la souris
 */
void GLWidget::mousePressEvent ( QMouseEvent *event )
{
    lastPos = event->pos();
}

/**
 * \fn void GLWidget::mouseMoveEvent  ( QMouseEvent *event )
 * \brief Gestion de la souris en mouvement.
 */
void GLWidget::mouseMoveEvent ( QMouseEvent *event )
{
    GLfloat dx = GLfloat ( event->x() - lastPos.x() );
    GLfloat dy = GLfloat ( event->y() - lastPos.y() );

    if ( event->buttons() & Qt::LeftButton )
    {
        rotationX +=dy;
        rotationY +=dx;
    }
    else if ( event->buttons() & Qt::RightButton )
    {
        rotationZ -= dx;
    }

    updateGL();
    lastPos = event->pos();
}

/**
 * \fn void GLWidget::depthMask()
 * \brief Appel de la fonction  glDepthMask() avec GL_TRUE ou GL_FALSE.
 */
void GLWidget::depthMask()
{
if ( m_depthMask ) glDepthMask(GL_TRUE);
    else glDepthMask(GL_FALSE);
}

/**
 * \fn void GLWidget::clearColor()
 * \brief Appel de la fonction  glClearColor()
 */
void GLWidget::clearColor()
{
 glClearColor(m_backgroundColor->getR(),m_backgroundColor->getG(),m_backgroundColor->getB(),m_backgroundColor->getA());
}


/**
 * \fn void GLWidget::switchDepthMask(bool flag)
 * \brief Prend en compte l'activation/desactivation du depthMask.
 * \param flag vrai/faux.
 */
void GLWidget::switchDepthMask(bool flag)
{
  m_depthMask=flag;
  updateGL();
}

/**
 * \fn void GLWidget::update()
 * \brief Redessine la scene.
 */
void GLWidget::update()
{
    updateGL();
}
