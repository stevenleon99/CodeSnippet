#ifndef ARMSUBASSEMBLYWIDGET_H
#define ARMSUBASSEMBLYWIDGET_H

#include <QWidget>

class QLabel;
class QTableWidget;

class ArmSubassemblyWidget : public QWidget {
    Q_OBJECT
public:
    explicit ArmSubassemblyWidget(const QString &deviceName, QWidget *parent = nullptr);

    void updateStatus(const QString &status);
    void updateData(float pos, float vel, float torque);

private:
    QLabel *statusLabel;
    QTableWidget *dataTable;

public slots:
    void onPowerOnClicked();
    void onPowerOffClicked();
};

#endif // ARMSUBASSEMBLYWIDGET_H
