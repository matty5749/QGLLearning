/**
 *\file qgldepthmask.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef QGLDEPTHMASK_H
#define QGLDEPTHMASK_H

#include "qglfunctionenabledisable.h"
/**
 * \class QGLDepthMask
 * \brief Creer un widget permettant la gestion du fonctionnement du tampon de profondeur (passage du mode lecture seule/au fonctionnement normal).
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLDepthMask : public QGLFunctionEnableDisable
{
public:
    QGLDepthMask(QWidget* parent = 0);

protected:
    virtual void switchText(bool);
};

#endif // QGLDEPTHMASK_H
