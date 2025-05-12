#include "positioncalculator.h"
#include <cmath>

PositionCalculator::PositionCalculator(QObject *parent)
    : QObject(parent), x(0), y(0), z(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        x += 0.1;
        y = std::sin(x);
        z = std::cos(x);
        emit positionUpdated(x, y, z);
    });
}

void PositionCalculator::start() {
    timer->start(100);  // update every 100 ms
}
