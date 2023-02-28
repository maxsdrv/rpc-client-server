include(CMakeFindDependencyMacro)

set(_save_cmake_module_path "${CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_dependency(WrapProtobuf COMPONENTS Protobuf REQUIRED)
set(CMAKE_MODULE_PATH "${_save_cmake_module_path}")

if(NOT TARGET QtProtobuf::ProtobufWellKnownTypes)
    include("${CMAKE_CURRENT_LIST_DIR}/QtProtobufProtobufWellKnownTypesTargets.cmake")
endif()

# Make possible usage of
# $<TARGET_PROPERTY:${QT_PROTOBUF_NAMESPACE}::ProtobufWellKnownTypes,PROTO_INCLUDES>
# outside the build tree. Expecting that WrapProtobuf sets Protobuf_INCLUDE_DIRS.

string(JOIN " -I" proto_includes ${Protobuf_INCLUDE_DIRS})

set_target_properties(QtProtobuf::ProtobufWellKnownTypes PROPERTIES
    PROTO_INCLUDES "-I${proto_includes}"
)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was QtProtobufWellKnownTypesConfig.cmake.in                            ########

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
