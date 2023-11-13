cmake_minimum_required(VERSION 3.20)

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

find_package(Git QUIET)
if(GIT_FOUND)
   execute_process(
      COMMAND           ${GIT_EXECUTABLE} submodule status
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      OUTPUT_VARIABLE   GIT_SUBMOD_STATUS
      RESULT_VARIABLE   GIT_SUBMOD_STATUS_RES)

   set(UNINITIALIZED_FOUND FALSE)

   if(GIT_SUBMOD_STATUS_RES EQUAL "0")
      string(REPLACE "\n" ";" GIT_SUBMOD_STATUS_LINES "${GIT_SUBMOD_STATUS}")
      foreach(SUBMODULE_LINE IN LISTS GIT_SUBMOD_STATUS_LINES)
         string(REGEX MATCH "^-" IS_UNINITIALIZED "${SUBMODULE_LINE}")
         if(IS_UNINITIALIZED)
            string(REGEX MATCH " [^ ]+$" SUBMODULE_PATH "${SUBMODULE_LINE}")
            message(WARNING "Uninitialized submodule: ${SUBMODULE_PATH}")
            set(UNINITIALIZED_FOUND TRUE)
         endif()
      endforeach()

   if(UNINITIALIZED_FOUND)
      message(FATAL_ERROR "One or more submodules are uninitialized. Please initialize them.")
   endif()

   endif()
endif()

# Активация CTest
enable_testing()

# Загружаем модуль CMake "GoogleTest".
include(GoogleTest)

add_subdirectory(External/GoogleTest)
add_subdirectory(Src)