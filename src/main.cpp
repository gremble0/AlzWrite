#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QMainWindow window;
    window.setWindowTitle("AlzWrite - lose yourself in text editing");
    window.resize(640, 480);
    window.show();
    
    return app.exec();
}
