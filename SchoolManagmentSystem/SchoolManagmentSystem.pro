QT       += core gui widgets sql

CONFIG += c++17

SOURCES += \
    Data/DAO/gradesdao.cpp \
    Data/DAO/scheduledao.cpp \
    Data/Entity/validator.cpp \
    Data/UndoRedo/addgroupcommand.cpp \
    Data/Model/gradesservice.cpp \
    Data/Model/resjournalmodel.cpp \
    Data/Model/schedulemodel.cpp \
    Data/Model/schedulepagemodel.cpp \
    Data/Model/studentjournalmodel.cpp \
    Data/Model/studentresjournalmodel.cpp \
    Data/UndoRedo/addstudentcommand.cpp \
    Data/UndoRedo/addsubjectcommand.cpp \
    Data/UndoRedo/deletegroupcommand.cpp \
    Data/UndoRedo/deletestudentcommand.cpp \
    Data/UndoRedo/deletesubjectcommand.cpp \
    Utils/database.cpp \
    Utils/logger.cpp \
    Data/Entity/grade.cpp \
    Data/Entity/group.cpp \
    Data/DAO/groupsdao.cpp \
    Views/Forms/StudentWindowPages/studentwindowjournalpage.cpp \
    Views/Forms/TeacherWindowPages/teacherwindowjournalpage.cpp \
    Views/Forms/TeacherWindowPages/teacherwindowschedulepage.cpp \
    Views/Forms/loginwindow.cpp \
    Views/Forms/studentwindow.cpp \
    Views/Forms/teacherwindow.cpp \
    Data/Model/groupspagemodel.cpp \
    Data/Model/journalpagemodel.cpp \
    Data/Model/journalmodel.cpp \
    Data/Model/datesservice.cpp \
    main.cpp \
    Data/Entity/student.cpp \
    Data/DAO/studentsdao.cpp \
    Data/DAO/subjectsdao.cpp \
    Views/Forms/TeacherWindowPages/teacherwindowgroupspage.cpp \
    Views/Forms/StudentWindowPages/studentwindowschedulepage.cpp

HEADERS += \
    Collections/mylist.h \
    Data/DAO/gradesdao.h \
    Data/DAO/igradesdao.h \
    Data/DAO/igroupsdao.h \
    Data/DAO/istudentsdao.h \
    Data/DAO/isubjectsdao.h \
    Data/DAO/scheduledao.h \
    Data/Entity/validator.h \
    Data/UndoRedo/addgroupcommand.h \
    Data/Model/gradesservice.h \
    Data/Model/resjournalmodel.h \
    Data/Model/schedulemodel.h \
    Data/Model/schedulepagemodel.h \
    Data/Model/studentjournalmodel.h \
    Data/Model/studentresjournalmodel.h \
    Data/UndoRedo/addstudentcommand.h \
    Data/UndoRedo/addsubjectcommand.h \
    Data/UndoRedo/deletegroupcommand.h \
    Data/UndoRedo/deletestudentcommand.h \
    Data/UndoRedo/deletesubjectcommand.h \
    Exceptions/baseexception.h \
    Exceptions/commandexception.h \
    Utils/database.h \
    Utils/logger.h \
    Exceptions/notworkingrequest.h \
    Data/Entity/grade.h \
    Data/Entity/group.h \
    Data/Entity/student.h \
    Data/DAO/groupsdao.h \
    Data/DAO/studentsdao.h \
    Data/DAO/subjectsdao.h \
    Exceptions/groupnotfound.h \
    Exceptions/studentnotfound.h \
    Views/Forms/StudentWindowPages/studentwindowjournalpage.h \
    Views/Forms/TeacherWindowPages/teacherwindowjournalpage.h \
    Views/Forms/TeacherWindowPages/teacherwindowschedulepage.h \
    Views/Forms/loginwindow.h \
    Views/Forms/studentwindow.h \
    Views/Forms/teacherwindow.h \
    Views/Forms/TeacherWindowPages/teacherwindowgroupspage.h \
    Data/Model/groupspagemodel.h \
    Data/Model/journalpagemodel.h \
    Data/Model/journalmodel.h \
    Data/Model/datesservice.h \
    Data/DAO/ischeduledao.h \
    Views/Forms/StudentWindowPages/studentwindowschedulepage.h

FORMS += \
    Views/Forms/loginwindow.ui \
    Views/Forms/studentwindow.ui \
    Views/Forms/teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/resources.qrc
