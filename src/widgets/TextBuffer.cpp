#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <QVector>
#include <QWidget>

#include "TextBuffer.hpp"

TextBuffer::TextBuffer(const std::string &path, QWidget *parent) : QWidget(parent), file(path) {
  this->setFocusPolicy(Qt::StrongFocus);
  this->setFont(QFont("Courier", 12));
}

void TextBuffer::paintEvent(QPaintEvent *event) {
  const auto lines = this->file.readLines();

  QPainter painter(this);
  painter.fillRect(this->rect(), Qt::black);
  painter.setPen(Qt::white);

  int y = this->fontMetrics().height();
  for (const auto &line : lines) {
    painter.drawText(QPoint(10, y), QString::fromStdString(line));
    y += fontMetrics().height();
  }
}
