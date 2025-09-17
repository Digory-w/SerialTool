/********************************************************************************
** Form generated from reading UI file 'valuedisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALUEDISPLAY_H
#define UI_VALUEDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ValueDisplay
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ValueDisplay)
    {
        if (ValueDisplay->objectName().isEmpty())
            ValueDisplay->setObjectName(QString::fromUtf8("ValueDisplay"));
        ValueDisplay->resize(500, 200);
        verticalLayout = new QVBoxLayout(ValueDisplay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(ValueDisplay);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->verticalHeader()->setMinimumSectionSize(24);
        tableWidget->verticalHeader()->setDefaultSectionSize(24);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ValueDisplay);

        QMetaObject::connectSlotsByName(ValueDisplay);
    } // setupUi

    void retranslateUi(QDialog *ValueDisplay)
    {
        ValueDisplay->setWindowTitle(QCoreApplication::translate("ValueDisplay", "Value Display", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ValueDisplay", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ValueDisplay", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ValueDisplay", "Additional", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ValueDisplay: public Ui_ValueDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALUEDISPLAY_H
