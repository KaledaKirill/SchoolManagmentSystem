#include "addgroupcommand.h"

AddGroupCommand::AddGroupCommand(GroupsPageModel* model, const QString& groupName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), groupName(groupName) {}

void AddGroupCommand::redo()
{
    if(!model->addGroup(groupName))
        throw std::runtime_error("Adding group error.");
    executed = true;
}

void AddGroupCommand::undo()
{
    if (executed)
    {
        if(!model->deleteGroup(groupName))
            throw std::runtime_error("Deleting group error.");
    }
}
