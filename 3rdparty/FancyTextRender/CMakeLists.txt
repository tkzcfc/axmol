set(target_name "FancyTextRender")
project(${target_name})

if(WINDOWS)
add_library(${target_name} SHARED IMPORTED GLOBAL)
endif()

if(WINDOWS)
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/${ARCH_ALIAS}/FancyTextToCppBridge.dll"
    IMPORTED_IMPLIB "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/${PLATFORM_NAME}/${ARCH_ALIAS}/FancyTextToCppBridge.lib"
  )
endif()

set_target_properties(${target_name} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
