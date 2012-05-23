/**
 *\file qglcullface.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLCULLFACE_H
#define QGLCULLFACE_H

#include "qglfunctionenabledisable.h"

/**
 * \class QGLCullFace
 * \brief Creer un widget permettant la gestion de la fonction glCullFace
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLCullFace : public QGLFunctionEnableDisable
{
public:
    QGLCullFace(QWidget* parent = 0);
protected:
    virtual void switchText(bool);
    



};

#endif // QGLCULLFACE_H
