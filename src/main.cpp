#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>

#include "widgets/TextBuffer.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QMainWindow window;
  TextBuffer buffer(&window);
  QWidget centralWidget(&window);

  QVBoxLayout layout(&centralWidget);
  layout.addWidget(&buffer);

  window.setCentralWidget(&centralWidget);
  window.setWindowTitle("AlzWrite");
  window.resize(640, 480);
  window.show();

  return app.exec();
}
