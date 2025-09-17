/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPort
{
public:
    QHBoxLayout *horizontalLayout_1;
    QLabel *labelPort;
    QComboBox *portNameBox;
    QLabel *labelBaudRate;
    QComboBox *baudRateBox;

    void setupUi(QWidget *SerialPort)
    {
        if (SerialPort->objectName().isEmpty())
            SerialPort->setObjectName(QString::fromUtf8("SerialPort"));
        SerialPort->resize(308, 29);
        horizontalLayout_1 = new QHBoxLayout(SerialPort);
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(2, 0, 2, 0);
        labelPort = new QLabel(SerialPort);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
        labelPort->setSizePolicy(sizePolicy);

        horizontalLayout_1->addWidget(labelPort);

        portNameBox = new QComboBox(SerialPort);
        portNameBox->setObjectName(QString::fromUtf8("portNameBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(portNameBox->sizePolicy().hasHeightForWidth());
        portNameBox->setSizePolicy(sizePolicy1);
        portNameBox->setMinimumSize(QSize(120, 0));
        portNameBox->setMaximumSize(QSize(120, 16777215));
        portNameBox->setStyleSheet(QString::fromUtf8("QComboBox { width: 120px }"));
        portNameBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        horizontalLayout_1->addWidget(portNameBox);

        labelBaudRate = new QLabel(SerialPort);
        labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
        sizePolicy.setHeightForWidth(labelBaudRate->sizePolicy().hasHeightForWidth());
        labelBaudRate->setSizePolicy(sizePolicy);

        horizontalLayout_1->addWidget(labelBaudRate);

        baudRateBox = new QComboBox(SerialPort);
        baudRateBox->addItem(QString::fromUtf8("1200"));
        baudRateBox->addItem(QString::fromUtf8("2400"));
        baudRateBox->addItem(QString::fromUtf8("4800"));
        baudRateBox->addItem(QString::fromUtf8("9600"));
        baudRateBox->addItem(QString::fromUtf8("14400"));
        baudRateBox->addItem(QString::fromUtf8("19200"));
        baudRateBox->addItem(QString::fromUtf8("28800"));
        baudRateBox->addItem(QString::fromUtf8("38400"));
        baudRateBox->addItem(QString::fromUtf8("57600"));
        baudRateBox->addItem(QString::fromUtf8("115200"));
        baudRateBox->addItem(QString::fromUtf8("230400"));
        baudRateBox->addItem(QString::fromUtf8("460800"));
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));
        sizePolicy1.setHeightForWidth(baudRateBox->sizePolicy().hasHeightForWidth());
        baudRateBox->setSizePolicy(sizePolicy1);
        baudRateBox->setMinimumSize(QSize(80, 0));
        baudRateBox->setMaximumSize(QSize(80, 16777215));
        baudRateBox->setFocusPolicy(Qt::ClickFocus);
        baudRateBox->setStyleSheet(QString::fromUtf8("QComboBox { width: 80px }"));
        baudRateBox->setEditable(true);
        baudRateBox->setCurrentText(QString::fromUtf8("1200"));
        baudRateBox->setMaxVisibleItems(20);

        horizontalLayout_1->addWidget(baudRateBox);


        retranslateUi(SerialPort);

        QMetaObject::connectSlotsByName(SerialPort);
    } // setupUi

    void retranslateUi(QWidget *SerialPort)
    {
        labelPort->setText(QCoreApplication::translate("SerialPort", "Port", nullptr));
        labelBaudRate->setText(QCoreApplication::translate("SerialPort", "Baud Rate", nullptr));

        (void)SerialPort;
    } // retranslateUi

};

namespace Ui {
    class SerialPort: public Ui_SerialPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
