/********************************************************************************
** Form generated from reading UI file 'tcpudpport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPUDPPORT_H
#define UI_TCPUDPPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpUdpPort
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *protocolBox;
    QLabel *ipLabel;
    QLineEdit *ipEdit;
    QLabel *label_2;
    QLineEdit *portEdit;

    void setupUi(QWidget *TcpUdpPort)
    {
        if (TcpUdpPort->objectName().isEmpty())
            TcpUdpPort->setObjectName(QString::fromUtf8("TcpUdpPort"));
        TcpUdpPort->resize(390, 20);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TcpUdpPort->sizePolicy().hasHeightForWidth());
        TcpUdpPort->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(TcpUdpPort);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TcpUdpPort);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        protocolBox = new QComboBox(TcpUdpPort);
        protocolBox->addItem(QString::fromUtf8("TCP Server"));
        protocolBox->addItem(QString::fromUtf8("TCP Client"));
        protocolBox->addItem(QString::fromUtf8("UDP"));
        protocolBox->setObjectName(QString::fromUtf8("protocolBox"));
        protocolBox->setMinimumSize(QSize(90, 0));
        protocolBox->setMaximumSize(QSize(90, 16777215));
        protocolBox->setStyleSheet(QString::fromUtf8("QComboBox { width: 90px }\n"
""));

        horizontalLayout->addWidget(protocolBox);

        ipLabel = new QLabel(TcpUdpPort);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        sizePolicy.setHeightForWidth(ipLabel->sizePolicy().hasHeightForWidth());
        ipLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ipLabel);

        ipEdit = new QLineEdit(TcpUdpPort);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setStyleSheet(QString::fromUtf8("QLineEdit { width: 7em }"));
        ipEdit->setText(QString::fromUtf8(""));
        ipEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ipEdit);

        label_2 = new QLabel(TcpUdpPort);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        portEdit = new QLineEdit(TcpUdpPort);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setStyleSheet(QString::fromUtf8("QLineEdit { width: 4em }"));
        portEdit->setText(QString::fromUtf8(""));
        portEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(portEdit);


        retranslateUi(TcpUdpPort);

        QMetaObject::connectSlotsByName(TcpUdpPort);
    } // setupUi

    void retranslateUi(QWidget *TcpUdpPort)
    {
        TcpUdpPort->setWindowTitle(QCoreApplication::translate("TcpUdpPort", "Form", nullptr));
        label->setText(QCoreApplication::translate("TcpUdpPort", "Protocol", nullptr));

        ipLabel->setText(QCoreApplication::translate("TcpUdpPort", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("TcpUdpPort", "Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpUdpPort: public Ui_TcpUdpPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPUDPPORT_H
