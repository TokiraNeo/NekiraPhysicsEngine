#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "NekiraECSLib::NekiraECSCore" for configuration "Release"
set_property(TARGET NekiraECSLib::NekiraECSCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(NekiraECSLib::NekiraECSCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libNekiraECSCore.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libNekiraECSCore.dll"
  )

list(APPEND _cmake_import_check_targets NekiraECSLib::NekiraECSCore )
list(APPEND _cmake_import_check_files_for_NekiraECSLib::NekiraECSCore "${_IMPORT_PREFIX}/lib/libNekiraECSCore.dll.a" "${_IMPORT_PREFIX}/bin/libNekiraECSCore.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
