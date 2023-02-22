cmake_minimum_required(VERSION 3.14)

project(Test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path with QtProtobuf libraries
set(CMAKE_PREFIX_PATH "/home/maxim/projects-okb44/aik/rpc-client-server/3rdPart/lib/cmake")

# Function for compatibility Qt6 and Qt5 https://cmake.org/cmake/help/latest/prop_tgt/AUTOMOC.html
function (add_qt5_server)
    find_package(Qt5 REQUIRED QUIET COMPONENTS Core Quick)
    set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        PROPERTY Qt5Core_VERSION_MAJOR "${Qt5Core_VERSION_MAJOR}")
    set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            PROPERTY Qt5Core_VERSION_MINOR "${Qt5Core_VERSION_MAJOR}")
endfunction()

# QtProtobuf settings https://github.com/semlanik/qtprotobuf/blob/0.6/examples/clienttutorial/CMakeLists.txt
set(CMAKE_POSITION_INDEPENDENT_CODE ${Qt5_POSITION_INDEPENDENT_CODE})
set(QT_PROTOBUF_NAMESPACE QtProtobuf)
if(NOT TARGET ${QT_PROTOBUF_NAMESPACE}::qtprotobufgen)
    find_package(${QT_PROTOBUF_NAMESPACE} COMPONENTS ProtobufGenerator CONFIG REQUIRED)
endif()
if(NOT TARGET ${QT_PROTOBUF_NAMESPACE}::Protobuf)
    find_package(${QT_PROTOBUF_NAMESPACE} COMPONENTS Protobuf CONFIG REQUIRED)
endif()
if(NOT TARGET ${QT_PROTOBUF_NAMESPACE}::Grpc)
    find_package(${QT_PROTOBUF_NAMESPACE} COMPONENTS Grpc CONFIG REQUIRED)
endif()

set(PROJECT_SOURCES
        ClientMKO.h
        ClientMKO.cpp
        main.cpp
        qml.qrc
)

add_executable(Test
  ${PROJECT_SOURCES}
)
# Generate Protobuf files
qtprotobuf_generate(TARGET Test ${CMAKE_CURRENT_BINARY_DIR} PROTO_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/test_rpc.proto"
        QML TRUE)


# For Qml requirements
target_compile_definitions(Test
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

# Call compatibility function
add_qt5_server()

# Link libraries
target_link_libraries(Test
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Quick
        ${QT_PROTOBUF_NAMESPACE}::Grpc
        ${QT_PROTOBUF_NAMESPACE}::Protobuf
        )


