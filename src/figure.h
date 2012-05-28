/**
 *\file figure.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef FIGURE_H
#define FIGURE_H

#include <GL/gl.h>
#include <QObject>
#include "color4f.h"

class QVBoxLayout;
class QGLCullFace;
class QGLDepthTest;
class QGLDepthMask;
class QGLBlend;
class QGLBlendFunc;
class QGLBlendEquation;
class QDialog;

/**
 *\class Figure
 *\brief Abstraite.Classe mère de toutes les figures.
 *\details On peut avoir la main(ou non , depend de l'instanciation du constructeur) sur le cullFace , le depthTest et le blending.
 *Si on peut avoir la main sur le blending , on  a aussi la main sur BlendFunc et BlendEquation
 */
class Figure : public QObject
{
    Q_OBJECT
protected:
    Color4f* m_color;

    bool m_depthMaskWidget;
    bool m_cullFaceWidget;
    bool m_depthTestWidget;
    bool m_blendWidget;
    

    bool m_depthMask;
    bool m_cullFace;
    bool m_depthTest;
    bool m_blend;

    bool m_noCullFace;
    bool m_noDepthTest;
    bool m_noBlend;

    int m_srcBlendFunc;
    int m_dstBlendFunc;
    int m_blendEquation;

    QDialog* m_dialogCodeVertex;

    QVBoxLayout *m_vbox;

    QGLCullFace* m_qGLCullFace;
    QGLDepthTest* m_qGLDepthTest;
    QGLDepthMask *m_qGLDepthMask;
    QGLBlend* m_qGLBlend;
    QGLBlendFunc* m_qGLBlendFunc;
    QGLBlendEquation* m_qGLBlendEquation;

public:
    Figure(GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool depthMaskWidget = false, bool cullFaceWidget = true, bool depthTestWidget = true, bool blendWidget = true);
    ~Figure();
    /**
     * \fn virtual void drawFigure()=0;
     * \brief Methode a definir dans les sous classes de Figure.Permet de dessiner la figure.
     */
    virtual void drawFigure()=0;

private:
    /**
     * \fn virtual QDialog* getDialogCode()=0;
     * \brief Methode a definir dans les sous classes de Figure.Permet d'envoyer une QDialog qui communique avec la figure.Methode appelé par une sous classe de Learning .
     */
    virtual QDialog* getDialogCode()=0;

protected:
    void cullFace();
    void depthTest();
    void depthMask();
    void blend();
    void blendFunc();
    void blendEquation();
    void switchDst(int src, int dst);

protected slots:
    void switchCullFace(bool);
    void switchDepthTest(bool);
    void switchBlend(bool);
    void switchDepthMask(bool);
    void switchBlendFunc(int,int);
    void switchBlendEquation(int);
    void changeColor();

signals:
    void figureChanged();

};

#endif // FIGURE_H
