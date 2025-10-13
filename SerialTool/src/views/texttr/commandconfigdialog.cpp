#include "commandconfigdialog.h"

#include <QAbstractItemView>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

CommandConfigDialog::CommandConfigDialog(const QStringList &commands, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Command Presets"));
    setModal(true);
    resize(360, 320);

    auto *mainLayout = new QVBoxLayout(this);

    m_listWidget = new QListWidget(this);
    m_listWidget->addItems(commands);
    m_listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    mainLayout->addWidget(m_listWidget);

    auto *inputLayout = new QHBoxLayout();
    m_inputEdit = new QLineEdit(this);
    m_inputEdit->setPlaceholderText(tr("New command"));
    inputLayout->addWidget(m_inputEdit);

    m_addButton = new QPushButton(tr("Add"), this);
    inputLayout->addWidget(m_addButton);
    mainLayout->addLayout(inputLayout);

    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Close, this);
    m_removeButton = new QPushButton(tr("Remove"), this);
    buttonBox->addButton(m_removeButton, QDialogButtonBox::ActionRole);
    mainLayout->addWidget(buttonBox);

    connect(m_addButton, &QPushButton::clicked, this, &CommandConfigDialog::addCommand);
    connect(m_removeButton, &QPushButton::clicked, this, &CommandConfigDialog::removeSelected);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &CommandConfigDialog::accept);
    connect(m_listWidget, &QListWidget::itemSelectionChanged, this, &CommandConfigDialog::updateButtonStates);
    connect(m_inputEdit, &QLineEdit::textChanged, this, &CommandConfigDialog::updateButtonStates);

    updateButtonStates();
}

QStringList CommandConfigDialog::commands() const
{
    QStringList result;
    result.reserve(m_listWidget->count());
    for (int i = 0; i < m_listWidget->count(); ++i) {
        result.append(m_listWidget->item(i)->text());
    }
    return result;
}

void CommandConfigDialog::addCommand()
{
    const QString text = m_inputEdit->text().trimmed();
    if (!canAdd(text)) {
        return;
    }
    m_listWidget->addItem(text);
    m_inputEdit->clear();
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
    const QString text = m_inputEdit->text().trimmed();
    m_addButton->setEnabled(canAdd(text));
    m_removeButton->setEnabled(!m_listWidget->selectedItems().isEmpty());
}

bool CommandConfigDialog::canAdd(const QString &text) const
{
    if (text.isEmpty()) {
        return false;
    }
    for (int i = 0; i < m_listWidget->count(); ++i) {
        if (m_listWidget->item(i)->text() == text) {
            return false;
        }
    }
    return true;
}

