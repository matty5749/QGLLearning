/**
 *\file qglfunction.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef QGLFUNCTION_H
#define QGLFUNCTION_H

#include <QDialog>

class QHBoxLayout;
class QLabel;
/**
 * \class QGLFunction
 * \brief Classe mère de tout les widgets prefixés par QGL________ .Herite de QDialog
 */
class QGLFunction : public QDialog
{
protected:
    QLabel* m_nameFunction;
    QHBoxLayout* m_hbox;
public:
    QGLFunction(QWidget* parent = 0);

};

#endif // QGLFUNCTION_H
