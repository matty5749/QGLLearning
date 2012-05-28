/**
 *\file qglcolor.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLCLEARCOLOR_H
#define QGLCLEARCOLOR_H

#include "qglfunction4f.h"

#include "color4f.h"
/**
 * \class QGLClearColor
 * \brief Creer un widget permettant la gestion des couleurs du tampon de couleur lors de son effacement
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLClearColor : public QGLFunction4f
{
  Q_OBJECT
private:
    Color4f* m_color;
public:
    QGLClearColor(Color4f* color=0 , QWidget* parent = 0);
    ~QGLClearColor();
protected slots:
  void changeBackgroungColor();
signals:
  void qGLClearColorChanged();

};

#endif // QGLCLEARCOLOR_H
