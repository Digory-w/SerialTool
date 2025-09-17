/********************************************************************************
** Form generated from reading UI file 'portsetbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTSETBOX_H
#define UI_PORTSETBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PortSetBox
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *dataBitsBox;
    QLabel *label_2;
    QComboBox *paritBox;
    QLabel *label_3;
    QComboBox *stopBitsBox;
    QLabel *label_4;
    QComboBox *flowControlBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PortSetBox)
    {
        if (PortSetBox->objectName().isEmpty())
            PortSetBox->setObjectName(QString::fromUtf8("PortSetBox"));
        PortSetBox->resize(200, 145);
        gridLayout = new QGridLayout(PortSetBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(PortSetBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dataBitsBox = new QComboBox(PortSetBox);
        dataBitsBox->addItem(QString::fromUtf8("5"));
        dataBitsBox->addItem(QString::fromUtf8("6"));
        dataBitsBox->addItem(QString::fromUtf8("7"));
        dataBitsBox->addItem(QString::fromUtf8("8"));
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout->addWidget(dataBitsBox, 0, 1, 1, 1);

        label_2 = new QLabel(PortSetBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        paritBox = new QComboBox(PortSetBox);
        paritBox->addItem(QString::fromUtf8("None"));
        paritBox->addItem(QString::fromUtf8("Even"));
        paritBox->addItem(QString::fromUtf8("Odd"));
        paritBox->addItem(QString::fromUtf8("Space"));
        paritBox->addItem(QString::fromUtf8("Mark"));
        paritBox->setObjectName(QString::fromUtf8("paritBox"));

        gridLayout->addWidget(paritBox, 1, 1, 1, 1);

        label_3 = new QLabel(PortSetBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        stopBitsBox = new QComboBox(PortSetBox);
        stopBitsBox->addItem(QString::fromUtf8("1"));
        stopBitsBox->addItem(QString::fromUtf8("1.5"));
        stopBitsBox->addItem(QString::fromUtf8("2"));
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout->addWidget(stopBitsBox, 2, 1, 1, 1);

        label_4 = new QLabel(PortSetBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        flowControlBox = new QComboBox(PortSetBox);
        flowControlBox->addItem(QString::fromUtf8("None"));
        flowControlBox->addItem(QString::fromUtf8("RTS/CTS"));
        flowControlBox->addItem(QString::fromUtf8("XON/XOFF"));
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout->addWidget(flowControlBox, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(PortSetBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 1, 1, 1);


        retranslateUi(PortSetBox);
        QObject::connect(buttonBox, SIGNAL(accepted()), PortSetBox, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PortSetBox, SLOT(reject()));

        QMetaObject::connectSlotsByName(PortSetBox);
    } // setupUi

    void retranslateUi(QDialog *PortSetBox)
    {
        PortSetBox->setWindowTitle(QCoreApplication::translate("PortSetBox", "Port Settings", nullptr));
        label->setText(QCoreApplication::translate("PortSetBox", "Data Bits", nullptr));

        label_2->setText(QCoreApplication::translate("PortSetBox", "Parity", nullptr));

        label_3->setText(QCoreApplication::translate("PortSetBox", "Stop Bits", nullptr));

        label_4->setText(QCoreApplication::translate("PortSetBox", "Flow Control", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PortSetBox: public Ui_PortSetBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTSETBOX_H
