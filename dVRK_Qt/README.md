**Qt-Based desktop front-end application**

- the subsystem are wrapped into QtWidget
- the main application can be customly truncated or populated with user inputing the need for those QtWidget
```mermaid
graph TD
    QA[QApplication: <br>- Dispatches UI events <br>- Handles signals/slots <br>- Updates widgets]
    QC[mtsIntuitiveResearchKitConsoleQt]
    QA --> QC

    subgraph ConsoleQtTabs[Tabs arms, teleop, console, etc.]
        TAB_ECM[QWidget: ECM]
        TAB_PSM[QWidget: PSM]
    end

    QC --> ConsoleQtTabs

    subgraph Connections[Connected to:]
        CONSOLE[mtsIntuitiveResearchKitConsole <br> *cisst logic*]
        ROS[mtsROSBridge <br> *ROS integration*]
    end

    QC --> CONSOLE
    QC --> ROS

```

| name | description |
|------|------------------------------------------------------------------------------------------------------|
| mtsIntuitiveResearchKitConsole | defined by JSON and connect to hardware drivers (RobotIO, PSM...) |
| mtsIntuitiveResearchKitConsoleQt | the main front-end user interface and dynamically created acd to console |

```mermaid
graph TD
    A[QApplication]
    B[mtsIntuitiveResearchKitConsoleQt - consoleQt]
    C[mtsIntuitiveResearchKitConsole - console]
    D[Qt Event Loop]
    F[Qt slots]
    G[cisst functions]

    A -->|initializes| B
    B -->|configure with| C
    B -->|connect to| C
    A -->|runs| D
    D --> B
    B -->|signal slot interaction| F --> G
    G -->|call mtsFunctionWrite or Read| C
    C -->|send commands to| E[Hardware Components - MTM ECM PSM]

    subgraph Qt GUI Layer
        A
        D
        B
        F
        G
    end

    subgraph Real Time Control Layer
        C
        E
    end

```
- some connection is created but not registered yet by
```
mtsDelayedConnection
```
- the following is an implicit form to connect server and client interface
```
// Connections store the connection definition by
Connections.Add("consoleGUI", "Main", "console", "Main");
// same as mtsLocalManager::connection()
Connections.Connect()
```

```mermaid
graph TD
    subgraph ConsolQt
        A[mtsIntuitiveResearchKitConsoleQt - consoleQt]
        F[mtsDelayedConnections]
        subgraph Qt GUI
            I[consoleGUI - layer1 GUI]
            H[QTabWidget = consoleGUI->GetTabWidget - layer2 GUI]
            B[QTabWidget - layer3 GUI e.g. Arms IOs PIDs Teleop]
            C[GUI Widgets - layer4 GUI e.g. PSM ECM MTMQtWidget PIDQtWidget etc]
        end    
    end

    subgraph Real Time Layer - Console
        D[mtsIntuitiveResearchKitConsole - console]
        E[Robot Components - MTM PSM ECM Teleop IO]
    end

    A --> I
    I --> H
    H --> B
    B --> C
    C -->|Store all the connection definition | F
    F -->|Connect triggers| G[mtsManagerLocal Connect]
    G -->|Binds interfaces| E
    D --> E
    E -->|Decide what widgets to be created| C
    A -->|Has a function to call connect| F
```