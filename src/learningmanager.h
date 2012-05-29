/**
 *\file learningmanager.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#ifndef LEARNINGMANAGER_H
#define LEARNINGMANAGER_H
#include <QWidget>

class QDockWidget;
class QHBoxLayout;
class Learning;
class LearningQuadBlending;
class LearningDoubleQuadBlendingLessParam;
class LearningDoubleQuadBlendingFullParam;
class LearningTripleQuadBlendingLessParam;
class LearningTripleQuadBlendingFullParam;
class LearningCubeBlendingLessParam;
class LearningCubeBlendingFullParam;
class LearningChoiceWidget;
/**
 * \class LearningManager
 * \brief Gere la naviguation entre les différents thèmes.Herite de QWidget.Est instancié uniquement dans MainWindow : considéré comme le widget central.
 */
class LearningManager : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* m_mainLayout;
    QDockWidget* m_dockWidget;
    LearningChoiceWidget* m_learningChoiceWidget;
    Learning* m_currentLearning;

    /* Liste des themes */
    LearningQuadBlending* m_learningQuadBlending;
    LearningDoubleQuadBlendingLessParam* m_learningDoubleQuadBlendingLessParam;
    LearningDoubleQuadBlendingFullParam* m_learningDoubleQuadBlendingFulParam;
    LearningTripleQuadBlendingLessParam* m_learningTripleQuadBlendingLessParam;
    LearningTripleQuadBlendingFullParam* m_learningTripleQuadBlendingFullParam;
    LearningCubeBlendingLessParam *m_learningCubeBlendingLessParam;
    LearningCubeBlendingFullParam *m_learningCubeBlendingFullParam;

    /* Vecteur de theme */
    QVector<Learning*> m_learningVector;
public:
    LearningManager(QDockWidget* dockWidget = 0 , QWidget* parent = 0);

private slots:
    void changeLearning(int index);
};

#endif // LEARNINGMANAGER_H
