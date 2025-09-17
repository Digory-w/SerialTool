#include "scriptextensionview.h"
#include <QHBoxLayout>
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QPushButton>
#include <QLabel>

ScriptExtensionView::ScriptExtensionView(const QString &fileName, QWidget *parent) :
    AbstractView(parent),
    m_fileName(fileName)
{
    // Script functionality disabled - Qt Script module not available
    // Create a simple placeholder UI indicating the feature is disabled
    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *label = new QLabel(tr("Script extensions not available\n(Qt Script module removed for compatibility)"), this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel { color: gray; font-style: italic; }");
    layout->addWidget(label);
    setLayout(layout);
    
    qDebug() << "Script extension disabled for file:" << fileName;
}

void ScriptExtensionView::loadUi(const QString &fileName)
{
    // UI loading disabled - script functionality not available
    Q_UNUSED(fileName);
}

void ScriptExtensionView::transmitData(const QString &data)
{
    // Script functionality disabled
    Q_UNUSED(data);
}

void ScriptExtensionView::sendMessage(const QString &receiver, const QString &message)
{
    // Script functionality disabled
    Q_UNUSED(receiver);
    Q_UNUSED(message);
}

QString ScriptExtensionView::title()
{
    return tr("Script Extension (Disabled)");
}

QString ScriptExtensionView::iid()
{
    return "ScriptExtensionView_Disabled";
}

void ScriptExtensionView::clear()
{
    // Script functionality disabled
}

void ScriptExtensionView::loadConfig(QSettings *config)
{
    // Script functionality disabled
    Q_UNUSED(config);
}

void ScriptExtensionView::saveConfig(QSettings *config)
{
    // Script functionality disabled
    Q_UNUSED(config);
}

void ScriptExtensionView::loadSettings(QSettings *config)
{
    // Script functionality disabled
    Q_UNUSED(config);
}

void ScriptExtensionView::retranslate()
{
    // Script functionality disabled
}

void ScriptExtensionView::receiveData(const QByteArray &array)
{
    // Script functionality disabled
    Q_UNUSED(array);
}

void ScriptExtensionView::setEnabled(bool enabled)
{
    // Script functionality disabled
    Q_UNUSED(enabled);
    AbstractView::setEnabled(false); // Always disabled
}

QString ScriptExtensionView::openFileFilter()
{
    return QString(); // No file operations supported
}

QString ScriptExtensionView::saveFileFilter()
{
    return QString(); // No file operations supported
}

void ScriptExtensionView::saveFile(const QString &fileName, const QString &filter)
{
    // Script functionality disabled
    Q_UNUSED(fileName);
    Q_UNUSED(filter);
}

void ScriptExtensionView::openFile(const QString &fileName, const QString &filter)
{
    // Script functionality disabled
    Q_UNUSED(fileName);
    Q_UNUSED(filter);
}

void ScriptExtensionView::takeMessage(const QString &sender, const QByteArray &message)
{
    // Script functionality disabled
    Q_UNUSED(sender);
    Q_UNUSED(message);
}
