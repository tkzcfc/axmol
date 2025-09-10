set(target_name webm)

FILE(GLOB WEBM_HEADER src/*.h)
FILE(GLOB WEBM_SOURCE src/*.cpp)

add_library(${target_name} STATIC
  ${WEBM_HEADER}
  ${WEBM_SOURCE})

target_include_directories(${target_name} PUBLIC src)

setup_ax_extension_config(${target_name})
