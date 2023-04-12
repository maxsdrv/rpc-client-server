#pragma once

#include <QDebug>

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

    [[nodiscard]] int count() const override {
        return m_container.count();
    }

    [[nodiscard]] int rowCount(const QModelIndex& parent) const override {
        Q_UNUSED(parent)
        return count();
    }

    [[nodiscard]] QHash<int, QByteArray> roleNames() const override {
        s_role_names[NameRole] = "name";
        s_role_names[CommandRole] = "command";
        s_role_names[DescriptionRole] = "description";

        return s_role_names;
    }

    [[nodiscard]] QVariant data(const QModelIndex& index, int role) const override {
        int row = index.row();

        if (row < 0 || row >= m_container.count() || m_container.at(row).isNull()) {
            return {};
        }

        T* data_ptr = m_container.at(row).data();

        switch (role) {
            case NameRole:
                qDebug() << "From QVariant data()->" << data_ptr->name();
                return QVariant::fromValue(data_ptr->name());
            case CommandRole:
                qDebug() << "From QVariant data()->" << data_ptr->command();
                return QVariant::fromValue(data_ptr->command());
            case DescriptionRole: 
                qDebug() << "From QVariant data()->" << data_ptr->description();
                return QVariant::fromValue(data_ptr->description());
            default:
                return {};
        }
        return data_ptr->property(s_role_names.value(role));
    }

    int append(T *value) {
        qDebug() << "Append called";
        Q_ASSERT_X(value != nullptr, full_template_name(), "Trying to add member of NULL"); 
        auto it = std::find_if(std::begin(m_container), std::end(m_container), 
        [value](const QSharedPointer<T> &ptr) {
            return ptr.data() == value; 
        });
        if (it != std::end(m_container)) {
#ifdef DEBUG            
            qDebug() << full_template_name() << "Member already exists";
#endif
            return -1;
        }
        beginInsertRows(QModelIndex(), m_container.count(), m_container.count());
        m_container.append(QSharedPointer<T>(value));
        emit count_changed();
        endInsertRows();
        return m_container.count() - 1;
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
    static QByteArray full_template_name() { //Debug helper
        return QString("OperatorsListModel<%1>").arg(T::staticMetaObject.className()).
        toLatin1();
    }
protected:
    void clear() {
        m_container.clear();
        emit count_changed();
    }
};

template <typename T>
QHash<int, QByteArray> OperatorsListModel<T>::s_role_names;






