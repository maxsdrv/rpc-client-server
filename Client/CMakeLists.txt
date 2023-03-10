set(TARGET client_mko_grpc )


qt_protobuf_internal_find_dependencies()


set(PROJECT_SOURCES
        ClientMKO.h
        ClientMKO.cpp
        main.cpp
#        qml.qrc
        )
link_directories(../Libraries/examples_common/)

qt_protobuf_internal_add_example(TARGET ${TARGET}
        PROTO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/rpc_mko.proto"
        SOURCES main.cpp
                ClientMKO.cpp
        RESOURCES qml.qrc
        QML_DIR ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET} PRIVATE examples_common
        PUBLIC
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

#[[
add_executable(${TARGET}
        ${PROJECT_SOURCES}
        )
]]


# Generate Protobuf files
#[[
qtprotobuf_generate(TARGET ${TARGET}
        QML TRUE
        OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
        PROTO_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/rpc_mko.proto"
        )
]]

# For Qml requirements
#[[target_compile_definitions(${TARGET}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)]]


# Link libraries
#[[
target_link_libraries(${TARGET}
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
        ${QT_PROTOBUF_NAMESPACE}::Grpc
        ${QT_PROTOBUF_NAMESPACE}::Protobuf
        )
]]

