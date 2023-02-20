#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtProtobuf::Grpc" for configuration ""
set_property(TARGET QtProtobuf::Grpc APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(QtProtobuf::Grpc PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libQt5Grpc.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS QtProtobuf::Grpc )
list(APPEND _IMPORT_CHECK_FILES_FOR_QtProtobuf::Grpc "${_IMPORT_PREFIX}/lib/libQt5Grpc.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
