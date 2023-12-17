include($$PWD/lib.pri)


TARGET = yri_sd_runtime_verif


CONFIG -= import_plugins
CONFIG -= disable-desktop


QT += core
QT += sql
QT -= gui

CONFIG += debug

include($$PWD/yri_sd_runtime_verif.pri)
