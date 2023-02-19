/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#include "test_rpc_grpc.qpb.h"
#include <QQmlEngine>
#include <QJSEngine>
#include <QJSValue>
using namespace QtProtobuf;

namespace qtprotobuf {
namespace testrpc {

EchoServiceClient::EchoServiceClient(QObject *parent) : QAbstractGrpcClient("qtprotobuf.testrpc.EchoService", parent)
{
}

QtProtobuf::QGrpcStatus EchoServiceClient::Echo(const qtprotobuf::testrpc::EchoRequest &arg, const QPointer<qtprotobuf::testrpc::EchoResponse> &ret)
{
    return call("Echo", arg, ret);
}

QtProtobuf::QGrpcCallReplyShared EchoServiceClient::Echo(const qtprotobuf::testrpc::EchoRequest &arg)
{
    return call("Echo", arg);
}

void EchoServiceClient::Echo(const qtprotobuf::testrpc::EchoRequest &arg, const QObject *context, const std::function<void(QGrpcCallReplyShared)> &callback)
{
    QtProtobuf::QGrpcCallReplyShared reply = call("Echo", arg);
    QObject::connect(reply.get(), &QtProtobuf::QGrpcCallReply::finished, context, [reply, callback]() {
        callback(reply);
    });
}

void EchoServiceClient::Echo(qtprotobuf::testrpc::EchoRequest *arg, const QJSValue &callback, const QJSValue &errorCallback)
{
    if (!callback.isCallable()) {
        qProtoWarning() << "Unable to call EchoServiceClient::Echo, callback is not callable";
        return;
    }

    if (arg == nullptr) {
        qProtoWarning() << "Invalid argument provided for method EchoServiceClient::Echo, argument of type 'qtprotobuf::testrpc::EchoRequest *' expected";
        return;
    }

    QJSEngine *jsEngine = qjsEngine(this);
    if (jsEngine == nullptr) {
        qProtoWarning() << "Unable to call EchoServiceClient::Echo, it's only callable from JS engine context";
        return;
    }

    QtProtobuf::QGrpcCallReplyShared reply = call("Echo", *arg);
    reply->subscribe(jsEngine, [this, reply, callback, jsEngine]() {
        auto result = new qtprotobuf::testrpc::EchoResponse(reply->read<qtprotobuf::testrpc::EchoResponse>());
        qmlEngine(this)->setObjectOwnership(result, QQmlEngine::JavaScriptOwnership);
        QJSValue(callback).call(QJSValueList{jsEngine->toScriptValue(result)});
    }, [errorCallback, jsEngine](const QGrpcStatus &status) {
        QJSValue(errorCallback).call(QJSValueList{jsEngine->toScriptValue(status)});
    });
}

void EchoServiceClient::Echo(qtprotobuf::testrpc::EchoRequest *arg, qtprotobuf::testrpc::EchoResponse *ret, const QJSValue &errorCallback)
{
    if (ret == nullptr) {
        qProtoWarning() << "Invalid argument provided for method EchoServiceClient::Echo, argument of type 'qtprotobuf::testrpc::EchoResponse *' expected";
        return;
    }

    QPointer<qtprotobuf::testrpc::EchoResponse> safeReturn(ret);

    if (arg == nullptr) {
        qProtoWarning() << "Invalid argument provided for method EchoServiceClient::Echo, argument of type 'qtprotobuf::testrpc::EchoRequest *' expected";
        return;
    }

    QJSEngine *jsEngine = qjsEngine(this);
    if (jsEngine == nullptr) {
        qProtoWarning() << "Unable to call EchoServiceClient::Echo, it's only callable from JS engine context";
        return;
    }

    QtProtobuf::QGrpcCallReplyShared reply = call("Echo", *arg);
    reply->subscribe(jsEngine, [this, reply, jsEngine, safeReturn]() {
        if (safeReturn.isNull()) {
            qProtoWarning() << "Return value is destroyed. Ignore call result";
            return;
        }
        *safeReturn = qtprotobuf::testrpc::EchoResponse(reply->read<qtprotobuf::testrpc::EchoResponse>());
    }, [errorCallback, jsEngine](const QGrpcStatus &status) {
        QJSValue(errorCallback).call(QJSValueList{jsEngine->toScriptValue(status)});
    });
}

}
}
