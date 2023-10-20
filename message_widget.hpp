#ifndef MESSAGE_WINDOW_HPP
#define MESSAGE_WINDOW_HPP

#include <QString>
#include <QWidget>

class QLineEdit;
class QLabel;

class MessageWidget : public QWidget {
  Q_OBJECT

public:
  MessageWidget(QWidget *parent = nullptr);

private:
  QLineEdit *messagedis;
  QLabel *messagelabel;

public slots:

  void info(QString message);

  void error(QString message);

  void clear();
};

#endif
