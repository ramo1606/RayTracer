#---------------------------------------------------------------------------------------------------
# CMake Build Configuration for the RayTracer
#---------------------------------------------------------------------------------------------------

cmake_minimum_required ( VERSION 3.1.0 )

project ( rtftgu
  VERSION 1.0.0
  DESCRIPTION "Ray Tracing From the Ground Up"
  LANGUAGES CXX
)

if (MSVC)
  set(CMAKE_CXX_FLAGS "/EHsc /std:c++17")
  set(CMAKE_CXX_FLAGS_DEBUG "/Od")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else ()
  set(CMAKE_CXX_FLAGS "-std=c++17")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
  set(CMAKE_CXX_FLAGS_RELEASE "-O2")
endif ()

# Source
set (SOURCE_BRDFS
  
)

set ( SOURCE_CAMERAS
  #src/Cameras/camera.h
  #src/Cameras/camera.cpp
)

set (SOURCE_GEOMETRICOBJECTS
  src/GeometricObjects/geometric_object.h
  src/GeometricObjects/geometric_object.cpp
  src/GeometricObjects/sphere.h
  src/GeometricObjects/sphere.cpp  
)

set (SOURCE_LIGHTS
  
)

set (SOURCE_MATERIALS
  
)

set (SOURCE_SAMPLERS
  
)

set (SOURCE_TEXTURES
  
)

set ( SOURCE_TRACERS
  src/Tracers/single_sphere.h
  src/Tracers/single_sphere.cpp
  src/Tracers/tracer.h
  src/Tracers/tracer.cpp
)

set ( SOURCE_UTILITIES
  src/Utilities/constants.h
  src/Utilities/maths.h
  src/Utilities/color.h
  src/Utilities/color.cpp
  src/Utilities/matrix.h
  src/Utilities/matrix.cpp
  src/Utilities/normal.h
  src/Utilities/normal.cpp
  src/Utilities/shade_rec.h
  src/Utilities/shade_rec.cpp
  src/Utilities/ray.h
  src/Utilities/ray.cpp
  src/Utilities/vector3.h
  src/Utilities/vector3.cpp
  src/Utilities/point3.h
  src/Utilities/point3.cpp
)

set ( SOURCE_WORLD
  src/World/view_plane.h
  src/World/view_plane.cpp
  src/World/world.h
  src/World/world.cpp  
  src/World/build_function.cpp
)

# Executables
source_group ("src/BRDFs" FILES ${SOURCE_BRDFS})
source_group ("src/Cameras" FILES ${SOURCE_CAMERAS})
source_group ("src/GeometricObjects" FILES ${SOURCE_GEOMETRICOBJECTS})
source_group ("src/Lights" FILES ${SOURCE_LIGHTS})
source_group ("src/Materials" FILES ${SOURCE_MATERIALS})
source_group ("src/Samplers" FILES ${SOURCE_SAMPLERS})
source_group ("src/Textures" FILES ${SOURCE_TEXTURES})
source_group ("src/Tracers" FILES ${SOURCE_TRACERS})
source_group ("src/Utilities" FILES ${SOURCE_UTILITIES})
source_group ("src/World" FILES ${SOURCE_WORLD})

add_library (libRTF STATIC
  ${SOURCE_BRDFS}
  ${SOURCE_CAMERAS}
  ${SOURCE_GEOMETRICOBJECTS}
  ${SOURCE_LIGHTS}
  ${SOURCE_MATERIALS}
  ${SOURCE_SAMPLERS}
  ${SOURCE_TEXTURES}
  ${SOURCE_TRACERS}
  ${SOURCE_UTILITIES}
  ${SOURCE_WORLD}
)

add_executable (RayTracer main.cpp)

target_link_libraries (RayTracer libRTF)

include_directories(src/BRDFs)
include_directories(src/Cameras)
include_directories(src/GeometricObjects)
include_directories(src/Lights)
include_directories(src/Materials)
include_directories(src/Samplers)
include_directories(src/Textures)
include_directories(src/Tracers)
include_directories(src/Utilities)
include_directories(src/World)

# Unit Test Setup

#set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#enable_testing ()

#add_subdirectory (third_party/googletest-release-1.10.0)

#add_subdirectory (test)