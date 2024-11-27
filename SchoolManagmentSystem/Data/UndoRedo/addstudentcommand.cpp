#include "addstudentcommand.h"

AddStudentCommand::AddStudentCommand(GroupsPageModel* model, const QString& studentName, QUndoCommand* parent)
    : QUndoCommand(parent), model(model), studentName(studentName) {}

void AddStudentCommand::redo()
{
    if(!model->addStudent(studentName))
        throw std::runtime_error("Adding student error.");
    executed = true;
}

void AddStudentCommand::undo()
{
    if (executed)
    {
        if(!model->deleteStudent(studentName))
            throw std::runtime_error("Deleting student error.");
    }
}

