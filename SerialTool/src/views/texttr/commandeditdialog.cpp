#include "commandeditdialog.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

CommandEditDialog::CommandEditDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Command Details"));
    setModal(true);
    resize(420, 320);

    auto *mainLayout = new QVBoxLayout(this);

    auto *nameLayout = new QHBoxLayout();
    auto *nameLabel = new QLabel(tr("Name"), this);
    nameLayout->addWidget(nameLabel);
    m_nameEdit = new QLineEdit(this);
    nameLayout->addWidget(m_nameEdit, 1);
    mainLayout->addLayout(nameLayout);

    auto *commandLabel = new QLabel(tr("Command"), this);
    mainLayout->addWidget(commandLabel);
    m_commandEdit = new QPlainTextEdit(this);
    m_commandEdit->setTabChangesFocus(false);
    mainLayout->addWidget(m_commandEdit, 1);

    auto *noteLayout = new QHBoxLayout();
    auto *noteLabel = new QLabel(tr("Note"), this);
    noteLayout->addWidget(noteLabel);
    m_noteEdit = new QLineEdit(this);
    noteLayout->addWidget(m_noteEdit, 1);
    mainLayout->addLayout(noteLayout);

    m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    mainLayout->addWidget(m_buttonBox);

    connect(m_buttonBox, &QDialogButtonBox::accepted, this, &CommandEditDialog::accept);
    connect(m_buttonBox, &QDialogButtonBox::rejected, this, &CommandEditDialog::reject);
    connect(m_nameEdit, &QLineEdit::textChanged, this, &CommandEditDialog::updateButtonStates);
    connect(m_commandEdit, &QPlainTextEdit::textChanged, this, &CommandEditDialog::updateButtonStates);

    updateButtonStates();
}

void CommandEditDialog::setPreset(const CommandPreset &preset)
{
    m_nameEdit->setText(preset.name);
    m_commandEdit->setPlainText(preset.command);
    m_noteEdit->setText(preset.note);
    updateButtonStates();
}

void CommandEditDialog::setCommandText(const QString &command)
{
    m_commandEdit->setPlainText(command);
    updateButtonStates();
}

CommandPreset CommandEditDialog::preset() const
{
    CommandPreset preset;
    preset.name = m_nameEdit->text().trimmed();
    preset.command = m_commandEdit->toPlainText();
    preset.note = m_noteEdit->text().trimmed();
    return preset;
}

void CommandEditDialog::updateButtonStates()
{
    const bool hasCommand = !m_commandEdit->toPlainText().trimmed().isEmpty();
    QPushButton *okButton = m_buttonBox->button(QDialogButtonBox::Ok);
    if (okButton) {
        okButton->setEnabled(hasCommand);
    }
}
