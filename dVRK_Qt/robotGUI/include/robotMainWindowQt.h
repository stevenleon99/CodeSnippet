#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unordered_map>
#include <string>

class QPushButton;
class QLabel;
class QTabWidget;
class QTextEdit;
class ArmSubassemblyWidget;

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

    std::unordered_map<std::string, ArmSubassemblyWidget*> ArmSubassemblyWidgetList;

private slots:
    void onPowerOnClicked();
    void onPowerOffClicked();
    void onHomeClicked(); 
};

#endif // MAINWINDOW_H