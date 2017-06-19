#-------------------------------------------------
#
# Project created by QtCreator 2016-12-24T23:43:36
#
#-------------------------------------------------

TEMPLATE = app

TEMPLATE = subdirs

SUBDIRS += \
	src

unix: {
    target.path = /opt/Hiren/Clipboard
    INSTALLS += target
}

OTHER_FILES += debian/control
