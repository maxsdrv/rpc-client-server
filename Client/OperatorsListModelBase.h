#pragma once 

#include <QAbstractListModel>
#include <QObject>


class OperatorsListModelBase : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY count_changed)

public:
    explicit OperatorsListModelBase(QObject* parent = nullptr);

    virtual int count() const = 0;
signals:
    void count_changed();
};