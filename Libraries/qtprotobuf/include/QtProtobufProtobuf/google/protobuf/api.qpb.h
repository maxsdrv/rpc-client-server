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
#include "google/protobuf/source_context.qpb.h"
#include "google/protobuf/type.qpb.h"

namespace google {
namespace protobuf {
class Api;
using ApiRepeated = QList<QSharedPointer<Api>>;

}
}


namespace google {
namespace protobuf {
class Method;
using MethodRepeated = QList<QSharedPointer<Method>>;

}
}


namespace google {
namespace protobuf {
class Mixin;
using MixinRepeated = QList<QSharedPointer<Mixin>>;

}
}


namespace google {
namespace protobuf {
namespace Api_QtProtobufNested {
}

class Api : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Api)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::MethodRepeated methodsData READ methods WRITE setMethods NOTIFY methodsChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::OptionRepeated optionsData READ options WRITE setOptions NOTIFY optionsChanged SCRIPTABLE true)
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::SourceContext *sourceContext READ sourceContext_p WRITE setSourceContext_p NOTIFY sourceContextChanged)
    Q_PROPERTY(google::protobuf::MixinRepeated mixinsData READ mixins WRITE setMixins NOTIFY mixinsChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::SyntaxGadget::Syntax syntax READ syntax WRITE setSyntax NOTIFY syntaxChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Method> methods READ methods_l NOTIFY methodsChanged)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Option> options READ options_l NOTIFY optionsChanged)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Mixin> mixins READ mixins_l NOTIFY mixinsChanged)

public:
    Api(QObject *parent = nullptr);
    Api(const QString &name,QObject *parent = nullptr);
    Api(const QString &name,const MethodRepeated &methods,QObject *parent = nullptr);
    Api(const QString &name,const MethodRepeated &methods,const OptionRepeated &options,QObject *parent = nullptr);
    Api(const QString &name,const MethodRepeated &methods,const OptionRepeated &options,const QString &version,QObject *parent = nullptr);
    Api(const QString &name,const MethodRepeated &methods,const OptionRepeated &options,const QString &version,const SourceContext &sourceContext,QObject *parent = nullptr);
    Api(const QString &name,const MethodRepeated &methods,const OptionRepeated &options,const QString &version,const SourceContext &sourceContext,const MixinRepeated &mixins,QObject *parent = nullptr);
    Api(const QString &name,const MethodRepeated &methods,const OptionRepeated &options,const QString &version,const SourceContext &sourceContext,const MixinRepeated &mixins,SyntaxGadget::Syntax syntax,QObject *parent = nullptr);
    virtual ~Api();
    Api(const Api &other);
    Api &operator =(const Api &other);
    Api(Api &&other);
    Api &operator =(Api &&other);
    bool operator ==(const Api &other) const;
    bool operator !=(const Api &other) const;

    QString name() const {
        return m_name;
    }


    MethodRepeated methods() const {
        return m_methods;
    }

    MethodRepeated &methods() {
        return m_methods;
    }

    QQmlListProperty<Method> methods_l();

    OptionRepeated options() const {
        return m_options;
    }

    OptionRepeated &options() {
        return m_options;
    }

    QQmlListProperty<Option> options_l();

    QString version() const {
        return m_version;
    }


    const SourceContext &sourceContext() const;

    MixinRepeated mixins() const {
        return m_mixins;
    }

    MixinRepeated &mixins() {
        return m_mixins;
    }

    QQmlListProperty<Mixin> mixins_l();

    SyntaxGadget::Syntax syntax() const {
        return m_syntax;
    }

    void setName(const QString &name);
    void setMethods(const MethodRepeated &methods);
    void setOptions(const OptionRepeated &options);
    void setVersion(const QString &version);
    void setSourceContext(const SourceContext &sourceContext);
    void setMixins(const MixinRepeated &mixins);
    void setSyntax(const SyntaxGadget::Syntax &syntax) {
        if (m_syntax != syntax) {
            m_syntax = syntax;
            syntaxChanged();
        }
    }

    static void registerTypes();

signals:
    void nameChanged();
    void methodsChanged();
    void optionsChanged();
    void versionChanged();
    void sourceContextChanged();
    void mixinsChanged();
    void syntaxChanged();

private:
    SourceContext *sourceContext_p() const;
    void setSourceContext_p(SourceContext *sourceContext);

private:
    QString m_name;
    MethodRepeated m_methods;
    OptionRepeated m_options;
    QString m_version;
    QProtobufLazyMessagePointer<SourceContext> m_sourceContext;
    MixinRepeated m_mixins;
    SyntaxGadget::Syntax m_syntax;
};

using ApiRepeated = QList<QSharedPointer<Api>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Api)
Q_DECLARE_METATYPE(google::protobuf::ApiRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Api>)

namespace google {
namespace protobuf {
namespace Method_QtProtobufNested {
}

class Method : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Method)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(QString requestTypeUrl READ requestTypeUrl WRITE setRequestTypeUrl NOTIFY requestTypeUrlChanged SCRIPTABLE true)
    Q_PROPERTY(bool requestStreaming READ requestStreaming WRITE setRequestStreaming NOTIFY requestStreamingChanged SCRIPTABLE true)
    Q_PROPERTY(QString responseTypeUrl READ responseTypeUrl WRITE setResponseTypeUrl NOTIFY responseTypeUrlChanged SCRIPTABLE true)
    Q_PROPERTY(bool responseStreaming READ responseStreaming WRITE setResponseStreaming NOTIFY responseStreamingChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::OptionRepeated optionsData READ options WRITE setOptions NOTIFY optionsChanged SCRIPTABLE true)
    Q_PROPERTY(google::protobuf::SyntaxGadget::Syntax syntax READ syntax WRITE setSyntax NOTIFY syntaxChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<google::protobuf::Option> options READ options_l NOTIFY optionsChanged)

public:
    Method(QObject *parent = nullptr);
    Method(const QString &name,QObject *parent = nullptr);
    Method(const QString &name,const QString &requestTypeUrl,QObject *parent = nullptr);
    Method(const QString &name,const QString &requestTypeUrl,bool requestStreaming,QObject *parent = nullptr);
    Method(const QString &name,const QString &requestTypeUrl,bool requestStreaming,const QString &responseTypeUrl,QObject *parent = nullptr);
    Method(const QString &name,const QString &requestTypeUrl,bool requestStreaming,const QString &responseTypeUrl,bool responseStreaming,QObject *parent = nullptr);
    Method(const QString &name,const QString &requestTypeUrl,bool requestStreaming,const QString &responseTypeUrl,bool responseStreaming,const OptionRepeated &options,QObject *parent = nullptr);
    Method(const QString &name,const QString &requestTypeUrl,bool requestStreaming,const QString &responseTypeUrl,bool responseStreaming,const OptionRepeated &options,SyntaxGadget::Syntax syntax,QObject *parent = nullptr);
    virtual ~Method();
    Method(const Method &other);
    Method &operator =(const Method &other);
    Method(Method &&other);
    Method &operator =(Method &&other);
    bool operator ==(const Method &other) const;
    bool operator !=(const Method &other) const;

    QString name() const {
        return m_name;
    }


    QString requestTypeUrl() const {
        return m_requestTypeUrl;
    }


    bool requestStreaming() const {
        return m_requestStreaming;
    }


    QString responseTypeUrl() const {
        return m_responseTypeUrl;
    }


    bool responseStreaming() const {
        return m_responseStreaming;
    }


    OptionRepeated options() const {
        return m_options;
    }

    OptionRepeated &options() {
        return m_options;
    }

    QQmlListProperty<Option> options_l();

    SyntaxGadget::Syntax syntax() const {
        return m_syntax;
    }

    void setName(const QString &name);
    void setRequestTypeUrl(const QString &requestTypeUrl);
    void setRequestStreaming(const bool &requestStreaming) {
        if (m_requestStreaming != requestStreaming) {
            m_requestStreaming = requestStreaming;
            requestStreamingChanged();
        }
    }

    void setResponseTypeUrl(const QString &responseTypeUrl);
    void setResponseStreaming(const bool &responseStreaming) {
        if (m_responseStreaming != responseStreaming) {
            m_responseStreaming = responseStreaming;
            responseStreamingChanged();
        }
    }

    void setOptions(const OptionRepeated &options);
    void setSyntax(const SyntaxGadget::Syntax &syntax) {
        if (m_syntax != syntax) {
            m_syntax = syntax;
            syntaxChanged();
        }
    }

    static void registerTypes();

signals:
    void nameChanged();
    void requestTypeUrlChanged();
    void requestStreamingChanged();
    void responseTypeUrlChanged();
    void responseStreamingChanged();
    void optionsChanged();
    void syntaxChanged();

private:

private:
    QString m_name;
    QString m_requestTypeUrl;
    bool m_requestStreaming;
    QString m_responseTypeUrl;
    bool m_responseStreaming;
    OptionRepeated m_options;
    SyntaxGadget::Syntax m_syntax;
};

using MethodRepeated = QList<QSharedPointer<Method>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Method)
Q_DECLARE_METATYPE(google::protobuf::MethodRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Method>)

namespace google {
namespace protobuf {
namespace Mixin_QtProtobufNested {
}

class Mixin : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Mixin)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged SCRIPTABLE true)
    Q_PROPERTY(QString root READ root WRITE setRoot NOTIFY rootChanged SCRIPTABLE true)

public:
    Mixin(QObject *parent = nullptr);
    Mixin(const QString &name,QObject *parent = nullptr);
    Mixin(const QString &name,const QString &root,QObject *parent = nullptr);
    virtual ~Mixin();
    Mixin(const Mixin &other);
    Mixin &operator =(const Mixin &other);
    Mixin(Mixin &&other);
    Mixin &operator =(Mixin &&other);
    bool operator ==(const Mixin &other) const;
    bool operator !=(const Mixin &other) const;

    QString name() const {
        return m_name;
    }


    QString root() const {
        return m_root;
    }

    void setName(const QString &name);
    void setRoot(const QString &root);
    static void registerTypes();

signals:
    void nameChanged();
    void rootChanged();

private:

private:
    QString m_name;
    QString m_root;
};

using MixinRepeated = QList<QSharedPointer<Mixin>>;

}
}

Q_DECLARE_METATYPE(google::protobuf::Mixin)
Q_DECLARE_METATYPE(google::protobuf::MixinRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<google::protobuf::Mixin>)
