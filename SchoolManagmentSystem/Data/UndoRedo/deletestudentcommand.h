#ifndef DELETESTUDENTCOMMAND_H
#define DELETESTUDENTCOMMAND_H

#include "../Model/groupspagemodel.h"

#include <QUndoCommand>

class DeleteStudentCommand : public QUndoCommand
{
public:
    DeleteStudentCommand(GroupsPageModel* model, const QString& studentName, QUndoCommand* parent = nullptr);

    void redo() override;
    void undo() override;

private:
    GroupsPageModel* model;
    QString studentName;
    bool executed = false;

};

#endif
