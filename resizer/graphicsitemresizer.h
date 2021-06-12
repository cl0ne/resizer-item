#ifndef GRAPHICSITEMRESIZER_H
#define GRAPHICSITEMRESIZER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPen>
#include <QGraphicsView>

class GraphicsItemResizer : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit GraphicsItemResizer(QGraphicsItem *target, QGraphicsItem *parent = nullptr);
    ~GraphicsItemResizer();

    inline QBrush handleItemBrush() const;
    void setHandleItemBrush(const QBrush &brush);

    inline QPen handleItemPen() const;
    void setHandleItemPen(const QPen &pen);

    inline QBrush boundingRectAreaBrush() const;
    void setBoundingRectAreaBrush(const QBrush &brush);

    inline QPen boundingRectAreaPen() const;
    void setBoundingRectAreaPen(const QPen &pen);

    inline bool boundingRectAreaVisible() const;
    void setBoundingRectAreaVisible(bool visible);

    inline QGraphicsItem* target() const;

    QRectF targetBoundingRect() const;
    inline QSizeF targetSize() const;

    inline QSizeF targetMinSize() const;
    void setTargetMinSize(const QSizeF &minSize);

    bool handlersIgnoreTransformations() const;
    // If true, handler items ignore all transformations e.g. zooming the view etc
    void setHandlersIgnoreTransformations(bool ignore);

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public slots:
    void updateState();

signals:
    void targetRectChanged(const QRectF &rect);

private:
    class HandleItem;

    void updateHandleItemPositions();
    void updateSize(const QSizeF &size);
    void updateBoundingRect();
    void updateTargetRect(const QRectF &rect);

    QList<HandleItem *> mHandleItems;
    QPen mHandleItemPen;
    QBrush mHandleItemBrush;

    QGraphicsItem* mTarget;
    QSizeF mTargetSize;
    QSizeF mTargetMinSize;
    QRectF mBounds;

    bool mBoundingRectAreaVisible;
    QPen mBoundingRectAreaPen;
    QBrush mBoundingRectAreaBrush;

    bool mHandlersIgnoreTransformations;
};

QBrush GraphicsItemResizer::handleItemBrush() const
{
    return mHandleItemBrush;
}

QPen GraphicsItemResizer::handleItemPen() const
{
    return mHandleItemPen;
}

QBrush GraphicsItemResizer::boundingRectAreaBrush() const
{
    return mBoundingRectAreaBrush;
}

QPen GraphicsItemResizer::boundingRectAreaPen() const
{
    return mBoundingRectAreaPen;
}

bool GraphicsItemResizer::boundingRectAreaVisible() const
{
    return mBoundingRectAreaVisible;
}

QGraphicsItem* GraphicsItemResizer::target() const
{
    return mTarget;
}

QSizeF GraphicsItemResizer::targetSize() const
{
    return mTargetSize;
}

QSizeF GraphicsItemResizer::targetMinSize() const
{
    return mTargetMinSize;
}

#endif // GRAPHICSITEMRESIZER_H
