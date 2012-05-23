/**
 *\file glwidget.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglblend.h"
#include <QLabel>

QGLBlend::QGLBlend(QWidget* parent): QGLFunctionEnableDisable(parent)
{
    m_nameFunction->setText("glEnable(GL_BLEND);");
}

void QGLBlend::switchText(bool flag)
{
    if (flag) m_nameFunction->setText("glEnable(GL_BLEND);");
    else m_nameFunction->setText("glDisable(GL_BLEND);");
}
