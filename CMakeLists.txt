# Sets the minimum required version of cmake for a project.
cmake_minimum_required(VERSION 3.20)

# Sets the name of the project.
project(Draft C CXX)

# Устанавливаем 17-й стандарт C++.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Выходные директории
set(DRAFT_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(OUTPUT_DIR "${DRAFT_PATH}/Output")

set(OUTPUT_DEBUG_DIR "${OUTPUT_DIR}/Debug")
set(OUTPUT_RELEASE_DIR "${OUTPUT_DIR}/Release")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/Lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/Bin)

include(BuildScripts/CheckGitSubmodules.cmake)

set(GIT_SUBMODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
check_git_submodules("${GIT_SUBMODULE_DIR}" IS_UNINITIALIZED_FOUND)

if(IS_UNINITIALIZED_FOUND)
   message(
      FATAL_ERROR
      "One or more submodules are uninitialized in ${GIT_SUBMODULE_DIR}."
      " Please initialize them: git submodule update --init")
endif()

# Активация CTest
enable_testing()

# Загружаем модуль CMake "GoogleTest".
include(GoogleTest)

add_subdirectory(External/GoogleTest)
add_subdirectory(Src)