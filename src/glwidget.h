/**
 *\file glwidget.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>
#include "GL/gl.h"

class Color4f;
/**
 *\class GLWidget
 *\brief Abstraite.Gere la modelisation et l'interaction avec la souris des scènes.Herite de QGLWidget http://qt-project.org/doc/qt-4.8/QGLWidget.html
 */
class GLWidget : public QGLWidget
{
    Q_OBJECT
protected:
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QPoint lastPos;
    
    bool m_depthMask;
    
public:
  /**
   * \details Tout le monde peut acceder a la couleur de fond, cela n'a aucune incidence , et cela evite l'utilisation systematique de friends
   */
    Color4f* m_backgroundColor;
public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    /**
      * \fn virtual void draw()=0;
      * \brief Dessine entierement la scene
      */
    virtual void draw()=0;
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void depthMask();
    void clearColor();

    protected slots:
      void switchDepthMask(bool);
      void update();
    
   };

#endif
