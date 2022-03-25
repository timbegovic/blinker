#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

class gui : public QWidget, private Ui::gui
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = nullptr);
private slots:
    void on_startButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void toggle();
private:
    QTimer* m_timer;
    bool m_state;
    Gpio* m_gpio;
};

#endif // GUI_H
