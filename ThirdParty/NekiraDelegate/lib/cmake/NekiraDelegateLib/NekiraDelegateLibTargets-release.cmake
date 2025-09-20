#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NekiraDelegateLib::SignalSlot" for configuration "Release"
set_property(TARGET NekiraDelegateLib::SignalSlot APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(NekiraDelegateLib::SignalSlot PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libSignalSlot.a"
  )

list(APPEND _cmake_import_check_targets NekiraDelegateLib::SignalSlot )
list(APPEND _cmake_import_check_files_for_NekiraDelegateLib::SignalSlot "${_IMPORT_PREFIX}/lib/libSignalSlot.a" )

# Import target "NekiraDelegateLib::DelegateCore" for configuration "Release"
set_property(TARGET NekiraDelegateLib::DelegateCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(NekiraDelegateLib::DelegateCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libDelegateCore.a"
  )

list(APPEND _cmake_import_check_targets NekiraDelegateLib::DelegateCore )
list(APPEND _cmake_import_check_files_for_NekiraDelegateLib::DelegateCore "${_IMPORT_PREFIX}/lib/libDelegateCore.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
