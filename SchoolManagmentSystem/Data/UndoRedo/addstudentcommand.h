#ifndef ADDSTUDENTCOMMAND_H
#define ADDSTUDENTCOMMAND_H

#include "../Model/groupspagemodel.h"

#include <QUndoCommand>

class AddStudentCommand : public QUndoCommand
{
public:
    AddStudentCommand(GroupsPageModel* model, const QString& studentName, QUndoCommand* parent = nullptr);

    void redo() override;
    void undo() override;

private:
    GroupsPageModel* model;
    QString studentName;
    bool executed = false;

};

#endif
