# Minimum version for cmake compatiblity
cmake_minimum_required(VERSION 3.25)
include(CMakePrintHelpers)
include(FetchContent)

# show limited messages while cloning git repos
set(FETCHCONTENT_QUIET ON)

cmake_print_variables(GITHUB_BRANCH_TOOLCHAIN)
FetchContent_Declare(
    cmake-toolchains                             # Recommendation: Stick close to the original name.
    GIT_REPOSITORY  git@github.com:kodezine/cmake-toolchains.git
    GIT_TAG         ${GITHUB_BRANCH_TOOLCHAIN}
)

# pre-fetch the toolchain repository as the first job before project configuration
FetchContent_GetProperties(cmake-toolchains)

if(NOT cmake-toolchains_POPULATED)
    FetchContent_Populate(cmake-toolchains)
endif()

project(stm32f072rb-disco-board)

# Set pre-requsities for selecting the CPU identifier for cross compilation
set(CORTEX_TYPE "cm0" CACHE STRING "CPU identifier for toolchains options")
# Set pre-requsites for selecting the STM32 microcontroller family type
set(STM32_TYPE "f0" CACHE STRING "STM32 HAL Microcontroller type")
# Set pre-requisite for exact device name of the STM32
set(STM32_DEVICE "STM32F072xB" CACHE STRING "STM32 Microcontoller Device")
# Set branch names for the sub modules dependencies
set(GITHUB_BRANCH_TOOLCHAIN "HEAD" CACHE STRING "git SHA for CMake Toolchain")

if(DEFINED BOARD_VARIANT)
    message(STATUS "STM32F072RB-Discovery board with ${BOARD_VARIANT} features.")
else()
    set(BOARD_VARIANT main)
    message(STATUS "STM32F072RB-Discovery board with basic features.")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmake/lib_stm32f072rb_disco_${BOARD_VARIANT}.cmake)
if(DEMO)
    add_subdirectory(cubemx_${BOARD_VARIANT}/demo_${BOARD_VARIANT})
endif()
