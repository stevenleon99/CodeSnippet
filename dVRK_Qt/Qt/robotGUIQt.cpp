#include <QApplication>
#include <QListView>
#include <QAbstractListModel>
#include <QStringList>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

class SimpleListModel : public QAbstractListModel {
    Q_OBJECT
public:
    explicit SimpleListModel(QObject *parent = nullptr)
        : QAbstractListModel(parent), items({"Apple", "Banana", "Orange"}) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return items.size();
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();
        return items.at(index.row());
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role) override {
        if (index.isValid() && role == Qt::EditRole) {
            items[index.row()] = value.toString();
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        if (!index.isValid())
            return Qt::NoItemFlags;
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }

    void addItem(const QString &item) {
        beginInsertRows(QModelIndex(), items.size(), items.size());
        items << item;
        endInsertRows();
    }

private:
    QStringList items;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto model = new SimpleListModel;

    auto view = new QListView;
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    auto button = new QPushButton("Add Item");
    QObject::connect(button, &QPushButton::clicked, [&]() {
        model->addItem("New Item");
    });

    auto layout = new QVBoxLayout;
    layout->addWidget(view);
    layout->addWidget(button);

    auto window = new QWidget;
    window->setLayout(layout);
    window->setWindowTitle("MVC List Example");
    window->resize(300, 200);
    window->show();

    return app.exec();
}

#include "robotGUIQt.moc"