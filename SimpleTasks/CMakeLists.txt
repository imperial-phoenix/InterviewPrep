# Имя проекта
set(TARGET_NAME SimpleTasks)

# Заголовочные файлы
set(HEADERS_LIST)

# Исходные файлы
set(SOURCES_LIST
   main.cpp)

# Создание исполняемого файла
add_executable(${TARGET_NAME} ${HEADERS_LIST} ${SOURCES_LIST})
