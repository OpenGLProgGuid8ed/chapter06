/********************************************************************************
** Form generated from reading UI file 'volumetex.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMETEX_H
#define UI_VOLUMETEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_volumeTexClass
{
public:

    void setupUi(QWidget *volumeTexClass)
    {
        if (volumeTexClass->objectName().isEmpty())
            volumeTexClass->setObjectName(QStringLiteral("volumeTexClass"));
        volumeTexClass->resize(600, 400);

        retranslateUi(volumeTexClass);

        QMetaObject::connectSlotsByName(volumeTexClass);
    } // setupUi

    void retranslateUi(QWidget *volumeTexClass)
    {
        volumeTexClass->setWindowTitle(QApplication::translate("volumeTexClass", "volumeTex", 0));
    } // retranslateUi

};

namespace Ui {
    class volumeTexClass: public Ui_volumeTexClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETEX_H
