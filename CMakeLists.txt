cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0071 NEW)

project(TestgRPC CXX)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/common.cmake)

# Path to proto files
get_filename_component(server_proto "protos/server.proto" ABSOLUTE)
get_filename_component(server_path "${server_proto}" PATH)

# Generated sources
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/generated")
    message(ERROR "Folder" "${CMAKE_CURRENT_BINARY_DIR}/generated" "is not exist ... but i make it easily")
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)
else()
    message(STATUS "Folder" "${CMAKE_CURRENT_BINARY_DIR}/generated" " exist")
endif()

include_directories("${CMAKE_CURRENT_BINARY_DIR}/generated")

set(server_proto_src "${CMAKE_CURRENT_BINARY_DIR}/generated/server.pb.cc")
set(server_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/generated/server.pb.h")
set(server_grpc_src "${CMAKE_CURRENT_BINARY_DIR}/generated/server.grpc.pb.cc")
set(server_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/generated/server.grpc.pb.h")
add_custom_command(
        OUTPUT "${server_proto_src}" "${server_proto_hdrs}"
               "${server_grpc_src}" "${server_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/generated"
             --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/generated"
             -I "${server_path}"
             --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
             "${server_proto}"
        DEPENDS "${server_proto}"
)

find_package(Qt6 6.2 COMPONENTS Core REQUIRED)

set(PROJECT_SOURCES
        #[[JsonParser.cpp
        JsonParser.h]]
        Server.h
        Server.cpp
        profile.h
        main.cpp)

include_directories(Test/cmake-build-debug/)
# Server proto
add_library(server_grpc_proto
            ${server_proto_src}
            ${server_proto_hdrs}
            ${server_grpc_src}
            ${server_grpc_hdrs})
target_link_libraries(server_grpc_proto
            ${_REFLECTION}
            ${_GRPC_GRPCPP}
            ${_PROTOBUF_LIBPROTOBUF})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME}
        server_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
        Qt6::Core
        )

