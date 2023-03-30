#pragma once


#include "OperatorsListModelBase.h"


template <typename T>
class OperatorsListModel : public OperatorsListModelBase {
public:
    explicit OperatorsListModel(QList<QSharedPointer<T>> container = {}, QObject* parent = nullptr):
                        OperatorsListModelBase(parent) {

        reset(container);
    }
    ~OperatorsListModel() override {
        clear();
    }

    enum Roles {
        NameRole = Qt::UserRole + 1,
        CommandRole, 
        DescriptionRole
    };

    int count() const override {
        return m_container.count();
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        Q_UNUSED(parent)
        return count();
    }

    QHash<int, QByteArray> roleNames() const override {
        s_role_names[NameRole] = "name";
        s_role_names[CommandRole] = "command";
        s_role_names[DescriptionRole] = "description";

        return s_role_names;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        int row = index.row();

        if (row < 0 || row >= m_container.count() || m_container.at(row).isNull()) {
            return {};
        }

        T* data_ptr = m_container.at(row).data();

        // if(s_role_names.value(role) == "modelData") {
        //     return QVariant::fromValue(data_ptr);
        // } 

        switch (role) {
            case NameRole:
                return QVariant::fromValue(data_ptr->name());
            case CommandRole:
                return QVariant::fromValue(data_ptr->command());
            case DescriptionRole: 
                return QVariant::fromValue(data_ptr->description());
            default:
                return {};
        }

        return data_ptr->property(s_role_names.value(role));
    }
    void add(QSharedPointer<T> op) {
        beginInsertRows(QModelIndex(), m_container.size(), m_container.size());
        m_container.append(std::move(op));
        endInsertRows();
    }

    void reset(const QList<QSharedPointer<T>> &container) {
        beginResetModel();
        clear();
        m_container = container;
        emit count_changed();
        endResetModel();
    }

private:
    QList<QSharedPointer<T>> m_container; 
    static QHash<int, QByteArray> s_role_names;
protected:
    void clear() {
        m_container.clear();
        emit count_changed();
    }
};

template <typename T>
QHash<int, QByteArray> OperatorsListModel<T>::s_role_names;






