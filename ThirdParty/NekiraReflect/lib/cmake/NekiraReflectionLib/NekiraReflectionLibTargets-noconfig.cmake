#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NekiraReflectionLib::NekiraReflectDynamic" for configuration ""
set_property(TARGET NekiraReflectionLib::NekiraReflectDynamic APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(NekiraReflectionLib::NekiraReflectDynamic PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libNekiraReflectDynamic.dll.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libNekiraReflectDynamic.dll"
  )

list(APPEND _cmake_import_check_targets NekiraReflectionLib::NekiraReflectDynamic )
list(APPEND _cmake_import_check_files_for_NekiraReflectionLib::NekiraReflectDynamic "${_IMPORT_PREFIX}/lib/libNekiraReflectDynamic.dll.a" "${_IMPORT_PREFIX}/bin/libNekiraReflectDynamic.dll" )

# Import target "NekiraReflectionLib::NekiraReflectGen" for configuration ""
set_property(TARGET NekiraReflectionLib::NekiraReflectGen APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(NekiraReflectionLib::NekiraReflectGen PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libNekiraReflectGen.a"
  )

list(APPEND _cmake_import_check_targets NekiraReflectionLib::NekiraReflectGen )
list(APPEND _cmake_import_check_files_for_NekiraReflectionLib::NekiraReflectGen "${_IMPORT_PREFIX}/lib/libNekiraReflectGen.a" )

# Import target "NekiraReflectionLib::NekiraReflectTool" for configuration ""
set_property(TARGET NekiraReflectionLib::NekiraReflectTool APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(NekiraReflectionLib::NekiraReflectTool PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/NekiraReflectTool.exe"
  )

list(APPEND _cmake_import_check_targets NekiraReflectionLib::NekiraReflectTool )
list(APPEND _cmake_import_check_files_for_NekiraReflectionLib::NekiraReflectTool "${_IMPORT_PREFIX}/bin/NekiraReflectTool.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
