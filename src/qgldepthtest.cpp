/**
 *\file qgldepthtest.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qgldepthtest.h"
#include <QLabel>
#include "switchwidget.h"

QGLDepthTest::QGLDepthTest(QWidget* parent): QGLFunctionEnableDisable(parent)
{
    m_nameFunction->setText("glEnable(GL_DEPTH_TEST);");
}

void QGLDepthTest::switchText(bool flag)
{
    if (flag) m_nameFunction->setText("glEnable(GL_DEPTH_TEST);");
    else m_nameFunction->setText("glDisable(GL_DEPTH_TEST);");
}
