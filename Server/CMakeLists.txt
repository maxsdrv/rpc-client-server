set(TARGET server_mko_grpc)


set(GENERATED_SOURCES "${CMAKE_CURRENT_BINARY_DIR}/rpc_mko.pb.cc"
                      "${CMAKE_CURRENT_BINARY_DIR}/rpc_mko.grpc.pb.cc")
set_source_files_properties(${GENERATED_SOURCES} PROPERTIES GENERATED TRUE)

set(RES_PROJ resources.qrc)

set(PROJECT_SOURCES
        #[[JsonParser.cpp
        JsonParser.h]]
        Server.h
        Server.cpp
        helper.h
        helper.cpp
        profile.h
        main.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB PROTO_FILES ABSOLUTE "${CMAKE_CURRENT_SOURCE_DIR}/../Client/rpc_mko.proto")

add_executable(${TARGET} ${PROJECT_SOURCES} ${GENERATED_SOURCES} ${RES_PROJ})

qt_protobuf_internal_protobuf_generate_all(TARGET ${TARGET}
        GENERATED_SOURCES ${GENERATED_SOURCES}
        PROTO_FILES ${PROTO_FILES})

target_link_libraries(${TARGET} PRIVATE
        ${Qt5Core_LIBRARIES}
        PUBLIC
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

