#include "addsubjectcommand.h"
#include "../../Exceptions/commandexception.h"

AddSubjectCommand::AddSubjectCommand(GroupsPageModel* model, const QString& subjectName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), subjectName(subjectName) {}

void AddSubjectCommand::redo()
{
    if(!model->addSubject(subjectName))
        throw CommandException("Adding subject error.");
    executed = true;
}

void AddSubjectCommand::undo()
{
    if (executed)
    {
        if(!model->deleteSubject(subjectName))
            throw CommandException("Deleting subject error.");
    }

}

