/**
 *\file learningcubeblendinglessparam.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "learningcubeblendinglessparam.h"
#include <iostream>
#include "glcubeblendinglessparam.h"
#include "quad.h"
#include "qglclearcolor.h"

/**
 *\fn LearningCubeBlendingLessParam::LearningCubeBlendingLessParam(QWidget* parent)
 *\brief Construction des widgets necessaire à la relation avec la modelisation GLCubeBlendingLessParam
 */

LearningCubeBlendingLessParam::LearningCubeBlendingLessParam (GLCubeBlendingLessParam* modelisation , QWidget* parent): Learning(parent), m_glCubeBlendingLessParam(modelisation)
{
    m_hBox->setParent(this);

    m_glCubeBlendingLessParam=new GLCubeBlendingLessParam;
    m_splitter->addWidget(m_glCubeBlendingLessParam);
  
    m_qGLClearColor=new QGLClearColor(m_glCubeBlendingLessParam->m_backgroundColor);
    m_vBox->addWidget(m_qGLClearColor);
    m_vBox->addWidget(m_glCubeBlendingLessParam->m_cube->m_front->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingLessParam->m_cube->m_back->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingLessParam->m_cube->m_left->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingLessParam->m_cube->m_right->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingLessParam->m_cube->m_up->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingLessParam->m_cube->m_down->getDialogCode());
    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);

     connect(m_qGLClearColor,SIGNAL(qGLClearColorChanged()),m_glCubeBlendingLessParam,SLOT(update()));
    //CONNECTION QUAD
    connect(m_glCubeBlendingLessParam->m_cube->m_front,SIGNAL(quadChanged()),m_glCubeBlendingLessParam,SLOT(update()));
    connect(m_glCubeBlendingLessParam->m_cube->m_back,SIGNAL(quadChanged()),m_glCubeBlendingLessParam,SLOT(update()));
    connect(m_glCubeBlendingLessParam->m_cube->m_left,SIGNAL(quadChanged()),m_glCubeBlendingLessParam,SLOT(update()));
    connect(m_glCubeBlendingLessParam->m_cube->m_right,SIGNAL(quadChanged()),m_glCubeBlendingLessParam,SLOT(update()));
    connect(m_glCubeBlendingLessParam->m_cube->m_up,SIGNAL(quadChanged()),m_glCubeBlendingLessParam,SLOT(update()));
    connect(m_glCubeBlendingLessParam->m_cube->m_down,SIGNAL(quadChanged()),m_glCubeBlendingLessParam,SLOT(update()));
}

LearningCubeBlendingLessParam::~LearningCubeBlendingLessParam()
{
 delete m_glCubeBlendingLessParam;
}


QString LearningCubeBlendingLessParam::getName() const
{
    QString name;
    name=tr("Learning cube blending less param");
    return name;
}
