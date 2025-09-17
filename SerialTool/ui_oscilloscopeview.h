/********************************************************************************
** Form generated from reading UI file 'oscilloscopeview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSCILLOSCOPEVIEW_H
#define UI_OSCILLOSCOPEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/views/oscilloscope/plotview.h"

QT_BEGIN_NAMESPACE

class Ui_OscilloscopeView
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    PlotView *plotView;
    QScrollBar *horizontalScrollBar;
    QVBoxLayout *verticalLayout_2;
    QListWidget *channelList;
    QLabel *label;
    QDoubleSpinBox *yRangeBox;
    QLabel *label_2;
    QDoubleSpinBox *yOffsetBox;
    QLabel *label_3;
    QComboBox *xRangeBox;
    QCheckBox *holdReceiveBox;

    void setupUi(QWidget *OscilloscopeView)
    {
        if (OscilloscopeView->objectName().isEmpty())
            OscilloscopeView->setObjectName(QString::fromUtf8("OscilloscopeView"));
        OscilloscopeView->resize(554, 341);
        horizontalLayout = new QHBoxLayout(OscilloscopeView);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(OscilloscopeView);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plotView = new PlotView(widget);
        plotView->setObjectName(QString::fromUtf8("plotView"));

        verticalLayout->addWidget(plotView);

        horizontalScrollBar = new QScrollBar(widget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setMaximum(0);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        horizontalLayout->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        channelList = new QListWidget(OscilloscopeView);
        channelList->setObjectName(QString::fromUtf8("channelList"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(channelList->sizePolicy().hasHeightForWidth());
        channelList->setSizePolicy(sizePolicy1);
        channelList->setStyleSheet(QString::fromUtf8("QListWidget { width: 4.8em }"));

        verticalLayout_2->addWidget(channelList);

        label = new QLabel(OscilloscopeView);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label);

        yRangeBox = new QDoubleSpinBox(OscilloscopeView);
        yRangeBox->setObjectName(QString::fromUtf8("yRangeBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(yRangeBox->sizePolicy().hasHeightForWidth());
        yRangeBox->setSizePolicy(sizePolicy3);
        yRangeBox->setMinimum(2.000000000000000);
        yRangeBox->setMaximum(100000.000000000000000);

        verticalLayout_2->addWidget(yRangeBox);

        label_2 = new QLabel(OscilloscopeView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_2);

        yOffsetBox = new QDoubleSpinBox(OscilloscopeView);
        yOffsetBox->setObjectName(QString::fromUtf8("yOffsetBox"));
        sizePolicy3.setHeightForWidth(yOffsetBox->sizePolicy().hasHeightForWidth());
        yOffsetBox->setSizePolicy(sizePolicy3);
        yOffsetBox->setMinimum(-100000.000000000000000);
        yOffsetBox->setMaximum(100000.000000000000000);

        verticalLayout_2->addWidget(yOffsetBox);

        label_3 = new QLabel(OscilloscopeView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_3);

        xRangeBox = new QComboBox(OscilloscopeView);
        xRangeBox->addItem(QString::fromUtf8("10"));
        xRangeBox->addItem(QString::fromUtf8("20"));
        xRangeBox->addItem(QString::fromUtf8("25"));
        xRangeBox->addItem(QString::fromUtf8("50"));
        xRangeBox->addItem(QString::fromUtf8("100"));
        xRangeBox->addItem(QString::fromUtf8("200"));
        xRangeBox->addItem(QString::fromUtf8("250"));
        xRangeBox->addItem(QString::fromUtf8("500"));
        xRangeBox->addItem(QString::fromUtf8("1000"));
        xRangeBox->addItem(QString::fromUtf8("2000"));
        xRangeBox->addItem(QString::fromUtf8("2500"));
        xRangeBox->addItem(QString::fromUtf8("5000"));
        xRangeBox->addItem(QString::fromUtf8("10000"));
        xRangeBox->setObjectName(QString::fromUtf8("xRangeBox"));
        sizePolicy3.setHeightForWidth(xRangeBox->sizePolicy().hasHeightForWidth());
        xRangeBox->setSizePolicy(sizePolicy3);
        xRangeBox->setEditable(true);
        xRangeBox->setMaxVisibleItems(20);

        verticalLayout_2->addWidget(xRangeBox);

        holdReceiveBox = new QCheckBox(OscilloscopeView);
        holdReceiveBox->setObjectName(QString::fromUtf8("holdReceiveBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(holdReceiveBox->sizePolicy().hasHeightForWidth());
        holdReceiveBox->setSizePolicy(sizePolicy4);
        holdReceiveBox->setChecked(true);

        verticalLayout_2->addWidget(holdReceiveBox);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(OscilloscopeView);

        QMetaObject::connectSlotsByName(OscilloscopeView);
    } // setupUi

    void retranslateUi(QWidget *OscilloscopeView)
    {
        label->setText(QCoreApplication::translate("OscilloscopeView", "Y Range", nullptr));
        label_2->setText(QCoreApplication::translate("OscilloscopeView", "Y Offset", nullptr));
        label_3->setText(QCoreApplication::translate("OscilloscopeView", "X Points", nullptr));

        holdReceiveBox->setText(QCoreApplication::translate("OscilloscopeView", "Hold Receive", nullptr));
        (void)OscilloscopeView;
    } // retranslateUi

};

namespace Ui {
    class OscilloscopeView: public Ui_OscilloscopeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSCILLOSCOPEVIEW_H
