/**
 *\file color4f.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef COLOR4F_H
#define COLOR4F_H

#include <qobject.h>
#include <GL/gl.h>

/**
 * \class Color4f
 * \brief Structure une couleur pouvant etre manipuler par la fonction glColor4f.Prend en compte la composante alpha.
 * \details Voir la documentation openGL2.1 pour plus d'information http://www.opengl.org/sdk/docs/man/
 */

class QPalette;
class Color4f : public QObject
{
    Q_OBJECT
private:
    GLfloat m_r;
    GLfloat m_g;
    GLfloat m_b;
    GLfloat m_a;
public:
    Color4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    GLfloat getR() const;
    GLfloat getG() const;
    GLfloat getB() const;
    GLfloat getA() const;
    QPalette getQPalette() const;
    void drawColor() const;

protected slots:
    void changeR(int);
    void changeG(int);
    void changeB(int);
    void changeA(int);

signals:
    /**
     *\brief Est envoyé dès que l'un des membres de la classe change.
     */
    void colorChanged();

};

#endif // COLOR4F_H
