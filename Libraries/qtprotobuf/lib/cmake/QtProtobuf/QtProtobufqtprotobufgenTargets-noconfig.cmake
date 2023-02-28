#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtProtobuf::qtprotobufgen" for configuration ""
set_property(TARGET QtProtobuf::qtprotobufgen APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(QtProtobuf::qtprotobufgen PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/qtprotobufgen"
  )

list(APPEND _IMPORT_CHECK_TARGETS QtProtobuf::qtprotobufgen )
list(APPEND _IMPORT_CHECK_FILES_FOR_QtProtobuf::qtprotobufgen "${_IMPORT_PREFIX}/bin/qtprotobufgen" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
