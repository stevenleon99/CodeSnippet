#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QLabel;
class QTabWidget;
class QTextEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupUI();

    // UI components (optional for future slot connections)
    QPushButton *btnPowerOn;
    QPushButton *btnPowerOff;
    QPushButton *btnHome;

    QLabel *status1;
    QLabel *status2;

    QTabWidget *tabWidget = nullptr;
    QTextEdit *logViewer = nullptr;
};

#endif // MAINWINDOW_H