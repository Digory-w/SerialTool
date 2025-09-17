/********************************************************************************
** Form generated from reading UI file 'texttrview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTTRVIEW_H
#define UI_TEXTTRVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/views/texttr/textedit.h"

QT_BEGIN_NAMESPACE

class Ui_TextTRView
{
public:
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_2;
    TextEdit *textEditRx;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_19;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_20;
    QRadioButton *portReadAscii;
    QRadioButton *portReadHex;
    QCheckBox *wrapLineBox;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_21;
    QRadioButton *portWriteAscii;
    QRadioButton *portWriteHex;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *resendBox;
    QSpinBox *resendIntervalBox;
    QLabel *label_7;
    QGridLayout *gridLayout_7;
    QPushButton *sendButton;
    QComboBox *historyBox;
    TextEdit *textEditTx;

    void setupUi(QWidget *TextTRView)
    {
        if (TextTRView->objectName().isEmpty())
            TextTRView->setObjectName(QString::fromUtf8("TextTRView"));
        TextTRView->resize(540, 300);
        verticalLayout_2 = new QVBoxLayout(TextTRView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        splitter_2 = new QSplitter(TextTRView);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        textEditRx = new TextEdit(splitter_2);
        textEditRx->setObjectName(QString::fromUtf8("textEditRx"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(textEditRx->sizePolicy().hasHeightForWidth());
        textEditRx->setSizePolicy(sizePolicy);
        textEditRx->setFocusPolicy(Qt::ClickFocus);
        splitter_2->addWidget(textEditRx);
        layoutWidget_5 = new QWidget(splitter_2);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(layoutWidget_5);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        verticalLayout_16 = new QVBoxLayout(widget_5);
        verticalLayout_16->setSpacing(3);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        groupBox_9 = new QGroupBox(widget_5);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy2);
        verticalLayout_17 = new QVBoxLayout(groupBox_9);
        verticalLayout_17->setSpacing(2);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(4, -1, 4, 4);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        portReadAscii = new QRadioButton(groupBox_9);
        portReadAscii->setObjectName(QString::fromUtf8("portReadAscii"));
        portReadAscii->setText(QString::fromUtf8("ASCII"));
        portReadAscii->setChecked(true);

        horizontalLayout_20->addWidget(portReadAscii);

        portReadHex = new QRadioButton(groupBox_9);
        portReadHex->setObjectName(QString::fromUtf8("portReadHex"));
        portReadHex->setText(QString::fromUtf8("Hex"));

        horizontalLayout_20->addWidget(portReadHex);


        verticalLayout_17->addLayout(horizontalLayout_20);

        wrapLineBox = new QCheckBox(groupBox_9);
        wrapLineBox->setObjectName(QString::fromUtf8("wrapLineBox"));
        wrapLineBox->setEnabled(true);

        verticalLayout_17->addWidget(wrapLineBox);


        verticalLayout_16->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(widget_5);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        sizePolicy2.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy2);
        verticalLayout_18 = new QVBoxLayout(groupBox_10);
        verticalLayout_18->setSpacing(2);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(4, -1, 4, 4);
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        portWriteAscii = new QRadioButton(groupBox_10);
        portWriteAscii->setObjectName(QString::fromUtf8("portWriteAscii"));
        portWriteAscii->setText(QString::fromUtf8("ASCII"));
        portWriteAscii->setChecked(true);

        horizontalLayout_21->addWidget(portWriteAscii);

        portWriteHex = new QRadioButton(groupBox_10);
        portWriteHex->setObjectName(QString::fromUtf8("portWriteHex"));
        portWriteHex->setText(QString::fromUtf8("Hex"));

        horizontalLayout_21->addWidget(portWriteHex);


        verticalLayout_18->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(2);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        resendBox = new QCheckBox(groupBox_10);
        resendBox->setObjectName(QString::fromUtf8("resendBox"));

        horizontalLayout_22->addWidget(resendBox);

        resendIntervalBox = new QSpinBox(groupBox_10);
        resendIntervalBox->setObjectName(QString::fromUtf8("resendIntervalBox"));
        resendIntervalBox->setMinimum(10);
        resendIntervalBox->setMaximum(120000);
        resendIntervalBox->setValue(1000);

        horizontalLayout_22->addWidget(resendIntervalBox);

        label_7 = new QLabel(groupBox_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_22->addWidget(label_7);


        verticalLayout_18->addLayout(horizontalLayout_22);


        verticalLayout_16->addWidget(groupBox_10);


        horizontalLayout_19->addWidget(widget_5, 0, Qt::AlignBottom);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(3);
        sendButton = new QPushButton(layoutWidget_5);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(sendButton, 2, 1, 1, 1);

        historyBox = new QComboBox(layoutWidget_5);
        historyBox->setObjectName(QString::fromUtf8("historyBox"));

        gridLayout_7->addWidget(historyBox, 2, 0, 1, 1);

        textEditTx = new TextEdit(layoutWidget_5);
        textEditTx->setObjectName(QString::fromUtf8("textEditTx"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEditTx->sizePolicy().hasHeightForWidth());
        textEditTx->setSizePolicy(sizePolicy3);
        textEditTx->setFocusPolicy(Qt::StrongFocus);

        gridLayout_7->addWidget(textEditTx, 0, 0, 1, 2);


        horizontalLayout_19->addLayout(gridLayout_7);

        splitter_2->addWidget(layoutWidget_5);

        verticalLayout_2->addWidget(splitter_2);

        QWidget::setTabOrder(textEditTx, sendButton);
        QWidget::setTabOrder(sendButton, historyBox);
        QWidget::setTabOrder(historyBox, portReadAscii);
        QWidget::setTabOrder(portReadAscii, portReadHex);
        QWidget::setTabOrder(portReadHex, wrapLineBox);
        QWidget::setTabOrder(wrapLineBox, portWriteAscii);
        QWidget::setTabOrder(portWriteAscii, portWriteHex);
        QWidget::setTabOrder(portWriteHex, resendBox);
        QWidget::setTabOrder(resendBox, resendIntervalBox);

        retranslateUi(TextTRView);

        QMetaObject::connectSlotsByName(TextTRView);
    } // setupUi

    void retranslateUi(QWidget *TextTRView)
    {
        groupBox_9->setTitle(QCoreApplication::translate("TextTRView", "Rx Settings", nullptr));
        wrapLineBox->setText(QCoreApplication::translate("TextTRView", "Wrap Line", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("TextTRView", "Tx Settings", nullptr));
        resendBox->setText(QCoreApplication::translate("TextTRView", "Resend", nullptr));
        label_7->setText(QCoreApplication::translate("TextTRView", "ms", nullptr));
        sendButton->setText(QCoreApplication::translate("TextTRView", "Send", nullptr));
        (void)TextTRView;
    } // retranslateUi

};

namespace Ui {
    class TextTRView: public Ui_TextTRView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTTRVIEW_H
