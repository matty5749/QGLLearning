/**
 *\file glwidget.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef QGLBLEND_H
#define QGLBLEND_H
#include "qglfunctionenabledisable.h"
/**
 * \class QGLBlend
 * \brief Creer un widget permettant la gestion de la fonction glBlend
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLBlend : public QGLFunctionEnableDisable
{
public:
    QGLBlend(QWidget* parent = 0);

protected:
    virtual void switchText(bool flag);
};

#endif // QGLBLEND_H
