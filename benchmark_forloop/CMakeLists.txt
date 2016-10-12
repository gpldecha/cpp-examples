cmake_minimum_required(VERSION 2.8.11)

project(benchmark)

message(STATUS "")
message(STATUS "Configuring benchmark of multivarite array")
message(STATUS "")

project(benchmark)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
endif()


message(STATUS "CMAKE_SYSTEM_NAME          = ${CMAKE_SYSTEM_NAME}"         )
message(STATUS "CMAKE_CXX_COMPILER_ID      = ${CMAKE_CXX_COMPILER_ID}"     )
message(STATUS "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CMAKE_COMPILER_IS_GNUCXX   = ${CMAKE_COMPILER_IS_GNUCXX}"  )
message(STATUS "CMAKE_CXX_COMPILER         = ${CMAKE_CXX_COMPILER}"        )

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2 -O3 -Ofast -march=native -std=c++0x -mtune=native -fPIC -Wall ")        ## Optimize
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "")
message(STATUS "CMAKE_CXX_FLAGS= " ${CMAKE_CXX_FLAGS}   )
message(STATUS "")

set(PATH_CPU_M ${CMAKE_CURRENT_SOURCE_DIR}/../MeasureCPU)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PATH_MRFF}/include)
include_directories(${PATH_CPU_M})

set(HEADER_FILES ${HEADER_DIR}/BenchMark.h
                 ${HEADER_DIR}/ForLoopTraversal.h
                 ${HEADER_DIR}/save.h
                 ${HEADER_DIR}/tlimits.h
)

add_executable(benchmarking src/main.cpp ${HEADER_FILES})

target_link_libraries(benchmarking ${Boost_LIBRARIES} boost_system)

