/**
 *\file qgldepthtest.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLDEPTHTEST_H
#define QGLDEPTHTEST_H

#include "qglfunctionenabledisable.h"
/**
 * \class QGLDepthTest
 * \brief Creer un widget permettant la gestion de la fonction glDepthTest.
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLDepthTest : public QGLFunctionEnableDisable
{
public:
    QGLDepthTest(QWidget* parent = 0);

protected:
    virtual void switchText(bool);
};

#endif // QGLDEPTHTEST_H
