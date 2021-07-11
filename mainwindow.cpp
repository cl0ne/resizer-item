#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "resizer/graphicsitemresizer.h"

#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 100, 100));
    item->setPos(10, 10);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPen(QColor(102, 102, 102));
    item->setBrush(QColor(158, 204, 255));
    scene->addItem(item);

    GraphicsItemResizer *resizer = new GraphicsItemResizer(item);
    resizer->setBrush(QColor(64, 64, 64));
    resizer->setMinSize(QSizeF(30, 30));
    resizer->setTargetSize(item->boundingRect().size());
    resizer->setHandlersIgnoreTransformations(true);
    QObject::connect(
        resizer,
        &GraphicsItemResizer::targetRectChanged,
        [item](const QRectF & rect)
        {
            QPointF pos = item->pos();
            item->setPos(pos + rect.topLeft());
            QRectF old = item->rect();
            item->setRect(QRectF(old.topLeft(), rect.size()));
        }
    );

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    connect(
        ui->plusButton,
        &QPushButton::clicked, this,
        [&](){ ui->graphicsView->scale(1.2, 1.2); }
    );
    connect(
        ui->minusButton,
        &QPushButton::clicked,
        this,
        [&]() { ui->graphicsView->scale((1.0 / 1.2), (1.0 / 1.2)); }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}
