#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QVariant>
#include <QDebug>

class MyObject : public QObject {
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit MyObject(QObject *parent = nullptr);

    int value() const;
    void setValue(int val);

    Q_INVOKABLE void printMessage(const QString &msg);

signals:
    void valueChanged(int newValue);

public slots:
    void onValueChanged(int newValue);

protected:
    bool event(QEvent *event) override;

private:
    int m_value;
};

#endif // MYOBJECT_H