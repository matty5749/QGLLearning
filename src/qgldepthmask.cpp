/**
 *\file qgldepthtest.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "qgldepthmask.h"
#include <QLabel>
#include "switchwidget.h"

QGLDepthMask::QGLDepthMask(QWidget* parent): QGLFunctionEnableDisable(parent)
{
    m_nameFunction->setText("glDepthMask(GL_TRUE);");
}

void QGLDepthMask::switchText(bool flag)
{
    if (flag) m_nameFunction->setText("glDepthMask(GL_TRUE);");/* fonctionnement normal*/
    else m_nameFunction->setText("glDepthMask(GL_FALSE);");/* lecture seule */
}
