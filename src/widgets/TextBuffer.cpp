#include <QKeyEvent>
#include <QPainter>
#include <QString>
#include <QVector>
#include <iostream>

#include "TextBuffer.hpp"

void TextBuffer::initializeLayout() {
  this->layout.setContentsMargins(0, 0, 0, 0);
  this->layout.addWidget(&this->textEdit);
  this->setLayout(&layout);
}

void TextBuffer::loadText() {
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
