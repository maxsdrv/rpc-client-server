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
#include "google/protobuf/any.qpb.h"
#include "google/protobuf/source_context.qpb.h"

namespace google {
namespace protobuf {

class SyntaxGadget : public QObject
{
    Q_OBJECT

public:
    static void registerTypes();

private:
    SyntaxGadget() {}
    SyntaxGadget(const SyntaxGadget &) = delete;
    SyntaxGadget(SyntaxGadget &&) = delete;

public:
    enum Syntax {
        SYNTAX_PROTO2 = 0,
        SYNTAX_PROTO3 = 1,
    };
    Q_ENUM(Syntax)
    using SyntaxRepeated = QList<Syntax>;
};


}
}

Q_DECLARE_METATYPE(google::protobuf::SyntaxGadget::SyntaxRepeated)

namespace google {
namespace protobuf {
class Type;
using TypeRepeated = QList<QSharedPointer<Type>>;

}
}


namespace google {
namespace protobuf {
class Field;
using FieldRepeated = QList<QSharedPointer<Field>>;

}
}


namespace google {
namespace protobuf {
class Enum;
using EnumRepeated = QList<QSharedPointer<Enum>>;

}
}


namespace google {
namespace protobuf {
class EnumValue;
using EnumValueRepeated = QList<QSharedPointer<EnumValue>>;

}
}


namespace google {
namespace protobuf {
class Option;
using OptionRepeated = QList<QSharedPointer<Option>>;

}
}


namespace google {
namespace protobuf {
namespace Type_QtProtobufNested {
}

class Type : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Type)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::FieldRepeated fieldsData READ fields WRITE setFields NOTIFY fieldsChanged SCRIPTABLE true)
    Q_PROPERTY(QStringList oneofsData READ oneofs WRITE setOneofs NOTIFY oneofsChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::OptionRepeated optionsData READ options WRITE setOptions NOTIFY optionsChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::SourceContext *sourceContext READ sourceContext_p WRITE setSourceContext_p NOTIFY sourceContextChanged)
    Q_PROPERTY(google::protobuf::SyntaxGadget::Syntax syntax READ syntax WRITE setSyntax NOTIFY syntaxChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Field> fields READ fields_l NOTIFY fieldsChanged)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Option> options READ options_l NOTIFY optionsChanged)

public:
    Type(QObject *parent = nullptr);
    Type(const QString &name,QObject *parent = nullptr);
    Type(const QString &name,const FieldRepeated &fields,QObject *parent = nullptr);
    Type(const QString &name,const FieldRepeated &fields,const QStringList &oneofs,QObject *parent = nullptr);
    Type(const QString &name,const FieldRepeated &fields,const QStringList &oneofs,const OptionRepeated &options,QObject *parent = nullptr);
    Type(const QString &name,const FieldRepeated &fields,const QStringList &oneofs,const OptionRepeated &options,const SourceContext &sourceContext,QObject *parent = nullptr);
    Type(const QString &name,const FieldRepeated &fields,const QStringList &oneofs,const OptionRepeated &options,const SourceContext &sourceContext,SyntaxGadget::Syntax syntax,QObject *parent = nullptr);
    virtual ~Type();
    Type(const Type &other);
    Type &operator =(const Type &other);
    Type(Type &&other);
    Type &operator =(Type &&other);
    bool operator ==(const Type &other) const;
    bool operator !=(const Type &other) const;

    QString name() const {
        return m_name;
    }


    FieldRepeated fields() const {
        return m_fields;
    }

    FieldRepeated &fields() {
        return m_fields;
    }

    QQmlListProperty<Field> fields_l();

    QStringList oneofs() const {
        return m_oneofs;
    }

    QStringList &oneofs() {
        return m_oneofs;
    }


    OptionRepeated options() const {
        return m_options;
    }

    OptionRepeated &options() {
        return m_options;
    }

    QQmlListProperty<Option> options_l();

    const SourceContext &sourceContext() const;

    SyntaxGadget::Syntax syntax() const {
        return m_syntax;
    }

    void setName(const QString &name);
    void setFields(const FieldRepeated &fields);
    void setOneofs(const QStringList &oneofs);
    void setOptions(const OptionRepeated &options);
    void setSourceContext(const SourceContext &sourceContext);
    void setSyntax(const SyntaxGadget::Syntax &syntax) {
        if (m_syntax != syntax) {
            m_syntax = syntax;
            syntaxChanged();
        }
    }

    static void registerTypes();

signals:
    void nameChanged();
    void fieldsChanged();
    void oneofsChanged();
    void optionsChanged();
    void sourceContextChanged();
    void syntaxChanged();

private:
    SourceContext *sourceContext_p() const;
    void setSourceContext_p(SourceContext *sourceContext);

private:
    QString m_name;
    FieldRepeated m_fields;
    QStringList m_oneofs;
    OptionRepeated m_options;
    QProtobufLazyMessagePointer<SourceContext> m_sourceContext;
    SyntaxGadget::Syntax m_syntax;
};

using TypeRepeated = QList<QSharedPointer<Type>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Type)
Q_DECLARE_METATYPE(google::protobuf::TypeRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Type>)

namespace google {
namespace protobuf {
namespace Field_QtProtobufNested {
}

class Field : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Field)
    Q_PROPERTY(Kind kind READ kind WRITE setKind NOTIFY kindChanged SCRIPTABLE true)
    Q_PROPERTY(Cardinality cardinality READ cardinality WRITE setCardinality NOTIFY cardinalityChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::int32 number_p READ number WRITE setNumber NOTIFY numberChanged SCRIPTABLE false)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(QString typeUrl READ typeUrl WRITE setTypeUrl NOTIFY typeUrlChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::int32 oneofIndex_p READ oneofIndex WRITE setOneofIndex NOTIFY oneofIndexChanged SCRIPTABLE false)
    Q_PROPERTY(bool packed READ packed WRITE setPacked NOTIFY packedChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::OptionRepeated optionsData READ options WRITE setOptions NOTIFY optionsChanged SCRIPTABLE true)
    Q_PROPERTY(QString jsonName READ jsonName WRITE setJsonName NOTIFY jsonNameChanged SCRIPTABLE true)
    Q_PROPERTY(QString defaultValue READ defaultValue WRITE setDefaultValue NOTIFY defaultValueChanged SCRIPTABLE true)
    Q_PROPERTY(int number READ number_p WRITE setNumber_p NOTIFY numberChanged SCRIPTABLE true)
    Q_PROPERTY(int oneofIndex READ oneofIndex_p WRITE setOneofIndex_p NOTIFY oneofIndexChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Option> options READ options_l NOTIFY optionsChanged)

public:
    enum Kind {
        TYPE_UNKNOWN = 0,
        TYPE_DOUBLE = 1,
        TYPE_FLOAT = 2,
        TYPE_INT64 = 3,
        TYPE_UINT64 = 4,
        TYPE_INT32 = 5,
        TYPE_FIXED64 = 6,
        TYPE_FIXED32 = 7,
        TYPE_BOOL = 8,
        TYPE_STRING = 9,
        TYPE_GROUP = 10,
        TYPE_MESSAGE = 11,
        TYPE_BYTES = 12,
        TYPE_UINT32 = 13,
        TYPE_ENUM = 14,
        TYPE_SFIXED32 = 15,
        TYPE_SFIXED64 = 16,
        TYPE_SINT32 = 17,
        TYPE_SINT64 = 18,
    };
    Q_ENUM(Kind)
    enum Cardinality {
        CARDINALITY_UNKNOWN = 0,
        CARDINALITY_OPTIONAL = 1,
        CARDINALITY_REQUIRED = 2,
        CARDINALITY_REPEATED = 3,
    };
    Q_ENUM(Cardinality)
    using KindRepeated = QList<Kind>;
    using CardinalityRepeated = QList<Cardinality>;
    Field(QObject *parent = nullptr);
    Field(Field::Kind kind,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,const QString &typeUrl,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,const QString &typeUrl,QtProtobuf::int32 oneofIndex,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,const QString &typeUrl,QtProtobuf::int32 oneofIndex,bool packed,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,const QString &typeUrl,QtProtobuf::int32 oneofIndex,bool packed,const OptionRepeated &options,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,const QString &typeUrl,QtProtobuf::int32 oneofIndex,bool packed,const OptionRepeated &options,const QString &jsonName,QObject *parent = nullptr);
    Field(Field::Kind kind,Field::Cardinality cardinality,QtProtobuf::int32 number,const QString &name,const QString &typeUrl,QtProtobuf::int32 oneofIndex,bool packed,const OptionRepeated &options,const QString &jsonName,const QString &defaultValue,QObject *parent = nullptr);
    virtual ~Field();
    Field(const Field &other);
    Field &operator =(const Field &other);
    Field(Field &&other);
    Field &operator =(Field &&other);
    bool operator ==(const Field &other) const;
    bool operator !=(const Field &other) const;

    Field::Kind kind() const {
        return m_kind;
    }


    Field::Cardinality cardinality() const {
        return m_cardinality;
    }


    const QtProtobuf::int32 number() const {
        return m_number;
    }


    QString name() const {
        return m_name;
    }


    QString typeUrl() const {
        return m_typeUrl;
    }


    const QtProtobuf::int32 oneofIndex() const {
        return m_oneofIndex;
    }


    bool packed() const {
        return m_packed;
    }


    OptionRepeated options() const {
        return m_options;
    }

    OptionRepeated &options() {
        return m_options;
    }

    QQmlListProperty<Option> options_l();

    QString jsonName() const {
        return m_jsonName;
    }


    QString defaultValue() const {
        return m_defaultValue;
    }

    void setKind(const Field::Kind &kind) {
        if (m_kind != kind) {
            m_kind = kind;
            kindChanged();
        }
    }

    void setCardinality(const Field::Cardinality &cardinality) {
        if (m_cardinality != cardinality) {
            m_cardinality = cardinality;
            cardinalityChanged();
        }
    }

    void setNumber(const QtProtobuf::int32 &number) {
        if (m_number != number) {
            m_number = number;
            numberChanged();
        }
    }

    void setName(const QString &name);
    void setTypeUrl(const QString &typeUrl);
    void setOneofIndex(const QtProtobuf::int32 &oneofIndex) {
        if (m_oneofIndex != oneofIndex) {
            m_oneofIndex = oneofIndex;
            oneofIndexChanged();
        }
    }

    void setPacked(const bool &packed) {
        if (m_packed != packed) {
            m_packed = packed;
            packedChanged();
        }
    }

    void setOptions(const OptionRepeated &options);
    void setJsonName(const QString &jsonName);
    void setDefaultValue(const QString &defaultValue);
    static void registerTypes();

signals:
    void kindChanged();
    void cardinalityChanged();
    void numberChanged();
    void nameChanged();
    void typeUrlChanged();
    void oneofIndexChanged();
    void packedChanged();
    void optionsChanged();
    void jsonNameChanged();
    void defaultValueChanged();

private:
    int number_p() const {
        return m_number;
    }

    void setNumber_p(const int &number) {
        if (m_number != number) {
            m_number = number;
            numberChanged();
        }
    }

    int oneofIndex_p() const {
        return m_oneofIndex;
    }

    void setOneofIndex_p(const int &oneofIndex) {
        if (m_oneofIndex != oneofIndex) {
            m_oneofIndex = oneofIndex;
            oneofIndexChanged();
        }
    }


private:
    Field::Kind m_kind;
    Field::Cardinality m_cardinality;
    QtProtobuf::int32 m_number;
    QString m_name;
    QString m_typeUrl;
    QtProtobuf::int32 m_oneofIndex;
    bool m_packed;
    OptionRepeated m_options;
    QString m_jsonName;
    QString m_defaultValue;
};

using FieldRepeated = QList<QSharedPointer<Field>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Field)
Q_DECLARE_METATYPE(google::protobuf::FieldRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Field>)
Q_DECLARE_METATYPE(google::protobuf::Field::Kind)
Q_DECLARE_METATYPE(google::protobuf::Field::KindRepeated)
Q_DECLARE_METATYPE(google::protobuf::Field::Cardinality)
Q_DECLARE_METATYPE(google::protobuf::Field::CardinalityRepeated)

namespace google {
namespace protobuf {
namespace Enum_QtProtobufNested {
}

class Enum : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Enum)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::EnumValueRepeated enumvalueData READ enumvalue WRITE setEnumvalue NOTIFY enumvalueChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::OptionRepeated optionsData READ options WRITE setOptions NOTIFY optionsChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::SourceContext *sourceContext READ sourceContext_p WRITE setSourceContext_p NOTIFY sourceContextChanged)
    Q_PROPERTY(google::protobuf::SyntaxGadget::Syntax syntax READ syntax WRITE setSyntax NOTIFY syntaxChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<google::protobuf::EnumValue> enumvalue READ enumvalue_l NOTIFY enumvalueChanged)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Option> options READ options_l NOTIFY optionsChanged)

public:
    Enum(QObject *parent = nullptr);
    Enum(const QString &name,QObject *parent = nullptr);
    Enum(const QString &name,const EnumValueRepeated &enumvalue,QObject *parent = nullptr);
    Enum(const QString &name,const EnumValueRepeated &enumvalue,const OptionRepeated &options,QObject *parent = nullptr);
    Enum(const QString &name,const EnumValueRepeated &enumvalue,const OptionRepeated &options,const SourceContext &sourceContext,QObject *parent = nullptr);
    Enum(const QString &name,const EnumValueRepeated &enumvalue,const OptionRepeated &options,const SourceContext &sourceContext,SyntaxGadget::Syntax syntax,QObject *parent = nullptr);
    virtual ~Enum();
    Enum(const Enum &other);
    Enum &operator =(const Enum &other);
    Enum(Enum &&other);
    Enum &operator =(Enum &&other);
    bool operator ==(const Enum &other) const;
    bool operator !=(const Enum &other) const;

    QString name() const {
        return m_name;
    }


    EnumValueRepeated enumvalue() const {
        return m_enumvalue;
    }

    EnumValueRepeated &enumvalue() {
        return m_enumvalue;
    }

    QQmlListProperty<EnumValue> enumvalue_l();

    OptionRepeated options() const {
        return m_options;
    }

    OptionRepeated &options() {
        return m_options;
    }

    QQmlListProperty<Option> options_l();

    const SourceContext &sourceContext() const;

    SyntaxGadget::Syntax syntax() const {
        return m_syntax;
    }

    void setName(const QString &name);
    void setEnumvalue(const EnumValueRepeated &enumvalue);
    void setOptions(const OptionRepeated &options);
    void setSourceContext(const SourceContext &sourceContext);
    void setSyntax(const SyntaxGadget::Syntax &syntax) {
        if (m_syntax != syntax) {
            m_syntax = syntax;
            syntaxChanged();
        }
    }

    static void registerTypes();

signals:
    void nameChanged();
    void enumvalueChanged();
    void optionsChanged();
    void sourceContextChanged();
    void syntaxChanged();

private:
    SourceContext *sourceContext_p() const;
    void setSourceContext_p(SourceContext *sourceContext);

private:
    QString m_name;
    EnumValueRepeated m_enumvalue;
    OptionRepeated m_options;
    QProtobufLazyMessagePointer<SourceContext> m_sourceContext;
    SyntaxGadget::Syntax m_syntax;
};

using EnumRepeated = QList<QSharedPointer<Enum>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Enum)
Q_DECLARE_METATYPE(google::protobuf::EnumRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Enum>)

namespace google {
namespace protobuf {
namespace EnumValue_QtProtobufNested {
}

class EnumValue : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(EnumValue)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::int32 number_p READ number WRITE setNumber NOTIFY numberChanged SCRIPTABLE false)
    Q_PROPERTY(google::protobuf::OptionRepeated optionsData READ options WRITE setOptions NOTIFY optionsChanged SCRIPTABLE true)
    Q_PROPERTY(int number READ number_p WRITE setNumber_p NOTIFY numberChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Option> options READ options_l NOTIFY optionsChanged)

public:
    EnumValue(QObject *parent = nullptr);
    EnumValue(const QString &name,QObject *parent = nullptr);
    EnumValue(const QString &name,QtProtobuf::int32 number,QObject *parent = nullptr);
    EnumValue(const QString &name,QtProtobuf::int32 number,const OptionRepeated &options,QObject *parent = nullptr);
    virtual ~EnumValue();
    EnumValue(const EnumValue &other);
    EnumValue &operator =(const EnumValue &other);
    EnumValue(EnumValue &&other);
    EnumValue &operator =(EnumValue &&other);
    bool operator ==(const EnumValue &other) const;
    bool operator !=(const EnumValue &other) const;

    QString name() const {
        return m_name;
    }


    const QtProtobuf::int32 number() const {
        return m_number;
    }


    OptionRepeated options() const {
        return m_options;
    }

    OptionRepeated &options() {
        return m_options;
    }

    QQmlListProperty<Option> options_l();
    void setName(const QString &name);
    void setNumber(const QtProtobuf::int32 &number) {
        if (m_number != number) {
            m_number = number;
            numberChanged();
        }
    }

    void setOptions(const OptionRepeated &options);
    static void registerTypes();

signals:
    void nameChanged();
    void numberChanged();
    void optionsChanged();

private:
    int number_p() const {
        return m_number;
    }

    void setNumber_p(const int &number) {
        if (m_number != number) {
            m_number = number;
            numberChanged();
        }
    }


private:
    QString m_name;
    QtProtobuf::int32 m_number;
    OptionRepeated m_options;
};

using EnumValueRepeated = QList<QSharedPointer<EnumValue>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::EnumValue)
Q_DECLARE_METATYPE(google::protobuf::EnumValueRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::EnumValue>)

namespace google {
namespace protobuf {
namespace Option_QtProtobufNested {
}

class Option : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Option)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::Any *value READ value_p WRITE setValue_p NOTIFY valueChanged)

public:
    Option(QObject *parent = nullptr);
    Option(const QString &name,QObject *parent = nullptr);
    Option(const QString &name,const Any &value,QObject *parent = nullptr);
    virtual ~Option();
    Option(const Option &other);
    Option &operator =(const Option &other);
    Option(Option &&other);
    Option &operator =(Option &&other);
    bool operator ==(const Option &other) const;
    bool operator !=(const Option &other) const;

    QString name() const {
        return m_name;
    }


    const Any &value() const;
    void setName(const QString &name);
    void setValue(const Any &value);
    static void registerTypes();

signals:
    void nameChanged();
    void valueChanged();

private:
    Any *value_p() const;
    void setValue_p(Any *value);

private:
    QString m_name;
    QProtobufLazyMessagePointer<Any> m_value;
};

using OptionRepeated = QList<QSharedPointer<Option>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Option)
Q_DECLARE_METATYPE(google::protobuf::OptionRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Option>)