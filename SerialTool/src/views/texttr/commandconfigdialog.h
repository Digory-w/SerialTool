#ifndef COMMANDCONFIGDIALOG_H
#define COMMANDCONFIGDIALOG_H

#include <QDialog>
#include <QVector>

#include "usercommand.h"

class QListWidget;
class QLineEdit;
class QPushButton;
class QListWidgetItem;

class CommandConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommandConfigDialog(const QVector<UserCommand> &commands, QWidget *parent = nullptr);

    QVector<UserCommand> commands() const;

private slots:
    void addCommand();
    void updateCommand();
    void removeSelected();
    void onSelectionChanged();
    void onEditFieldsChanged();
    void updateButtonStates();

private:
    bool canAdd(const QString &commandText) const;
    bool canUpdate(const QString &commandText, const QListWidgetItem *current) const;
    bool commandExists(const QString &commandText, const QListWidgetItem *exclude = nullptr) const;
    static QString displayText(const UserCommand &command);

private:
    QListWidget *m_listWidget;
    QLineEdit *m_nameEdit;
    QLineEdit *m_commandEdit;
    QLineEdit *m_remarkEdit;
    QPushButton *m_addButton;
    QPushButton *m_updateButton;
    QPushButton *m_removeButton;
};

#endif // COMMANDCONFIGDIALOG_H

