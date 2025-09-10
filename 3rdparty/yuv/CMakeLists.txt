set(lib_name yuv)
set(target_name ${lib_name})

project(${lib_name})

#set(${target_name}_src
#)

FILE(GLOB ${target_name}_src *.cc)

add_library(${target_name} STATIC
  ${${target_name}_src}
)

target_include_directories(${target_name} PUBLIC .)
