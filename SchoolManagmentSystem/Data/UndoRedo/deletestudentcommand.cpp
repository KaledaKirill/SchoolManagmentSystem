#include "deletestudentcommand.h"
#include "../../Exceptions/commandexception.h"

DeleteStudentCommand::DeleteStudentCommand(GroupsPageModel* model, const QString& studentName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), studentName(studentName) {}

void DeleteStudentCommand::redo()
{
    if(!model->deleteStudent(studentName))
        throw CommandException("Deleting student error.");
    executed = true;
}

void DeleteStudentCommand::undo()
{
    if (executed)
    {
        if(!model->addStudent(studentName))
            throw CommandException("Adding student error.");
    }
}

