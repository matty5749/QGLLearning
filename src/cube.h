/**
 *\file cube.h
 *\author Gaetan PICOT
 *\author Jean_Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef CUBE_H
#define CUBE_H

#include "figure.h"

class Quad;
class Vertex;
class LearningCubeBlendingLessParam;
class LearningCubeBlendingFullParam;
/**
 * \class Cube
 * \brief Creer des cubes en partant du principe que un cube est un assemblage de 6 Quad.
 */
class Cube : public Figure
{
private:
  
    Vertex *m_one;
    Vertex *m_two;
    Vertex *m_three;
    Vertex *m_four;
    Vertex *m_five;
    Vertex *m_six;
    Vertex *m_seven;
    Vertex *m_eight;
  
    Quad *m_front;
    Quad *m_back;
    Quad *m_left;;
    Quad *m_right;
    Quad *m_up;
    Quad *m_down;
    
public:

    Cube(Vertex* base, GLfloat size, bool lessParam);
    ~Cube();
    virtual void drawFigure();
    virtual QDialog* getDialogCode();
    

friend class LearningCubeBlendingLessParam;
friend class LearningCubeBlendingFullParam;
};

#endif // CUBE_H
