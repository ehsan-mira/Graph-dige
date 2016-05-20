QT += widgets

HEADERS += \
    ????Edge.h \
    Node.h \
    Graphic.h \
    Edge.h \
    parser.h \
    Graph.h

SOURCES += \
        main.cpp \
    Edge.cpp \
    Node.cpp \
    Graphic.cpp \
    parser.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target
