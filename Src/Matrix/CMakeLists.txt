# TODO:
# 1) Понять как указать конкретный список распространяемых заголовочных файлов.
# 2) Можно ли собирать такую библиотеку через cmake --build build --target Matrix?
# 3) Какой смысл в target_sources?

# Задаем имя библиотеки.
set(TARGET_NAME Matrix)

# Создаем интерфейсную библиотеку (header-only).
add_library(${TARGET_NAME} INTERFACE)

# Указываем путь к заголовочным файлам.
target_include_directories(${TARGET_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Список распространяемых заголовочных файлов.
set(HEADERS_LIST
   Matrix.hpp)

# Добавьте заголовочные файлы к библиотеке
target_sources(${TARGET_NAME} INTERFACE ${HEADERS_LIST})

add_subdirectory(Test)