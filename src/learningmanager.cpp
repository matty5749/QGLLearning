/**
 *\file learningmanager.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include <iostream>
#include "learningmanager.h"
#include "learningdoublequadblendinglessparam.h"
#include "learningdoublequadblendingfullparam.h"
#include "learningtriplequadblendinglessparam.h"
#include "learningtriplequadblendingfullparam.h"
#include "learningcubeblendinglessparam.h"
#include "learningcubeblendingfullparam.h"
#include "learningchoicewidget.h"
#include <QDockWidget>
#include <QHBoxLayout>

/**
 * \fn LearningManager::LearningManager(QWidget* parent)
 * \brief Construction des controlleurs de modelisation ( sous classe de Learning )
 * \details Les controlleurs de modelisation ( sous classe de Learning ) sont stockés dans un vecteur de Learning* afin de pouvoir naviguer entre chaque modelisation
 */
LearningManager::LearningManager(QDockWidget* dockWidget , QWidget* parent): QWidget(parent),m_dockWidget(dockWidget)
{
    m_mainLayout=new QHBoxLayout(this);

    /* Creation des themes */
    m_learningDoubleQuadBlendingLessParam=new LearningDoubleQuadBlendingLessParam;
    m_learningDoubleQuadBlendingFulParam=new LearningDoubleQuadBlendingFullParam;
    m_learningTripleQuadBlendingLessParam=new LearningTripleQuadBlendingLessParam;
    m_learningTripleQuadBlendingFullParam=new LearningTripleQuadBlendingFullParam;
    m_learningCubeBlendingLessParam=new LearningCubeBlendingLessParam;
    m_learningCubeBlendingFullParam=new LearningCubeBlendingFullParam;
    
    /* Enregistrement des themes dans le vecteur */
    m_learningVector.append(m_learningDoubleQuadBlendingLessParam);
    m_learningVector.append(m_learningDoubleQuadBlendingFulParam);
    m_learningVector.append(m_learningTripleQuadBlendingLessParam);
    m_learningVector.append(m_learningTripleQuadBlendingFullParam);
    m_learningVector.append(m_learningCubeBlendingLessParam);
    m_learningVector.append(m_learningCubeBlendingFullParam);
    
    /* Liste contenant le nom des themes du vecteur dans le même ordre et avec les mêmes index */
    QStringList list;
    for (QVector<Learning*>::const_iterator it=m_learningVector.constBegin();it!=m_learningVector.constEnd();it++)
    {
        list.append((*it)->getName());
    }

    /* Gestion du widget de choix de themes au seins de LearningChoiceWidget , lui même rattache à un QDockWidget de MainWindow */
    m_learningChoiceWidget = new LearningChoiceWidget(list);
    m_dockWidget->setWidget(m_learningChoiceWidget);

    /* Choix du theme par defaut */
    m_currentLearning=m_learningVector[0];
    m_mainLayout->addWidget(m_currentLearning);

    /* Connection */
    connect (m_learningChoiceWidget,SIGNAL(learningChanged(int)),this,SLOT(changeLearning(int)));
}

LearningManager::~LearningManager()
{
    for (QVector<Learning*>::iterator it=m_learningVector.begin();it!=m_learningVector.end();it++)
    {
        delete (*it);
    }
}


/**
 * \fn void LearningManager::changeLearning(int index)
 * \brief Permet de changer de theme lorsque l'utilisateur double clic sur l'un d'entre eux dans le QDockWidget
 */
void LearningManager::changeLearning(int index)
{
    m_currentLearning->setParent(0);
    m_currentLearning=m_learningVector[index];
    m_mainLayout->addWidget(m_currentLearning);
}
