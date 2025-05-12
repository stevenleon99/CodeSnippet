#include "mainwindow.h"
#include <QVBoxLayout>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      label(new QLabel("Waiting...", this)),
      workerThread(new QThread),
      calculator(new PositionCalculator) {

    QWidget *central = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(label);
    setCentralWidget(central);

    // Move worker to thread
    // move the PositionCalculator object to the worker thread (otherwise it will run in the main thread)
    calculator->moveToThread(workerThread);
    // workerthread started signal will trigger the start() method of PositionCalculator
    // the start() method will start the timer
    // the timer will emit positionUpdated signal every 100ms
    connect(workerThread, &QThread::started, calculator, &PositionCalculator::start);
    // follow the best practice to update the UI from the main thread
    // `=` refer to the most neighboring scope; can be replaced with `this`
    connect(calculator, &PositionCalculator::positionUpdated, this, [=](double x, double y, double z) {
        label->setText(QString("X: %1, Y: %2, Z: %3").arg(x).arg(y).arg(z));
    });

    workerThread->start();
}

MainWindow::~MainWindow() {
    workerThread->quit();
    // wait for the thread to finish
    workerThread->wait();
    delete calculator;
}
