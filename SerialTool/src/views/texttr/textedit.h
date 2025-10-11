#pragma once
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QColor>
#include <QFont>

class TextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit TextEdit(QWidget *parent = nullptr);

    // 保留原有签名，内部用 QPlainTextEdit 等价实现
    void append(const QString &text);
    void setFonts(QString fonts, int size, QColor color = Qt::black, QString style = "");
    void setHighLight(const QString &language); // 现阶段 no-op，占位保持兼容
    void setIndentationsUseTabs(bool enable);   // no-op：QPlainTextEdit 不区分 Tab/Space 缩进
    void setTabWidth(int width);                // 使用 tabStopDistance 近似替代
    void setAutoIndent(bool enable);            // no-op
    void setIndentationGuides(bool enable);     // no-op

public slots:
    void setWrap(bool wrap);

private slots:
    void onTextChanged();
    void onVScrollBarRangeChanged();
    void onVScrollBarValueChanged();

private:
    // 纯文本控件无“行号边距”，此函数留空以兼容旧调用
    void setMarginsWidth();

    // 语法高亮相关：全部留空（不依赖 QScintilla）
    void highlightNone();
    void highlightCpp();
    void highlightBash();
    void highlightLua();
    void highlightJSON();

private:
    QString fontFamily, m_language;
    QFont   lineNumFont;
    int     fontSize = 10;
    bool    isWrap   = false;
    bool    scrollEnd = true;
};
