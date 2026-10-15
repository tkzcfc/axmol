set(target_name "vpx")
project(${target_name})

add_library(${target_name} STATIC IMPORTED GLOBAL)

if(WINDOWS)
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/${ARCH_ALIAS}/libvpx.lib"
  )
elseif(ANDROID)
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/${ARCH_ALIAS}/libvpx.a"
  )
elseif(LINUX)
  # Linux has no ARCH_ALIAS; pick the prebuilt by target processor.
  string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" _vpx_proc)
  if(_vpx_proc MATCHES "^(aarch64|arm64)$")
    set(_vpx_arch "arm64")
  elseif(_vpx_proc MATCHES "^(x86_64|amd64|x64)$")
    set(_vpx_arch "x64")
  else()
    message(FATAL_ERROR "vpx: no Linux prebuilt for processor '${CMAKE_SYSTEM_PROCESSOR}'")
  endif()
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/${_vpx_arch}/libvpx.a"
  )
else()
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/libvpx.a"
  )
endif()

set_target_properties(${target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
