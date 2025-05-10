#include <QCoreApplication>
#include "myobject.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    MyObject obj;

    // Signal-Slot connection
    QObject::connect(&obj, &MyObject::valueChanged, &obj, &MyObject::onValueChanged);

    // Dynamic property usage
    // the properties can be handled dynamically at runtime
    obj.setProperty("value", 42);
    qDebug() << "Dynamic property value:" << obj.property("value").toInt(); 

    // Meta-object introspection
    const QMetaObject *meta = obj.metaObject();
    qDebug() << "Class name:" << meta->className();

    // Invoke method dynamically
    // this method (static-akin) is declared with the keyword Q_INVOKABLE
    QMetaObject::invokeMethod(&obj, "printMessage", Q_ARG(QString, "Hello from invokeMethod"));

    // Type-safe casting
    QObject *base = &obj;
    MyObject *casted = qobject_cast<MyObject *>(base);
    if (casted) {
        qDebug() << "qobject_cast successful.";
    }

    // Event handling
    // QEvent::User is a user-defined event tag (QEvent::User+1)
    // Class inherit QEvent can custom the event information
    // Class override the event() method to handle the event
    QEvent customEvent(QEvent::User);
    QCoreApplication::sendEvent(&obj, &customEvent);

    return 0;
}