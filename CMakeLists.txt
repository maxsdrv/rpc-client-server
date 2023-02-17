project(TestgRPC)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(cmake/common.cmake)

#Qt libraries
find_package(Qt5 REQUIRED COMPONENTS Quick Core Widgets Network Concurrent)
find_package(QtProtobuf CONFIG REQUIRED COMPONENTS ProtobufGenerator Protobuf Grpc)
file(GLOB PROTO_FILES ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR}/protos/test_rpc.proto)


#[[
# Proto file
get_filename_component(tr_proto "protos/test_rpc.proto" ABSOLUTE)

get_filename_component(tr_proto_path "${tr_proto}" PATH)

get_filename_component(tr_include "/home/maxim/.local/include/google" ABSOLUTE)
get_filename_component(tr_include_path "${tr_include}" PATH)

# Generated sources
set(tr_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.pb.cc" )
set(tr_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.pb.h")
set(tr_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.grpc.pb.cc")
set(tr_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.grpc.pb.h")


add_custom_command(
        OUTPUT "${tr_proto_srcs}" "${tr_proto_hdrs}" "${tr_grpc_srcs}"
        "${tr_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}"
        -I "${tr_include_path}"
        -I "${tr_proto_path}"
        --plugin=protoc-gen-grpc= "${_GRPC_CPP_PLUGIN_EXECUTABLE}"
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

set(others)
list(APPEND other
        profile.h)
set(qt_source)
list(APPEND qt_source
        "ServerMKO.h"
        "ServerMKO.cpp"
        )

# Targets test_rpc(client|server)
add_executable(${PROJECT_NAME} ${other} ${qt_source})

qtprotobuf_generate(TARGET TestgRPC
        PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tutorial.proto
        QML TRUE)


target_link_libraries(${PROJECT_NAME} ${tr_grpc_proto} ${test_rpc_parser}
       ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
        )
]]
add_executable(${PROJECT_NAME} ServerMKO.h ServerMKO.cpp)

target_compile_definitions(${PROJECT_NAME}
        PRIVATE "$<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>")

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Widgets
        Qt5::Network
        Qt5::Concurrent
        ${QT_PROTOBUF_NAMESPACE}::Grpc
        ${QT_PROTOBUF_NAMESPACE}::Protobuf)

if(QT_PROTOBUF_STATIC)
    add_definitions(-DQT_PROTOBUF_STATIC)# add_definitions is used because old cmake versions
    # compatibility
endif()

#[[foreach(_target
        test_client test_server)
        add_executable(${_target}
            "${_target}.cpp" "${other}" "${qt_source}")
        target_link_libraries(${_target}
            tr_grpc_proto
            test_rpc_parser
            ${_REFLECTION}
            ${_GRPC_GRPCPP}
            ${_PROTOBUF_LIBPROTOBUF}
	    Qt6::Core
	    Qt6::Widgets
	    Qt6::Network
	    Qt6::Concurrent)
endforeach()]]


#add_subdirectory("qtprotobuf")





