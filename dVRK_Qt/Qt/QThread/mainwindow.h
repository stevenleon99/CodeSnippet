#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "positioncalculator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *label;
    QThread *workerThread;
    PositionCalculator *calculator;
};

#endif // MAINWINDOW_H
