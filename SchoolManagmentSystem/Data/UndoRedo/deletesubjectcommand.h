#ifndef DELETESUBJECTCOMMAND_H
#define DELETESUBJECTCOMMAND_H

#include "../Model/groupspagemodel.h"

#include <QUndoCommand>

class DeleteSubjectCommand : public QUndoCommand
{
public:
    DeleteSubjectCommand(GroupsPageModel* model, const QString& subjectName, QUndoCommand* parent = nullptr);

    void redo() override;
    void undo() override;

private:
    GroupsPageModel* model;
    QString subjectName;
    bool executed = false;

};

#endif
