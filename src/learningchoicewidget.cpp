/**
 *\file learningchoicewidget.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#include "learningchoicewidget.h"

#include <iostream>

#include <qstringlistmodel.h>
#include <QHBoxLayout>
#include <QListView>
#include <QPushButton>
/**
 * \fn LearningChoiceWidget::LearningChoiceWidget(const QStringList& learningList, QWidget* parent)
 * \brief Construit une liste de theme dans lesquels on peut interragir par le biais du signal doubleClicked de QListView
 * \details Est prevu d'etre le fils (pas au sens objet) d'un QDockWidget.
 */
LearningChoiceWidget::LearningChoiceWidget(const QStringList& learningList, QWidget* parent): QDialog(parent)
{	
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    m_model = new QStringListModel(this);
    m_model->setStringList(learningList);

    m_listView = new QListView;
    m_listView->setModel(m_model);
    m_listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_vbox = new QVBoxLayout(this);
    m_vbox->addWidget(m_listView);

    connect(m_listView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(learningChoiceChanged(QModelIndex)));
}

/**
 * \fn void LearningChoiceWidget::learningChoiceChanged(QModelIndex index)
 * \brief Envoie le signal learningChanged lorsque il y a eu un doubleClicked.Signal prevu pour la classe LearningManager.
 */
void LearningChoiceWidget::learningChoiceChanged(QModelIndex index)
{
    emit learningChanged(index.row());
}
