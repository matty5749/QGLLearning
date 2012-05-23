/**
 *\file qglblendfunc.h
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef QGLBLENDFUNC_H
#define QGLBLENDFUNC_H

#include "qglfunction2enum.h"

class QComboBox;
/**
 * \class QGLBlendFunc
 * \brief Creer un widget permettant la gestion de la fonction glBlendFunc
 * \details http://www.opengl.org/sdk/docs/man/
 */
class QGLBlendFunc : public QGLFunction2Enum
{
    Q_OBJECT
public:
    QGLBlendFunc ( QWidget* parent = 0);
private:
    int convertSrcToGLEnum(int);
    int convertDstToGLEnum(int);
protected slots:
    void changeSrc(int);
    void changeDst(int);
signals:
    void blendFuncChanged(int,int);
};

#endif // QGLBLENDFUNC_H
