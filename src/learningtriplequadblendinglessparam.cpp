/**
 *\file learningtriplequadblendinglessparam.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "learningtriplequadblendinglessparam.h"
#include "gltriplequadblendinglessparam.h"

/**
 *\fn LearningTripleQuadBlendingLessParam::LearningTripleQuadBlendingLessParam(QWidget* parent, Qt::WindowFlags f, GLTripleQuadBlendingLessParam* modelisation)
 *\brief Construction de tout les widgets necessaire ET en relation avec la modelisation GLTripleQuadBlendingLessParam
 */
LearningTripleQuadBlendingLessParam::LearningTripleQuadBlendingLessParam(QWidget* parent): Learning(parent)
{
    m_hBox->setParent(this);//Recuperation du layout de la classe mere Figure

    m_glTripleQuadBlendingLessParam=new GLTripleQuadBlendingLessParam;
    m_splitter->addWidget(m_glTripleQuadBlendingLessParam);


    m_vBox->addWidget(m_glTripleQuadBlendingLessParam->m_quad1->getDialogCode());
    m_vBox->addWidget(m_glTripleQuadBlendingLessParam->m_quad2->getDialogCode());
    m_vBox->addWidget(m_glTripleQuadBlendingLessParam->m_quad3->getDialogCode());
    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);

    //CONNECTION QUAD
    connect(m_glTripleQuadBlendingLessParam->m_quad1,SIGNAL(quadChanged()),m_glTripleQuadBlendingLessParam,SLOT(update()));
    connect(m_glTripleQuadBlendingLessParam->m_quad2,SIGNAL(quadChanged()),m_glTripleQuadBlendingLessParam,SLOT(update()));
    connect(m_glTripleQuadBlendingLessParam->m_quad3,SIGNAL(quadChanged()),m_glTripleQuadBlendingLessParam,SLOT(update()));
}

QString LearningTripleQuadBlendingLessParam::getName() const
{
    QString name;
    name=tr("Learning triple quad blending less param");
    return name;
}
