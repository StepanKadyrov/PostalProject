#ifndef POSTCARDS_H
#define POSTCARDS_H

#include <QObject>
#include <QtWidgets>
#include <QSqlDatabase>

class Postcards : public QWidget
{
    Q_OBJECT
public:
    explicit Postcards(QWidget *parent = nullptr);

signals:

private slots:
    void addPostcard();
    void savePostcard();
    void addPhoto();
    void typeSelect(int);
private:
    QButtonGroup *typeBtns;
    QLineEdit *numberEdit;
    QLineEdit *countryEdit;
    QLineEdit *townEdit;
    QLineEdit *humanEdit;
    QDateEdit *dateEdit;
    QLineEdit *photoEdit;
    QTextEdit *noteEdit;
    QLabel *lbl4;
    QLabel *lbl5;
    QList <QLabel*> statisticsLbls;
    QSqlDatabase db;
};

#endif // POSTCARDS_H
