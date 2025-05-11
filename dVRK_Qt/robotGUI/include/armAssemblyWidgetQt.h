#ifndef ARMSUBASSEMBLYWIDGET_H
#define ARMSUBASSEMBLYWIDGET_H

#include <QWidget>
#include <QVector>
#include "qcustomplot.h"


class QLabel;
class QTableWidget;

class ArmSubassemblyWidget : public QWidget {
    Q_OBJECT
public:
    explicit ArmSubassemblyWidget(const QString &deviceName, QWidget *parent = nullptr);

    void updateStatus(const QString &status);
    void updateData(float pos, float vel, float torque);
    void appendPlotPoint(float x, float y);

private:
    QLabel *statusLabel;
    QTableWidget *dataTable;
    QCustomPlot *plot;
    QCPGraph *curve;
    QVector<double> xData, yData;

public slots:
    void onPowerOnClicked();
    void onPowerOffClicked();
};

#endif // ARMSUBASSEMBLYWIDGET_H
