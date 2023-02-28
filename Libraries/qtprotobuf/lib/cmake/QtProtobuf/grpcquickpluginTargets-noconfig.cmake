#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtProtobuf::grpcquickplugin" for configuration ""
set_property(TARGET QtProtobuf::grpcquickplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(QtProtobuf::grpcquickplugin PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/qml/QtGrpc/libgrpcquickplugin.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS QtProtobuf::grpcquickplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_QtProtobuf::grpcquickplugin "${_IMPORT_PREFIX}/lib/qml/QtGrpc/libgrpcquickplugin.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
