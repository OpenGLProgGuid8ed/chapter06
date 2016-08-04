/********************************************************************************
** Form generated from reading UI file 'volumeRgb.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMERGB_H
#define UI_VOLUMERGB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_r;
    QSlider *horizontalSlider;
    QLabel *label_g;
    QSlider *horizontalSlider_2;
    QLabel *label_b;
    QSlider *horizontalSlider_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(418, 193);
        verticalLayoutWidget = new QWidget(Form);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 391, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_r = new QLabel(verticalLayoutWidget);
        label_r->setObjectName(QStringLiteral("label_r"));

        verticalLayout->addWidget(label_r);

        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_g = new QLabel(verticalLayoutWidget);
        label_g->setObjectName(QStringLiteral("label_g"));

        verticalLayout->addWidget(label_g);

        horizontalSlider_2 = new QSlider(verticalLayoutWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        label_b = new QLabel(verticalLayoutWidget);
        label_b->setObjectName(QStringLiteral("label_b"));

        verticalLayout->addWidget(label_b);

        horizontalSlider_3 = new QSlider(verticalLayoutWidget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label_r->setText(QApplication::translate("Form", "R", 0));
        label_g->setText(QApplication::translate("Form", "G", 0));
        label_b->setText(QApplication::translate("Form", "B", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMERGB_H
