# Задаем имя библиотеки.
set(TARGET_NAME Array)

# Создаем интерфейсную библиотеку (header-only).
add_library(${TARGET_NAME} INTERFACE)

# Указываем путь к заголовочным файлам.
target_include_directories(${TARGET_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Список распространяемых заголовочных файлов.
set(HEADERS_LIST
   Array.hpp)

# Добавьте заголовочные файлы к библиотеке
target_sources(${TARGET_NAME} INTERFACE ${HEADERS_LIST})

add_subdirectory(Test)