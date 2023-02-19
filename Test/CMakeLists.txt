cmake_minimum_required(VERSION 3.14)

project(Test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt6  COMPONENTS REQUIRED Quick)
find_package(QtProtobuf CONFIG REQUIRED COMPONENTS ProtobufGenerator Protobuf Grpc)

set(PROJECT_SOURCES
        ServerMKO.h
        ServerMKO.cpp
        main.cpp
        qml.qrc
)
add_executable(Test
  ${PROJECT_SOURCES}
)

qtprotobuf_generate(TARGET Test
                     PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.proto QML TRUE)

target_compile_definitions(Test
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Test
  PRIVATE
  Qt5::Core
  Qt6::Quick
  QtProtobuf::Protobuf
  QtProtobuf::Grpc)

set_target_properties(Test PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

