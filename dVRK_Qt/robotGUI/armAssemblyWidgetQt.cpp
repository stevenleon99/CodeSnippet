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
}

void ArmSubassemblyWidget::updateStatus(const QString &status) {
    statusLabel->setText("Status: " + status);
}

void ArmSubassemblyWidget::updateData(float pos, float vel, float torque) {
    dataTable->setItem(0, 1, new QTableWidgetItem(QString::number(pos)));
    dataTable->setItem(1, 1, new QTableWidgetItem(QString::number(vel)));
    dataTable->setItem(2, 1, new QTableWidgetItem(QString::number(torque)));
}

void ArmSubassemblyWidget::onPowerOnClicked() {
    updateStatus("Powered On");
}

void ArmSubassemblyWidget::onPowerOffClicked() {
    updateStatus("Powered Off");
}
