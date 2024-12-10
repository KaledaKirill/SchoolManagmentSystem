#include "addgroupcommand.h"
#include "../../Exceptions/commandexception.h"

AddGroupCommand::AddGroupCommand(GroupsPageModel* model, const QString& groupName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), groupName(groupName) {}

void AddGroupCommand::redo()
{
    if(!model->addGroup(groupName))
        throw CommandException("Adding group error.");
    executed = true;
}

void AddGroupCommand::undo()
{
    if (executed)
    {
        if(!model->deleteGroup(groupName))
            throw CommandException("Deleting group error.");
    }
}
