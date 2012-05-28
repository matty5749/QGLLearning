/**
 *\file switchwidget.h
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */

#ifndef SWITCHWIDGET_H
#define SWITCHWIDGET_H
#include <QWidget>


class QGLFunctionEnableDisable;
/**
 * \class SwitchWidget
 * \brief Widget qui gere le dessin d'un interupteur , uniquement utilisés par les classes filles de QGLFunctionEnableDisable
 */
class SwitchWidget : public QWidget
{
    Q_OBJECT
private:
    QPixmap* m_pixmap;
    bool m_flag;
    int m_height;
    int m_width;
    int m_lastPos;
public:
    SwitchWidget(bool flag=true , QWidget* parent=0);
    ~SwitchWidget();
    void drawSwitch();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMouveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    
signals:
    void switchChanged(bool);

    friend class QGLFunctionEnableDisable;
};

#endif // SWITCHWIDGET_H
