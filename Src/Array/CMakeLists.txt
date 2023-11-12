# Set the name of the library.
set(TARGET_NAME Array)

# Create the header-only library.
add_library(${TARGET_NAME} INTERFACE)

# Set C++20.
target_compile_features(${TARGET_NAME} INTERFACE cxx_std_20)

# Set path to the header files.
target_include_directories(${TARGET_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# List of distributed header files.
set(HEADERS_LIST
   Array.hpp)

target_sources(${TARGET_NAME} INTERFACE ${HEADERS_LIST})

# Unit tests.
add_subdirectory(Test)