#include <QFile>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class TextBuffer : public QWidget {
  Q_OBJECT;

public:
  TextBuffer(const QString &path, QWidget *parent = nullptr)
      : QWidget(parent), file(path), textEdit(this), layout(this) {
    this->initializeLayout();
    this->loadText();
  }

private:
  QFile file;
  QVBoxLayout layout;
  QTextEdit textEdit;

  void initializeLayout();
  void loadText();
};
