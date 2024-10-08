#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <QVector>
#include <QWidget>

#include "TextBuffer.hpp"

// TODO: this is all garbage, just here because it renders something

void TextBuffer::paintEvent(QPaintEvent *event) {
  const auto lines = this->file.readLines();

  QPainter painter(this);
  painter.fillRect(rect(), Qt::white);
  painter.setPen(Qt::black);

  int y = fontMetrics().height();
  for (const auto &line : lines) {
    painter.drawText(QPoint(10, y), QString::fromStdString(line));
    y += fontMetrics().height();
  }

  // Draw cursor
  int cursorLine = 0;
  int cursorColumn = cursorPosition;
  for (int i = 0; i < lines.size(); ++i) {
    if (cursorColumn > lines[i].length()) {
      cursorColumn -= lines[i].length() + 1; // +1 for newline
      cursorLine++;
    } else {
      break;
    }
  }
  int cursorX = 10 + fontMetrics().horizontalAdvance(
                         QString::fromStdString(lines[cursorLine]).left(cursorColumn));
  int cursorY = (cursorLine + 1) * fontMetrics().height();
  painter.fillRect(QRect(cursorX, cursorY - fontMetrics().height(), 2, fontMetrics().height()),
                   Qt::black);
}
