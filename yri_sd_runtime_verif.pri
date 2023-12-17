
# temp dirs (unix)
unix{
    MOC_DIR = $$OUT_PWD/_generated
    OBJECTS_DIR = $$OUT_PWD/_generated
    UI_DIR = $$OUT_PWD/_generated
    RCC_DIR = $$OUT_PWD/_generated
}

SOURCES += $$files($$PWD/src/*.CPP)
SOURCES += $$files($$PWD/src/*.cpp)
HEADERS += $$files($$PWD/src/*.HPP)
HEADERS += $$files($$PWD/src/*.hpp)
HEADERS += $$files($$PWD/src/*.h)
SOURCES += $$files($$PWD/src/utils/*.CPP)
SOURCES += $$files($$PWD/src/utils/*.cpp)
HEADERS += $$files($$PWD/src/utils/*.HPP)
HEADERS += $$files($$PWD/src/utils/*.hpp)
HEADERS += $$files($$PWD/src/utils/*.h)
SOURCES += $$files($$PWD/src/yri-recovery/*.cpp)
HEADERS += $$files($$PWD/src/yri-recovery/*.hpp)
SOURCES += $$files($$PWD/src/yri-expressions-conditions/*.CPP)
SOURCES += $$files($$PWD/src/yri-expressions-conditions/*.cpp)
HEADERS += $$files($$PWD/src/yri-expressions-conditions/*.HPP)
HEADERS += $$files($$PWD/src/yri-expressions-conditions/*.hpp)
HEADERS += $$files($$PWD/src/yri-expressions-conditions/*.h)

RESOURCES = yri_sd_runtime_verif.qrc

