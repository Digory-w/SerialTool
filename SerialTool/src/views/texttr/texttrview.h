#ifndef TEXTTRVIEW_H
#define TEXTTRVIEW_H

#include "../abstractview.h"

#include <QByteArray>
#include <QDateTime>
#include <QStringList>
#include <QVector>

namespace Ui {
class TextTRView;
}

class TextTRView : public AbstractView
{
    Q_OBJECT

public:
    explicit TextTRView(QWidget *parent = nullptr);
    ~TextTRView();

    QString title() { return tr("Text Tx/Rx"); }
    QString iid() { return "text_tx/rx"; }
    void retranslate();
    void loadConfig(QSettings *config);
    void saveConfig(QSettings *config);
    void loadSettings(QSettings *config);
    void receiveData(const QByteArray &array);
    void setEnabled(bool enabled);
    void clear();

    //QString openFileFilter();
    QString saveFileFilter();
    void saveFile(const QString &fileName, const QString &filter);

private:
    void setFontFamily(QString fonts, int size, QString style);
    void setHighlight(const QString &language);
    void setTextCodec(const QString &name);
    void setTabsInsertSpaces(bool enable);
    void setTabWidth(int width);
    void setAutoIndent(bool enable);
    void setIndentationGuides(bool enable);
    void saveText(const QString &fname);

    void appendReceivedEntry(const QString &text);
    void rebuildReceiveView();
    QString formatEntry(const QDateTime &timestamp, const QString &text) const;
    void refreshCommandBox();
    void loadUserCommands(QSettings *config);
    void saveUserCommands(QSettings *config);
    void rememberHistory(const QString &command);
    void findInReceive(bool forward);

    void keyPressEvent(QKeyEvent  *event);
    void arrayToHex(QString &str, const QByteArray &arr, int countOfLine);
    void arrayToString(QString &str, const QByteArray &arr);
    void loadHistory(QSettings *config);
    void saveHistory(QSettings *config);

    void arrayToUTF8(QString &str, const QByteArray &array);
    void arrayToUTF16(QString &str, const QByteArray &array);
    void arrayToDualByte(QString &str, const QByteArray &array);
    void arrayToASCII(QString &str, const QByteArray &array);

private slots:
    void sendData();
    void onWrapBoxChanged(int status);
    void onSendButtonClicked();
    void updateResendTimerStatus();
    void setResendInterval(int msc);
    void onHistoryBoxChanged(const QString &string);
    void onFilterTextChanged(const QString &text);
    void onClearFilterClicked();
    void onSearchReturnPressed();
    void onLogTimestampToggled(bool enabled);
    void onSaveCommandClicked();
    void onManageCommandsClicked();

private:
    enum TextCodec {
        ASCII,
        GB2312,
        GB18030,
        UTF8,
        UTF16
    };

    Ui::TextTRView *ui;
    int m_hexCount = 0;
    QTimer *m_resendTimer;
    QByteArray *m_asciiBuf;
    enum TextCodec m_textCodec;
    QByteArray m_codecName;
    bool m_logWithTimestamp = false;
    QString m_timeStampFormat;
    QVector<QDateTime> m_entryTimestamps;
    QStringList m_receivedTexts;
    QStringList m_historyRecords;
    QStringList m_userCommands;
};

#endif // TEXTTRVIEW_H
