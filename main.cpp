#include "Graphic.h"
#include "parser.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char **argv)
{
    Parser p;
    //p.func();
    //p.Write();
    p.Read();

    QApplication app(argc, argv);

    Graphic *widget = new Graphic;

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(widget);

    mainWindow.showFullScreen();
    return app.exec();
}
