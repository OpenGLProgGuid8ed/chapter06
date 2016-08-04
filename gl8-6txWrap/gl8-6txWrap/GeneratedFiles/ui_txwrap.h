/********************************************************************************
** Form generated from reading UI file 'txwrap.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TXWRAP_H
#define UI_TXWRAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_txWrapClass
{
public:

    void setupUi(QWidget *txWrapClass)
    {
        if (txWrapClass->objectName().isEmpty())
            txWrapClass->setObjectName(QStringLiteral("txWrapClass"));
        txWrapClass->resize(600, 400);

        retranslateUi(txWrapClass);

        QMetaObject::connectSlotsByName(txWrapClass);
    } // setupUi

    void retranslateUi(QWidget *txWrapClass)
    {
        txWrapClass->setWindowTitle(QApplication::translate("txWrapClass", "txWrap", 0));
    } // retranslateUi

};

namespace Ui {
    class txWrapClass: public Ui_txWrapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TXWRAP_H
