QT       += core gui widgets sql

CONFIG += c++17

SOURCES += \
    Data/DAO/gradesdao.cpp \
    Utils/database.cpp \
    Utils/logger.cpp \
    Data/Entity/grade.cpp \
    Data/Entity/group.cpp \
    Data/DAO/groupsdao.cpp \
    Views/Forms/TeacherWindowPages/teacherwindowjournalpage.cpp \
    Views/Forms/TeacherWindowPages/teacherwindowschedulepage.cpp \
    Views/Forms/teacherwindow.cpp \
    Data/Model/groupspagemodel.cpp \
    Data/Model/journalpagemodel.cpp \
    Data/Model/journalmodel.cpp \
    main.cpp \
    Data/Entity/student.cpp \
    Data/DAO/studentsdao.cpp \
    Data/DAO/subjectsdao.cpp \
    Views/Forms/TeacherWindowPages/teacherwindowgroupspage.cpp

HEADERS += \
    Data/DAO/IGradesDAO.h \
    Data/DAO/IGroupsDAO.h \
    Data/DAO/IStudentsDAO.h \
    Data/DAO/ISubjectsDAO.h \
    Data/DAO/gradesdao.h \
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
    Views/Forms/TeacherWindowPages/teacherwindowjournalpage.h \
    Views/Forms/TeacherWindowPages/teacherwindowschedulepage.h \
    Views/Forms/teacherwindow.h \
    Views/Forms/TeacherWindowPages/teacherwindowgroupspage.h \
    Data/Model/groupspagemodel.h \
    Data/Model/journalpagemodel.h \
    Data/Model/journalmodel.h

FORMS += \
    Views/Forms/teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
