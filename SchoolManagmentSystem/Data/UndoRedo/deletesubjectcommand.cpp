#include "deletesubjectcommand.h"
#include "../../Exceptions/commandexception.h"

DeleteSubjectCommand::DeleteSubjectCommand(GroupsPageModel* model, const QString& subjectName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), subjectName(subjectName) {}

void DeleteSubjectCommand::redo()
{
    if(!model->deleteSubject(subjectName))
        throw CommandException("Deleting subject error.");
    executed = true;
}

void DeleteSubjectCommand::undo()
{
    if (executed)
    {
        if(!model->addSubject(subjectName))
            throw CommandException("Adding subject error.");
    }
}

