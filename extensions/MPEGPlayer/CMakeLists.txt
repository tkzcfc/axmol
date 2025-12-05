set(target_name MPEGPlayer)

FILE(GLOB EMPEGPLAYER_HEADER src/*.h)
FILE(GLOB EMPEGPLAYER_SOURCE src/*.cpp)

add_library(${target_name} STATIC
  ${EMPEGPLAYER_HEADER}
  ${EMPEGPLAYER_SOURCE})

target_include_directories(${target_name} PUBLIC src)

ax_find_shaders(${CMAKE_CURRENT_LIST_DIR}/shaders IMGUI_SHADER_SOURCES)
ax_target_compile_shaders(${target_name} FILES ${IMGUI_SHADER_SOURCES} CUSTOM)

setup_ax_extension_config(${target_name})
