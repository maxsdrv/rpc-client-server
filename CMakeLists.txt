cmake_minimum_required(VERSION 3.14)
cmake_policy(VERSION 3.6...3.14)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0071 NEW)

set(QT_PROTOBUF_VERSION 0.6.0)
set(MKO_SERVER_VERSION 0.1.0)

project(MKOServer VERSION ${MKO_SERVER_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Path to link QtProtobuf libraries
set(CMAKE_PREFIX_PATH "/home/maxim/projects-okb44/aik/rpc-client-server/Libraries/")
# Path to link GoogleTest libraries 
#set(CMAKE_PREFIX_PATH "/home/maxim/projects-okb44/aik/rpc-client-server/Libraries/GoogleTest/lib/cmake/")
# Path to link MikroJson libraries 
#set(CMAKE_PREFIX_PATH "/home/maxim/projects-okb44/aik/rpc-client-server/Libraries/MikroJson/lib/cmake/")


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

find_package(WrapProtobuf COMPONENTS Protoc OPTIONAL_COMPONENTS Generator Protobuf REQUIRED)

# Function for compatibility Qt6 and Qt5 https://cmake.org/cmake/help/latest/prop_tgt/AUTOMOC.html
function (add_qt5_server)
    find_package(Qt5 REQUIRED QUIET COMPONENTS Core Quick)
    set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            PROPERTY Qt5Core_VERSION_MAJOR "${Qt5Core_VERSION_MAJOR}")
    set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            PROPERTY Qt5Core_VERSION_MINOR "${Qt5Core_VERSION_MAJOR}")
endfunction()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/common.cmake)

add_qt5_server()

add_subdirectory("Client")
add_subdirectory("Server")












