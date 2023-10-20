#include "main_window.hpp"

#include <iostream>

#include <QLayout>

#include "message_widget.hpp"
#include "canvas_widget.hpp"
#include "repl_widget.hpp"
#include "interpreter_semantic_error.hpp"

MainWindow::MainWindow(QWidget *parent) : MainWindow("", parent)
{
  // TODO: your code here...
}

MainWindow::MainWindow(std::string filename, QWidget *parent) : QWidget(parent)
{
  MessageWidget *message = new MessageWidget();
  CanvasWidget *canvas = new CanvasWidget();
  REPLWidget *repl = new REPLWidget();
  QtInterpreter *interp = new QtInterpreter();

  /////////////////connects/////////////////
  connect(repl, SIGNAL(lineEntered(QString)),
          interp, SLOT(parseAndEvaluate(QString)));

  connect(interp, SIGNAL(info(QString)),
          message, SLOT(info(QString)));

  connect(interp, SIGNAL(error(QString)),
          message, SLOT(error(QString)));

  connect(interp, SIGNAL(drawGraphic(QGraphicsItem*)),
          canvas, SLOT(addGraphic(QGraphicsItem*)));


/////////////////layouts//////////////////
QGridLayout *layout = new QGridLayout;
layout->addWidget(message, 0, 0);
layout->addWidget(canvas, 1, 0);
layout->addWidget(repl, 2, 0);

setLayout(layout);
setWindowTitle("slisp");
}
