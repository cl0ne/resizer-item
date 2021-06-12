#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resizer/graphicsitemresizer.h"
#include <QGraphicsRectItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsRectItem *item = new QGraphicsRectItem(QRectF(0, 0, 100, 100));
    item->setPen(QColor(102, 102, 102));
    item->setBrush(QColor(158, 204, 255));

    GraphicsItemResizer *resizer = new GraphicsItemResizer(item);
    resizer->setPos(10, 10);
    resizer->setHandleItemBrush(QColor(64, 64, 64));
    resizer->setTargetMinSize(QSizeF(30, 30));
    resizer->setHandlersIgnoreTransformations(true);
    resizer->setBoundingRectAreaVisible(true);
    scene->addItem(resizer);
    QObject::connect(resizer, &GraphicsItemResizer::targetRectChanged, [item](const QRectF &rect)
    {
        QRectF old = item->rect();
        item->setRect(QRectF(old.topLeft(), rect.size()));
    });

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    mTestItem = item;
    mResizer = resizer;

    connect(ui->plusButton, &QPushButton::clicked, this, [&]() {
        ui->graphicsView->scale(1.2, 1.2);
    });
    connect(ui->minusButton, &QPushButton::clicked, this, [&]() {
        ui->graphicsView->scale((1.0 / 1.2), (1.0 / 1.2));
    });
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, [&]() {
        mTestItem->setRotation(ui->spinBox->value());
        mResizer->updateState();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
