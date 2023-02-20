include(CMakeFindDependencyMacro)

# We only look for protoc, libprotoc should already be in rpath or linked statically
set(_save_cmake_module_path "${CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
find_package(WrapProtobuf COMPONENTS Generator REQUIRED)
set(CMAKE_MODULE_PATH "${_save_cmake_module_path}")

if(NOT TARGET QtProtobuf::qtprotobufgen)
    include("${CMAKE_CURRENT_LIST_DIR}/QtProtobufqtprotobufgenTargets.cmake")
endif()

set_property(TARGET QtProtobuf::qtprotobufgen
    PROPERTY PROTO_PARSER "${CMAKE_CURRENT_LIST_DIR}/parsemessages.go"
)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was QtqtprotobufgenConfig.cmake.in                            ########

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
include("${CMAKE_CURRENT_LIST_DIR}/QtProtobufGen.cmake")
