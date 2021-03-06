/**
 *\file learningdoublequadblendinglessparam.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "learningdoublequadblendingfullparam.h"
#include <iostream>
#include "gldoublequadblendingfullparam.h"
#include "qglclearcolor.h"

/**
 *\fn LearningDoubleQuadBlendingFullParam::LearningDoubleQuadBlendingFullParam(QWidget* parent)
 *\brief Construction des widgets necessaire à la relation avec la modelisation GLDoubleQuadBlendingFullParam
 */

LearningDoubleQuadBlendingFullParam::LearningDoubleQuadBlendingFullParam (GLDoubleQuadBlendingFullParam* modelisation , QWidget* parent): Learning(parent), m_glDoubleQuadBlendingFullParam(modelisation)
{
    m_hBox->setParent(this);

    m_glDoubleQuadBlendingFullParam=new GLDoubleQuadBlendingFullParam;
    m_splitter->addWidget(m_glDoubleQuadBlendingFullParam);

    m_qGLClearColor=new QGLClearColor(m_glDoubleQuadBlendingFullParam->m_backgroundColor);
    m_vBox->addWidget(m_qGLClearColor);
    m_vBox->addWidget(m_glDoubleQuadBlendingFullParam->m_quad1->getDialogCode());
    m_vBox->addWidget(m_glDoubleQuadBlendingFullParam->m_quad2->getDialogCode());
    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);

    connect(m_qGLClearColor,SIGNAL(qGLClearColorChanged()),m_glDoubleQuadBlendingFullParam,SLOT(update()));
    //CONNECTION QUAD
    connect(m_glDoubleQuadBlendingFullParam->m_quad1,SIGNAL(quadChanged()),m_glDoubleQuadBlendingFullParam,SLOT(update()));
    connect(m_glDoubleQuadBlendingFullParam->m_quad2,SIGNAL(quadChanged()),m_glDoubleQuadBlendingFullParam,SLOT(update()));
}

LearningDoubleQuadBlendingFullParam::~LearningDoubleQuadBlendingFullParam()
{
  delete m_glDoubleQuadBlendingFullParam;
}


QString LearningDoubleQuadBlendingFullParam::getName() const
{
    QString name;
    name=tr("Learning double quad blending full param");
    return name;
}
