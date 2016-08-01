/********************************************************************************
** Form generated from reading UI file 'mipmap.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIPMAP_H
#define UI_MIPMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mipMapClass
{
public:

    void setupUi(QWidget *mipMapClass)
    {
        if (mipMapClass->objectName().isEmpty())
            mipMapClass->setObjectName(QStringLiteral("mipMapClass"));
        mipMapClass->resize(600, 400);

        retranslateUi(mipMapClass);

        QMetaObject::connectSlotsByName(mipMapClass);
    } // setupUi

    void retranslateUi(QWidget *mipMapClass)
    {
        mipMapClass->setWindowTitle(QApplication::translate("mipMapClass", "mipMap", 0));
    } // retranslateUi

};

namespace Ui {
    class mipMapClass: public Ui_mipMapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIPMAP_H
