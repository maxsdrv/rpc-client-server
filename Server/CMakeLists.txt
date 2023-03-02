set(TARGET server_mko_grpc)

include(../cmake/QtProtobufTestHelpers.cmake)

set(GENERATED_SOURCES "${CMAKE_CURRENT_BINARY_DIR}/rpc_mko.pb.cc"
                      "${CMAKE_CURRENT_BINARY_DIR}/rpc_mko.grpc.pb.cc")
set_source_files_properties(${GENERATED_SOURCES} PROPERTIES GENERATED TRUE)

set(PROJECT_SOURCES
        #[[JsonParser.cpp
        JsonParser.h]]
        Server.h
        Server.cpp
        helper.h
        helper.cpp
        profile.h
        main.cpp)

set(RES_PROJ resources.qrc)
add_executable(${TARGET} ${PROJECT_SOURCES} ${GENERATED_SOURCES} ${RES_PROJ})

target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB PROTO_FILES ABSOLUTE "${CMAKE_CURRENT_SOURCE_DIR}/../protos/rpc_mko.proto")
qt_protobuf_internal_protobuf_generate_all(TARGET ${TARGET}
        GENERATED_SOURCES ${GENERATED_SOURCES}
        PROTO_FILES ${PROTO_FILES})

target_link_libraries(${TARGET} PRIVATE
        protobuf::libprotobuf
        gRPC::grpc++
        gRPC::grpc
        Qt5::Core)
