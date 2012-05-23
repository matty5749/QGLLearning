/**
 *\file qglblendequation.h
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef QGLBLENDEQUATION_H
#define QGLBLENDEQUATION_H

#include "qglfunctionenum.h"

class QComboBox;
/**
 * \class QGLBlendEquation
 * \brief Creer un widget permettant la gestion de la fonction glBlendEquation
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLBlendEquation : public QGLFunctionEnum
{
    Q_OBJECT
public:
    QGLBlendEquation ( QWidget* parent = 0);
private:
    int convertEquToGLEnum(int);
protected slots:
    void changeEqu(int);
signals:
    void blendEquationChanged(int);
};

#endif // QGLBLENDEQUATION_H
