---
title: dVRK Qt
description: Qt-based desktop front-end application for da Vinci Research Kit.
---

Qt-based desktop front-end application for the da Vinci Research Kit (dVRK) robotic system.

## Architecture

The application wraps subsystems into QtWidgets. The main application can be dynamically populated with user-selected widgets.

Key components:

- **mtsIntuitiveResearchKitConsole** — defined by JSON, connects to hardware drivers (RobotIO, PSM, etc.)
- **mtsIntuitiveResearchKitConsoleQt** — main front-end UI, dynamically creates widgets based on console configuration

## GUI Layer Structure

1. **QApplication** — dispatches UI events, handles signals/slots
2. **mtsIntuitiveResearchKitConsoleQt** — main console Qt wrapper
3. **QTabWidget** — tabbed interface (Arms, Teleop, Console, etc.)
4. **GUI Widgets** — individual components (PSM, ECM, MTMQtWidget, PIDQtWidget, etc.)

## Connection Pattern

Connections are defined using `mtsDelayedConnection` and registered with:

```cpp
Connections.Add("consoleGUI", "Main", "console", "Main");
Connections.Connect();
```

This implicitly connects server and client interfaces between the Qt GUI layer and the real-time control layer.
