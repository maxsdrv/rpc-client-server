#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtProtobuf::ProtobufWellKnownTypes" for configuration ""
set_property(TARGET QtProtobuf::ProtobufWellKnownTypes APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(QtProtobuf::ProtobufWellKnownTypes PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libQt5ProtobufWellKnownTypes.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS QtProtobuf::ProtobufWellKnownTypes )
list(APPEND _IMPORT_CHECK_FILES_FOR_QtProtobuf::ProtobufWellKnownTypes "${_IMPORT_PREFIX}/lib/libQt5ProtobufWellKnownTypes.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
