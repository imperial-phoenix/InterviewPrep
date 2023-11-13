cmake_minimum_required(VERSION 3.20)

project(Draft LANGUAGES C CXX)

# Activates CTest.
enable_testing()

# Includes the CMake script to check that Git submodules are initialized.
include(BuildScripts/CheckGitSubmodules.cmake)

# Includes the CMake module for GTest integration.
include(GoogleTest)

# Sets C++20 as the standard for the project.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
   message("Compiler is clang")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
   add_compile_options(-Wall -Wextra -Wpedantic)
   message("Compiler is gnu")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
   message("Compiler is msvc")
endif()

# Output directories for build artifacts.
# set(DRAFT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/Output")

set(OUTPUT_DEBUG_DIR "${OUTPUT_DIR}/Debug")
set(OUTPUT_RELEASE_DIR "${OUTPUT_DIR}/Release")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/Lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/Bin)

# Checks the initialization status of Git submodules
set(GIT_SUBMODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
check_git_submodules("${GIT_SUBMODULE_DIR}" IS_UNINITIALIZED_FOUND)

# If any uninitialized submodules are found, stops the configuration process
# with an error message.
if(IS_UNINITIALIZED_FOUND)
   message(
      FATAL_ERROR
      "One or more submodules are uninitialized in ${GIT_SUBMODULE_DIR}."
      " Please initialize them: git submodule update --init")
endif()

add_subdirectory(External/GoogleTest)
add_subdirectory(Src)