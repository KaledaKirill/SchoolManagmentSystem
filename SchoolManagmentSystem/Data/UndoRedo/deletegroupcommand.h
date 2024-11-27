#ifndef DELETEGROUPCOMMAND_H
#define DELETEGROUPCOMMAND_H

#include "../Model/groupspagemodel.h"

#include <QUndoCommand>

class DeleteGroupCommand : public QUndoCommand
{
public:
    DeleteGroupCommand(GroupsPageModel* model, const QString& groupName, QUndoCommand* parent = nullptr);

    void redo() override;
    void undo() override;

private:
    GroupsPageModel* model;
    QString groupName;
    bool executed = false;

};

#endif
