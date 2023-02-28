/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#pragma once

#include <QObject>
#include <QMetaType>
#include <QList>
#include <QProtobufObject>
#include <QProtobufLazyMessagePointer>
#include <QSharedPointer>

#include <memory>
#include <unordered_map>

#include <QtQml/QQmlListProperty>
#include <QQmlListPropertyConstructor>

#include <QByteArray>
#include <QString>

namespace google {
namespace protobuf {
class Duration;
using DurationRepeated = QList<QSharedPointer<Duration>>;

}
}


namespace google {
namespace protobuf {
namespace Duration_QtProtobufNested {
}

class Duration : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Duration)
    Q_PROPERTY(QtProtobuf::int64 seconds READ seconds WRITE setSeconds NOTIFY secondsChanged SCRIPTABLE false)
    Q_PROPERTY(QtProtobuf::int32 nanos_p READ nanos WRITE setNanos NOTIFY nanosChanged SCRIPTABLE false)
    Q_PROPERTY(int nanos READ nanos_p WRITE setNanos_p NOTIFY nanosChanged SCRIPTABLE true)

public:
    Duration(QObject *parent = nullptr);
    Duration(QtProtobuf::int64 seconds,QObject *parent = nullptr);
    Duration(QtProtobuf::int64 seconds,QtProtobuf::int32 nanos,QObject *parent = nullptr);
    virtual ~Duration();
    Duration(const Duration &other);
    Duration &operator =(const Duration &other);
    Duration(Duration &&other);
    Duration &operator =(Duration &&other);
    bool operator ==(const Duration &other) const;
    bool operator !=(const Duration &other) const;

    const QtProtobuf::int64 seconds() const {
        return m_seconds;
    }


    const QtProtobuf::int32 nanos() const {
        return m_nanos;
    }

    void setSeconds(const QtProtobuf::int64 &seconds) {
        if (m_seconds != seconds) {
            m_seconds = seconds;
            secondsChanged();
        }
    }

    void setNanos(const QtProtobuf::int32 &nanos) {
        if (m_nanos != nanos) {
            m_nanos = nanos;
            nanosChanged();
        }
    }

    static void registerTypes();

signals:
    void secondsChanged();
    void nanosChanged();

private:
    int nanos_p() const {
        return m_nanos;
    }

    void setNanos_p(const int &nanos) {
        if (m_nanos != nanos) {
            m_nanos = nanos;
            nanosChanged();
        }
    }


private:
    QtProtobuf::int64 m_seconds;
    QtProtobuf::int32 m_nanos;
};

using DurationRepeated = QList<QSharedPointer<Duration>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Duration)
Q_DECLARE_METATYPE(google::protobuf::DurationRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Duration>)