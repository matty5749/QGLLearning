/**
 *\file learningcubeblendingfullparam.cpp
 *\author Gaetan PICOT
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "learningcubeblendingfullparam.h"
#include <iostream>
#include "glcubeblendingfullparam.h"
#include "quad.h"
#include "qgldepthmask.h"
#include "qglclearcolor.h"

/**
 *\fn LearningCubeBlendingFullParam::LearningCubeBlendingFullParam(QWidget* parent)
 *\brief Construction des widgets necessaire à la relation avec la modelisation GLCubeBlendingFullParam
 */

LearningCubeBlendingFullParam::LearningCubeBlendingFullParam (GLCubeBlendingFullParam* modelisation , QWidget* parent): Learning(parent), m_glCubeBlendingFullParam(modelisation)
{
    m_hBox->setParent(this);

    m_glCubeBlendingFullParam=new GLCubeBlendingFullParam;
    m_splitter->addWidget(m_glCubeBlendingFullParam);
    
    m_qGLClearColor=new QGLClearColor(m_glCubeBlendingFullParam->m_backgroundColor);
    m_vBox->addWidget(m_qGLClearColor);
    m_vBox->addWidget(m_glCubeBlendingFullParam->m_cube->m_front->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingFullParam->m_cube->m_back->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingFullParam->m_cube->m_left->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingFullParam->m_cube->m_right->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingFullParam->m_cube->m_up->getDialogCode());
    m_vBox->addWidget(m_glCubeBlendingFullParam->m_cube->m_down->getDialogCode());
    
    m_qGLDepthMask=new QGLDepthMask();
    
    m_vBox->addWidget(m_qGLDepthMask);
    
    m_vBox->addStretch();

    m_blocCode->setWidget(m_conteneur);

    connect(m_qGLClearColor,SIGNAL(qGLClearColorChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    //CONNECTION QUAD
    connect(m_glCubeBlendingFullParam->m_cube->m_front,SIGNAL(quadChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    connect(m_glCubeBlendingFullParam->m_cube->m_back,SIGNAL(quadChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    connect(m_glCubeBlendingFullParam->m_cube->m_left,SIGNAL(quadChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    connect(m_glCubeBlendingFullParam->m_cube->m_right,SIGNAL(quadChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    connect(m_glCubeBlendingFullParam->m_cube->m_up,SIGNAL(quadChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    connect(m_glCubeBlendingFullParam->m_cube->m_down,SIGNAL(quadChanged()),m_glCubeBlendingFullParam,SLOT(update()));
    connect(m_qGLDepthMask,SIGNAL(switchChanged(bool)),m_glCubeBlendingFullParam,SLOT(switchDepthMask(bool)));
}

QString LearningCubeBlendingFullParam::getName() const
{
    QString name;
    name=tr("Learning cube blending full param");
    return name;
}
