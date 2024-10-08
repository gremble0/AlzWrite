#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <QVector>
#include <QWidget>

#include "TextBuffer.hpp"

void TextBuffer::paintEvent(QPaintEvent *event) {
  const auto lines = this->file.readLines();

  QPainter painter(this);
  painter.fillRect(this->rect(), Qt::black);
  painter.setPen(Qt::white);

  int y = fontMetrics().height();
  for (const auto &line : lines) {
    painter.drawText(QPoint(10, y), QString::fromStdString(line));
    y += fontMetrics().height();
  }
}
