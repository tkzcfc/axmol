cmake_minimum_required(VERSION 3.6)

set(lib_name lua-protobuf)
set(target_name ${lib_name})

project(${lib_name})

set(${target_name}_src
  pb.c
)

add_library(${target_name} STATIC
  ${${target_name}_src}
)

if(NOT AX_USE_LUAJIT)
  target_include_directories(${target_name} PRIVATE ../lua/${AX_LUA_ENGINE})
else()
  target_include_directories(${target_name} PRIVATE ../lua/${AX_LUA_ENGINE}/include)
endif()
target_include_directories(${target_name} PUBLIC .)
