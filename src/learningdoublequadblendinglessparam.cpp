/**
 *\file learningdoublequadblendinglessparam.cpp
 *\author Jean-Mathieu CHANTREIN
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "learningdoublequadblendinglessparam.h"
#include <iostream>
#include "gldoublequadblendinglessparam.h"

/**
 *\fn LearningDoubleQuadBlendingLessParam::LearningDoubleQuadBlendingLessParam(QWidget* parent)
 *\brief Construction des widgets necessaire à la relation avec la modelisation GLDoubleQuadBlendingLessParam
 */

LearningDoubleQuadBlendingLessParam::LearningDoubleQuadBlendingLessParam (GLDoubleQuadBlendingLessParam* modelisation , QWidget* parent): Learning(parent), m_glDoubleQuadBlendingLessParam(modelisation)
{
    m_hBox->setParent(this);

    m_glDoubleQuadBlendingLessParam=new GLDoubleQuadBlendingLessParam;
    m_splitter->addWidget(m_glDoubleQuadBlendingLessParam);

    m_vBox->addWidget(m_glDoubleQuadBlendingLessParam->m_quad1->getDialogCode());
    m_vBox->addWidget(m_glDoubleQuadBlendingLessParam->m_quad2->getDialogCode());
    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);

    //CONNECTION QUAD
    connect(m_glDoubleQuadBlendingLessParam->m_quad1,SIGNAL(quadChanged()),m_glDoubleQuadBlendingLessParam,SLOT(update()));
    connect(m_glDoubleQuadBlendingLessParam->m_quad2,SIGNAL(quadChanged()),m_glDoubleQuadBlendingLessParam,SLOT(update()));
}

QString LearningDoubleQuadBlendingLessParam::getName() const
{
    QString name;
    name=tr("Learning double quad blending less param");
    return name;
}
