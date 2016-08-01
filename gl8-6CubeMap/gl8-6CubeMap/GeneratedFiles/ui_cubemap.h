/********************************************************************************
** Form generated from reading UI file 'cubemap.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBEMAP_H
#define UI_CUBEMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CubeMapClass
{
public:

    void setupUi(QWidget *CubeMapClass)
    {
        if (CubeMapClass->objectName().isEmpty())
            CubeMapClass->setObjectName(QStringLiteral("CubeMapClass"));
        CubeMapClass->resize(600, 400);

        retranslateUi(CubeMapClass);

        QMetaObject::connectSlotsByName(CubeMapClass);
    } // setupUi

    void retranslateUi(QWidget *CubeMapClass)
    {
        CubeMapClass->setWindowTitle(QApplication::translate("CubeMapClass", "CubeMap", 0));
    } // retranslateUi

};

namespace Ui {
    class CubeMapClass: public Ui_CubeMapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBEMAP_H
