#include "robotMainWindowQt.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTabWidget>
#include <QTextEdit>
#include <QPixmap>
#include <QWidget>

#include "armAssemblyWidgetQt.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUI();
}

void MainWindow::setupUI() {
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(central);

    // --- Left Panel ---
    QVBoxLayout *leftPanel = new QVBoxLayout;

    btnPowerOn = new QPushButton("Power On");
    btnPowerOff = new QPushButton("Power Off");
    btnHome = new QPushButton("Home");

    status1 = new QLabel("ECM: OK");
    status2 = new QLabel("PSM1: OK");

    leftPanel->addWidget(btnPowerOn);
    leftPanel->addWidget(btnPowerOff);
    leftPanel->addWidget(btnHome);
    leftPanel->addWidget(status1);
    leftPanel->addWidget(status2);
    leftPanel->addStretch();

    QLabel *icon = new QLabel;
    icon->setPixmap(QPixmap("../media/surgibot_logo.png").scaled(160, 160));
    icon->setAlignment(Qt::AlignCenter);
    leftPanel->addWidget(icon);

    // --- Right Panel ---
    QVBoxLayout *rightPanel = new QVBoxLayout;

    tabWidget = new QTabWidget;
    QWidget *tabArms = new QWidget;
    QWidget *tabPID = new QWidget;
    tabWidget->addTab(tabArms, "Arms");
    tabWidget->addTab(tabPID, "PID");

    // nested tab under tabArms
    QTabWidget* subTabArms = new QTabWidget;
    ArmSubassemblyWidget *tabPSM1 = new ArmSubassemblyWidget("PSM1");
    ArmSubassemblyWidget *tabPSM2 = new ArmSubassemblyWidget("PSM2");
    ArmSubassemblyWidget *tabECM = new ArmSubassemblyWidget("ECM");
    subTabArms->addTab(tabPSM1, "PSM1");
    subTabArms->addTab(tabPSM2, "PSM2");
    subTabArms->addTab(tabECM, "ECM");
    // Set layout for the tabArms container
    QVBoxLayout *armsLayout = new QVBoxLayout;
    armsLayout->setContentsMargins(0, 0, 0, 0);
    armsLayout->addWidget(subTabArms);
    // add nested tab to tabArms
    tabArms->setLayout(armsLayout);
    
    logViewer = new QTextEdit;
    logViewer->setReadOnly(true);
    logViewer->setMinimumHeight(120);

    if (this->tabWidget != nullptr) {
        rightPanel->addWidget(tabWidget);
    }
    rightPanel->addWidget(logViewer);

    mainLayout->addLayout(leftPanel, 1);
    mainLayout->addLayout(rightPanel, 4);

    setCentralWidget(central);
    setWindowTitle("Control GUI");
    resize(1000, 600);
}