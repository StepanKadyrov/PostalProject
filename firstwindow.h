#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QObject>
#include <QtWidgets>

class FirstWindow : public QWidget
{
    Q_OBJECT
public:
    FirstWindow(QWidget *parent = nullptr);
    void updateWdgt();
private:
    void randomPicture();
    QLabel *lblTitle;
    QLabel *lblPctr;
    QList <QLabel*> statisticsLbls;
private slots:
};

const QList <QString> randomLbl = {"Случайная открытка", "Случайное письмо", "Случайный КПД"};

#endif // FIRSTWINDOW_H
