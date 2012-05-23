/**
 *\file qglcullface.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglcullface.h"
#include <QLabel>

QGLCullFace::QGLCullFace(QWidget* parent): QGLFunctionEnableDisable(parent)
{
    m_nameFunction->setText("glDisable(GL_CULL_FACE);");
    setSwitch(false);
}


void QGLCullFace::switchText(bool flag)
{
    if (flag) m_nameFunction->setText("glEnable(GL_CULL_FACE);");
    else m_nameFunction->setText("glDisable(GL_CULL_FACE);");
}
