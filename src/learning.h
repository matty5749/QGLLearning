/**
 *\file learning.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNING_H
#define LEARNING_H

class QSplitter;
class QHBoxLayout;
class QScrollArea;
class QVBoxLayout;

#include <QWidget>
/**
 * \class Learning
 * \brief Abstraite.Permet la creation d'un vecteur de Learning* dans LearningManager afin de pouvoir stocker les différents types de scenes (les classes filles) dans un conteneur et de les manipuler lors
 * de l'utilisation du programme.
 * Les classes filles permettent de construire une modelisation (sous classes de GLWidget ) et de gerer l'affichage de celle-ci
 *
 */
class Learning : public QWidget
{
protected:
    QSplitter* m_splitter;
    QHBoxLayout* m_hBox;
    QVBoxLayout* m_vBox;
    QScrollArea* m_blocCode;
    QWidget* m_conteneur;
public:
    Learning(QWidget* parent = 0);
    virtual QString getName() const = 0 ;
};

#endif // LEARNING_H
