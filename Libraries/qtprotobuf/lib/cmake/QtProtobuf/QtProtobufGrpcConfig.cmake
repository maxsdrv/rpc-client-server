include(CMakeFindDependencyMacro)

find_dependency(${QT_VERSIONED_PREFIX} COMPONENTS Network REQUIRED CONFIG)

set(QT_PROTOBUF_NATIVE_GRPC_CHANNEL OFF)
if(QT_PROTOBUF_NATIVE_GRPC_CHANNEL)
    find_dependency(Threads)
    find_dependency(gRPC)
endif()

if(NOT TARGET QtProtobuf::Grpc)
    include("${CMAKE_CURRENT_LIST_DIR}/QtProtobufGrpcTargets.cmake")
endif()

if(QT_PROTOBUF_STATIC AND NOT TARGET QtProtobuf::grpcquickplugin)
    include("${CMAKE_CURRENT_LIST_DIR}/grpcquickpluginTargets.cmake")
endif()


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was QtGrpcConfig.cmake.in                            ########

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
