/**
 *\file learningquadblending.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "learningquadblending.h"
#include <iostream>
#include "glquadblending.h"
#include "qglclearcolor.h"

/**
 *\fn LearningQuadBlending::LearningQuadBlending(QWidget* parent)
 *\brief Construction des widgets necessaire à la relation avec la modelisation GLQuadBlending
 */

LearningQuadBlending::LearningQuadBlending (GLQuadBlending* modelisation , QWidget* parent): Learning(parent), m_glQuadBlending(modelisation)
{
    m_hBox->setParent(this);

    m_glQuadBlending=new GLQuadBlending;
    m_splitter->addWidget(m_glQuadBlending);

    m_qGLClearColor=new QGLClearColor(m_glQuadBlending->m_backgroundColor);
    m_vBox->addWidget(m_qGLClearColor);
    
    m_vBox->addWidget(m_glQuadBlending->m_quad1->getDialogCode());

    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);
    

    connect(m_qGLClearColor,SIGNAL(qGLClearColorChanged()),m_glQuadBlending,SLOT(update()));
    //CONNECTION QUAD
    connect(m_glQuadBlending->m_quad1,SIGNAL(quadChanged()),m_glQuadBlending,SLOT(update()));
}

QString LearningQuadBlending::getName() const
{
    QString name;
    name=tr("Learning  quad blending");
    return name;
}
