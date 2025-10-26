

# 设置变量
set(NekiraReflection_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")
set(NekiraReflection_LIBRARIES 
    NekiraReflectionLib::NekiraReflectStatic
    NekiraReflectionLib::NekiraReflectDynamic
)



message(NOTICE "NekiraReflection_INCLUDE_DIRS: ${NekiraReflection_INCLUDE_DIRS}")
message(NOTICE "NekiraReflection_LIBRARIES: ${NekiraReflection_LIBRARIES}")


