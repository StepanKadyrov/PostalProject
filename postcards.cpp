#include "postcards.h"

Postcards::Postcards(QWidget *parent)
    : QWidget{parent}
{
//    db = QSqlDatabase::addDatabase()

    QVBoxLayout *mainLayout = new  QVBoxLayout(this);

    QLabel *lbl0 = new QLabel("Открытки",this);
    lbl0->setFont(QFont("Comic Sans MS", 14, QFont::Normal));
    mainLayout->addWidget(lbl0);

    QList <QString> lblNames = {"Всего:", "Полученных:", "Отправленных:", "Стран:", "Населённых пунктов:"};
    QHBoxLayout *lbls = new QHBoxLayout();
    for(int i = 0; i < lblNames.size(); i++)
    {
        statisticsLbls.append(new QLabel(lblNames.at(i), this));
        lbls->addWidget(statisticsLbls.at(i));
    }
    mainLayout->addLayout(lbls);


    QPushButton *addBtn = new QPushButton("Добавить открытку");
    connect(addBtn, SIGNAL(clicked()), this, SLOT(addPostcard()));
    mainLayout->addWidget(addBtn);

    this->setLayout(mainLayout);
}

void Postcards::addPostcard()
{
    QWidget *addWidget = new QWidget();
    addWidget->setMaximumSize(800, 750);
    addWidget->setAttribute(Qt::WA_DeleteOnClose);
    addWidget->setFont(QFont("Comic Sans MS", 12, QFont::Normal));
    addWidget->setWindowTitle("Добавление открытки");
    QGridLayout *layout = new QGridLayout(addWidget);
    layout->setAlignment(Qt::AlignCenter);

    QLabel *lbl0 = new QLabel("Добавление открытки", addWidget);
    lbl0->setAlignment(Qt::AlignCenter);

    //Добавляем радиокнопки для выбора типа открытки

    typeBtns = new QButtonGroup(addWidget);
    connect(typeBtns, SIGNAL(idClicked(int)), this, SLOT(typeSelect(int)));
    QRadioButton *btnRec = new QRadioButton("&Полученная", addWidget);
    btnRec->setChecked(true);
    typeBtns->addButton(btnRec, 0);
    QRadioButton *btnSent = new QRadioButton("&Отправленная", addWidget);
    typeBtns->addButton(btnSent, 1);
    QRadioButton *btnClean = new QRadioButton("&Чистая", addWidget);
    typeBtns->addButton(btnClean, 2);

    QLabel *lbl1 = new QLabel("Номер",addWidget);
    numberEdit = new QLineEdit(addWidget);

    QLabel *lbl2 = new QLabel("Страна",addWidget);
    countryEdit = new QLineEdit(addWidget);

    QLabel *lbl3 = new QLabel("Населённый пункт",addWidget);
    townEdit = new QLineEdit(addWidget);

    lbl4 = new QLabel("От кого",addWidget);
    humanEdit = new QLineEdit(addWidget);

    lbl5 = new QLabel("Дата",addWidget);
    dateEdit = new QDateEdit(addWidget);
    dateEdit->setCalendarPopup(true);
    dateEdit->setDate(QDate(2022, 1, 1));

    QLabel *lbl6 = new QLabel("Фото",addWidget);
    photoEdit = new QLineEdit(addWidget);
    QPushButton *addPhotoBtn = new QPushButton("Обзор", addWidget);
    connect(addPhotoBtn, SIGNAL(clicked()), this, SLOT(addPhoto()));

    QLabel *lbl7 = new QLabel("Заметка",addWidget);
    noteEdit = new QTextEdit(addWidget);
    noteEdit->setMaximumHeight(300);

    QPushButton *btnOk = new QPushButton("Добавить",addWidget);
    connect(btnOk, SIGNAL(clicked()), this, SLOT(savePostcard()));
    QPushButton *btnCancel = new QPushButton("Отмена",addWidget);
    connect(btnCancel, SIGNAL(clicked()), addWidget, SLOT(close()));

    //Добавляем всё в компоновщик

    layout->addWidget(lbl0, 0, 0, 1, -1);

    QHBoxLayout *btnTypeLayout = new QHBoxLayout();
    btnTypeLayout->setAlignment(Qt::AlignCenter);

    btnTypeLayout->addWidget(btnRec);
    btnTypeLayout->addWidget(btnSent);
    btnTypeLayout->addWidget(btnClean);

    layout->addLayout(btnTypeLayout, 1, 0, 1, -1);

    layout->addWidget(lbl1, 2, 0);
    layout->addWidget(numberEdit, 2, 1, 1, -1);

    layout->addWidget(lbl2, 3, 0);
    layout->addWidget(countryEdit, 3, 1, 1, -1);

    layout->addWidget(lbl3, 4, 0);
    layout->addWidget(townEdit, 4, 1, 1, -1);

    layout->addWidget(lbl4, 5, 0);
    layout->addWidget(humanEdit, 5, 1, 1, -1);

    layout->addWidget(lbl5, 6, 0);
    layout->addWidget(dateEdit, 6, 1, 1, -1);

    layout->addWidget(lbl6, 7, 0);
    layout->addWidget(photoEdit, 7, 1);
    layout->addWidget(addPhotoBtn, 7, 2);

    layout->addWidget(lbl7, 8, 0, 1, -1);
    layout->addWidget(noteEdit, 9, 0, 1, -1);

//    layout->addWidget(btnOk, 10, 0, 1, 2);
//    layout->addWidget(btnCancel, 10, 1);
    QHBoxLayout *btnsOkCan = new QHBoxLayout();
    btnsOkCan->addWidget(btnOk);
    btnsOkCan->addWidget(btnCancel);
    layout->addLayout(btnsOkCan, 10, 0, 1, 3);

    addWidget->setLayout(layout);
    addWidget->show();
    addWidget->resize(600, 700);
}

void Postcards::savePostcard()
{

}

void Postcards::addPhoto()
{
    QString phonoFileName = QFileDialog::getOpenFileName(qobject_cast<QPushButton*>(sender()), "Выбор фото", "", "*.jpg; *.jpeg; *.png;");
    photoEdit->setText(phonoFileName);
}

void Postcards::typeSelect(int id)
{
    switch(id)
    {
        case 0:
            lbl4->show();
            lbl4->setText("От кого");
            humanEdit->show();
            lbl5->show();
            dateEdit->show();
            break;
        case 1:
            lbl4->show();
            lbl4->setText("Кому");
            humanEdit->show();
            lbl5->show();
            dateEdit->show();
            break;
        case 2:
            lbl4->hide();
            humanEdit->hide();
            lbl5->hide();
            dateEdit->hide();
            break;
    }
}
