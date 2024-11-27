#ifndef ADDGROUPCOMMAND_H
#define ADDGROUPCOMMAND_H

#include "../Model/groupspagemodel.h"

#include <QUndoCommand>

class AddGroupCommand : public QUndoCommand
{
public:
    AddGroupCommand(GroupsPageModel* model, const QString& groupName, QUndoCommand* parent = nullptr);

    void redo() override;
    void undo() override;

private:
    GroupsPageModel* model;
    QString groupName;
    bool executed = false;

};

#endif
