#include "message_widget.hpp"

#include <QLabel>
#include <QLayout>
#include <QLineEdit>

MessageWidget::MessageWidget(QWidget *parent) : QWidget(parent)
{
  messagelabel = new QLabel("Massage:");
  messagedis = new QLineEdit();
  messagedis->setReadOnly(true);

  ////////////////////////////////////////
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(messagelabel, 0, 0);
  layout->addWidget(messagedis, 0, 1);
  setLayout(layout);
}

void MessageWidget::info(QString message)
{
  QPalette info_mes;
  messagedis->setPalette(info_mes);
  messagedis->setText(message);
}

void MessageWidget::error(QString message)
{
  //https://stackoverflow.com/questions/2749798/qlabel-set-color-of-text-and-background
  QPalette error_mes;
  error_mes.setColor(QPalette::Background, Qt::red);

  messagedis->setAutoFillBackground(true);
  messagedis->setPalette(error_mes);
  messagedis->setText(message);
}

void MessageWidget::clear()
{
  // TODO: your code here...
}
