#include "gltriplequadblendinglessparam.h"
#include "vertex.h"

GLTripleQuadBlendingLessParam::GLTripleQuadBlendingLessParam(QWidget* parent): GLWidget(parent)
{
    Vertex* one = new Vertex(0, 0, 0);
    Vertex* two = new Vertex(1, 0, 0);
    Vertex* three = new Vertex(1, 1, 0);
    Vertex* four = new Vertex(0, 1, 0);

    Vertex* five = new Vertex(0.5, 0.5, 0.5);
    Vertex* six = new Vertex(1.5, 0.5, 0.5);
    Vertex* seven = new Vertex(1.5, 1.5, 0.5);
    Vertex* eight = new Vertex(0.5, 1.5, 0.5);

    Vertex* nine = new Vertex(0.5, 0.0, 1.0);
    Vertex* ten = new Vertex(1.5, 0.0, 1.0);
    Vertex* eleven = new Vertex(1.5, 1.0, 1.0);
    Vertex *twelve = new Vertex(0.5, 1.0, 1.0);

    m_quad1 = new Quad(0.0, 0.0, 0.99, 0.5, one, two, three, four);
    m_quad2 = new Quad(0.99, 0.0, 0.0, 0.5, five, six, seven, eight, false, false, false, false);
    m_quad3 = new Quad(0.0, 0.99, 0.0, 0.5, nine, ten, eleven, twelve, false, false, false, false);
}

GLTripleQuadBlendingLessParam::~GLTripleQuadBlendingLessParam()
{
    delete m_quad1;
    delete m_quad2;
    delete m_quad3;
}


void GLTripleQuadBlendingLessParam::draw()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);

    //MODELISATION
    m_quad1->drawFigure();
    m_quad2->drawFigure();
    m_quad3->drawFigure();
}

