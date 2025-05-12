**Common Problem in multithread program**

| Challenge                             | Cause                                                        | Recommended Solution                                           |
|---------------------------------------|--------------------------------------------------------------|----------------------------------------------------------------|
| UI freezing or unresponsiveness       | Long-running tasks in the main GUI thread                    | Use `QThread`, `QtConcurrent`, or signal-slot offloading       |
| Too-frequent GUI updates              | Excessive redraw rate (e.g., every few ms)                   | Throttle with `QTimer` (e.g., 30–100 ms update rate)           |
| Rendering performance bottlenecks     | Plotting too many points                                     | Use windowed plots, decimation, or `addData()` efficiently     |
| Memory usage growth                   | Unbounded data vectors or tables                             | Use fixed-size circular buffers or trim old data               |
| Thread-safety violations              | Updating UI from non-GUI threads                             | Emit signals to GUI thread with `Qt::QueuedConnection`         |
| Inconsistent sampling/timing drift    | Poor timing via `sleep()` or `QTimer` without correction     | Use `QElapsedTimer` or timestamp-based sampling logic          |
| Delayed plot refresh or no update     | Not calling `replot()` or overloading Qt event loop          | Call `plot->replot()` after updates, use `rpQueuedReplot`      |


**Best practice**

- Do background work (e.g., position calculations, hardware polling, data acquisition) in a secondary thread.
- Communicate results back to the main thread using Qt’s signal-slot mechanism with Qt::QueuedConnection (default for cross-thread connections).
- Update GUI components only in the main thread.


**Debug in multithread program**

| Technique                    | Purpose                                              | Example / Usage                                      |
|------------------------------|------------------------------------------------------|------------------------------------------------------|
| `QObject::thread()`         | Check which thread owns a widget                     | `qDebug() << label->thread();`                       |
| `QThread::setObjectName()`  | Name threads for logging clarity                     | `thread->setObjectName("WorkerThread");`             |
| Heartbeat with `QTimer`     | Verify thread is alive and responsive                | Emit log every second from worker thread             |
| `QElapsedTimer`             | Measure slot/UI processing time                      | `qDebug() << timer.elapsed() << "ms";`               |
| `QThread::isRunning()`      | Check if thread is still active                      | `worker->isRunning()`                                |
| Debugger thread inspection  | Detect infinite loops or deadlocks                   | Use Qt Creator or gdb/lldb to inspect stack traces   |
| Event loop logging          | View Qt internal event handling                     | `QT_LOGGING_RULES="qt.qpa.*=true"`                   |
