#include <QWidget>
#include <string>
// TODO: fix import paths from root
#include "../files/File.hpp"

class TextBuffer : public QWidget {
  Q_OBJECT;

public:
  TextBuffer(const std::string &path, QWidget *parent = nullptr) : QWidget(parent), file(path) {
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFont(QFont("Courier", 12));
  }

  void paintEvent(QPaintEvent *event) override;

private:
  File file;
  int cursorPosition;
};
