#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "widgets/TextBuffer.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Please specify a file to edit" << std::endl;
    std::exit(1);
  } else if (!std::ifstream(argv[1]).good()) {
    std::cerr << "Could not open file '" << argv[1] << "'" << std::endl;
    std::exit(1);
  }

  QApplication app(argc, argv);
  QMainWindow window;
  TextBuffer buffer(argv[1], &window);
  QWidget centralWidget(&window);

  QVBoxLayout layout(&centralWidget);
  layout.addWidget(&buffer);

  window.setCentralWidget(&centralWidget);
  window.setWindowTitle("AlzWrite");
  window.resize(640, 480);
  window.show();

  return app.exec();
}
