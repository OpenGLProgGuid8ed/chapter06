/********************************************************************************
** Form generated from reading UI file 'statictex.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATICTEX_H
#define UI_STATICTEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_staticTexClass
{
public:

    void setupUi(QWidget *staticTexClass)
    {
        if (staticTexClass->objectName().isEmpty())
            staticTexClass->setObjectName(QStringLiteral("staticTexClass"));
        staticTexClass->resize(600, 400);

        retranslateUi(staticTexClass);

        QMetaObject::connectSlotsByName(staticTexClass);
    } // setupUi

    void retranslateUi(QWidget *staticTexClass)
    {
        staticTexClass->setWindowTitle(QApplication::translate("staticTexClass", "staticTex", 0));
    } // retranslateUi

};

namespace Ui {
    class staticTexClass: public Ui_staticTexClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATICTEX_H
