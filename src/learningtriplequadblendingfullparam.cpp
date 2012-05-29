/**
 *\file learningtriplequadblendingfullparam.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "learningtriplequadblendingfullparam.h"
#include "gltriplequadblendingfullparam.h"
#include "qglclearcolor.h"

/**
 *\fn LearningTripleQuadBlendingFullParam::LearningTripleQuadBlendingFullParam(QWidget* parent, Qt::WindowFlags f, GLTripleQuadBlendingFullParam* modelisation)
 *\brief Construction de tout les widgets necessaire ET en relation avec la modelisation GLTripleQuadBlendingFullParam
 */
LearningTripleQuadBlendingFullParam::LearningTripleQuadBlendingFullParam(QWidget* parent): Learning(parent)
{
    m_hBox->setParent(this);//Recuperation du layout de la classe mere Figure

    m_glTripleQuadBlendingFullParam=new GLTripleQuadBlendingFullParam;
    m_splitter->addWidget(m_glTripleQuadBlendingFullParam);

    m_qGLClearColor=new QGLClearColor(m_glTripleQuadBlendingFullParam->m_backgroundColor);
    m_vBox->addWidget(m_qGLClearColor);
    m_vBox->addWidget(m_glTripleQuadBlendingFullParam->m_quad1->getDialogCode());
    m_vBox->addWidget(m_glTripleQuadBlendingFullParam->m_quad2->getDialogCode());
    m_vBox->addWidget(m_glTripleQuadBlendingFullParam->m_quad3->getDialogCode());
    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);

    connect(m_qGLClearColor,SIGNAL(qGLClearColorChanged()),m_glTripleQuadBlendingFullParam,SLOT(update()));
    //CONNECTION QUAD
    connect(m_glTripleQuadBlendingFullParam->m_quad1,SIGNAL(quadChanged()),m_glTripleQuadBlendingFullParam,SLOT(update()));
    connect(m_glTripleQuadBlendingFullParam->m_quad2,SIGNAL(quadChanged()),m_glTripleQuadBlendingFullParam,SLOT(update()));
    connect(m_glTripleQuadBlendingFullParam->m_quad3,SIGNAL(quadChanged()),m_glTripleQuadBlendingFullParam,SLOT(update()));
}

QString LearningTripleQuadBlendingFullParam::getName() const
{
    QString name;
    name=tr("Learning triple quad blending full param");
    return name;
}
