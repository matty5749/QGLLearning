/**
 *\file qglfunctionenabledisable.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLFUNCTIONENABLEDISABLE_H
#define QGLFUNCTIONENABLEDISABLE_H

#include "qglfunction.h"

class SwitchWidget;
/**
 * \class QGLFunctionEnableDisable
 * \brief Permet la gestion des fonctions openGL glEnable et glDisable
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLFunctionEnableDisable : public QGLFunction
{
    Q_OBJECT
protected:
    SwitchWidget* m_switch;
public:
    QGLFunctionEnableDisable(QWidget* parent = 0);

protected:
    virtual void switchText(bool flag)=0;
    void setSwitch(bool);

protected slots:
    void switchBool(bool);

signals:
    void switchChanged(bool);

};

#endif // QGLFUNCTIONENABLEDISABLE_H
