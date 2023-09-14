set(TARGET_NAME Matrix)

# Заголовочные файлы
set(HEADERS_LIST)

# Исходные файлы
set(SOURCES_LIST
   Matrix.cpp)

# Создание исполняемого файла
add_executable(${TARGET_NAME} ${HEADERS_LIST} ${SOURCES_LIST})