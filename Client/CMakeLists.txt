set(TARGET client_mko_grpc )

set(PROJECT_SOURCES
        ClientMKO.h
        ClientMKO.cpp
        main.cpp
        qml.qrc
)


add_executable(${TARGET}
        ${PROJECT_SOURCES}
        )


# Generate Protobuf files
qtprotobuf_generate(TARGET ${TARGET}
        QML TRUE
        OUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
        PROTO_FILES
        "../protos/rpc_mko.proto"
        )

# For Qml requirements
target_compile_definitions(${TARGET}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)


# Link libraries
target_link_libraries(${TARGET}
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
        ${QT_PROTOBUF_NAMESPACE}::Grpc
        ${QT_PROTOBUF_NAMESPACE}::Protobuf
        )


