
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was NekiraECSLibConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

message(NOTICE "NekiraECSLib: 1.0.0")

set(NekiraECSLib_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")
set(NekiraECSLib_LIBRARIES NekiraECSLib::NekiraECSCore)

message(NOTICE "NekiraECSLib_INCLUDE_DIRS: ${NekiraECSLib_INCLUDE_DIRS}")
message(NOTICE "NekiraECSLib_LIBRARIES: ${NekiraECSLib_LIBRARIES}")

# 导入NekiraECSLib的目标cmake配置
include("${CMAKE_CURRENT_LIST_DIR}/NekiraECSLibTargets.cmake")
