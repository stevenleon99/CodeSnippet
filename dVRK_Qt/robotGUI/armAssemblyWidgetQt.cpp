#include "armAssemblyWidgetQt.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>

ArmSubassemblyWidget::ArmSubassemblyWidget(const QString &deviceName, QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel(QString("Device: %1").arg(deviceName));
    title->setStyleSheet("font-weight: bold");
    layout->addWidget(title);

    statusLabel = new QLabel("Status: Unknown");
    layout->addWidget(statusLabel);

    dataTable = new QTableWidget(3, 2);
    dataTable->setHorizontalHeaderLabels({"Signal", "Value"});
    dataTable->setVerticalHeaderLabels({"Position", "Velocity", "Torque"});
    dataTable->horizontalHeader()->setStretchLastSection(true);
    dataTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(dataTable);

    // Plot initialization
    plot = new QCustomPlot;
    curve = plot->addGraph();
    plot->xAxis->setLabel("Time");
    plot->yAxis->setLabel("Value");
    plot->xAxis->setRange(0, 10);
    plot->yAxis->setRange(-10, 10);
    plot->setMinimumHeight(150);
    plot->setMinimumWidth(300);
    layout->addWidget(plot);
}

void ArmSubassemblyWidget::updateStatus(const QString &status) {
    statusLabel->setText("Status: " + status);
}

void ArmSubassemblyWidget::updateData(float pos, float vel, float torque) {
    dataTable->setItem(0, 1, new QTableWidgetItem(QString::number(pos)));
    dataTable->setItem(1, 1, new QTableWidgetItem(QString::number(vel)));
    dataTable->setItem(2, 1, new QTableWidgetItem(QString::number(torque)));
}

void ArmSubassemblyWidget::appendPlotPoint(float x, float y) {
    xData.append(x);
    yData.append(y);
    curve->setData(xData, yData);
    plot->xAxis->setRange(std::max(0.0, x - 10.0), x + 1);  // Scroll window
    plot->replot();
}

void ArmSubassemblyWidget::onPowerOnClicked() {
    updateStatus("Powered On");
}

void ArmSubassemblyWidget::onPowerOffClicked() {
    updateStatus("Powered Off");
}

