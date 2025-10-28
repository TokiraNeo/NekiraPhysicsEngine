
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was NekiraReflectionLibConfig.cmake.in                            ########

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

message(NOTICE "NekiraReflectionLib: 1.0.2")

# 包含导出的NekiraReflection、NekiraReflectTool目标配置

# 这里确保先导入NekiraReflection，以获得NekiraReflection的include路径信息
include("${CMAKE_CURRENT_LIST_DIR}/NekiraReflectionConfig.cmake")

include("${CMAKE_CURRENT_LIST_DIR}/NekiraReflectToolConfig.cmake")

# 包含导出的NekiraReflectLib目标详细信息
include("${CMAKE_CURRENT_LIST_DIR}/NekiraReflectionLibTargets.cmake")

