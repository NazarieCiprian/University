/********************************************************************************
** Form generated from reading UI file 'programmerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMERWINDOW_H
#define UI_PROGRAMMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammerWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *filesList;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QPushButton *addButton;
    QPushButton *reviseButton;
    QLabel *label;
    QLabel *revised;
    QLabel *label_3;
    QLabel *toRevise;

    void setupUi(QWidget *ProgrammerWindow)
    {
        if (ProgrammerWindow->objectName().isEmpty())
            ProgrammerWindow->setObjectName(QStringLiteral("ProgrammerWindow"));
        ProgrammerWindow->resize(589, 590);
        verticalLayoutWidget = new QWidget(ProgrammerWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 241, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        filesList = new QListWidget(verticalLayoutWidget);
        filesList->setObjectName(QStringLiteral("filesList"));

        verticalLayout->addWidget(filesList);

        formLayoutWidget = new QWidget(ProgrammerWindow);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(300, 30, 241, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(formLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        addButton = new QPushButton(ProgrammerWindow);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(290, 110, 75, 23));
        reviseButton = new QPushButton(ProgrammerWindow);
        reviseButton->setObjectName(QStringLiteral("reviseButton"));
        reviseButton->setGeometry(QRect(380, 110, 75, 23));
        label = new QLabel(ProgrammerWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 240, 47, 13));
        revised = new QLabel(ProgrammerWindow);
        revised->setObjectName(QStringLiteral("revised"));
        revised->setGeometry(QRect(310, 270, 41, 31));
        label_3 = new QLabel(ProgrammerWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 240, 81, 16));
        toRevise = new QLabel(ProgrammerWindow);
        toRevise->setObjectName(QStringLiteral("toRevise"));
        toRevise->setGeometry(QRect(400, 260, 71, 21));

        retranslateUi(ProgrammerWindow);

        QMetaObject::connectSlotsByName(ProgrammerWindow);
    } // setupUi

    void retranslateUi(QWidget *ProgrammerWindow)
    {
        ProgrammerWindow->setWindowTitle(QApplication::translate("ProgrammerWindow", "ProgrammerWindow", 0));
        nameLabel->setText(QApplication::translate("ProgrammerWindow", "Name", 0));
        addButton->setText(QApplication::translate("ProgrammerWindow", "Add", 0));
        reviseButton->setText(QApplication::translate("ProgrammerWindow", "Revise", 0));
        label->setText(QApplication::translate("ProgrammerWindow", "Revised", 0));
        revised->setText(QString());
        label_3->setText(QApplication::translate("ProgrammerWindow", "To be revised", 0));
        toRevise->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProgrammerWindow: public Ui_ProgrammerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERWINDOW_H
