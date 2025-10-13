#include "commandconfigdialog.h"

#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

CommandConfigDialog::CommandConfigDialog(const QStringList &commands, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("User Commands"));
    setModal(true);

    m_listWidget = new QListWidget(this);
    m_listWidget->addItems(commands);
    if (!commands.isEmpty()) {
        m_listWidget->setCurrentRow(0);
    }

    m_input = new QLineEdit(this);
    m_input->setPlaceholderText(tr("New command"));

    m_addButton = new QPushButton(tr("Add"), this);
    m_removeButton = new QPushButton(tr("Remove"), this);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(m_input);
    inputLayout->addWidget(m_addButton);

    QHBoxLayout *actionsLayout = new QHBoxLayout;
    actionsLayout->addStretch();
    actionsLayout->addWidget(m_removeButton);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(new QLabel(tr("Saved commands:"), this));
    mainLayout->addWidget(m_listWidget);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(actionsLayout);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    connect(m_addButton, &QPushButton::clicked,
            this, &CommandConfigDialog::onAddCommand);
    connect(m_removeButton, &QPushButton::clicked,
            this, &CommandConfigDialog::onRemoveCommand);
    connect(m_listWidget, &QListWidget::currentRowChanged,
            this, &CommandConfigDialog::onSelectionChanged);
    connect(m_listWidget, &QListWidget::itemSelectionChanged,
            this, &CommandConfigDialog::onSelectionChanged);
    connect(m_input, &QLineEdit::textChanged,
            this, &CommandConfigDialog::onInputChanged);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &CommandConfigDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &CommandConfigDialog::reject);

    updateButtons();
}

QStringList CommandConfigDialog::commands() const
{
    QStringList result;
    for (int i = 0; i < m_listWidget->count(); ++i) {
        result.append(m_listWidget->item(i)->text());
    }
    return result;
}

void CommandConfigDialog::setPendingCommand(const QString &command)
{
    QString trimmed = command.trimmed();
    if (trimmed.isEmpty()) {
        return;
    }
    m_input->setText(trimmed);
    m_input->selectAll();
    m_input->setFocus();
}

void CommandConfigDialog::onAddCommand()
{
    QString text = m_input->text().trimmed();
    if (text.isEmpty()) {
        return;
    }

    bool exists = false;
    for (int i = 0; i < m_listWidget->count(); ++i) {
        if (m_listWidget->item(i)->text() == text) {
            exists = true;
            m_listWidget->setCurrentRow(i);
            break;
        }
    }

    if (!exists) {
        m_listWidget->addItem(text);
        m_listWidget->setCurrentRow(m_listWidget->count() - 1);
    }

    m_input->clear();
    updateButtons();
}

void CommandConfigDialog::onRemoveCommand()
{
    int row = m_listWidget->currentRow();
    if (row >= 0) {
        delete m_listWidget->takeItem(row);
    }
    updateButtons();
}

void CommandConfigDialog::onSelectionChanged()
{
    updateButtons();
}

void CommandConfigDialog::onInputChanged(const QString &text)
{
    Q_UNUSED(text)
    updateButtons();
}

void CommandConfigDialog::updateButtons()
{
    const bool hasSelection = m_listWidget->currentRow() >= 0;
    const bool hasText = !m_input->text().trimmed().isEmpty();
    m_addButton->setEnabled(hasText);
    m_removeButton->setEnabled(hasSelection);
}
