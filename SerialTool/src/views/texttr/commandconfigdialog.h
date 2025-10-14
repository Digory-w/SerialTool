#ifndef COMMANDCONFIGDIALOG_H
#define COMMANDCONFIGDIALOG_H

#include "commandpreset.h"

#include <QDialog>
#include <QVector>

class QListWidget;
class QListWidgetItem;
class QPushButton;

class CommandConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommandConfigDialog(const QVector<CommandPreset> &commands, QWidget *parent = nullptr);

    QVector<CommandPreset> commands() const;

private slots:
    void addCommand();
    void removeSelected();
    void updateButtonStates();

private:
    void appendListItem(const CommandPreset &preset);
    void applyPresetToItem(QListWidgetItem *item, const CommandPreset &preset) const;
    CommandPreset presetFromItem(int row) const;

private:
    QListWidget *m_listWidget;
    QPushButton *m_addButton;
    QPushButton *m_removeButton;
};

#endif // COMMANDCONFIGDIALOG_H

