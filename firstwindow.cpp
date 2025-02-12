#include "firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent)
    : QWidget(parent)
{
    // Создаём лейблы с информацией

    statisticsLbls.append(new QLabel("Отправленных\nОткрыток: \nПисем: "));
    statisticsLbls.append(new QLabel("Полученных\nОткрыток: \nПисем: "));
    statisticsLbls.append(new QLabel("Чистых\nОткрыток: \nПисем: "));
    statisticsLbls.append(new QLabel("Страны: "));
    statisticsLbls.append(new QLabel("Населённых пунктов: "));

    lblTitle = new QLabel(randomLbl.at(QRandomGenerator::global()->bounded(0, 3)));
    lblPctr = new QLabel;

    // Компануем их

    QHBoxLayout *lblsLayout = new QHBoxLayout();
    for(int i = 0; i < statisticsLbls.size(); i++)
            lblsLayout->addWidget(statisticsLbls.at(i));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addLayout(lblsLayout);
    mainLayout->addWidget(lblTitle);
    mainLayout->addWidget(lblPctr);

    this->setLayout(mainLayout);
}

void FirstWindow::randomPicture()
{
    QRandomGenerator::global()->bounded(0, 2);
}

void FirstWindow::updateWdgt()
{
    lblTitle->setText(randomLbl.at(QRandomGenerator::global()->bounded(0, 3)));
}
