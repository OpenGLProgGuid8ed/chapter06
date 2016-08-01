/********************************************************************************
** Form generated from reading UI file 'multitex.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTITEX_H
#define UI_MULTITEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiTexClass
{
public:

    void setupUi(QWidget *multiTexClass)
    {
        if (multiTexClass->objectName().isEmpty())
            multiTexClass->setObjectName(QStringLiteral("multiTexClass"));
        multiTexClass->resize(600, 400);

        retranslateUi(multiTexClass);

        QMetaObject::connectSlotsByName(multiTexClass);
    } // setupUi

    void retranslateUi(QWidget *multiTexClass)
    {
        multiTexClass->setWindowTitle(QApplication::translate("multiTexClass", "multiTex", 0));
    } // retranslateUi

};

namespace Ui {
    class multiTexClass: public Ui_multiTexClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTITEX_H
