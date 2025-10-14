#pragma once

#include <QString>

struct CommandPreset
{
    QString name;
    QString command;
    QString note;
};

inline bool operator==(const CommandPreset &lhs, const CommandPreset &rhs)
{
    return lhs.name == rhs.name && lhs.command == rhs.command && lhs.note == rhs.note;
}
