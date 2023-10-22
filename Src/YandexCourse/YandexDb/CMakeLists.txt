# Имя проекта
set(TARGET_NAME YandexDb)

# Заголовочные файлы
set(HEADERS_LIST)

# Исходные файлы
set(SOURCES_LIST
   YandexDb.cpp)

# Создание исполняемого файла
add_executable(${TARGET_NAME} ${HEADERS_LIST} ${SOURCES_LIST})