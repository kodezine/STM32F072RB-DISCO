
if(NOT (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm"))
    message(FATAL_ERROR "${PROJECT_NAME} can only compile with a suitable ARM cross compiler; no target build.")
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CMakePrintHelpers)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::framework ALIAS ${PROJECT_NAME})

# Get the CMSIS5 independent library from ARM CMSIS GitHub pages
include(cmake/lib_cmsis.cmake)
set(cmsis_DEVICE_INCLUDE_DIR "${cmsis_SOURCE_DIR}/Device/ARM/ARMCM0/Include" CACHE STRING "Path to ARM0 from standard CMSIS")
set(cmsis_CORE_INCLUDE_DIR "${cmsis_SOURCE_DIR}/CMSIS/Core/Include" CACHE STRING "Path to CMSIS core includes")

set(cubemx_core_INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Core/Inc")
set(cubemx_core_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cubemx/Core/Src")
set(cubemx_core_SOURCES
    ${cubemx_core_SOURCE_DIR}/main.c
    ${cubemx_core_SOURCE_DIR}/stm32f0xx_hal_msp.c
    ${cubemx_core_SOURCE_DIR}/system_stm32f0xx.c
    ${cubemx_core_SOURCE_DIR}/stm32f0xx_hal_timebase_tim.c
    ${cubemx_core_SOURCE_DIR}/gpio.c
    ${cubemx_core_SOURCE_DIR}/can.c
    ${cubemx_core_SOURCE_DIR}/i2c.c
    ${cubemx_core_SOURCE_DIR}/spi.c
    ${cubemx_core_SOURCE_DIR}/tim.c
    ${cubemx_core_SOURCE_DIR}/tsc.c
    ${cubemx_core_SOURCE_DIR}/usb.c
)

target_sources(${PROJECT_NAME}
    PRIVATE
    ${cubemx_core_SOURCES}
)
cmake_print_variables(st_hal_SOURCE_DIR)
target_include_directories(${PROJECT_NAME}
    PRIVATE
    PUBLIC
    $<BUILD_INTERFACE:${st_hal_SOURCE_DIR}/Inc>
        $<BUILD_INTERFACE:${cmsis_CORE_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${cmsis_DEVICE_INCLUDE_DIR}>
        $<BUILD_INTERFACE:${cubemx_core_INCLUDES_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)


set(${PROJECT_NAME}_PUBLIC_HEADERS

    ${cubemx_core_INCLUDES_DIR}/can.h
    ${cubemx_core_INCLUDES_DIR}/gpio.h
    ${cubemx_core_INCLUDES_DIR}/i2c.h
    ${cubemx_core_INCLUDES_DIR}/main.h
    ${cubemx_core_INCLUDES_DIR}/spi.h
    ${cubemx_core_INCLUDES_DIR}/stm32f0xx_hal_conf.h
    ${cubemx_core_INCLUDES_DIR}/stm32f0xx_it.h
    ${cubemx_core_INCLUDES_DIR}/tim.h
    ${cubemx_core_INCLUDES_DIR}/tsc.h
    ${cubemx_core_INCLUDES_DIR}/usb.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        C_STANDARD          11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS        OFF
        PUBLIC_HEADER       "${${PROJECT_NAME}_PUBLIC_HEADERS}"
        EXPORT_NAME         framework
)

write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
    VERSION       ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

setTargetCompileOptions(PROJECT_NAME)

target_link_libraries(${PROJECT_NAME}
    stm32${STM32_TYPE}xx_hal
)

# CPACK begins here
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
set(CPACK_BINARY_7Z ON)
set(CPACK_BINARY_NSIS OFF)
include(CPack)
