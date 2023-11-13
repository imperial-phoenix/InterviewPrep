set(TARGET_NAME Array)

# Create the header-only library.
add_library(${TARGET_NAME} INTERFACE)

# Set path to the header files.
target_include_directories(${TARGET_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# List of distributed header files.
set(HEADERS_LIST
   Array.hpp)

# ???
target_sources(${TARGET_NAME} INTERFACE ${HEADERS_LIST})

# Unit tests.
add_subdirectory(Test)