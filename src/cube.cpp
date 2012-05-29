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
    m_one = new Vertex(base->getX(), base->getY(), base->getZ());
    m_two = new Vertex(base->getX() + size, base->getY(), base->getZ());
    m_three = new Vertex(base->getX() + size, base->getY() + size, base->getZ());
    m_four = new Vertex(base->getX(), base->getY() + size , base->getZ());
    m_five = new Vertex(base->getX(), base->getY(), base->getZ() - size);
    m_six = new Vertex(base->getX(), base->getY() + size, base->getZ() - size);
    m_seven = new Vertex(base->getX() + size, base->getY() + size, base->getZ() - size);
    m_eight = new Vertex(base->getX() + size, base->getY(), base->getZ() - size);

    if (lessParam)
    {
        m_front = new Quad(0.8,0.4,0.2,1.0, m_one, m_two, m_three, m_four, true);
        m_back = new Quad(0.2,0.4,0.8,0.5, m_five, m_six, m_seven, m_eight, false, false, false, false);
        m_left = new Quad(0.8,0.2,0.4,0.5, m_one, m_four, m_six ,m_five, false, false, false, false);
        m_right = new Quad(0.2,0.8,0.4,0.5, m_two, m_eight, m_seven, m_three, false, false, false, false);
        m_up = new Quad(1,0.0,0.0,0.5, m_four, m_three, m_seven, m_six, false, false, false, false);
        m_down = new Quad(1,1,0.0,0.5, m_one, m_five, m_eight, m_two, false, false, false, false);
    }
    else
    {
        m_front = new Quad(0.8,0.4,0.2,1.0, m_one, m_two, m_three, m_four, true);
        m_back = new Quad(0.2,0.4,0.8,0.5, m_five, m_six, m_seven, m_eight, true);
        m_left = new Quad(0.8,0.2,0.4,0.5, m_one, m_four, m_six ,m_five, true);
        m_right = new Quad(0.2,0.8,0.4,0.5, m_two, m_eight, m_seven, m_three, true);
        m_up = new Quad(1,0.0,0.0,0.5, m_four, m_three, m_seven, m_six, true);
        m_down = new Quad(1,1,0.0,0.5, m_one, m_five, m_eight, m_two, true);
    }
}

Cube::~Cube()
{
 /*On detruit les vertex ici afin d'eviter de vouloir detruire plusieurs fois le meme objet , ce qui est le cas ici , un sommet est concerné par 3 Quad */ 
 delete m_one;m_one=NULL;
 delete m_two;m_two=NULL;
 delete m_three;m_three=NULL;
 delete m_four;m_four=NULL;
 delete m_five;m_five=NULL;
 delete m_six;m_six=NULL;
 delete m_seven;m_seven=NULL;
 delete m_eight;m_eight=NULL;
 
 delete m_front;
 delete m_back;
 delete m_down;
 delete m_left;
 delete m_right;
 delete m_up;
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
