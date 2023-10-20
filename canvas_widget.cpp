#include "canvas_widget.hpp"

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLayout>

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent)
{
  scene = new QGraphicsScene(this);
  QGraphicsView *view = new QGraphicsView(scene);
  ////////////////////////////////////////////////////////
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(view);
  setLayout(layout);
}

void CanvasWidget::addGraphic(QGraphicsItem *item)
{
  scene->addItem(item);
}