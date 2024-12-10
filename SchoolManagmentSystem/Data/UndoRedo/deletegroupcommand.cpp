#include "deletegroupcommand.h"
#include "../../Exceptions/commandexception.h"

DeleteGroupCommand::DeleteGroupCommand(GroupsPageModel* model, const QString& groupName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), groupName(groupName) {}

void DeleteGroupCommand::redo()
{
    if(!model->deleteGroup(groupName))
        throw CommandException("Deleting group error.");
    executed = true;
}

void DeleteGroupCommand::undo()
{
    if (executed)
    {
        if(!model->addGroup(groupName))
            throw CommandException("Adding group error.");
    }
}
