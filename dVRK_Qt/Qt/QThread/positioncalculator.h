#ifndef POSITIONCALCULATOR_H
#define POSITIONCALCULATOR_H

#include <QObject>
#include <QTimer>

class PositionCalculator : public QObject {
    Q_OBJECT
public:
    explicit PositionCalculator(QObject *parent = nullptr);

public slots:
    void start();

signals:
    void positionUpdated(double x, double y, double z);

private:
    QTimer *timer;
    double x, y, z;
};

#endif // POSITIONCALCULATOR_H
