#include "addstudentcommand.h"
#include "../../Exceptions/commandexception.h"

AddStudentCommand::AddStudentCommand(GroupsPageModel* model, const QString& studentName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), studentName(studentName) {}

void AddStudentCommand::redo()
{
    if(!model->addStudent(studentName))
        throw CommandException("Adding student error.");
    executed = true;
}

void AddStudentCommand::undo()
{
    if (executed)
    {
        if(!model->deleteStudent(studentName))
            throw CommandException("Deleting student error.");
    }
}

