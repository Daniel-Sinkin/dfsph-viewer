# CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

if(APPLE AND NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED CMAKE_CXX_COMPILER)
  foreach(DS_TEMPLATE_LLVM_PREFIX IN ITEMS /opt/homebrew/opt/llvm /usr/local/opt/llvm)
    if(EXISTS "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang" AND EXISTS "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang++")
      set(CMAKE_C_COMPILER "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang" CACHE FILEPATH "C compiler" FORCE)
      set(CMAKE_CXX_COMPILER "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang++" CACHE FILEPATH "C++ compiler" FORCE)
      message(STATUS "Using LLVM toolchain from ${DS_TEMPLATE_LLVM_PREFIX}")
      break()
    endif()
  endforeach()
endif()

project(dfsph_viewer LANGUAGES C CXX)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
  find_library(DFSPH_ZLIB_LIBRARY z REQUIRED)
else()
  find_package(ZLIB REQUIRED)
  set(DFSPH_ZLIB_LIBRARY ZLIB::ZLIB)
endif()

add_subdirectory(external/ds-vk)

add_executable(dfsph_viewer
  app/main.cpp
  src/dfsph_viewer_app.cpp
)

target_include_directories(dfsph_viewer PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_precompile_headers(dfsph_viewer PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp
)

target_compile_definitions(dfsph_viewer PRIVATE
  DS_VK_ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/local/assets"
)

target_link_libraries(dfsph_viewer PRIVATE
  ds_vk
  ds_vk_viz
  ${DFSPH_ZLIB_LIBRARY}
  ds_vk_warnings
)
