#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <QVector>
#include <QWidget>

#include "TextBuffer.hpp"

// TODO: this is all garbage, just here because it renders something

void TextBuffer::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.fillRect(rect(), Qt::white);
  painter.setPen(Qt::black);

  int y = fontMetrics().height();
  for (const auto &line : lines) {
    painter.drawText(QPoint(10, y), line);
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
  int cursorX = 10 + fontMetrics().horizontalAdvance(lines[cursorLine].left(cursorColumn));
  int cursorY = (cursorLine + 1) * fontMetrics().height();
  painter.fillRect(QRect(cursorX, cursorY - fontMetrics().height(), 2, fontMetrics().height()),
                   Qt::black);
}

void TextBuffer::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_Backspace:
    if (cursorPosition > 0) {
      int line = 0;
      int column = cursorPosition - 1;
      for (int i = 0; i < lines.size(); ++i) {
        if (column > lines[i].length()) {
          column -= lines[i].length() + 1;
          line++;
        } else {
          break;
        }
      }
      lines[line].remove(column, 1);
      if (lines[line].isEmpty() && lines.size() > 1) {
        lines.removeAt(line);
      }
      cursorPosition--;
    }
    break;
  case Qt::Key_Return:
  case Qt::Key_Enter: {
    int line = 0;
    int column = cursorPosition;
    for (int i = 0; i < lines.size(); ++i) {
      if (column > lines[i].length()) {
        column -= lines[i].length() + 1;
        line++;
      } else {
        break;
      }
    }
    QString newLine = lines[line].mid(column);
    lines[line].truncate(column);
    lines.insert(line + 1, newLine);
    cursorPosition++;
  } break;
  default:
    if (!event->text().isEmpty()) {
      int line = 0;
      int column = cursorPosition;
      for (int i = 0; i < lines.size(); ++i) {
        if (column > lines[i].length()) {
          column -= lines[i].length() + 1;
          line++;
        } else {
          break;
        }
      }
      lines[line].insert(column, event->text());
      cursorPosition++;
    }
    break;
  }
  update();
}
