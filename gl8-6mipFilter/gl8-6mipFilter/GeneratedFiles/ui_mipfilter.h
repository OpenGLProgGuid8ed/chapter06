/********************************************************************************
** Form generated from reading UI file 'mipfilter.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIPFILTER_H
#define UI_MIPFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mipFilterClass
{
public:

    void setupUi(QWidget *mipFilterClass)
    {
        if (mipFilterClass->objectName().isEmpty())
            mipFilterClass->setObjectName(QStringLiteral("mipFilterClass"));
        mipFilterClass->resize(600, 400);

        retranslateUi(mipFilterClass);

        QMetaObject::connectSlotsByName(mipFilterClass);
    } // setupUi

    void retranslateUi(QWidget *mipFilterClass)
    {
        mipFilterClass->setWindowTitle(QApplication::translate("mipFilterClass", "mipFilter", 0));
    } // retranslateUi

};

namespace Ui {
    class mipFilterClass: public Ui_mipFilterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIPFILTER_H
