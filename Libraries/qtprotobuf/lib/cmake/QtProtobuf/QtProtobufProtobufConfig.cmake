include(CMakeFindDependencyMacro)

find_package(${QT_VERSIONED_PREFIX} COMPONENTS Core Qml REQUIRED CONFIG)

set(CMAKE_POSITION_INDEPENDENT_CODE ${${QT_VERSIONED_PREFIX}_POSITION_INDEPENDENT_CODE})

if(NOT TARGET QtProtobuf::Protobuf)
    include("${CMAKE_CURRENT_LIST_DIR}/QtProtobufProtobufTargets.cmake")
endif()

if(QT_PROTOBUF_STATIC AND NOT TARGET QtProtobuf::protobufquickplugin)
    include("${CMAKE_CURRENT_LIST_DIR}/protobufquickpluginTargets.cmake")
endif()


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was QtProtobufConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################
if(QT_PROTOBUF_STATIC)
    add_definitions(-DQT_PROTOBUF_STATIC)# add_definitions is used because old cmake versions
                                         # compatibility
endif()
