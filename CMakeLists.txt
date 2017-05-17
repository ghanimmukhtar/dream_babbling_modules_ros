cmake_minimum_required(VERSION 2.8.3)
project(dream_babbling_modules)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

find_package(PkgConfig REQUIRED)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES babbling_module
 CATKIN_DEPENDS roscpp std_msgs geometry_msgs
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(supervisor src/supervisor.cpp src/modules_finder.cpp src/modules_defs.c src/modules.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(supervisor  ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(supervisor
  ${catkin_LIBRARIES}
)
