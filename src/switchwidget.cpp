/**
 *\file switchwidget.cpp
 *\author Jean-Mathieu CHANTREIN
 *\version 2.0 Copyright CC-BY-NC-SA (Creative Commons) https://fr.wikipedia.org/wiki/Licence_Creative_Commons
 */
#include "switchwidget.h"
#include <qpainter.h>
#include <qevent.h>

SwitchWidget::SwitchWidget(bool flag,QWidget* parent): QWidget(parent),m_flag(flag)
{
    m_height=20;
    m_width=40;
    setMinimumSize(m_width+1,m_height+1);
}
/**
 * \fn void SwitchWidget::drawSwitch()
 * \brief dessine l'interrupteur suivant sont etat ON/OFF
 */
void SwitchWidget::drawSwitch()
{
    m_pixmap->fill(this,QPoint(0,0));
    QPainter painter(m_pixmap);
    if (m_flag)
    {
        painter.setBrush(Qt::green);
        painter.drawRoundedRect(QRectF(0,0,m_width,m_height),4,4);
        painter.setBrush(Qt::gray);
        painter.drawRoundedRect(QRectF(m_width/2,0,m_width/2,m_height),4,4);
    }
    else
    {
        painter.setBrush(Qt::red);
        painter.drawRoundedRect(QRectF(0,0,m_width,m_height),4,4);
        painter.setBrush(Qt::gray);
        painter.drawRoundedRect(QRectF(0,0,m_width/2,m_height),4,4);
    }
    update();
}

/**
 * \fn void SwitchWidget::mousePressEvent(QMouseEvent* event)
 * \brief Gestion des clics de la souris.
 */
void SwitchWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPos=event->pos().x();
        if (event->pos().x()>width()/2) m_flag=true;
        else m_flag=false;
        emit switchChanged(m_flag);

        drawSwitch();
    }
}

/**
 * \fn void SwitchWidget::mouseMouveEvent(QMouseEvent* event)
 * \todo Implementer la methode pour glisser le widget
 */
void SwitchWidget::mouseMouveEvent(QMouseEvent* event)
{

}


/**
 * \fn void SwitchWidget::paintEvent(QPaintEvent* event)
 * \brief Redessine la scene lorsque il le faut ( update() , resize() , ...)
 */
void SwitchWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,*m_pixmap);
}

/**
 * \fn void SwitchWidget::resizeEvent(QResizeEvent* event)
 * \brief Gestion du widget lors du redimenssionnement de celui-ci
 */
void SwitchWidget::resizeEvent(QResizeEvent* event)
{
    m_width=width()-1;
    m_height=height()-1;
    QPixmap* temp=new QPixmap(size());//temp est un QPixmap qui est de la taille du widget redimenssioné
    m_pixmap=temp;

    drawSwitch();

    update();
}
