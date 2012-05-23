/**
 *\file learningchoicewidget.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGCHOICEWIDGET_H
#define LEARNINGCHOICEWIDGET_H


#include <QDialog>
#include <qabstractitemmodel.h>

class QListView;
class QStringListModel;
class QVBoxLayout;

/**
 * \class LearningChoiceWidget
 * \brief Permet de choisir un theme parmi une liste (de theme) qui correspond à m_learningVector dans LearningManager
 */

class LearningChoiceWidget : public QDialog
{
    Q_OBJECT

private:
    QListView *m_listView;
    QStringListModel *m_model;
    QVBoxLayout *m_vbox;

public:
    LearningChoiceWidget(const QStringList &learningList, QWidget *parent = 0);

private slots:
    void learningChoiceChanged(QModelIndex index);

signals:
    void learningChanged(int);



};

#endif // LEARNINGCHOICEWIDGET_H
