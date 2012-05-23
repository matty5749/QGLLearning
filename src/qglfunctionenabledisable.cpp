/**
 *\file qglfunctionenabledisable.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "qglfunctionenabledisable.h"

#include <iostream>
#include <QLabel>
#include "switchwidget.h"
#include <QHBoxLayout>

QGLFunctionEnableDisable::QGLFunctionEnableDisable(QWidget* parent): QGLFunction(parent)
{
    m_hbox->setParent(this);
    m_switch=new SwitchWidget(this);

    m_hbox->addWidget(m_switch);

    connect(m_switch,SIGNAL(switchChanged(bool)),this,SLOT(switchBool(bool)));
}

void QGLFunctionEnableDisable::setSwitch(bool flag)
{
    m_switch->m_flag=flag;
}

void QGLFunctionEnableDisable::switchBool(bool flag)
{
    switchText(flag);
    emit switchChanged(flag);
}
