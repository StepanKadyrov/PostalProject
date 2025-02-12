#include "postalproject.h"
#include "ui_postalproject.h"

PostalProject::PostalProject(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PostalProject)
{
    ui->setupUi(this);

    // Создаём и устанавливаем центральный виджет

    stackWdgt = new QStackedWidget(this);
    this->setCentralWidget(stackWdgt);

    // Меню делаем

    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *mainMenu = new QMenu("&Меню", menuBar);
    mainMenu->addAction("&Добавить коллекцию", this, SLOT(addCollectionSlot()));
    mainMenu->addAction("&Настройки", this, SLOT(setParametersSlot()));
    mainMenu->addAction("&Статистика", this, SLOT(statisticsSlot()));
    mainMenu->addSeparator();
    mainMenu->addAction("&Закрыть приложение", this, SLOT(close()));
    menuBar->addMenu(mainMenu);
    this->setMenuWidget(menuBar);

    // Создаём кнопки слева, сначала ToolBar

    QToolBar *toolBar = new QToolBar(this);
    toolBar->setContextMenuPolicy(Qt::CustomContextMenu); // Устанавливаем своё меню, при этом его не создавая, значит, не будет ничего вылазить, всё как и хотелось
    toolBar->setMovable(false);

    // Добавляем кнопки в ToolBar, объединённые в группу

    QList <QString> btnLbls = {"Главная", "Открытки", "Письма", "КПД", "Коллекции", "Галерея"};
    QButtonGroup *btnGroup = new QButtonGroup(this);
    connect(btnGroup, SIGNAL(idToggled(int,bool)), this, SLOT(tbSlot(int,bool)));

    for(int i = 0; i < btnLbls.size(); i++)
    {
        QToolButton *tb = new QToolButton;
        tb->setText(btnLbls.at(i));
        tb->setIcon(QIcon(QString(":/Иконки/%1.png").arg(i)));
        tb->setIconSize(QSize(64, 64));
        tb->setFixedSize(120, 80);
        tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tb->setCheckable(true); // Чтобы кнопку можно было сделать воткнутой
        toolBar->addWidget(tb);
        if(i == 0 || i == 3)
            toolBar->addSeparator();
        if(i == 0)
            tb->setChecked(true);
        btnGroup->addButton(tb, i);
    }

    // Добавляем ToolBar

    this->addToolBar(Qt::LeftToolBarArea, toolBar);

    // Создаём и добавляем все окна

    firstWdgt = new FirstWindow(stackWdgt);
    idArray[Index::MAIN] = stackWdgt->addWidget(firstWdgt);

    postcardsWdgt = new Postcards(stackWdgt);
    idArray[Index::POSTCARDS] = stackWdgt->addWidget(postcardsWdgt);
}

PostalProject::~PostalProject()
{
    delete ui;
}

void PostalProject::addCollectionSlot()
{

}

void PostalProject::setParametersSlot()
{

}

void PostalProject::statisticsSlot()
{

}

void PostalProject::tbSlot(int i, bool check)
{
    //QButtonGroup *btngroup = qobject_cast<QButtonGroup*>(sender());
    if(check)
    {
        if(i == 0 || i == 1)
            stackWdgt->setCurrentIndex(idArray[i]);
        switch(i)
        {
            case 0:
                firstWdgt->updateWdgt();
                break;
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
}

void PostalProject::mainWndShow()
{

}


