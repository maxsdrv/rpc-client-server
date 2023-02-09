project(TestgRPC)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/common.cmake)

# Proto file
get_filename_component(tr_proto "protos/test_rpc.proto" ABSOLUTE)

get_filename_component(tr_proto_path "${tr_proto}" PATH)

# Generated sources
set(tr_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.pb.cc")
set(tr_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.pb.h")
set(tr_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.grpc.pb.cc")
set(tr_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.grpc.pb.h")
add_custom_command(
    OUTPUT "${tr_proto_srcs}" "${tr_proto_hdrs}" "${tr_grpc_srcs}"
    "${tr_grpc_hdrs}"
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}"
    --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}"
    -I "${tr_proto_path}"
    --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
    "${tr_proto}"
    DEPENDS "${tr_proto}"
    )

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# tr_grpc_proto
add_library(tr_grpc_proto
    ${tr_grpc_srcs}
    ${tr_grpc_hdrs}
    ${tr_proto_srcs}
    ${tr_proto_hdrs})
target_link_libraries(tr_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

# test_rpc json parser
add_library(test_rpc_parser
        "JsonParser.h"
        "JsonParser.cpp")
target_link_libraries(test_rpc_parser
    tr_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})

# Targets test_rpc(client|server)
foreach(_target
        test_client test_server)
        add_executable(${_target}
            "${_target}.cpp" )
        target_link_libraries(${_target}
            tr_grpc_proto
            test_rpc_parser
            ${_REFLECTION}
            ${_GRPC_GRPCPP}
            ${_PROTOBUF_LIBPROTOBUF})
endforeach()









