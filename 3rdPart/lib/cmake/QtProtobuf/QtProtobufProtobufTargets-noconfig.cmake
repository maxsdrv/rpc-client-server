#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtProtobuf::Protobuf" for configuration ""
set_property(TARGET QtProtobuf::Protobuf APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(QtProtobuf::Protobuf PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libQt5Protobuf.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS QtProtobuf::Protobuf )
list(APPEND _IMPORT_CHECK_FILES_FOR_QtProtobuf::Protobuf "${_IMPORT_PREFIX}/lib/libQt5Protobuf.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
