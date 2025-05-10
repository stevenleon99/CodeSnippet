#include <QApplication>
#include "robotMainWindowQt.h"  // Include the header where MainWindow is declared

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}