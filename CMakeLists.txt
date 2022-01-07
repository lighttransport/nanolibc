cmake_minimum_required(VERSION 3.5)

set(BUILD_TARGET "nanolibc")
set(TEST_TARGET "test_nanolibc")

project(${BUILD_TARGET} C)

# C11 by default.
set(CMAKE_C_STANDARD 11)

list(APPEND LIBC_SOURCES
  ${CMAKE_SOURCE_DIR}/src/nanoassert.c
  ${CMAKE_SOURCE_DIR}/src/nanostdio.c
  ${CMAKE_SOURCE_DIR}/src/nanothreads.c
)

add_library(${BUILD_TARGET} ${LIBC_SOURCES})

target_include_directories(${BUILD_TARGET} PRIVATE
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/include)

#add_executable(${TEST_TARGET} ${CMAKE_SOURCE_DIR}/test/main.cc)
#target_link_libraries(${TEST_TARGET} ${BUILD_TARGET})

#target_include_directories(${TEST_TARGET} PRIVATE
#	${CMAKE_SOURCE_DIR}/src
#	${CMAKE_SOURCE_DIR}/include)


# [VisualStudio]
if (WIN32)
  # Set target as a startup project for VS IDE
  set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${BUILD_TARGET})

  # # For easier debugging in VS IDE(cmake 3.8.0 or later required)
  # # Set working directory to $gltf-insight git repo root.
  # if (CMAKE_VERSION VERSION_GREATER 3.8.0)
  #       set_target_properties(${BUILD_TARGET} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
  # endif()
endif ()
