#include "repl_widget.hpp"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QKeyEvent>

REPLWidget::REPLWidget(QWidget *parent) : QWidget(parent)
{
  //ex11
  repllabel = new QLabel("slisp>");
  repllineedit = new QLineEdit;
  ////////////////////////////////////////
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(repllabel, 0, 0);
  layout->addWidget(repllineedit, 0, 1);
  setLayout(layout);

  ///////////////////////////////////////////

  connect(repllineedit, SIGNAL(returnPressed()),
          this, SLOT(changed()));
}

void REPLWidget::changed()
{
  emit lineEntered(repllineedit->text());
  repllineedit->setText("");
}
