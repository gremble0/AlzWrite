#include <QFile>
#include <QTextEdit>
#include <QWidget>
#include <qevent.h>
#include <qobject.h>

#include "files/File.hpp"

class TextBuffer : public QWidget {
  Q_OBJECT;

public:
  TextBuffer(const QString &path, QWidget *parent = nullptr)
      : QWidget(parent), file(path), textEdit(this) {}

  void paintEvent(QPaintEvent *event) override;

private:
  QFile file;
  QTextEdit textEdit;
};
