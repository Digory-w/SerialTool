#ifndef COMMANDCONFIGDIALOG_H
#define COMMANDCONFIGDIALOG_H

#include <QDialog>
#include <QStringList>

class QListWidget;
class QLineEdit;
class QPushButton;

class CommandConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommandConfigDialog(const QStringList &commands, QWidget *parent = nullptr);

    QStringList commands() const;
    void setPendingCommand(const QString &command);

private slots:
    void onAddCommand();
    void onRemoveCommand();
    void onSelectionChanged();
    void onInputChanged(const QString &text);

private:
    void updateButtons();

    QListWidget *m_listWidget;
    QLineEdit *m_input;
    QPushButton *m_addButton;
    QPushButton *m_removeButton;
};

#endif // COMMANDCONFIGDIALOG_H
