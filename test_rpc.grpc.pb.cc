// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test_rpc.proto

#include "test_rpc.pb.h"
#include "test_rpc.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace testrpc {

static const char* TestgRPC_method_names[] = {
  "/testrpc.TestgRPC/get_result",
  "/testrpc.TestgRPC/record_result",
  "/testrpc.TestgRPC/result_chat",
};

std::unique_ptr< TestgRPC::Stub> TestgRPC::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< TestgRPC::Stub> stub(new TestgRPC::Stub(channel, options));
  return stub;
}

TestgRPC::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_get_result_(TestgRPC_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_record_result_(TestgRPC_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_result_chat_(TestgRPC_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::Status TestgRPC::Stub::get_result(::grpc::ClientContext* context, const ::testrpc::Variables& request, ::testrpc::Operator* response) {
  return ::grpc::internal::BlockingUnaryCall< ::testrpc::Variables, ::testrpc::Operator, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_get_result_, context, request, response);
}

void TestgRPC::Stub::async::get_result(::grpc::ClientContext* context, const ::testrpc::Variables* request, ::testrpc::Operator* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::testrpc::Variables, ::testrpc::Operator, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_get_result_, context, request, response, std::move(f));
}

void TestgRPC::Stub::async::get_result(::grpc::ClientContext* context, const ::testrpc::Variables* request, ::testrpc::Operator* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_get_result_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::testrpc::Operator>* TestgRPC::Stub::PrepareAsyncget_resultRaw(::grpc::ClientContext* context, const ::testrpc::Variables& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::testrpc::Operator, ::testrpc::Variables, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_get_result_, context, request);
}

::grpc::ClientAsyncResponseReader< ::testrpc::Operator>* TestgRPC::Stub::Asyncget_resultRaw(::grpc::ClientContext* context, const ::testrpc::Variables& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncget_resultRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientWriter< ::testrpc::Variables>* TestgRPC::Stub::record_resultRaw(::grpc::ClientContext* context, ::testrpc::OperatorsSummary* response) {
  return ::grpc::internal::ClientWriterFactory< ::testrpc::Variables>::Create(channel_.get(), rpcmethod_record_result_, context, response);
}

void TestgRPC::Stub::async::record_result(::grpc::ClientContext* context, ::testrpc::OperatorsSummary* response, ::grpc::ClientWriteReactor< ::testrpc::Variables>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::testrpc::Variables>::Create(stub_->channel_.get(), stub_->rpcmethod_record_result_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::testrpc::Variables>* TestgRPC::Stub::Asyncrecord_resultRaw(::grpc::ClientContext* context, ::testrpc::OperatorsSummary* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::testrpc::Variables>::Create(channel_.get(), cq, rpcmethod_record_result_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::testrpc::Variables>* TestgRPC::Stub::PrepareAsyncrecord_resultRaw(::grpc::ClientContext* context, ::testrpc::OperatorsSummary* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::testrpc::Variables>::Create(channel_.get(), cq, rpcmethod_record_result_, context, response, false, nullptr);
}

::grpc::ClientReaderWriter< ::testrpc::SummNote, ::testrpc::SummNote>* TestgRPC::Stub::result_chatRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::testrpc::SummNote, ::testrpc::SummNote>::Create(channel_.get(), rpcmethod_result_chat_, context);
}

void TestgRPC::Stub::async::result_chat(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::testrpc::SummNote,::testrpc::SummNote>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::testrpc::SummNote,::testrpc::SummNote>::Create(stub_->channel_.get(), stub_->rpcmethod_result_chat_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::testrpc::SummNote, ::testrpc::SummNote>* TestgRPC::Stub::Asyncresult_chatRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::testrpc::SummNote, ::testrpc::SummNote>::Create(channel_.get(), cq, rpcmethod_result_chat_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::testrpc::SummNote, ::testrpc::SummNote>* TestgRPC::Stub::PrepareAsyncresult_chatRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::testrpc::SummNote, ::testrpc::SummNote>::Create(channel_.get(), cq, rpcmethod_result_chat_, context, false, nullptr);
}

TestgRPC::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestgRPC_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< TestgRPC::Service, ::testrpc::Variables, ::testrpc::Operator, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](TestgRPC::Service* service,
             ::grpc::ServerContext* ctx,
             const ::testrpc::Variables* req,
             ::testrpc::Operator* resp) {
               return service->get_result(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestgRPC_method_names[1],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< TestgRPC::Service, ::testrpc::Variables, ::testrpc::OperatorsSummary>(
          [](TestgRPC::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::testrpc::Variables>* reader,
             ::testrpc::OperatorsSummary* resp) {
               return service->record_result(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TestgRPC_method_names[2],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< TestgRPC::Service, ::testrpc::SummNote, ::testrpc::SummNote>(
          [](TestgRPC::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::testrpc::SummNote,
             ::testrpc::SummNote>* stream) {
               return service->result_chat(ctx, stream);
             }, this)));
}

TestgRPC::Service::~Service() {
}

::grpc::Status TestgRPC::Service::get_result(::grpc::ServerContext* context, const ::testrpc::Variables* request, ::testrpc::Operator* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestgRPC::Service::record_result(::grpc::ServerContext* context, ::grpc::ServerReader< ::testrpc::Variables>* reader, ::testrpc::OperatorsSummary* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TestgRPC::Service::result_chat(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::testrpc::SummNote, ::testrpc::SummNote>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace testrpc

