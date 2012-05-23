/**
 *\file cube.cpp
 *\author Gaetan PICOT
 *\author Jean_Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "cube.h"

#include "quad.h"
#include "vertex.h"
#include "qglcullface.h"
#include "switchwidget.h"

/**
 *\fn Cube::Cube(Vertex* base, GLfloat size, bool lessParam)
 *\param base represente le vertex a partir duquel on dessinera le cube :c'est le coin inferieur gauche de la face de devant
 *\param size represente la taille arrete du cube
 *\param lessParam variable booleenne = vrai si l'on souhaite un cube en lessParam. =faux si l'on souhaite un cube en fullParam
 */
Cube::Cube(Vertex* base, GLfloat size, bool lessParam):Figure(1,1,1,1)
{
    Vertex *one = new Vertex(base->getX(), base->getY(), base->getZ());
    Vertex *two = new Vertex(base->getX() + size, base->getY(), base->getZ());
    Vertex *three = new Vertex(base->getX() + size, base->getY() + size, base->getZ());
    Vertex *four = new Vertex(base->getX(), base->getY() + size , base->getZ());
    Vertex *five = new Vertex(base->getX(), base->getY(), base->getZ() - size);
    Vertex *six = new Vertex(base->getX(), base->getY() + size, base->getZ() - size);
    Vertex *seven = new Vertex(base->getX() + size, base->getY() + size, base->getZ() - size);
    Vertex *eight = new Vertex(base->getX() + size, base->getY(), base->getZ() - size);

    if (lessParam)
    {
        m_front = new Quad(0.8,0.4,0.2,1.0, one, two, three, four, true);
        m_back = new Quad(0.2,0.4,0.8,0.5, five, six, seven, eight, false, false, false, false);
        m_left = new Quad(0.8,0.2,0.4,0.5, one, four, six ,five, false, false, false, false);
        m_right = new Quad(0.2,0.8,0.4,0.5, two, eight, seven, three, false, false, false, false);
        m_up = new Quad(1,0.0,0.0,0.5, four, three, seven, six, false, false, false, false);
        m_down = new Quad(1,1,0.0,0.5, one, five, eight, two, false, false, false, false);
    }
    else
    {
        m_front = new Quad(0.8,0.4,0.2,1.0, one, two, three, four, true);
        m_back = new Quad(0.2,0.4,0.8,0.5, five, six, seven, eight, true);
        m_left = new Quad(0.8,0.2,0.4,0.5, one, four, six ,five, true);
        m_right = new Quad(0.2,0.8,0.4,0.5, two, eight, seven, three, true);
        m_up = new Quad(1,0.0,0.0,0.5, four, three, seven, six, true);
        m_down = new Quad(1,1,0.0,0.5, one, five, eight, two, true);
    }
}

void Cube::drawFigure()
{
    //MODELISATION
    m_front->drawFigure();
    m_back->drawFigure();
    m_left->drawFigure();
    m_right->drawFigure();
    m_up->drawFigure();
    m_down->drawFigure();
}

/**
 * \fn QDialog* Cube::getDialogCode()
 * \brief N'est jamais appelé , est implanté afin de pouvoir instancier la classe.Virtuelle pure sinon
 */
QDialog* Cube::getDialogCode()
{
  return 0;
}
