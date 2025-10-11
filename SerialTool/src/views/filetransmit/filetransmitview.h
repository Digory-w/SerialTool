#ifndef FILETRANSFERVIEW_H
#define FILETRANSFERVIEW_H

#include "../abstractview.h"
#include "filethread.h"

#include <QString>      // 用在返回值
#include <QByteArray>   // 用在参数/成员
#include <QColor>       // 用在默认参数 Qt::black

class QSettings;        // 只做指针/引用传递：前置声明即可
class QAction;          // 若接口里出现 QAction*，同理前置声明

namespace Ui { class FileTransmitView; }

class FileTransmitView : public AbstractView
{
    Q_OBJECT
public:
    explicit FileTransmitView(QWidget *parent = nullptr);
    ~FileTransmitView() override;

    QString title() { return tr("File Transmit"); }
    QString iid()   { return "file_transmit"; }

    void retranslate();
    void loadConfig(QSettings *config);
    void saveConfig(QSettings *config);
    void setEnabled(bool enabled) override;

public slots:
    void receiveData(const QByteArray &array);
    void cancelTransfer();
    void logOut(const QString &string, QColor color = Qt::black);

private:
    void beforceSend();

private slots:
    void browseButtonClicked();
    void portSendData(const QByteArray &array);
    void sendFile();
    void onTransFinsh();
    void onTimeoutError();

private:
    Ui::FileTransmitView *ui;
    FileThread thread;
    QByteArray receiveArray;
};

#endif // FILETRANSFERVIEW_H
