cmake_minimum_required(VERSION 3.15)
project(TONEAPI VERSION 0.0.1 DESCRIPTION "A header-only C++ wrapper of Intel Performance Primitives")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Define the header-only library
# This is the core of a header-only library. 
# INTERFACE libraries don't produce a compiled artifact (like .lib or .so). 
# They only propagate properties (like include directories) to targets that link against them.
add_library(TONEAPI INTERFACE)

# GNUInstallDirs helps to set the $CMAKE_INSTALL_INCLUDEDIR variable in a platform-independent way.
include(GNUInstallDirs)

# Specify the include directory for the public headers
target_include_directories(TONEAPI INTERFACE
    # This generator expression specifies where the 
    # headers will be found after installation
    # CMAKE_INSTALL_INCLUDEDIR is a variable defined by GNUInstallDirs
    # It typically resolves to `include` (relative to the install prefix)
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    # During build process, the headers and source files are kept in the source tree.
    # This generator expression specifies where the headers will be found during the build.
    # Build process generally allows you to build test cases or examples to try things out 
    # before installation into the system directories.
    # There is no real building of the target since this is a header-only library.
    # But I am stil specifying it for completeness.
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
#######################
# Install the library #
#######################
# This command prepares the toneapi target for export
install(TARGETS TONEAPI EXPORT toneapi_targets)  # `toneapi_targets` is an arbitrary name for the export set.
# This installs the contents of your include/ directory to the install prefix's include directory. 
# This is where users will find your header files after installing your library
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Generate and install the package configuration file
include(CMakePackageConfigHelpers)

# Configure a file to tell CMake how to find the installed headers
# This command generates toneapiConfig.cmake from toneapiConfig.cmake.in. 
# It replaces @PACKAGE_INIT@ with standard CMake code that sets up 
# CMAKE_CURRENT_LIST_DIR and other variables correctly when the package is found by find_package().
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toneapiConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/toneapiConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/toneapi"
)

# Generate the version file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/toneapiConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Install the generated configuration files
# Installs the generated toneapiConfig.cmake and
# toneapiConfigVersion.cmake to the specified destination. 
# This is crucial for find_package to locate your package.
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/toneapiConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/toneapiConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake"
)

# Export the targets for use by other projects
export(EXPORT toneapi_targets
    FILE "${CMAKE_INSTALL_PREFIX}/cmake/toneapiTargets.cmake"
)

# Install the export file
install(EXPORT toneapi_targets
    FILE toneapiTargets.cmake
    # NAMESPACE toneapi::
    DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake"
)

# Generate and install pkg-config file
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toneapi.pc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/toneapi.pc"
    @ONLY
)

# Install the generated pkg-config file
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/toneapi.pc"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

# You can then use CMAKE_PROJECT_VERSION, CMAKE_PROJECT_VERSION_MAJOR, etc.
# to generate a version.h file
# configure_file(
#     "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/version.h"
#     @ONLY
# )
