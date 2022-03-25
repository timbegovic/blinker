#include "gui.h"
#include "config.h"
#include <QDebug>

gui::gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(parent);

    m_state = false;
    m_timer = new QTimer(this);
    m_gpio = new Gpio(this);
    connect(m_timer, &QTimer::timeout, this, &gui::toggle);
}

void gui::on_startButton_clicked()
{
    int time = 1000 / horizontalSlider->value();
    m_timer->start(time);
}

void gui::on_horizontalSlider_valueChanged(int value)
{
    int time = 1000 / value;
    m_timer->setInterval(time);
}

void gui::toggle()
{
    m_state = !m_state;
    blinklabel->setNum(m_state);
    m_gpio->set(LEDS[0], m_state);
}
