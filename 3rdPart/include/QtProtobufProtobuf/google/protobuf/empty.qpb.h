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
class Empty;
using EmptyRepeated = QList<QSharedPointer<Empty>>;

}
}


namespace google {
namespace protobuf {
namespace Empty_QtProtobufNested {
}

class Empty : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Empty)

public:
    Empty(QObject *parent = nullptr);
    virtual ~Empty();
    Empty(const Empty &other);
    Empty &operator =(const Empty &other);
    Empty(Empty &&other);
    Empty &operator =(Empty &&other);
    bool operator ==(const Empty &other) const;
    bool operator !=(const Empty &other) const;
    static void registerTypes();

signals:

private:

private:
};

using EmptyRepeated = QList<QSharedPointer<Empty>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Empty)
Q_DECLARE_METATYPE(google::protobuf::EmptyRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Empty>)