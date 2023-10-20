#ifndef REPL_WIDGET_HPP
#define REPL_WIDGET_HPP

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QVector>
#include <QLabel>

class REPLWidget: public QWidget{
Q_OBJECT

public:

  REPLWidget(QWidget * parent = nullptr);

signals:

  void lineEntered(QString entry);

private:
  
  QLabel *repllabel;
  QLineEdit *repllineedit;

private slots:

  void changed();
};

#endif