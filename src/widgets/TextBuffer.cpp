#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <QVector>
#include <QWidget>
#include <iostream>
#include <qcoreevent.h>
#include <qobject.h>

#include "TextBuffer.hpp"

void TextBuffer::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.fillRect(this->rect(), Qt::black);
  painter.setPen(Qt::white);

  if (!this->file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    std::cerr << "cant read from closed file" << std::endl;
    return;
  }

  const QString lines = this->file.readAll();
  this->textEdit.setText(lines);
}
