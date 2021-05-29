#ifndef NODESHAPE_H
#define NODESHAPE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

class NodeShape: public QGraphicsItem
{
public:
    NodeShape();
    ~NodeShape();
    QColor NodeBrushColor = Qt::cyan;
    QColor NodePenColor = Qt::black;
    void SetNodeCoords(double& x, double& y);
    void SetTextCoords(double& x, double& y);
    void SetNodeRadius(double& radius);
protected:
    double node_x, node_y;
    double text_x, text_y;
    double node_radius;
    //выделение области для рисования узла
    virtual QRectF boundingRect() const;
    //рисование узла
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //обработчики события наведения мышки:
    //вхождение курсора в область прорисовки узла
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    //выход курсора из области прорисовки узла
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // NODESHAPE_H
