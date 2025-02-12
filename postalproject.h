#ifndef POSTALPROJECT_H
#define POSTALPROJECT_H

#include <QtWidgets>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>

#include "firstwindow.h"
#include "postcards.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PostalProject; }
QT_END_NAMESPACE

class PostalProject : public QMainWindow
{
    Q_OBJECT

public:
    PostalProject(QWidget *parent = nullptr);
    ~PostalProject();
private:
    Ui::PostalProject *ui;
    QStackedWidget *stackWdgt;
    FirstWindow *firstWdgt;
    Postcards *postcardsWdgt;
    int idArray[6];

private slots:
    void addCollectionSlot();
    void setParametersSlot();
    void statisticsSlot();
    void tbSlot(int, bool);
    void mainWndShow();
//    void show();
//    void show();
//    void show();
//    void show();
//    void show();
};

enum Index{MAIN, POSTCARDS, LETTERS, KPD, COLLECTIONS, GALLERY};
#endif // POSTALPROJECT_H
