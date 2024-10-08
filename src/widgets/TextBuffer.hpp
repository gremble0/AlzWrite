#include <QWidget>

class TextBuffer : public QWidget {
  Q_OBJECT;

public:
  TextBuffer(QWidget *parent = nullptr) : QWidget(parent) {
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFont(QFont("Courier", 12));
  }

  void paintEvent(QPaintEvent *event) override;

  void keyPressEvent(QKeyEvent *event) override;

private:
  QVector<QString> lines{QString("")};
  int cursorPosition;
};
