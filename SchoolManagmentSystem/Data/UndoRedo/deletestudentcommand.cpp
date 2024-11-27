#include "deletestudentcommand.h"

DeleteStudentCommand::DeleteStudentCommand(GroupsPageModel* model, const QString& studentName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), studentName(studentName) {}

void DeleteStudentCommand::redo()
{
    if(!model->deleteStudent(studentName))
        throw std::runtime_error("Deleting student error.");
    executed = true;
}

void DeleteStudentCommand::undo()
{
    if (executed)
    {
        if(!model->addStudent(studentName))
            throw std::runtime_error("Adding student error.");
    }
}

