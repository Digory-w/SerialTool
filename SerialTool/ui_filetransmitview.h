/********************************************************************************
** Form generated from reading UI file 'filetransmitview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILETRANSMITVIEW_H
#define UI_FILETRANSMITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileTransmitView
{
public:
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *sendButton;
    QRadioButton *receiveButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *beforeSendEdit;
    QCheckBox *enableBerforSendBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QComboBox *protocolBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *stopButton;
    QPushButton *browseButton;
    QLabel *label_3;
    QProgressBar *progressBar;
    QLineEdit *pathBox;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FileTransmitView)
    {
        if (FileTransmitView->objectName().isEmpty())
            FileTransmitView->setObjectName(QString::fromUtf8("FileTransmitView"));
        FileTransmitView->resize(569, 246);
        verticalLayout_2 = new QVBoxLayout(FileTransmitView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        textEdit = new QTextEdit(FileTransmitView);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(FileTransmitView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sendButton = new QRadioButton(groupBox);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setChecked(true);

        verticalLayout->addWidget(sendButton);

        receiveButton = new QRadioButton(groupBox);
        receiveButton->setObjectName(QString::fromUtf8("receiveButton"));

        verticalLayout->addWidget(receiveButton);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(FileTransmitView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, -1, 4, 2);
        beforeSendEdit = new QTextEdit(groupBox_2);
        beforeSendEdit->setObjectName(QString::fromUtf8("beforeSendEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(beforeSendEdit->sizePolicy().hasHeightForWidth());
        beforeSendEdit->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(beforeSendEdit);

        enableBerforSendBox = new QCheckBox(groupBox_2);
        enableBerforSendBox->setObjectName(QString::fromUtf8("enableBerforSendBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(enableBerforSendBox->sizePolicy().hasHeightForWidth());
        enableBerforSendBox->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(enableBerforSendBox);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(FileTransmitView);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        protocolBox = new QComboBox(groupBox_3);
        protocolBox->addItem(QString());
        protocolBox->addItem(QString());
        protocolBox->addItem(QString());
        protocolBox->setObjectName(QString::fromUtf8("protocolBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(protocolBox->sizePolicy().hasHeightForWidth());
        protocolBox->setSizePolicy(sizePolicy3);
        protocolBox->setMinimumSize(QSize(90, 0));

        gridLayout_2->addWidget(protocolBox, 2, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        stopButton = new QPushButton(groupBox_3);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setEnabled(false);
        sizePolicy2.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(stopButton, 2, 4, 1, 1);

        browseButton = new QPushButton(groupBox_3);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        sizePolicy2.setHeightForWidth(browseButton->sizePolicy().hasHeightForWidth());
        browseButton->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(browseButton, 1, 4, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(progressBar, 0, 1, 1, 4);

        pathBox = new QLineEdit(groupBox_3);
        pathBox->setObjectName(QString::fromUtf8("pathBox"));

        gridLayout_2->addWidget(pathBox, 1, 1, 1, 3);

        startButton = new QPushButton(groupBox_3);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        sizePolicy2.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(startButton, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FileTransmitView);

        QMetaObject::connectSlotsByName(FileTransmitView);
    } // setupUi

    void retranslateUi(QWidget *FileTransmitView)
    {
        groupBox->setTitle(QCoreApplication::translate("FileTransmitView", "Mode", nullptr));
        sendButton->setText(QCoreApplication::translate("FileTransmitView", "Send", nullptr));
        receiveButton->setText(QCoreApplication::translate("FileTransmitView", "Receive", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("FileTransmitView", "Before Send", nullptr));
        enableBerforSendBox->setText(QCoreApplication::translate("FileTransmitView", "Use Berfor Send", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("FileTransmitView", "Operations", nullptr));
        protocolBox->setItemText(0, QCoreApplication::translate("FileTransmitView", "XModem", nullptr));
        protocolBox->setItemText(1, QCoreApplication::translate("FileTransmitView", "YModem", nullptr));
        protocolBox->setItemText(2, QCoreApplication::translate("FileTransmitView", "ZModem", nullptr));

        label->setText(QCoreApplication::translate("FileTransmitView", "File", nullptr));
        label_2->setText(QCoreApplication::translate("FileTransmitView", "Protocol", nullptr));
        stopButton->setText(QCoreApplication::translate("FileTransmitView", "Cancel", nullptr));
        browseButton->setText(QCoreApplication::translate("FileTransmitView", "Browse...", nullptr));
        label_3->setText(QCoreApplication::translate("FileTransmitView", "Progress", nullptr));
        startButton->setText(QCoreApplication::translate("FileTransmitView", "Start", nullptr));
        (void)FileTransmitView;
    } // retranslateUi

};

namespace Ui {
    class FileTransmitView: public Ui_FileTransmitView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILETRANSMITVIEW_H
