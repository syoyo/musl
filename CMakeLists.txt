cmake_minimum_required(VERSION 3.5)

set(BUILD_TARGET "musl")

#set(BUILD_VERSION_MAJOR 0)
#set(BUILD_VERSION_MINOR 1)
#set(BUILD_VERSION_PATCH 0)

project(${BUILD_TARGET})

list(APPEND LIBC_SOURCES
  ${CMAKE_SOURCE_DIR}/src/stdlib/abs.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/atof.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/atoi.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/atol.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/atoll.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/bsearch.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/div.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/ecvt.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/fcvt.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/gcvt.c
  #${CMAKE_SOURCE_DIR}/src/stdlib/imaxabs.c
  #${CMAKE_SOURCE_DIR}/src/stdlib/imaxdiv.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/labs.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/ldiv.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/llabs.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/lldiv.c
  ${CMAKE_SOURCE_DIR}/src/stdlib/qsort.c
  #${CMAKE_SOURCE_DIR}/src/stdlib/strtod.c
  #${CMAKE_SOURCE_DIR}/src/stdlib/strtol.c
  #${CMAKE_SOURCE_DIR}/src/stdlib/wcstod.c
  #${CMAKE_SOURCE_DIR}/src/stdlib/wcstol.c
)

add_library(${BUILD_TARGET} ${LIBC_SOURCES})

target_include_directories(${BUILD_TARGET} PRIVATE
	# TODO(syoyo): Support 32bit
	${CMAKE_SOURCE_DIR}/arch/msvc-x86_64
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/src/include
	${CMAKE_SOURCE_DIR}/src/internal)

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
