#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "microjson" for configuration ""
set_property(TARGET microjson APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(microjson PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmicrojson.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS microjson )
list(APPEND _IMPORT_CHECK_FILES_FOR_microjson "${_IMPORT_PREFIX}/lib/libmicrojson.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
