#ifndef ADDSUBJECTCOMMAND_H
#define ADDSUBJECTCOMMAND_H

#include "../Model/groupspagemodel.h"

#include <QUndoCommand>

class AddSubjectCommand : public QUndoCommand
{
public:
    AddSubjectCommand(GroupsPageModel* model, const QString& subjectName, QUndoCommand* parent = nullptr);

    void redo() override;
    void undo() override;

private:
    GroupsPageModel* model;
    QString subjectName;
    bool executed = false;

};

#endif
