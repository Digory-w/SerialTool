/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionOption;
    QAction *portSwitchAction;
    QAction *portRunAction;
    QAction *clearAction;
    QAction *portSetAction;
    QAction *actionClose;
    QAction *actionVisibleToolbar;
    QAction *actionVisibleStatusBar;
    QAction *actionAbout;
    QAction *actionWiki;
    QAction *actionOpen;
    QAction *actionStaysOnTop;
    QAction *actionUpdate;
    QAction *actionReset;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QToolBar *toolBar1;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 426);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setWindowTitle(QString::fromUtf8("SerialTool"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SerialTool/images/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/SerialTool/images/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionOption = new QAction(MainWindow);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/SerialTool/images/config.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOption->setIcon(icon2);
        portSwitchAction = new QAction(MainWindow);
        portSwitchAction->setObjectName(QString::fromUtf8("portSwitchAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/SerialTool/images/connect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        portSwitchAction->setIcon(icon3);
        portRunAction = new QAction(MainWindow);
        portRunAction->setObjectName(QString::fromUtf8("portRunAction"));
        portRunAction->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/SerialTool/images/pause.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/SerialTool/images/pause.png"), QSize(), QIcon::Active, QIcon::Off);
        portRunAction->setIcon(icon4);
        clearAction = new QAction(MainWindow);
        clearAction->setObjectName(QString::fromUtf8("clearAction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/SerialTool/images/clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        clearAction->setIcon(icon5);
        portSetAction = new QAction(MainWindow);
        portSetAction->setObjectName(QString::fromUtf8("portSetAction"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/SerialTool/images/port config.ico"), QSize(), QIcon::Normal, QIcon::Off);
        portSetAction->setIcon(icon6);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/SerialTool/images/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon7);
        actionVisibleToolbar = new QAction(MainWindow);
        actionVisibleToolbar->setObjectName(QString::fromUtf8("actionVisibleToolbar"));
        actionVisibleToolbar->setCheckable(true);
        actionVisibleToolbar->setChecked(true);
        actionVisibleStatusBar = new QAction(MainWindow);
        actionVisibleStatusBar->setObjectName(QString::fromUtf8("actionVisibleStatusBar"));
        actionVisibleStatusBar->setCheckable(true);
        actionVisibleStatusBar->setChecked(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionWiki = new QAction(MainWindow);
        actionWiki->setObjectName(QString::fromUtf8("actionWiki"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/SerialTool/images/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon8);
        actionStaysOnTop = new QAction(MainWindow);
        actionStaysOnTop->setObjectName(QString::fromUtf8("actionStaysOnTop"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/SerialTool/images/pin_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStaysOnTop->setIcon(icon9);
        actionUpdate = new QAction(MainWindow);
        actionUpdate->setObjectName(QString::fromUtf8("actionUpdate"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/SerialTool/images/reset.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        MainWindow->setMenuBar(menuBar);
        toolBar1 = new QToolBar(MainWindow);
        toolBar1->setObjectName(QString::fromUtf8("toolBar1"));
        toolBar1->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
        toolBar1->setIconSize(QSize(20, 20));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar1);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addSeparator();
        menu->addAction(actionClose);
        menu_2->addAction(actionOption);
        menu_2->addSeparator();
        menu_3->addAction(portSwitchAction);
        menu_3->addAction(portRunAction);
        menu_3->addAction(clearAction);
        menu_3->addSeparator();
        menu_3->addAction(portSetAction);
        menu_4->addSeparator();
        menu_4->addAction(actionVisibleToolbar);
        menu_4->addAction(actionVisibleStatusBar);
        menu_4->addSeparator();
        menu_4->addAction(actionStaysOnTop);
        menu_5->addAction(actionWiki);
        menu_5->addAction(actionAbout);
        menu_5->addAction(actionUpdate);
        toolBar1->addAction(portSetAction);
        toolBar1->addSeparator();
        toolBar1->addAction(portSwitchAction);
        toolBar1->addAction(actionReset);
        toolBar1->addAction(portRunAction);
        toolBar1->addAction(clearAction);
        toolBar1->addSeparator();
        toolBar1->addAction(actionOption);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOption->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        portSwitchAction->setText(QCoreApplication::translate("MainWindow", "Open Port", nullptr));
#if QT_CONFIG(shortcut)
        portSwitchAction->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        portRunAction->setText(QCoreApplication::translate("MainWindow", "Pause Tx/Rx", nullptr));
#if QT_CONFIG(shortcut)
        portRunAction->setShortcut(QCoreApplication::translate("MainWindow", "Alt+R", nullptr));
#endif // QT_CONFIG(shortcut)
        clearAction->setText(QCoreApplication::translate("MainWindow", "Clear Buffer", nullptr));
#if QT_CONFIG(shortcut)
        clearAction->setShortcut(QCoreApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        portSetAction->setText(QCoreApplication::translate("MainWindow", "Port Settings", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionVisibleToolbar->setText(QCoreApplication::translate("MainWindow", "Tool Bar", nullptr));
        actionVisibleStatusBar->setText(QCoreApplication::translate("MainWindow", "Status Bar", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWiki->setText(QCoreApplication::translate("MainWindow", "Wiki", nullptr));
#if QT_CONFIG(tooltip)
        actionWiki->setToolTip(QCoreApplication::translate("MainWindow", "Wiki", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStaysOnTop->setText(QCoreApplication::translate("MainWindow", "Stays On Top", nullptr));
        actionUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
#if QT_CONFIG(tooltip)
        actionReset->setToolTip(QCoreApplication::translate("MainWindow", "Reset", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar1->setWindowTitle(QCoreApplication::translate("MainWindow", "Tool Bar", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
