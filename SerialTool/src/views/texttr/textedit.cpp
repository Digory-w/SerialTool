#include "textedit.h"
#include <QTextCursor>
#include <QTextBlock>
#include <QFontMetrics>
#include <QApplication>

TextEdit::TextEdit(QWidget *parent)
    : QPlainTextEdit(parent)
{
    // 和旧行为保持一致：默认不自动换行，Tab 不跳焦点
    setLineWrapMode(QPlainTextEdit::NoWrap);
    setTabChangesFocus(false);

    // 信号连接：改用 QPlainTextEdit 自带信号
    connect(this, &QPlainTextEdit::textChanged, this, &TextEdit::onTextChanged);
    connect(verticalScrollBar(), &QScrollBar::rangeChanged,
            this, &TextEdit::onVScrollBarRangeChanged);
    connect(verticalScrollBar(), &QScrollBar::valueChanged,
            this, &TextEdit::onVScrollBarValueChanged);
}

void TextEdit::append(const QString &text)
{
    // 若光标原本在末尾，保持末尾附加与跟随
    const bool atEnd = (textCursor().position() == document()->characterCount()-1);
    QTextCursor c = textCursor();
    c.movePosition(QTextCursor::End);
    c.insertText(text);
    if (atEnd || scrollEnd) {
        setTextCursor(c);
        verticalScrollBar()->setValue(verticalScrollBar()->maximum());
    }
}

void TextEdit::setFonts(QString fonts, int size, QColor color, QString style)
{
    fontFamily = fonts;
    fontSize   = size;
    lineNumFont = QFont(fonts.section(',', 0, 0), size);

    QFont f(fonts.section(',', 0, 0), size);
    f.setBold(style.contains("bold", Qt::CaseInsensitive));
    f.setItalic(style.contains("italic", Qt::CaseInsensitive));
    setFont(f);
    setStyleSheet(QString("QPlainTextEdit { color: %1; }").arg(color.name()));

    // 纯文本控件没有行号边距与滚动宽度追踪；保持兼容占位
    setMarginsWidth();

    // 你之前在 setFonts() 里会重设高亮，这里保留调用但内部是 no-op
    setHighLight(m_language);
}

void TextEdit::setWrap(bool wrap)
{
    setLineWrapMode(wrap ? QPlainTextEdit::WidgetWidth : QPlainTextEdit::NoWrap);
    isWrap = wrap;
}

void TextEdit::onTextChanged()
{
    if (scrollEnd && isVisible()) {
        verticalScrollBar()->setValue(verticalScrollBar()->maximum());
    }
}

void TextEdit::onVScrollBarRangeChanged()
{
    if (scrollEnd) {
        verticalScrollBar()->setValue(verticalScrollBar()->maximum());
    }
}

void TextEdit::onVScrollBarValueChanged()
{
    QScrollBar *sb = verticalScrollBar();
    scrollEnd = (sb->value() == sb->maximum());
}

// —— 以下均为兼容占位实现（不依赖 QScintilla）——
void TextEdit::setMarginsWidth() {}
void TextEdit::setIndentationsUseTabs(bool) {}
void TextEdit::setTabWidth(int width) {
    // 近似：tabStopDistance 以像素为单位；这里按字符宽 * width
    QFontMetrics fm(font());
    setTabStopDistance(fm.horizontalAdvance(' ') * qMax(1, width));
}
void TextEdit::setAutoIndent(bool) {}
void TextEdit::setIndentationGuides(bool) {}
void TextEdit::setHighLight(const QString &language) { m_language = language; }
void TextEdit::highlightNone() {}
void TextEdit::highlightCpp() {}
void TextEdit::highlightBash() {}
void TextEdit::highlightLua() {}
void TextEdit::highlightJSON() {}
