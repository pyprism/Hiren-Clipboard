#-------------------------------------------------
#
# Project created by QtCreator 2016-12-24T23:43:36
#
#-------------------------------------------------

TEMPLATE = app

TEMPLATE = subdirs

SUBDIRS += \
	src

#unix: {
#    target.path = /opt/Hiren/Clipboard
#    INSTALLS += target
#}

CONFIG += warn_on qt debug_and_release

OTHER_FILES += debian/control debian/rules debian/compat debian/changelog \
               debian/copyright debian/dirs debian/packagename.install \
               hiren-clipboard.desktop
