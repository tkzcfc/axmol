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
else()
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/libvpx.a"
  )
endif()

set_target_properties(${target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
