#include "nodeshape.h"


NodeShape::NodeShape(): QGraphicsItem()
{
    //включение приема событий от обработчиков событий курсора
    setAcceptHoverEvents(true);
}

NodeShape::~NodeShape(){}

QRectF NodeShape::boundingRect() const {
    return QRectF(node_x - node_radius, node_y - node_radius, node_radius*2, node_radius*2);
}

void NodeShape::SetNodeCoords(double &x, double &y){
    node_x = x;
    node_y = y;
}

void NodeShape::SetTextCoords(double &x, double &y){
    text_x = x;
    text_y = y;
}

void NodeShape::SetNodeRadius(double &radius){
    node_radius = radius;
}


void NodeShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPointF pointF(node_x, node_y);
    painter->setBrush(NodeBrushColor);
    painter->setPen(NodePenColor);
    painter->drawEllipse(pointF, node_radius, node_radius);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void NodeShape::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    NodeBrushColor = Qt::darkGreen;
    update();
}

void NodeShape::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    NodeBrushColor = Qt::cyan;
    update();
}
