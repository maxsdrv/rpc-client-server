set(TARGET client_mko_grpc )


qt_protobuf_internal_find_dependencies()

find_package(Qt5 REQUIRED COMPONENTS Concurrent)


set(PROJECT_SOURCES
        ClientMKO.h
        OperatorsListModelBase.h
        OperatorsListModel.h
        )
set(PROJ_CPP 
        ClientMKO.cpp
        OperatorsListModelBase.cpp 
        OperatorsListModel.cpp
        )

link_directories(../Libraries/examples_common/)

qt_protobuf_internal_add_example(TARGET ${TARGET}
        PROTO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/rpc_mko.proto"
        SOURCES main.cpp ${PROJ_CPP}
        RESOURCES qml.qrc
        QML_DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${TARGET} PRIVATE examples_common
        Qt5::Concurrent
        PUBLIC
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})



# Link libraries

# target_link_libraries(${TARGET}
#   PRIVATE
#   Qt${QT_VERSION_MAJOR}::Core
#   Qt${QT_VERSION_MAJOR}::Quick
#         ${QT_PROTOBUF_NAMESPACE}::Grpc
#         ${QT_PROTOBUF_NAMESPACE}::Protobuf
#         )


