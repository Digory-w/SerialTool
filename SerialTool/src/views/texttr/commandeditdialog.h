#pragma once

#include "commandpreset.h"

#include <QDialog>

class QDialogButtonBox;
class QLineEdit;
class QPlainTextEdit;

class CommandEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommandEditDialog(QWidget *parent = nullptr);

    void setPreset(const CommandPreset &preset);
    void setCommandText(const QString &command);
    CommandPreset preset() const;

private slots:
    void updateButtonStates();

private:
    QLineEdit *m_nameEdit;
    QPlainTextEdit *m_commandEdit;
    QLineEdit *m_noteEdit;
    QDialogButtonBox *m_buttonBox;
};
