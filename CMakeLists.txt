cmake_minimum_required(VERSION 3.20.0)
project(TP_Algos)

# Set source directory
set(SOURCE_DIR "TP_Algos")

# Tell CMake that headers are also in SOURCE_DIR
include_directories(${SOURCE_DIR})
set(SOURCES "${SOURCE_DIR}/NorthWestCorner.hpp")
set(SOURCES "${SOURCE_DIR}/LeastCostMethod.hpp")
set(SOURCES "${SOURCE_DIR}/VogelApproximationMethod.hpp")
set(SOURCES "${SOURCE_DIR}/SteppingStoneMethod.hpp")
set(SOURCES "${SOURCE_DIR}/MODIMethod.hpp")
set(SOURCES "${SOURCE_DIR}/utils.hpp")
set(SOURCES "${SOURCE_DIR}/common.hpp")

# Generate Python module
add_subdirectory(lib/pybind11-2.6.1)
pybind11_add_module(TP_Algos ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
