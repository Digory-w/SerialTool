#ifndef TEXTTRVIEW_H
#define TEXTTRVIEW_H

#include "../abstractview.h"
#include <QDateTime>
#include <QList>
#include <QStringList>
#include <QTextDocument>

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
    enum class LogDirection {
        Receive,
        Transmit
    };

    struct LogEntry {
        LogDirection direction;
        QDateTime timestamp;
        QString content;
    };

    void setFontFamily(QString fonts, int size, QString style);
    void setHighlight(const QString &language);
    void setTextCodec(const QString &name);
    void setTabsInsertSpaces(bool enable);
    void setTabWidth(int width);
    void setAutoIndent(bool enable);
    void setIndentationGuides(bool enable);
    void saveText(const QString &fname);

    void keyPressEvent(QKeyEvent  *event);
    void arrayToHex(QString &str, const QByteArray &arr, int countOfLine);
    void arrayToString(QString &str, const QByteArray &arr);
    void loadHistory(QSettings *config);
    void saveHistory(QSettings *config);
    void loadUserCommands(QSettings *config);
    void saveUserCommands(QSettings *config);
    void appendLogEntry(LogDirection direction, const QString &text);
    void refreshLogDisplay();
    bool passesFilter(const LogEntry &entry) const;
    QString formatLogEntry(const LogEntry &entry) const;
    void populateCommandBox();
    bool findText(const QString &text, QTextDocument::FindFlags flags = {});

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
    void onLogFormatBoxToggled(bool checked);
    void onFilterTextChanged(const QString &text);
    void onClearFilterButtonClicked();
    void onShowRxBoxToggled(bool checked);
    void onShowTxBoxToggled(bool checked);
    void onFindNext();
    void onFindPrevious();
    void onSearchReturnPressed();
    void onCommandBoxActivated(int index);
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
    QList<LogEntry> m_logEntries;
    bool m_logFormatEnabled = false;
    bool m_showRxMessages = true;
    bool m_showTxMessages = true;
    QString m_filterText;
    QString m_timeStampFormat;
    QStringList m_userCommands;
    QString m_lastSearch;
};

#endif // TEXTTRVIEW_H
