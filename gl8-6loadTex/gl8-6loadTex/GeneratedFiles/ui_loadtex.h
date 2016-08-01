/********************************************************************************
** Form generated from reading UI file 'loadtex.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADTEX_H
#define UI_LOADTEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadTexClass
{
public:

    void setupUi(QWidget *LoadTexClass)
    {
        if (LoadTexClass->objectName().isEmpty())
            LoadTexClass->setObjectName(QStringLiteral("LoadTexClass"));
        LoadTexClass->resize(600, 400);

        retranslateUi(LoadTexClass);

        QMetaObject::connectSlotsByName(LoadTexClass);
    } // setupUi

    void retranslateUi(QWidget *LoadTexClass)
    {
        LoadTexClass->setWindowTitle(QApplication::translate("LoadTexClass", "LoadTex", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadTexClass: public Ui_LoadTexClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADTEX_H
