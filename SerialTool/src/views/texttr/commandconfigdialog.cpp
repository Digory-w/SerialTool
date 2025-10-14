#include "commandconfigdialog.h"
#include "commandeditdialog.h"

#include <QAbstractItemView>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QVariant>
#include <QVBoxLayout>

namespace {
QString displayTextForPreset(const CommandPreset &preset)
{
    if (!preset.name.isEmpty() && !preset.note.isEmpty()) {
        return QStringLiteral("%1 — %2").arg(preset.name, preset.note);
    }
    if (!preset.name.isEmpty()) {
        return preset.name;
    }
    if (!preset.note.isEmpty()) {
        return QStringLiteral("%1 — %2").arg(preset.command, preset.note);
    }
    return preset.command;
}
}

CommandConfigDialog::CommandConfigDialog(const QVector<CommandPreset> &commands, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Command Presets"));
    setModal(true);
    resize(360, 320);

    auto *mainLayout = new QVBoxLayout(this);

    m_listWidget = new QListWidget(this);
    m_listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    mainLayout->addWidget(m_listWidget);

    auto *buttonLayout = new QHBoxLayout();
    m_addButton = new QPushButton(tr("Add"), this);
    buttonLayout->addWidget(m_addButton);
    m_removeButton = new QPushButton(tr("Remove"), this);
    buttonLayout->addWidget(m_removeButton);
    buttonLayout->addStretch(1);
    mainLayout->addLayout(buttonLayout);

    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Close, this);
    mainLayout->addWidget(buttonBox);

    connect(m_addButton, &QPushButton::clicked, this, &CommandConfigDialog::addCommand);
    connect(m_removeButton, &QPushButton::clicked, this, &CommandConfigDialog::removeSelected);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &CommandConfigDialog::accept);
    connect(m_listWidget, &QListWidget::itemSelectionChanged, this, &CommandConfigDialog::updateButtonStates);

    for (const CommandPreset &preset : commands) {
        appendListItem(preset);
    }

    updateButtonStates();
}

QVector<CommandPreset> CommandConfigDialog::commands() const
{
    QVector<CommandPreset> result;
    result.reserve(m_listWidget->count());
    for (int i = 0; i < m_listWidget->count(); ++i) {
        result.append(presetFromItem(i));
    }
    return result;
}

void CommandConfigDialog::addCommand()
{
    CommandEditDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }
    const CommandPreset preset = dialog.preset();
    if (preset.command.isEmpty()) {
        return;
    }
    for (int i = 0; i < m_listWidget->count(); ++i) {
        CommandPreset existing = presetFromItem(i);
        const bool sameName = !preset.name.isEmpty() && !existing.name.isEmpty() &&
                existing.name.compare(preset.name, Qt::CaseInsensitive) == 0;
        const bool sameCommand = existing.command == preset.command;
        if (sameName || sameCommand) {
            applyPresetToItem(m_listWidget->item(i), preset);
            updateButtonStates();
            return;
        }
    }
    appendListItem(preset);
    updateButtonStates();
}

void CommandConfigDialog::removeSelected()
{
    const auto selected = m_listWidget->selectedItems();
    for (QListWidgetItem *item : selected) {
        delete item;
    }
    updateButtonStates();
}

void CommandConfigDialog::updateButtonStates()
{
    m_removeButton->setEnabled(!m_listWidget->selectedItems().isEmpty());
}

void CommandConfigDialog::appendListItem(const CommandPreset &preset)
{
    auto *item = new QListWidgetItem(m_listWidget);
    applyPresetToItem(item, preset);
}

void CommandConfigDialog::applyPresetToItem(QListWidgetItem *item, const CommandPreset &preset) const
{
    if (!item) {
        return;
    }
    item->setText(displayTextForPreset(preset));
    QVariantMap map;
    map.insert(QStringLiteral("name"), preset.name);
    map.insert(QStringLiteral("command"), preset.command);
    map.insert(QStringLiteral("note"), preset.note);
    item->setData(Qt::UserRole, map);
}

CommandPreset CommandConfigDialog::presetFromItem(int row) const
{
    CommandPreset preset;
    if (row < 0 || row >= m_listWidget->count()) {
        return preset;
    }
    const QVariant data = m_listWidget->item(row)->data(Qt::UserRole);
    const QVariantMap map = data.toMap();
    preset.name = map.value(QStringLiteral("name")).toString();
    preset.command = map.value(QStringLiteral("command")).toString();
    preset.note = map.value(QStringLiteral("note")).toString();
    return preset;
}

