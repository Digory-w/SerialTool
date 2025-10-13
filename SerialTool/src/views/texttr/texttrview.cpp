#include "texttrview.h"
#include "ui_texttrview.h"
#include "commandconfigdialog.h"
#include <QComboBox>
#include <QDateTime>
#include <QKeyEvent>
#include <QMessageBox>
#include <QSettings>
#include <QTextCodec>
#include <QTextCursor>
#include <QTextDocument>
#include <QTimer>

TextTRView::TextTRView(QWidget *parent) :
    AbstractView(parent),
    ui(new Ui::TextTRView)
{
    ui->setupUi(this);

    m_resendTimer = new QTimer;
    m_asciiBuf = new QByteArray;

    ui->textEditRx->setReadOnly(true);
    ui->textEditTx->setWrap(true); // Send area auto wrap.
    ui->showTxBox->setEnabled(false);
    ui->commandBox->setEnabled(false);

    setTextCodec("GB-2312"); // default

    connect(ui->wrapLineBox, SIGNAL(stateChanged(int)), this, SLOT(onWrapBoxChanged(int)));
    connect(ui->sendButton, &QPushButton::clicked, this, &TextTRView::onSendButtonClicked);
    connect(ui->resendBox, &QCheckBox::stateChanged, this, &TextTRView::updateResendTimerStatus);
    connect(m_resendTimer, &QTimer::timeout, this, &TextTRView::sendData);
    connect(ui->resendIntervalBox, SIGNAL(valueChanged(int)), this, SLOT(setResendInterval(int)));
    connect(ui->historyBox, SIGNAL(activated(const QString &)), this, SLOT(onHistoryBoxChanged(const QString &)));
    connect(ui->logFormatBox, &QCheckBox::toggled, this, &TextTRView::onLogFormatBoxToggled);
    connect(ui->filterEdit, &QLineEdit::textChanged, this, &TextTRView::onFilterTextChanged);
    connect(ui->clearFilterButton, &QPushButton::clicked, this, &TextTRView::onClearFilterButtonClicked);
    connect(ui->showRxBox, &QCheckBox::toggled, this, &TextTRView::onShowRxBoxToggled);
    connect(ui->showTxBox, &QCheckBox::toggled, this, &TextTRView::onShowTxBoxToggled);
    connect(ui->findNextButton, &QPushButton::clicked, this, &TextTRView::onFindNext);
    connect(ui->findPrevButton, &QPushButton::clicked, this, &TextTRView::onFindPrevious);
    connect(ui->searchEdit, &QLineEdit::returnPressed, this, &TextTRView::onSearchReturnPressed);
    connect(ui->commandBox, QOverload<int>::of(&QComboBox::activated),
            this, &TextTRView::onCommandBoxActivated);
    connect(ui->saveCommandButton, &QPushButton::clicked, this, &TextTRView::onSaveCommandClicked);
    connect(ui->manageCommandsButton, &QPushButton::clicked, this, &TextTRView::onManageCommandsClicked);
}

TextTRView::~TextTRView()
{
    delete ui;
    delete m_resendTimer;
    delete m_asciiBuf;
}

void TextTRView::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        if (event->key() == Qt::Key_Return) {
            onSendButtonClicked(); // Ctrl + Enter to send.
        }
    }
}

void TextTRView::retranslate()
{
    ui->retranslateUi(this);
}

// load terminal config
void TextTRView::loadConfig(QSettings *config)
{
    bool status;
    QRadioButton *rbtn;

    config->beginGroup("Terminal");

    // set tx/rx mode
    rbtn = config->value("ReceiveMode").toString() == "Hex" ? ui->portReadHex : ui->portReadAscii;
    rbtn->setChecked(true);
    rbtn = config->value("TransmitMode").toString() == "Hex" ? ui->portWriteHex : ui->portWriteAscii;
    rbtn->setChecked(true);

    // set resend
    int msc = config->value("RepeatInterval").toInt();
    msc = msc < 10 ? 1000 : msc;
    ui->resendIntervalBox->setValue(msc);
    ui->resendBox->setChecked(config->value("ResendMode").toBool());
    setResendInterval(msc);
    updateResendTimerStatus();

    // set warp line
    status = config->value("RxAreaWrapLine").toBool();
    ui->wrapLineBox->setChecked(status);
    ui->textEditRx->setWrap(status);

    // log format
    ui->logFormatBox->setChecked(config->value("LogFormatEnabled").toBool());
    onLogFormatBoxToggled(ui->logFormatBox->isChecked());

    // load history
    ui->historyBox->clear();
    loadHistory(config);

    // load user commands
    loadUserCommands(config);

    m_showRxMessages = ui->showRxBox->isChecked();
    m_showTxMessages = ui->showTxBox->isChecked();

    config->endGroup();
}

void TextTRView::saveConfig(QSettings *config)
{
    QString str;

    config->beginGroup("Terminal");

    // save tx/rx mode
    str = ui->portReadHex->isChecked() ? "Hex" : "Ascii";
    config->setValue("ReceiveMode", QVariant(str));
    str = ui->portWriteHex->isChecked() ? "Hex" : "Ascii";
    config->setValue("TransmitMode", QVariant(str));
    // save resend mode
    config->setValue("RepeatInterval", QVariant(ui->resendIntervalBox->value()));
    config->setValue("ResendMode", QVariant(ui->resendBox->isChecked()));
    // save warp line
    config->setValue("RxAreaWrapLine", QVariant(ui->wrapLineBox->isChecked()));
    config->setValue("LogFormatEnabled", QVariant(ui->logFormatBox->isChecked()));

    // save history
    saveHistory(config);

    // save user commands
    saveUserCommands(config);

    config->endGroup();
}

void TextTRView::loadSettings(QSettings *config)
{
    QString fontFamily(config->value("FontFamily").toString());
    QString fontStyle(config->value("FontStyle").toString());
    int fontSize = config->value("FontSize").toInt();

    fontSize = fontSize < 6 ? 10 : fontSize;
    setFontFamily(fontFamily, fontSize, fontStyle);

    // highlight
    setHighlight(config->value("TerminalHighlight").toString());
    // text codec
    setTextCodec(config->value("TerminalTextCodec").toString());
    setTabsInsertSpaces(config->value("TerminalTabsInsertSpaces").toBool());
    setTabWidth(config->value("TerminalTabWidth").toInt());
    setAutoIndent(config->value("TerminalAutoIndent").toBool());
    setIndentationGuides(config->value("TerminalIndentationGuides").toBool());

    m_timeStampFormat = config->value("TerminalLogTimeFormat",
                                      QStringLiteral("yyyy-MM-dd HH:mm:ss"))
                             .toString();
    if (m_timeStampFormat.isEmpty()) {
        m_timeStampFormat = QStringLiteral("yyyy-MM-dd HH:mm:ss");
    }
}

void TextTRView::loadHistory(QSettings *config)
{
    config->beginGroup("HistoryBox");
    int count = config->beginReadArray("Items");
    for (int i = 0; i < count; ++i) {
        config->setArrayIndex(i);
        ui->historyBox->addItem(config->value("data").toString());
    }
    config->endArray();
    ui->historyBox->setCurrentIndex(0);
    config->endGroup();
}

void TextTRView::saveHistory(QSettings *config)
{
    config->beginGroup("HistoryBox");
    int count = ui->historyBox->count();
    config->beginWriteArray("Items");
    for (int i = 0; i < count; ++i) {
        config->setArrayIndex(i);
        config->setValue("data", ui->historyBox->itemText(i));
    }
    config->endArray();
    config->endGroup();
}

void TextTRView::loadUserCommands(QSettings *config)
{
    m_userCommands.clear();
    config->beginGroup("UserCommands");
    int count = config->beginReadArray("Items");
    for (int i = 0; i < count; ++i) {
        config->setArrayIndex(i);
        QString cmd = config->value("data").toString();
        if (!cmd.isEmpty()) {
            m_userCommands.append(cmd);
        }
    }
    config->endArray();
    config->endGroup();
    populateCommandBox();
}

void TextTRView::saveUserCommands(QSettings *config)
{
    config->beginGroup("UserCommands");
    config->remove("");
    config->beginWriteArray("Items");
    for (int i = 0; i < m_userCommands.size(); ++i) {
        config->setArrayIndex(i);
        config->setValue("data", m_userCommands.at(i));
    }
    config->endArray();
    config->endGroup();
}

void TextTRView::setHighlight(const QString &language)
{
    // Send and Receive area highlight.
    ui->textEditTx->setHighLight(language);
    ui->textEditRx->setHighLight(language);
}

void TextTRView::appendLogEntry(LogDirection direction, const QString &text)
{
    if (text.isEmpty()) {
        return;
    }

    LogEntry entry;
    entry.direction = direction;
    entry.timestamp = QDateTime::currentDateTime();
    entry.content = text;
    m_logEntries.append(entry);

    refreshLogDisplay();
}

void TextTRView::refreshLogDisplay()
{
    QString buffer;
    for (const LogEntry &entry : m_logEntries) {
        if (!passesFilter(entry)) {
            continue;
        }

        QString formatted = formatLogEntry(entry);
        buffer.append(formatted);
        if (m_logFormatEnabled && !formatted.endsWith('\n')) {
            buffer.append('\n');
        }
    }

    ui->textEditRx->setPlainText(buffer);
    QTextCursor cursor = ui->textEditRx->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEditRx->setTextCursor(cursor);
}

bool TextTRView::passesFilter(const LogEntry &entry) const
{
    if (entry.direction == LogDirection::Receive) {
        if (!m_showRxMessages) {
            return false;
        }
    } else {
        if (!m_logFormatEnabled || !m_showTxMessages) {
            return false;
        }
    }

    if (!m_filterText.isEmpty()) {
        if (!entry.content.contains(m_filterText, Qt::CaseInsensitive)) {
            return false;
        }
    }

    return true;
}

QString TextTRView::formatLogEntry(const LogEntry &entry) const
{
    if (!m_logFormatEnabled) {
        return entry.content;
    }

    QString format = m_timeStampFormat;
    if (format.isEmpty()) {
        format = QStringLiteral("yyyy-MM-dd HH:mm:ss");
    }

    QString direction = entry.direction == LogDirection::Receive ? tr("RX") : tr("TX");
    QString prefix = QStringLiteral("[%1][%2] ")
                         .arg(entry.timestamp.toString(format), direction);

    QStringList lines = entry.content.split('\n', Qt::KeepEmptyParts);
    if (lines.isEmpty()) {
        lines.append(QString());
    }

    for (QString &line : lines) {
        line = prefix + line;
    }

    return lines.join('\n');
}

void TextTRView::populateCommandBox()
{
    QString previousSelection = ui->commandBox->currentText();
    ui->commandBox->clear();

    for (const QString &command : m_userCommands) {
        ui->commandBox->addItem(command);
    }

    int index = ui->commandBox->findText(previousSelection);
    if (index >= 0) {
        ui->commandBox->setCurrentIndex(index);
    } else if (!m_userCommands.isEmpty()) {
        ui->commandBox->setCurrentIndex(0);
    }

    ui->commandBox->setEnabled(!m_userCommands.isEmpty());
}

bool TextTRView::findText(const QString &text, QTextDocument::FindFlags flags)
{
    if (text.isEmpty()) {
        return false;
    }

    if (ui->textEditRx->find(text, flags)) {
        return true;
    }

    QTextCursor cursor = ui->textEditRx->textCursor();
    cursor.movePosition(flags.testFlag(QTextDocument::FindBackward)
                           ? QTextCursor::End
                           : QTextCursor::Start);
    ui->textEditRx->setTextCursor(cursor);
    return ui->textEditRx->find(text, flags);
}

void TextTRView::receiveData(const QByteArray &array)
{
    QString string, pre;
    if (ui->portReadAscii->isChecked()) {
        if (m_hexCount > 0) {
            pre = '\n';
        }
        m_hexCount = -1;
        arrayToString(string, array);
    } else {
        if (m_hexCount == -1) {
            m_hexCount = 0;
            pre = '\n';
        }
        arrayToHex(string, array, 16);
    }
    appendLogEntry(LogDirection::Receive, pre + string);
}

void TextTRView::clear()
{
    ui->textEditRx->clear();
    m_asciiBuf->clear();
    m_hexCount = 0;
    m_logEntries.clear();
    refreshLogDisplay();
}

void TextTRView::setFontFamily(QString fontFamily, int size, QString style)
{
    ui->textEditRx->setFonts(fontFamily, size, Qt::black, style);
    ui->textEditTx->setFonts(fontFamily, size, Qt::black, style);
}

void TextTRView::setEnabled(bool enabled)
{
    QString str;

    ui->sendButton->setEnabled(enabled);
    str = enabled ? tr("Ctrl + Enter to send") :
        tr("Connect port and start transmission to enable this button");
    ui->sendButton->setToolTip(str);
    // auto resend
    updateResendTimerStatus();
}

// send data
void TextTRView::sendData()
{
    QByteArray array;

    if (ui->portWriteAscii->isChecked() == true) {
        if(m_codecName == "ASCII"){
            array = ui->textEditTx->toPlainText().toLatin1();
        }else{
            QTextCodec *code = QTextCodec::codecForName(m_codecName);
            array = code->fromUnicode(ui->textEditTx->toPlainText());
        }
    } else {
        array = QByteArray::fromHex(ui->textEditTx->toPlainText().toLatin1());
    }
    emit transmitData(array);

    QString displayText = ui->textEditTx->toPlainText();
    if (!displayText.isEmpty()) {
        appendLogEntry(LogDirection::Transmit, displayText);
    }
}

void TextTRView::onWrapBoxChanged(int status)
{
    ui->textEditRx->setWrap(status);
}

void TextTRView::onLogFormatBoxToggled(bool checked)
{
    m_logFormatEnabled = checked;
    ui->showTxBox->setEnabled(checked);
    m_showTxMessages = ui->showTxBox->isChecked();
    refreshLogDisplay();
}

void TextTRView::onFilterTextChanged(const QString &text)
{
    m_filterText = text;
    refreshLogDisplay();
}

void TextTRView::onClearFilterButtonClicked()
{
    if (!ui->filterEdit->text().isEmpty()) {
        ui->filterEdit->clear();
    }
}

void TextTRView::onShowRxBoxToggled(bool checked)
{
    m_showRxMessages = checked;
    refreshLogDisplay();
}

void TextTRView::onShowTxBoxToggled(bool checked)
{
    m_showTxMessages = checked;
    refreshLogDisplay();
}

void TextTRView::onFindNext()
{
    QString text = ui->searchEdit->text();
    if (text.isEmpty()) {
        text = m_lastSearch;
    } else {
        m_lastSearch = text;
    }
    if (!text.isEmpty()) {
        findText(text);
    }
}

void TextTRView::onFindPrevious()
{
    QString text = ui->searchEdit->text();
    if (text.isEmpty()) {
        text = m_lastSearch;
    } else {
        m_lastSearch = text;
    }
    if (!text.isEmpty()) {
        findText(text, QTextDocument::FindBackward);
    }
}

void TextTRView::onSearchReturnPressed()
{
    onFindNext();
}

void TextTRView::onCommandBoxActivated(int index)
{
    if (index >= 0) {
        ui->textEditTx->setPlainText(ui->commandBox->itemText(index));
    }
}

void TextTRView::onSaveCommandClicked()
{
    QString command = ui->textEditTx->toPlainText().trimmed();
    if (command.isEmpty()) {
        QMessageBox::information(this, tr("Information"),
                                 tr("The command is empty and cannot be saved."));
        return;
    }

    int index = m_userCommands.indexOf(command);
    if (index == -1) {
        m_userCommands.prepend(command);
        populateCommandBox();
        ui->commandBox->setCurrentIndex(0);
    } else {
        ui->commandBox->setCurrentIndex(index);
    }
}

void TextTRView::onManageCommandsClicked()
{
    CommandConfigDialog dialog(m_userCommands, this);
    dialog.setPendingCommand(ui->textEditTx->toPlainText());
    if (dialog.exec() == QDialog::Accepted) {
        m_userCommands = dialog.commands();
        populateCommandBox();
    }
}

void TextTRView::onSendButtonClicked()
{
    QString str = ui->textEditTx->toPlainText();
    if (!str.isEmpty()) {
        sendData();

        // 历史记录下拉列表删除多余项
        while (ui->historyBox->count() >= 20) {
            ui->historyBox->removeItem(19);
        }
        // 数据写入历史记录下拉列表
        int i = ui->historyBox->findText(str);
        if (i != -1) { // 存在的项先删除
            ui->historyBox->removeItem(i);
        }
        ui->historyBox->insertItem(0, str); // 数据添加到第0个元素
        ui->historyBox->setCurrentIndex(0);
    }
}

void TextTRView::updateResendTimerStatus()
{
    if (ui->sendButton->isEnabled() && ui->resendBox->isChecked()) {
        m_resendTimer->start(ui->resendIntervalBox->text().toInt());
    } else {
        m_resendTimer->stop();
    }
}

//  set resend interval time
void TextTRView::setResendInterval(int msc)
{
    m_resendTimer->setInterval(msc);
}

void TextTRView::setTextCodec(const QString &name)
{
    if (name == "GB-2312") {
        m_textCodec = GB2312;
        m_codecName = "GB-2312";
    } else if (name == "GB-18030") {
        m_textCodec = GB18030;
        m_codecName = "GB-18030";
    } else if (name == "UTF-8") {
        m_textCodec = UTF8;
        m_codecName = "UTF-8";
    } else if (name == "UTF-16BE") {
        m_textCodec = UTF16;
        m_codecName = "UTF-16BE";
    } else if (name == "UTF-16LE") {
        m_textCodec = UTF16;
        m_codecName = "UTF-16LE";
    } else { // ASCII
        m_textCodec = ASCII;
        m_codecName = "ASCII";
    }
}

void TextTRView::onHistoryBoxChanged(const QString &string)
{
    ui->textEditTx->setPlainText(string);
}

void TextTRView::arrayToHex(QString &str, const QByteArray &array, int countOfLine)
{
    int len = array.length();
    str.resize(len * 3 + (len + m_hexCount) / countOfLine);
    for (int i = 0, j = 0; i < len; ++i) {
        uint8_t outChar = uint8_t(array[i]), t;   //每字节填充一次，直到结束
        //十六进制的转换
        t = (outChar >> 4) & 0x0F;
        str[j++] = t + (t < 10 ? '0' : 'A' - 10);
        t = outChar & 0x0F;
        str[j++] = t + (t < 10 ? '0' : 'A' - 10);
        str[j++] = ' ';
        if (m_hexCount >= countOfLine - 1) {
            m_hexCount = 0;
            str[j++] = '\n';
        } else {
            ++m_hexCount;
        }
    }
}

// array转UTF8
void TextTRView::arrayToUTF8(QString &str, const QByteArray &array)
{
    int lastIndex, cut = 0;
    bool isCut = false;

    m_asciiBuf->append(array);
    lastIndex = m_asciiBuf->length() - 1;
    if (m_asciiBuf->at(lastIndex) & 0x80) { // 0xxx xxxx -> OK
        // UTF8最大编码为4字节，因此向前搜寻三字节
        for (int i = lastIndex; i >= 0 && ++cut < 4; --i) {
            uint8_t byte = uint8_t(m_asciiBuf->at(i));
            if (((cut < 2) && (byte & 0xE0) == 0xC0) ||
                ((cut < 3) && (byte & 0xF0) == 0xE0) ||
                (byte & 0xF8) == 0xF0) {
                isCut = true;
                break;
            }
        }
    }
    lastIndex -= isCut ? cut - 1 : -1;
    QByteArray cutArray = m_asciiBuf->mid(lastIndex);
    m_asciiBuf->remove(lastIndex, cut);
    QTextCodec *code = QTextCodec::codecForName(m_codecName);
    str = code->toUnicode(*m_asciiBuf);
    m_asciiBuf->clear();
    m_asciiBuf->append(cutArray);
}

// array转双字节编码格式(GB2312等)
void TextTRView::arrayToDualByte(QString &str, const QByteArray &array)
{
    int lastIndex;
    bool isCut = false;

    m_asciiBuf->append(array);
    lastIndex = m_asciiBuf->length() - 1;
    for (int i = lastIndex; i >= 0 && m_asciiBuf->at(i) & 0x80; --i) {
        isCut = !isCut;
    }
    if (isCut) { // 字符串最末尾的非ASCII字节数不为2的整数倍
        char ch = m_asciiBuf->at(lastIndex);
        m_asciiBuf->remove(lastIndex, 1);
        QTextCodec *code = QTextCodec::codecForName(m_codecName);
        str = code->toUnicode(*m_asciiBuf);
        m_asciiBuf->clear();
        m_asciiBuf->append(ch);
    } else {
        QTextCodec *code = QTextCodec::codecForName(m_codecName);
        str = code->toUnicode(*m_asciiBuf);
        m_asciiBuf->clear();
    }
}

// array转Unicode
void TextTRView::arrayToUTF16(QString &str, const QByteArray &array)
{
    int lastIndex;
    bool isCut = false;;

    m_asciiBuf->append(array);
    lastIndex = m_asciiBuf->length() - 1;
    isCut = (lastIndex + 1) & 0x01;
    if (isCut) { // 字符串长度不为偶数
        char ch = m_asciiBuf->at(lastIndex);
        m_asciiBuf->remove(lastIndex, 1);
        QTextCodec *code = QTextCodec::codecForName(m_codecName);
        str = code->toUnicode(*m_asciiBuf);
        m_asciiBuf->clear();
        m_asciiBuf->append(ch);
    } else {
        QTextCodec *code = QTextCodec::codecForName(m_codecName);
        str = code->toUnicode(*m_asciiBuf);
        m_asciiBuf->clear();
    }
}

// array转ASCII
void TextTRView::arrayToASCII(QString &str, const QByteArray &array)
{
    if (m_asciiBuf->isEmpty()) {
        str = QString::fromLatin1(array);
    } else {
        m_asciiBuf->append(array);
        str = QString::fromLatin1(*m_asciiBuf);
        m_asciiBuf->clear();
    }
}

// 这个函数可以避免中文接收的乱码
void TextTRView::arrayToString(QString &str, const QByteArray &array)
{
    switch (m_textCodec) {
    case GB2312:
    case GB18030:
        arrayToDualByte(str, array);
        break;
    case UTF8:
        arrayToUTF8(str, array);
        break;
    case UTF16:
        arrayToUTF16(str, array);
        break;
    default: // ASCII
        arrayToASCII(str, array);
        break;
    }
}

void TextTRView::saveText(const QString &fname)
{
    QFile file(fname);

    if (file.open(QFile::WriteOnly)) {
        file.write(ui->textEditRx->toPlainText().toUtf8());
        file.close();
    }
}

void TextTRView::setTabsInsertSpaces(bool enable)
{
    ui->textEditTx->setIndentationsUseTabs(!enable);
}

void TextTRView::setTabWidth(int width)
{
    ui->textEditTx->setTabWidth(width);
}

void TextTRView::setAutoIndent(bool enable)
{
    ui->textEditTx->setAutoIndent(enable);
}

void TextTRView::setIndentationGuides(bool enable)
{
    ui->textEditTx->setIndentationGuides(enable);
}

QString TextTRView::saveFileFilter()
{
    return tr("Terminal Text File (*.txt)");
}

void TextTRView::saveFile(const QString &fileName, const QString &filter)
{
    if (filter == tr("Terminal Text File (*.txt)")) {
        saveText(fileName);
    }
}
