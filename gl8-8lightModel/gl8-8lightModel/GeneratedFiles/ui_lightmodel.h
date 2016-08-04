/********************************************************************************
** Form generated from reading UI file 'lightmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTMODEL_H
#define UI_LIGHTMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "renderwidget.h"
#include "volumergb.h"

QT_BEGIN_NAMESPACE

class Ui_LightModelClass
{
public:
    QGLWidget *centralWidget;
    renderWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    VolumeRgb *dockWidgetContents;

    void setupUi(QMainWindow *LightModelClass)
    {
        if (LightModelClass->objectName().isEmpty())
            LightModelClass->setObjectName(QStringLiteral("LightModelClass"));
        LightModelClass->resize(847, 549);
        centralWidget = new QGLWidget(LightModelClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new renderWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 471, 381));
        LightModelClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LightModelClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 23));
        LightModelClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LightModelClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LightModelClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LightModelClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LightModelClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(LightModelClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new VolumeRgb();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);
        LightModelClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(LightModelClass);

        QMetaObject::connectSlotsByName(LightModelClass);
    } // setupUi

    void retranslateUi(QMainWindow *LightModelClass)
    {
        LightModelClass->setWindowTitle(QApplication::translate("LightModelClass", "LightModel", 0));
    } // retranslateUi

};

namespace Ui {
    class LightModelClass: public Ui_LightModelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTMODEL_H
