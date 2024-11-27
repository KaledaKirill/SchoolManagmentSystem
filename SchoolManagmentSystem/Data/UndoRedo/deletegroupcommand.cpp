#include "deletegroupcommand.h"

DeleteGroupCommand::DeleteGroupCommand(GroupsPageModel* model, const QString& groupName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), groupName(groupName) {}

void DeleteGroupCommand::redo()
{
    if(!model->deleteGroup(groupName))
        throw std::runtime_error("Deleting group error.");
    executed = true;
}

void DeleteGroupCommand::undo()
{
    if (executed)
    {
        if(!model->addGroup(groupName))
            throw std::runtime_error("Adding group error.");
    }
}
