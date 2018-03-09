/********************************************************************************
** Form generated from reading UI file 'examenpractic.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMENPRACTIC_H
#define UI_EXAMENPRACTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examenpracticClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *examenpracticClass)
    {
        if (examenpracticClass->objectName().isEmpty())
            examenpracticClass->setObjectName(QStringLiteral("examenpracticClass"));
        examenpracticClass->resize(600, 400);
        menuBar = new QMenuBar(examenpracticClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        examenpracticClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(examenpracticClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        examenpracticClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(examenpracticClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        examenpracticClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(examenpracticClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        examenpracticClass->setStatusBar(statusBar);

        retranslateUi(examenpracticClass);

        QMetaObject::connectSlotsByName(examenpracticClass);
    } // setupUi

    void retranslateUi(QMainWindow *examenpracticClass)
    {
        examenpracticClass->setWindowTitle(QApplication::translate("examenpracticClass", "examenpractic", 0));
    } // retranslateUi

};

namespace Ui {
    class examenpracticClass: public Ui_examenpracticClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMENPRACTIC_H
