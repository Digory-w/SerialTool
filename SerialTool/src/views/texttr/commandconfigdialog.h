#ifndef COMMANDCONFIGDIALOG_H
#define COMMANDCONFIGDIALOG_H

#include <QDialog>

class QListWidget;
class QLineEdit;
class QPushButton;

class CommandConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommandConfigDialog(const QStringList &commands, QWidget *parent = nullptr);

    QStringList commands() const;

private slots:
    void addCommand();
    void removeSelected();
    void updateButtonStates();

private:
    bool canAdd(const QString &text) const;

private:
    QListWidget *m_listWidget;
    QLineEdit *m_inputEdit;
    QPushButton *m_addButton;
    QPushButton *m_removeButton;
};

#endif // COMMANDCONFIGDIALOG_H

