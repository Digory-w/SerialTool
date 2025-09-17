/********************************************************************************
** Form generated from reading UI file 'vediobox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEDIOBOX_H
#define UI_VEDIOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VedioBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *copyButton;

    void setupUi(QDialog *VedioBox)
    {
        if (VedioBox->objectName().isEmpty())
            VedioBox->setObjectName(QString::fromUtf8("VedioBox"));
        VedioBox->resize(331, 279);
        verticalLayout = new QVBoxLayout(VedioBox);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        label = new QLabel(VedioBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(325, 245));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setText(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveButton = new QPushButton(VedioBox);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);

        copyButton = new QPushButton(VedioBox);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        horizontalLayout->addWidget(copyButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(VedioBox);

        QMetaObject::connectSlotsByName(VedioBox);
    } // setupUi

    void retranslateUi(QDialog *VedioBox)
    {
        VedioBox->setWindowTitle(QCoreApplication::translate("VedioBox", "Vedio Box", nullptr));
        saveButton->setText(QCoreApplication::translate("VedioBox", "Save Image", nullptr));
        copyButton->setText(QCoreApplication::translate("VedioBox", "Copy C Array", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VedioBox: public Ui_VedioBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEDIOBOX_H
