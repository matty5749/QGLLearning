/**
 *\file learning.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "learning.h"
#include <QHBoxLayout>
#include <QSplitter>
#include <QVBoxLayout>
#include <QScrollArea>
#include "qglclearcolor.h"
#include "color4f.h"
#include "glwidget.h"

Learning::Learning(QWidget* parent): QWidget(parent)
{
    m_hBox=new QHBoxLayout(this);

    m_splitter=new QSplitter();
    m_hBox->addWidget(m_splitter);


    m_blocCode=new QScrollArea();
    m_blocCode->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

    m_conteneur=new QWidget(m_blocCode);

    m_splitter->addWidget(m_blocCode);

    m_vBox=new QVBoxLayout(m_conteneur);
}

