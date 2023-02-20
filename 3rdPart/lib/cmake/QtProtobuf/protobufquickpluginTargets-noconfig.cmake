#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "QtProtobuf::protobufquickplugin" for configuration ""
set_property(TARGET QtProtobuf::protobufquickplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(QtProtobuf::protobufquickplugin PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/qml/QtProtobuf/libprotobufquickplugin.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS QtProtobuf::protobufquickplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_QtProtobuf::protobufquickplugin "${_IMPORT_PREFIX}/lib/qml/QtProtobuf/libprotobufquickplugin.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
