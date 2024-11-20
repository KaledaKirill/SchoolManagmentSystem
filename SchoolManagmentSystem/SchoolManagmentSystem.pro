QT       += core gui widgets sql

CONFIG += c++17

SOURCES += \
    Utils/database.cpp \
    Utils/logger.cpp \
    Data/Entity/grade.cpp \
    Data/Entity/group.cpp \
    main.cpp \
    Views/mainwindow.cpp \
    Data/Entity/student.cpp

HEADERS += \
    Data/DAO/IGradesDAO.h \
    Data/DAO/IGroupsDAO.h \
    Data/DAO/IStudentsDAO.h \
    Data/DAO/ISubjectsDAO.h \
    Utils/database.h \
    Views/mainwindow.h \
    Utils/logger.h \
    Exceptions/notworkingrequest.h \
    Data/Entity/grade.h \
    Data/Entity/group.h \
    Data/Entity/student.h

FORMS += \
    Views/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
