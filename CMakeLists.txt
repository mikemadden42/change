cmake_minimum_required(VERSION 3.10)

project(change C)

set(CMAKE_C_STANDARD 17)
if (NOT MSVC)
  set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
endif()

set(PROGRAMS
  change
)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})

foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.c)
  add_definitions(${GLIB_CFLAGS_OTHER})
  target_link_libraries(${program} ${GLIB_LIBRARIES})
endforeach(program)
