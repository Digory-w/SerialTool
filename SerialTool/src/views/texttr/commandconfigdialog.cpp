#include "commandconfigdialog.h"

#include <QAbstractItemView>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

namespace {

constexpr int kCommandRole = Qt::UserRole;
constexpr int kNameRole = Qt::UserRole + 1;
constexpr int kRemarkRole = Qt::UserRole + 2;

}

CommandConfigDialog::CommandConfigDialog(const QVector<UserCommand> &commands, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Command Presets"));
    setModal(true);
    resize(360, 320);

    auto *mainLayout = new QVBoxLayout(this);

    m_listWidget = new QListWidget(this);
    for (const UserCommand &command : commands) {
        auto *item = new QListWidgetItem(displayText(command), m_listWidget);
        item->setData(kCommandRole, command.command);
        item->setData(kNameRole, command.name);
        item->setData(kRemarkRole, command.remark);
        if (!command.remark.isEmpty()) {
            item->setToolTip(command.remark);
        }
    }
    m_listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    mainLayout->addWidget(m_listWidget);

    auto *formLayout = new QFormLayout();
    m_nameEdit = new QLineEdit(this);
    m_nameEdit->setPlaceholderText(tr("Command name"));
    formLayout->addRow(tr("Name"), m_nameEdit);

    m_commandEdit = new QLineEdit(this);
    m_commandEdit->setPlaceholderText(tr("Command"));
    formLayout->addRow(tr("Command"), m_commandEdit);

    m_remarkEdit = new QLineEdit(this);
    m_remarkEdit->setPlaceholderText(tr("Remark"));
    formLayout->addRow(tr("Remark"), m_remarkEdit);

    mainLayout->addLayout(formLayout);

    auto *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    m_addButton = new QPushButton(tr("Add"), this);
    buttonLayout->addWidget(m_addButton);

    m_updateButton = new QPushButton(tr("Update"), this);
    buttonLayout->addWidget(m_updateButton);

    mainLayout->addLayout(buttonLayout);

    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Close, this);
    m_removeButton = new QPushButton(tr("Remove"), this);
    buttonBox->addButton(m_removeButton, QDialogButtonBox::ActionRole);
    mainLayout->addWidget(buttonBox);

    connect(m_addButton, &QPushButton::clicked, this, &CommandConfigDialog::addCommand);
    connect(m_updateButton, &QPushButton::clicked, this, &CommandConfigDialog::updateCommand);
    connect(m_removeButton, &QPushButton::clicked, this, &CommandConfigDialog::removeSelected);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &CommandConfigDialog::accept);
    connect(m_listWidget, &QListWidget::itemSelectionChanged, this, &CommandConfigDialog::onSelectionChanged);
    connect(m_nameEdit, &QLineEdit::textChanged, this, &CommandConfigDialog::onEditFieldsChanged);
    connect(m_commandEdit, &QLineEdit::textChanged, this, &CommandConfigDialog::onEditFieldsChanged);
    connect(m_remarkEdit, &QLineEdit::textChanged, this, &CommandConfigDialog::onEditFieldsChanged);

    updateButtonStates();
}

QVector<UserCommand> CommandConfigDialog::commands() const
{
    QVector<UserCommand> result;
    result.reserve(m_listWidget->count());
    for (int i = 0; i < m_listWidget->count(); ++i) {
        const QListWidgetItem *item = m_listWidget->item(i);
        UserCommand command;
        command.command = item->data(kCommandRole).toString();
        command.name = item->data(kNameRole).toString();
        command.remark = item->data(kRemarkRole).toString();
        result.append(command);
    }
    return result;
}

void CommandConfigDialog::addCommand()
{
    const QString name = m_nameEdit->text().trimmed();
    const QString command = m_commandEdit->text().trimmed();
    const QString remark = m_remarkEdit->text().trimmed();

    if (!canAdd(command)) {
        return;
    }
    UserCommand value{name, command, remark};
    auto *item = new QListWidgetItem(displayText(value), m_listWidget);
    item->setData(kCommandRole, command);
    item->setData(kNameRole, name);
    item->setData(kRemarkRole, remark);
    item->setToolTip(remark);

    m_listWidget->setCurrentItem(item);
    m_nameEdit->clear();
    m_commandEdit->clear();
    m_remarkEdit->clear();
    updateButtonStates();
}

void CommandConfigDialog::updateCommand()
{
    const auto selected = m_listWidget->selectedItems();
    if (selected.size() != 1) {
        return;
    }

    QListWidgetItem *item = selected.first();
    const QString name = m_nameEdit->text().trimmed();
    const QString command = m_commandEdit->text().trimmed();
    const QString remark = m_remarkEdit->text().trimmed();

    if (!canUpdate(command, item)) {
        return;
    }

    UserCommand value{name, command, remark};
    item->setText(displayText(value));
    item->setData(kCommandRole, command);
    item->setData(kNameRole, name);
    item->setData(kRemarkRole, remark);
    item->setToolTip(remark);

    updateButtonStates();
}

void CommandConfigDialog::removeSelected()
{
    const auto selected = m_listWidget->selectedItems();
    for (QListWidgetItem *item : selected) {
        delete item;
    }
    onSelectionChanged();
    updateButtonStates();
}

void CommandConfigDialog::onSelectionChanged()
{
    const auto selected = m_listWidget->selectedItems();
    if (selected.size() == 1) {
        QListWidgetItem *item = selected.first();
        m_nameEdit->setText(item->data(kNameRole).toString());
        m_commandEdit->setText(item->data(kCommandRole).toString());
        m_remarkEdit->setText(item->data(kRemarkRole).toString());
    } else if (selected.isEmpty()) {
        m_nameEdit->clear();
        m_commandEdit->clear();
        m_remarkEdit->clear();
    }
    updateButtonStates();
}

void CommandConfigDialog::onEditFieldsChanged()
{
    updateButtonStates();
}

void CommandConfigDialog::updateButtonStates()
{
    const QString command = m_commandEdit->text().trimmed();
    const auto selected = m_listWidget->selectedItems();
    QListWidgetItem *singleSelection = selected.size() == 1 ? selected.first() : nullptr;
    m_addButton->setEnabled(canAdd(command));
    m_updateButton->setEnabled(canUpdate(command, singleSelection));
    m_removeButton->setEnabled(!selected.isEmpty());
}

bool CommandConfigDialog::canAdd(const QString &commandText) const
{
    if (commandText.isEmpty()) {
        return false;
    }
    return !commandExists(commandText);
}

bool CommandConfigDialog::canUpdate(const QString &commandText, const QListWidgetItem *current) const
{
    if (!current || commandText.isEmpty()) {
        return false;
    }
    return !commandExists(commandText, current);
}

bool CommandConfigDialog::commandExists(const QString &commandText, const QListWidgetItem *exclude) const
{
    if (commandText.isEmpty()) {
        return false;
    }
    for (int i = 0; i < m_listWidget->count(); ++i) {
        QListWidgetItem *item = m_listWidget->item(i);
        if (item == exclude) {
            continue;
        }
        if (item->data(kCommandRole).toString() == commandText) {
            return true;
        }
    }
    return false;
}

QString CommandConfigDialog::displayText(const UserCommand &command)
{
    QString text = command.name.isEmpty() ? command.command : command.name;
    if (!command.remark.isEmpty()) {
        if (!text.isEmpty()) {
            text.append(QStringLiteral(" — "));
        }
        text.append(command.remark);
    }
    if (text.isEmpty()) {
        text = command.command;
    }
    return text;
}

