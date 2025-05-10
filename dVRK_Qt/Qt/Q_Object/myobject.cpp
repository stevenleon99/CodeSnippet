#include "myobject.h"
#include <QEvent>

MyObject::MyObject(QObject *parent) : QObject(parent), m_value(0) {}

int MyObject::value() const {
    return m_value;
}

void MyObject::setValue(int val) {
    if (m_value != val) {
        m_value = val;
        emit valueChanged(val);
    }
}

void MyObject::printMessage(const QString &msg) {
    qDebug() << "Message:" << msg;
}

void MyObject::onValueChanged(int newValue) {
    qDebug() << "Value changed to" << newValue;
}

bool MyObject::event(QEvent *event) {
    qDebug() << "Custom event received of type:" << event->type();
    return QObject::event(event);
}